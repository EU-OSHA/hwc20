<?php
class HWCTaxonomyToolsAndExamplesMigration extends AbstractNCWTaxonomyTermMigration {

  function addFieldMappings() {
    parent::addFieldMappings();
    $this->addSimpleMappings(array('parent'));
  }

  public function getMigrationURL() {
    $root = variable_get('hwc_tk_migration_root_url', '');
    $variable = variable_get('hwc_tk_migration_' . $this->getMachineName() . '_url');
    if (isset($_REQUEST['debug'])) {
      drupal_set_message($this->getMachineName() . " = " . $root . $variable);
    }
    return $root . $variable;
  }

  public function __construct($arguments) {
    parent::__construct($arguments, 'ToolsAndExamplesHWCTaxonomyTermSource', 'tools_and_examples');
    $this->description = 'Sync taxonomy "tools and examples" from HWC';
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_tk_tool_type = osha_migration_normalize_migrated_term_reference($row->field_tk_tool_type, 'tax_tools_and_examples');
    if ($row->tid && $this->source->parents[$row->tid]) {
      $parent_tid = $this->source->parents[$row->tid];
      $weight = $this->source->weight[$row->tid];
      $row->weight = $weight;
      $tmp = [$parent_tid];
      $parent_tid = osha_migration_normalize_migrated_term_reference($tmp, 'tax_tools_and_examples');
      if ($parent_tid) {
        $row->parent = $parent_tid;
      }
    }

  }

  public function computeCount() {
    ncw_migration_debug('!klass: Starting counting !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    if ($this->count == -1) {
      $data = $this->fileGetContents($this->endpoint_url);
      $this->count = 0;
      if ($data = json_decode($data)) {
        if (!empty($data->items)) {
          $data = $data->items;
          foreach ($data as $ob) {
            $ob = $ob->item;
            $id = $this->itemIdentifier($ob);
            if (!in_array($id, $this->skip_ids)) {
              $this->count++;
            }
          }
        }
      }
    }
    ncw_migration_debug('!klass: Found !count items', array('!klass' => get_class($this), '!count' => $this->count));
    return $this->count;
  }

}

class ToolsAndExamplesHWCTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public $parents;
  public $weights;

  public function readData() {
    ncw_migration_debug('!klass: Starting reading items from !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    $this->rows = array();
    $this->parents = array();
    $this->weight = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      ncw_migration_debug('!klass:      * Processing !count items', array('!klass' => get_class($this), '!count' => count($data->items)));
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        if (in_array($id, $this->skip_ids)) {
          continue;
        }
        $this->parents[$id] = $ob->parent_tid;
        $this->weights[$id] = $ob->weight;
        $node_url = $this->itemURL($id);
        ncw_migration_debug('!klass:      * Reading item: !url', array('!klass' => get_class($this), '!url' => $node_url));
        if ($rowd = $this->fileGetContents($node_url)) {
          if ($row_ob = json_decode($rowd, TRUE)) {
            $row = new stdClass();
            foreach ($row_ob as $k => $v) {
              $row->$k = $v;
            }
            $this->rows[$id] = $row;
          }
        }
        else {
          $msg = format_string('Failed to read data from !url', array('!url' => $node_url));
          watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
          $this->rows[$id] = NULL;
        }
      }
    }
    else {
      $msg = format_string('Failed to read data from !url', array('!url' => $this->endpoint_url));
      watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
      throw new MigrateException($msg, Migration::MESSAGE_ERROR);
    }
    ncw_migration_debug('!klass: Done reading items', array('!klass' => get_class($this)));
    reset($this->rows);
  }

  function hwc_tk_migration_datasource_url() {
    $ret = NULL;
    static $errorDisplayed = FALSE;
    $ret = variable_get('hwc_tk_migration_root_url');
    if (empty($ret)) {
      $ret = 'http://hwc.localhost';
      if (!$errorDisplayed) {
        $errorDisplayed = TRUE;
        drupal_set_message("Empty 'hwc_tk_migration_root_url' variable. Using default 'http://hwc.localhost'", 'warning');
      }
    }
    return $ret;
  }

  public function itemURL($id) {
    return $this->hwc_tk_migration_datasource_url() . 'export/taxonomy_term/' . $id;
  }

  public function contentFields() {
    return array('parent');
  }

}

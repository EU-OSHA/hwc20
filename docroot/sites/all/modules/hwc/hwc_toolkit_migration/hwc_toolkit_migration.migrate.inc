<?php

define('MIGRATE_STUB_MARKER_TMP', '#stub#');

/**
 * Implements hook_migrate_api().
 *
 * Set the API level to 2, for migration classes to be recognized by Migrate.
 */
function hwc_toolkit_migration_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'hwc_toolkit' => array(
        'title' => 'Sync data from HWC toolkit',
      ),
    ),
    'migrations' => array(

      'tax_tools_and_examples' => array(
        'group_name' => 'hwc_toolkit',
        'dependencies' => array(),
        'class_name' => 'HWCTaxonomyToolsAndExamplesMigration',
      ),

      'tk_example' => array(
        'group_name' => 'hwc_toolkit',
        'dependencies' => array(),
        'class_name' => 'TKExampleMigration',
      ),

      'tk_topic' => array(
        'group_name' => 'hwc_toolkit',
        'dependencies' => array('tk_example'),
        'class_name' => 'TKTopicMigration',
      ),

      'tk_article' => array(
        'group_name' => 'hwc_toolkit',
        'dependencies' => array('tk_example'),
        'class_name' => 'TKArticleMigration',
      ),

      'tk_tool' => array(
        'group_name' => 'hwc_toolkit',
        'dependencies' => array('tk_topic'),
        'class_name' => 'TKToolMigration',
      ),
    ),
  );
}

abstract class AbstractHWCToolkitNodeMigration extends AbstractNCWNodeMigration {

  function fixBody(&$row) {
    $root = variable_get('hwc_tk_migration_root_url', '');
    foreach ($row->body as &$body) {
      $body = str_replace(json_decode('"\u00a0"'), '', $body);
      $body = str_replace(['</p> <p>','<span>  </span>'], ['</p><p>', ''], $body);
      $body = str_replace(
        [$root . 'en', '<p></p>', '<span> </span>', '<ul> </ul>', "\n", '<p><br /></p>'],
        '', $body);
    }
  }

  /**
   * Implements Migration::prepareRow()
   *
   * To adapt JSON fields data to what migrate expects in the field.
   */
  public function prepareRow($row) {
    try {
      hwc_tk_migration_debug('!klass:      * Preparing source node: !id', array(
        '!klass' => get_class($this),
        '!id' => $row->nid,
      ));
      $row->path = !empty($row->path['alias']) ? $row->path['alias'] : NULL;
      // Normalize JSON structure, to match migrate expectations for field data.
      $fields = field_info_instances('node', $this->bundle);
      foreach ($fields as $field_name => $field_info) {
        if (in_array($field_name, $this->getManuallyMigratedFields())) {
          continue;
        }
        $fi = field_info_field($field_name);

        if ($fi['type'] == 'entityreference') {
          // Entity references will be manually handled by each migration.
          continue;
        }
        $normalizer = 'hwc_migration_normalize_field_' . $fi['type'];
        if (!function_exists($normalizer)) {
          $normalizer = 'osha_migration_normalize_field_' . $fi['type'];
        }
        if (function_exists($normalizer)) {
          $filter_languages = array();
          if (!$this->allowMigrateTranslation()) {
            $filter_languages = array('en');
          }
          $normalizer($row, $field_name, $fi, $filter_languages);
        }
        else {
          $name = $this->currentMigration()->getMachineName();
          hwc_tk_migration_debug("[BUG][$name] Cannot find normalization '$normalizer', skipping field $field_name");
          $row->{$field_name} = array();
        }
      }
      $row->field_migration_source = 'hwc_toolkit';
    }
    catch (Exception $e) {
      hwc_tk_migration_debug("Exception while preparing the row: {$row->nid}", 'error');
      return FALSE;
    }
    $this->fixBody($row);
    return TRUE;
  }

  /**
   * Implements Migration::complete() to configure translations.
   */
  public function complete($entity, stdClass $row) {
  }

  public function postImport() {
  }

  public function getMigrationURL() {
    $root = variable_get('hwc_tk_migration_root_url', '');
    $variable = variable_get('hwc_tk_migration_' . $this->getMachineName() . '_url');
    if (isset($_REQUEST['debug'])) {
      drupal_set_message($this->getMachineName() . " = " . $root . $variable);
    }
    return $root . $variable;
  }

}

abstract class AbstractHWCToolkitNodeSource extends AbstractNCWNodeSource {

  /**
   * Return a string representing the source, for display in the UI.
   */
  public function __toString() {
    return 'Extract data from HWC Toolkit endpoint';
  }

  public function itemIdentifier($ob) {
    return $ob->nid;
  }

  public function fileGetContents($url) {
    return file_get_contents($url);
  }

  /**
   * Total number of entities.
   */
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

  public function readData() {
    hwc_tk_migration_debug('!klass: Starting reading items from !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      hwc_tk_migration_debug('!klass:      * Processing !count items', array('!klass' => get_class($this), '!count' => count($data->items)));
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        if (in_array($id, $this->skip_ids)) {
          continue;
        }
        $node_url = $this->itemURL($id);
        hwc_tk_migration_debug('!klass:      * Reading item: !url', array('!klass' => get_class($this), '!url' => $node_url));
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
    hwc_tk_migration_debug('!klass: Done reading items', array('!klass' => get_class($this)));
    reset($this->rows);
  }

  public function itemURL($id) {
    return hwc_tk_migration_datasource_url() . '/export/node/' . $id;
  }
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

function hwc_tk_migration_debug($message, $message_args = array(), $level = 'notice') {
  if (function_exists('drush_get_option')) {
    // Message appear when running 'drush -d migrate-import events'.
    if ($debug = drush_get_option('debug')) {
      $str = format_string($message, $message_args);
      drush_log($str, $level);
    }
  }
}

function hwc_migration_url_files($suffix = '') {
  return hwc_tk_migration_datasource_url() . '/sites/default/files/' . $suffix;
}

function hwc_migration_normalize_field_image($row, $field_name, $field_info, $filter_languages) {
  hwc_migration_normalize_field_file($row, $field_name, $field_info, $filter_languages);
}

function hwc_migration_normalize_field_file($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $languages = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach ($values as $f) {
        $field[] = hwc_migration_url_files(str_replace('public://', '', $f['uri']));
        $languages[] = $language;
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_language'} = $languages;
}

function hwc_migration_normalize_field_text_with_summary($row, $field_name, $field_info, $filter_languages) {
  hwc_migration_normalize_field_text_long($row, $field_name, $field_info, $filter_languages);
}

function hwc_migration_normalize_field_text_long($row, $field_name, $field_info, $filter_languages) {
  $field = array();
  $summary = array();
  $languages = array();
  $format = array();
  if (!empty($row->{$field_name}) && is_array($row->{$field_name})) {
    foreach ($row->{$field_name} as $language => $values) {
      if (!empty($filter_languages) && !in_array($language, $filter_languages)) {
        continue;
      }
      foreach ($values as $v) {
        $field[] = $v['value'];
        $summary[] = $v['summary'];
        $languages[] = $language;
        $v['format'] = str_replace('full_html_minimal', 'full_html', $v['format']);
        $v['format'] = str_replace('dangerous_substances_minimal', 'audio_visual', $v['format']);
        $format[] = str_replace('dangerous_substances', 'audio_visual', $v['format']);
      }
    }
  }
  $row->{$field_name} = $field;
  $row->{$field_name . '_summary'} = $summary;
  $row->{$field_name . '_language'} = $languages;
  $row->{$field_name . '_format'} = $format;
}

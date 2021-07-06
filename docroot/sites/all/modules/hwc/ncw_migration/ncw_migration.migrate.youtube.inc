<?php

/**
 * Class NCWYoutubeMigration migrates infographics.
 *
 * Set hwc_migration_youtube_url variable for explicit source URL.
 */
class NCWYoutubeMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    $source_klass = 'NCWYoutubeSource';
    if (isset($arguments['source_klass'])) {
      $source_klass = $arguments['source_klass'];
    }
    parent::__construct($arguments, $source_klass, 'youtube');
    $this->description = 'Import youtube from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addUnmigratedDestinations(array(
    ));
    $this->ignoreMetatagMigration();
  }

  /**
   * {@inheritdoc}
   */
  protected function getManuallyMigratedFields() {
    return array('field_tags');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_migration_path_alias = $row->path;
    // Disable NCW alias.
    $row->path = NULL;
  }
}

class NCWYoutubeSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_youtube',
      'field_migration_path_alias',
      'field_character_count',
      'field_page_count',
    );
    return array_combine($fields, $fields);
  }

  /**
   * Include the related infographics recursively into the migrated content.
   */
  public function readData() {
    $msg = format_string('Updating from !url', array('!url' => $this->endpoint_url));
    watchdog('ncw_migration',  $msg, []);
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        $node_url = $this->itemURL($id);
        if ($rowd = $this->fileGetContents($node_url)) {
          if ($row_ob = json_decode($rowd, TRUE)) {
            $row = new stdClass();
            foreach ($row_ob as $k => $v) { $row->$k = $v; }
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
    reset($this->rows);
  }


}

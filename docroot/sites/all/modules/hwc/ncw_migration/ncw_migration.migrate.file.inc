<?php

/**
 * Class NCWFileMigration migrates infographics.
 *
 * Set hwc_migration_file_url variable for explicit source URL.
 */
class NCWFileMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    $source_klass = 'NCWFileSource';
    if (isset($arguments['source_klass'])) {
      $source_klass = $arguments['source_klass'];
    }
    parent::__construct($arguments, $source_klass, 'file');
    $this->description = 'Import file from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags', 'field_tags');

    $this->addUnmigratedDestinations(array(
      'field_tags:ignore_case',
      'field_image:title',
      'field_image:file_class',
      'field_image:preserve_files',
      'field_image:destination_dir',
      'field_image:destination_file',
      'field_image:urlencode',
      'field_image:source_dir',
      'field_image:alt',
      'field_thumbnail:title',
      'field_thumbnail:file_class',
      'field_thumbnail:preserve_files',
      'field_thumbnail:destination_dir',
      'field_thumbnail:destination_file',
      'field_thumbnail:urlencode',
      'field_thumbnail:source_dir',
      'field_thumbnail:alt',
      'field_file:file_class',
      'field_file:preserve_files',
      'field_file:destination_dir',
      'field_file:destination_file',
      'field_file:source_dir',
      'field_file:urlencode',
      'field_file:description',
      'field_file:display',
      'field_publication_date:rrule',
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
    $row->field_tags = osha_migration_normalize_migrated_term_reference($row->field_tags, 'tax_tags');
  }
}


class NCWFileSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_tags',
      'field_image',
      'field_image_language',
      'field_thumbnail',
      'field_thumbnail_language',
      'field_file',
      'field_file_language',
      'field_migration_path_alias',
    );
    return array_combine($fields, $fields);
  }

  /**
   * Include the related infographics recursively into the migrated content.
   */
  public function readData() {
    $msg = format_string('Updating from !url', array('!url' => $this->endpoint_url));
    watchdog('ncw_migration', $msg, []);
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

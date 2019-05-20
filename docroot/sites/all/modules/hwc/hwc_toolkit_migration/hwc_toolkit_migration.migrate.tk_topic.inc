<?php

/**
 * Class TKTopicMigration migrates topic.
 *
 * Set hwc_migration_news_url variable for explicit source URL.
 */
class TKTopicMigration extends AbstractHWCToolkitNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'TKTopicSource', 'tk_topic');
    $this->description = 'Import TKTopic from HWC Toolkit';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addUnmigratedDestinations(array(
      'field_image:file_class',
      'field_image:preserve_files',
      'field_image:destination_dir',
      'field_image:destination_file',
      'field_image:source_dir',
      'field_image:urlencode',
      'field_image:alt',
      'field_image:title',
    ));
    $this->ignoreMetatagMigration();
  }

  protected function getManuallyMigratedFields() {
    return array();
  }

}


class TKTopicSource extends AbstractHWCToolkitNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',

      'body',
      'body_format',
      'body_language',
      'body_summary',

      'field_image',
      'field_image_language',

    );
    return array_combine($fields, $fields);
  }

}

<?php

/**
 * Class TKExampleMigration migrates example.
 *
 * Set hwc_migration_news_url variable for explicit source URL.
 */
class TKExampleMigration extends AbstractHWCToolkitNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'TKExampleSource', 'tk_example');
    $this->description = 'Import TKExample from HWC Toolkit';
  }

  protected function getManuallyMigratedFields() {
    return ['field_country'];
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_country:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_country:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_country', 'field_country');

    $this->addUnmigratedDestinations(array(
      'field_country:ignore_case',

      'field_download_pdf:file_class',
      'field_download_pdf:preserve_files',
      'field_download_pdf:destination_dir',
      'field_download_pdf:destination_file',
      'field_download_pdf:source_dir',
      'field_download_pdf:urlencode',
      'field_download_pdf:description',
      'field_download_pdf:display',

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

  function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_country = $row->field_country['tid'];
  }

}


class TKExampleSource extends AbstractHWCToolkitNodeSource {

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
      'field_organisation',
      'field_external_link',

      'field_image',
      'field_image_language',

      'field_download_pdf',
      'field_download_pdf_language',
      'field_country',
    );
    return array_combine($fields, $fields);
  }

}

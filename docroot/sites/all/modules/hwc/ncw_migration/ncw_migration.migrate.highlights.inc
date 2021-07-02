<?php

/**
 * Class NCWHighlightMigration migrates highlights into news content type
 *
 * Set hwc_migration_highlights_url variable for explicit source URL.
 */
class NCWHighlightMigration extends AbstractNCWNodeMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    $source_klass = 'NCWHighlightSource';
    if (isset($arguments['source_klass'])) {
      $source_klass = $arguments['source_klass'];
    }
    parent::__construct($arguments, $source_klass, 'news');
    $this->description = 'Import highlights (into news) from NCW';
  }

  /**
   * {@inheritdoc}
   */
  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags', 'field_tags');
    $this->addFieldMapping('field_aditional_resources', 'field_aditional_resources');

    $this->addUnmigratedDestinations(array(
      'field_tags:ignore_case',
      'field_expiration_date:rrule',
      'field_image:file_class',
      'field_image:preserve_files',
      'field_image:destination_dir',
      'field_image:destination_file',
      'field_image:source_dir',
      'field_image:urlencode',
      'field_image:alt',
      'field_image:title',
      'field_publication_date:rrule',
      'field_summary',
      'field_summary:format',
      'field_summary:language',
    ));
    $this->ignoreMetatagMigration();
  }

  /**
   * {@inheritdoc}
   */
  protected function getManuallyMigratedFields() {
    return array('field_tags', 'field_aditional_resources');
  }

  /**
   * Implements Migration::prepare()
   */
  public function prepare($entity, stdClass $row) {
    parent::prepare($entity, $row);
    if ($row->field_image_image_captions_language) {
      foreach ($row->field_image_image_captions_language as $i => $lang) {
        $entity->field_image[$lang][$i]['image_field_caption']['value'] = $row->field_image_image_captions[$i];
        $entity->field_image[$lang][$i]['image_field_caption']['format'] = 'full_html';
      }
    }
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
    $fi = field_info_field('field_aditional_resources');
    osha_migration_normalize_field_entityreference($row, 'field_aditional_resources', $fi);
    $additional_resources = $row->field_aditional_resources;
    $row->field_aditional_resources = array();
    foreach ($additional_resources as $original_nid) {
      if ($destid1 = ncw_migration_find_additional_resource($original_nid)) {
        $row->field_aditional_resources[] = $destid1;
      }
    }
  }

}


class NCWHighlightSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_image',
      'field_image_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'field_expiration_date',
      'field_expiration_date_timezone',
      'field_expiration_date_value2',
      'field_tags',
      'field_archived',
      'field_character_count',
      'field_page_count',
      'field_aditional_resources',
      'field_migration_source',
      'field_migration_path_alias',
      'field_show_on',
    );
    return array_combine($fields, $fields);
  }
}

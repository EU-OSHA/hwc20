<?php

/**
 * Class NCWNoteMigration migrates note_to_editor
 *
 * Set hwc_migration_notes_to_editor_url variable for explicit source URL.
 */
class NCWNoteMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWNoteSource', 'note_to_editor');
    $this->description = 'Import notes to editor from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags', 'field_tags');

    $this->addUnmigratedDestinations(array());
    $this->ignoreMetatagMigration();
  }

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


class NCWNoteSource extends AbstractNCWNodeSource {

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
      'field_character_count',
      'field_page_count',
      'field_migration_path_alias',
    );
    return array_combine($fields, $fields);
  }
}

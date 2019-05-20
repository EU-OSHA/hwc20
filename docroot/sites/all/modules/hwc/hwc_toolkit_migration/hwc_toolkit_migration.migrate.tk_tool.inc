<?php

/**
 * Class TKToolMigration migrates tool.
 *
 * Set hwc_migration_news_url variable for explicit source URL.
 */
class TKToolMigration extends AbstractHWCToolkitNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'TKToolSource', 'tk_tool');
    $this->description = 'Import TKTool from HWC Toolkit';
  }

  protected function getManuallyMigratedFields() {
    return ['field_tk_tool_type', 'field_tk_examples'];
  }

  function addFieldMappings() {
    parent::addFieldMappings();
    $this->addFieldMapping('field_tk_tool_type:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tk_tool_type:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tk_tool_type', 'field_tk_tool_type');

    $this->addFieldMapping('field_tk_examples', 'field_tk_examples');
    $this->ignoreMetatagMigration();
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_tk_tool_type = osha_migration_normalize_migrated_term_reference($row->field_tk_tool_type, 'tax_tools_and_examples');

    $fi = field_info_field('field_tk_examples');
    osha_migration_normalize_field_entityreference($row, 'field_tk_examples', $fi);
    $tk_examples = $row->field_tk_examples;
    $row->field_tk_examples = array();
    foreach ($tk_examples as $original_nid) {
      if ($destid1 = hwc_migration_find_destid1($original_nid)) {
        $row->field_tk_examples[] = $destid1;
      }
    }

  }

}

class TKToolSource extends AbstractHWCToolkitNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',

      'field_tk_tool_type',
      'field_introduction',
      'field_image',
      'field_image_language',

      'body',
      'body_language',
      'body_summary',
      'body_format',

      'field_tk_examples',
      'field_benefits',
    );
    return array_combine($fields, $fields);
  }

}

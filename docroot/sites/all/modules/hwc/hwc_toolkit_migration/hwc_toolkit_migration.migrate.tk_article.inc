<?php

/**
 * Class TKArticleMigration migrates article.
 *
 * Set hwc_migration_news_url variable for explicit source URL.
 */
class TKArticleMigration extends AbstractHWCToolkitNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'TKArticleSource', 'tk_article');
    $this->description = 'Import TKArticle from HWC Toolkit';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tools_examples:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tools_examples:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tools_examples', 'field_tools_examples');

    $this->addFieldMapping('field_tk_article', 'field_tk_article');
    $this->addFieldMapping('field_tk_topics', 'field_tk_topics');

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

  function prepareRow($row) {
    parent::prepareRow($row);

    $row->field_tools_examples = osha_migration_normalize_migrated_term_reference($row->field_tools_examples, 'tax_tools_and_examples');

    $fi = field_info_field('field_tk_article');
    osha_migration_normalize_field_entityreference($row, 'field_tk_article', $fi);
    $tk_examples = $row->field_tk_article;
    $row->field_tk_article = array();
    foreach ($tk_examples as $original_nid) {
      if ($destid1 = hwc_migration_find_destid1($original_nid, 'tk_article')) {
        $row->field_tk_article[] = $destid1;
      }
    }

    $fi = field_info_field('field_tk_topics');
    osha_migration_normalize_field_entityreference($row, 'field_tk_topics', $fi);
    $tk_examples = $row->field_tk_topics;
    $row->field_tk_topics = array();
    foreach ($tk_examples as $original_nid) {
      if ($destid1 = hwc_migration_find_destid1($original_nid, 'tk_topic')) {
        $row->field_tk_topics[] = $destid1;
      }
    }
  }

  protected function getManuallyMigratedFields() {
    return array('field_tk_article', 'field_tk_topics', 'field_tools_examples');
  }

}


class TKArticleSource extends AbstractHWCToolkitNodeSource {

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

      'field_tk_article_type',
      'field_tk_article',
      'field_tk_topics',
      'field_tools_examples',
    );
    return array_combine($fields, $fields);
  }

}

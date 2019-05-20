<?php
/**
 * Class NCWGalleryMigration migrates gallery.
 *
 * Set hwc_migration_audio_visual_url variable for explicit source URL.
 */
class NCWGalleryMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWGallerySource', 'flickr_gallery');
    $this->description = 'Import Gallery from NCW';
  }

  function getTermReferenceFieldsMap() {
    return [
      'field_tags' => 'tags',
    ];
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $unmigrated_destinations = [];
    foreach ($this->getTermReferenceFieldsMap() as $taxonomy => $vocabulary) {
      $this->addFieldMapping($taxonomy . ':source_type')->defaultValue('tid');
      $this->addFieldMapping($taxonomy . ':create_term')->defaultValue(FALSE);
      $this->addFieldMapping($taxonomy, $taxonomy);
      $unmigrated_destinations[] = $taxonomy . ':ignore_case';
    }

    $this->addUnmigratedDestinations($unmigrated_destinations);
    $this->ignoreMetatagMigration();
  }

  public function prepare($entity, stdClass $row) {
    parent::prepare($entity, $row);
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
    foreach ($this->getTermReferenceFieldsMap() as $taxonomy => $vocabulary) {
      if ($row->{$taxonomy}) {
        $orig_taxonomies = $row->{$taxonomy};
        foreach ($row->{$taxonomy} as $idx => $term_name) {
          $term = taxonomy_get_term_by_name($term_name, $vocabulary);
          $row->{$taxonomy}[$idx] = current($term)->tid;
        }
        if (!$row->{$taxonomy}) {
          foreach ($orig_taxonomies as $orig_taxonomy) {
            watchdog('ncw_migration', "[BUG]Cannot find taxonomy '".serialize($orig_taxonomy)."', for $vocabulary", array(), WATCHDOG_ERROR);
          }
        }
      }
    }
  }
}


class NCWGallerySource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'field_publication_date',
      'field_flickr',
      'field_cover_flickr',
    );

    return array_combine($fields, $fields);
  }

}

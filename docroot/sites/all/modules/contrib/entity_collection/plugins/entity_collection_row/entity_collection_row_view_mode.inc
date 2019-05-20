<?php
/**
 * @file
 * Plugin for view mode row.
 */

/**
 * This class let's you render each row with a particular view mode.
 */
class EntityCollectionRowViewMode extends EntityCollectionRow {

  /**
   * @see EntityCollectionRowInterface::getAllOptions().
   */
  public function getAllOptions() {
    $options = array();
    foreach ($this->entity_collection->settings['allowed_bundles'] as $type => $bundles) {
      if (count($bundles)) {
        $entity_info = entity_get_info($type);
        foreach ($entity_info['view modes'] as $mode => $info) {
          $options[$type][$mode] = $info['label'];
        }
      }
    }
    return $options;
  }

  /**
   * @see EntityCollectionRowInterface::getOptions()
   */
  public function getOptions($entity_type) {
    $entity_info = entity_get_info($entity_type);
    $options = array();
    foreach ($entity_info['view modes'] as $mode => $info) {
      $options[$mode] = $info['label'];
    }
    return $options;
  }

  /**
   * @see EntityCollectionRowInterface::build()
   */
  public function build(EntityCollection $collection, EntityCollectionTreeNode $item, $langcode = NULL) {
    if ($item->type != 'entity_collection') {
      return entity_view($item->type, array($item->entity_id => $item->content), $item->style, $langcode);
    }
  }
}

<?php
/**
 * @file
 * Representation of an Entity Collection entity.
 */

/**
 * This class is used to represent an entity collection.
 */
class EntityCollection extends Entity {
  // We provide the values here for reference.
  public $type;
  public $name;
  public $bid;
  public $title;
  public $cache;
  protected $tree;
  public $requiredcontexts = array();
  public $contexts = array();

  /**
   * Create an entity collection entity.
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'entity_collection');
  }

  /**
   * Gets the type entity.
   *
   * @return Entity
   *  The type associated with this entity.
   */
  public function getTypeEntity() {
    if (isset($this->type)) {
      return entity_get_types($this->type);
    }
  }

  /**
   * Set the current contexts.
   */
  public function setContexts($contexts) {
    $this->contexts = $contexts;
  }
  /**
   * Get the entity collection tree.
   * @return EntityCollectionTreeNode
   *   The tree for this entity collection.
   */
  public function getTree($reset = FALSE) {
    if (!isset($this->tree) || $reset) {
      $this->tree = EntityCollectionStorage::getBundleStorage($this->bundle)->retrieve($this, $this->contexts);
    }
    return $this->tree;
  }

  /**
   * Build content.
   * @param string $view_mod
   *   The current view mode.
   * @param type $langcode
   *   The language code to use.
   * @return array
   *  An array that can be used with Drupals rendering system.
   */
  public function buildContent($view_mode = 'default', $langcode = NULL, $settings = array()) {
    $tree = $this->getTree();
    $content = array();
    $content['entity_collection'] = EntityCollectionStyle::getStyle($this)->build($this, $tree, $langcode, $settings);
    if (isset($content['entity_collection'])) {
      foreach ($content['entity_collection'] as &$row) {
        $row[]['#entity_collection'] = $this;
      }
    }
    $rendered = entity_get_controller($this->entityType)->buildContent($this, $view_mode, $langcode, $content);
    $rendered['#entity_collection'] = $this;
    $rendered['#theme'] = 'entity_collection';
    return $rendered;
  }
}

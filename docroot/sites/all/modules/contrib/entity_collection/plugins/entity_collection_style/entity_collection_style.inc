<?php
/**
 * @file
 * Base style interface and abstract class.
 */

/**
 * Interface describing an Entity Collection style.
 */
interface EntityCollectionStyleInterface {
  /**
   * Get the max depth that this style allows.
   * @return int
   *   An integer value indicating the depth.
   */
  public function getMaxDepth();

  /**
   * Indicate if this style supports grouping.
   */
  public function useGrouping();

  /**
   * Indicate if this style will use reordering.
   */
  public function useReordering();

  /**
   * Build the entity collection content.
   * @param EntityCollection $entity
   *   The entity in which the content belongs.
   * @param EntityCollectionTreeNode $tree
   *   The tree to build
   * @param $langcode
   *   The language code to use.
   */
  public function build(EntityCollection $entity, EntityCollectionTreeNode $tree, $langcode = NULL);
}
/**
* Simple interface for storing entity_collections.
*/
abstract class EntityCollectionStyle {
  function __construct($entity_collection, $settings = array()) {
    $this->entity_collection = $entity_collection;
    $this->settings = $settings;
  }

  /**
   * Use a max depth of 0 by default (disabled).
   */
  public function getMaxDepth() {
    return 0;
  }

  /**
   * Use reordering by default.
   */
  public function useReordering() {
    return TRUE;
  }

  /**
   * Get a style plugin for a particular collection.
   * @param EntityCollection $collection
   *   The collection for which we should look up the style for.
   * @return EntityCollectionStyle
   *   The active style plugin for the entity collection.
   */
  public static function getStyle(EntityCollection $collection) {
    ctools_include('plugins');
    if (!isset($collection->style)) {
      return FALSE;

    }
    $plugin = ctools_get_plugins('entity_collection', 'plugins', $collection->style);
    if (isset($plugin['entity_collection_style']['class'])) {
      return new $plugin['entity_collection_style']['class']($collection, isset($collection->settings['style_settings']) ? $collection->settings['style_settings'] : array());
    }
    return FALSE;
  }

  /**
   * Get all available styles.
   */
  public static function getStyles() {
    ctools_include('plugins');
    $plugins = ctools_get_plugins('entity_collection', 'plugins');
    $style_plugins = array();
    foreach ($plugins as $name => $info) {
      if (isset($info['title']) && isset($info['entity_collection_style'])) {
        $style_plugins[$name] = $info;
      }
    }
    return $style_plugins;
  }

  /**
   * Get all styles formatted for #options
   * @return array
   *   An array of storage backends.
   */
  public static function getStyleOptions() {
    $styles = EntityCollectionStyle::getStyles();
    foreach ($styles as $name => $info) {
      if (isset($info['title']) && isset($info['entity_collection_style'])) {
        $options[$name] = $info['title'];
      }
    }
    return $options;
  }

  /**
   * Give the option to add a settings form for the style plugin.
   */
  public function settingsForm(&$form, $settings = array()) {}

  /**
   * Give the possibility to process the settings after submit.
   */
  public function formSettingsSubmit(&$settings) {}
}
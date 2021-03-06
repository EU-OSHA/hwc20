<?php
/**
 * @file
 * A hiearchy style plugin.
 */

/**
 * This style can show groups of content in hierarchies.
 */
class EntityCollectionStyleHierarchy extends EntityCollectionStyle {

  /**
   * Build the hierarchy.
   * @see EntityCollectionStyle::build().
   */
  public function build(EntityCollection $entity, EntityCollectionTreeNode $tree, $langcode = NULL) {
    $content = array();
    $this->renderTreeNode($content, $entity, $tree, $langcode);
    return $content;
  }

  /**
   * Render the content of a tree as a tree using a template.
   */
  protected function renderTreeNode(&$content, $entity, EntityCollectionTreeNode $item, $langcode = NULL) {
    $element = array(
      '#collection_children' => array(),
      '#weight' => $item->position,
      '#theme' => 'entity_collection_style_hierarchy'
    );
    if (isset($item->content)) {
      $data = EntityCollectionRow::getRow($entity)->build($entity, $item);
      $element['#collection_parent'] = $data;
    }
    foreach ($item->getChildren() as $key => $child) {
      $this->renderTreeNode($element['#collection_children'], $entity, $child, $langcode);
    }
    $content[] = $element;
  }

  /**
   * Return the depth setting.
   */
  public function getMaxDepth() {
    return $this->settings['max_depth'];
  }

  public function settingsForm(&$form, $settings = array()) {
    $depth_options = array();
    for ($i = 1; $i <= 10; $i++) {
      $depth_options[$i] = $i;
    }
    $form['max_depth'] = array(
      '#type' => 'select',
      '#options' => $depth_options,
      '#title' => t('Max depth'),
    );
  }
}

/**
 * Preprocess function for this plugin.
 */
function template_preprocess_entity_collection_style_hierarchy(&$variables) {
  $variables['parent'] = isset($variables['element']['#collection_parent']) ? $variables['element']['#collection_parent'] : 0;
  $variables['children'] = $variables['element']['#collection_children'];
}

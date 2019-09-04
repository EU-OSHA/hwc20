<?php
/**
 * @file
 * hwc_previous_campaigns.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_previous_campaigns_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hwc_previous_campaigns_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hwc_previous_campaigns_image_default_styles() {
  $styles = array();

  // Exported image style: relres.
  $styles['relres'] = array(
    'label' => 'relres',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function hwc_previous_campaigns_node_info() {
  $items = array(
    'campaign_16' => array(
      'name' => 'Article Campaign 16',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'campaign_18' => array(
      'name' => 'Article Campaign 18',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

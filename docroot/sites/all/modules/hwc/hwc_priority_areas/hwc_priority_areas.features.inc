<?php
/**
 * @file
 * hwc_priority_areas.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_priority_areas_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hwc_priority_areas_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hwc_priority_areas_node_info() {
  $items = array(
    'pa_highlights' => array(
      'name' => 'PA Highlights',
      'base' => 'node_content',
      'description' => 'Priority area Highlights',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'priority_area' => array(
      'name' => 'Priority area',
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

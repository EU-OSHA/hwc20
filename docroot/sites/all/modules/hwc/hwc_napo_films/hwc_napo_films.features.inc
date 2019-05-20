<?php
/**
 * @file
 * hwc_napo_films.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_napo_films_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hwc_napo_films_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hwc_napo_films_node_info() {
  $items = array(
    'napo_film' => array(
      'name' => 'Napo Film',
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

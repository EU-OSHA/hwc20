<?php
/**
 * @file
 * hwc_partner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_partner_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hwc_partner_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hwc_partner_node_info() {
  $items = array(
    'partner' => array(
      'name' => 'Partner',
      'base' => 'node_content',
      'description' => 'Content type to store info about Official Campaign Partners and Media Partners',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'private_aria_article' => array(
      'name' => 'Private area article',
      'base' => 'node_content',
      'description' => 'Article used for private area of partners.',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

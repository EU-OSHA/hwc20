<?php
/**
 * @file
 * osha_infographics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_infographics_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
function osha_infographics_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function osha_infographics_image_default_styles() {
  $styles = array();

  // Exported image style: infographic_thumbnail.
  $styles['infographic_thumbnail'] = array(
    'label' => 'Infographic thumbnail (350 x 260)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 350,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function osha_infographics_node_info() {
  $items = array(
    'infographic' => array(
      'name' => 'Infographic',
      'base' => 'node_content',
      'description' => 'Infographics',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

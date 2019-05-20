<?php
/**
 * @file
 * osha_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
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
function osha_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function osha_news_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: good_practice_exchange
  $nodequeues['good_practice_exchange'] = array(
    'name' => 'good_practice_exchange',
    'title' => 'Good Practice Exchange',
    'subqueue_title' => '',
    'size' => 3,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function osha_news_image_default_styles() {
  $styles = array();

  // Exported image style: medium_newsletter_crop.
  $styles['medium_newsletter_crop'] = array(
    'label' => 'Medium Newsletter Crop (220 x 145)',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'manual_crop',
          'apply_all_effects' => 0,
        ),
        'weight' => 0,
      ),
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 145,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function osha_news_node_info() {
  $items = array(
    'news' => array(
      'name' => 'News',
      'base' => 'node_content',
      'description' => 'OSH news',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

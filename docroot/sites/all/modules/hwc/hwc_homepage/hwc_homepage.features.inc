<?php
/**
 * @file
 * hwc_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hwc_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function hwc_homepage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_partner_frontpage
  $nodequeues['featured_partner_frontpage'] = array(
    'name' => 'featured_partner_frontpage',
    'title' => 'Featured Partner Frontpage',
    'subqueue_title' => '',
    'size' => 1,
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
      0 => 'partner',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: homepage_about_the_topic
  $nodequeues['homepage_about_the_topic'] = array(
    'name' => 'homepage_about_the_topic',
    'title' => 'Homepage about the topic',
    'subqueue_title' => '',
    'size' => 0,
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
      0 => 'article',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function hwc_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: partner_logo_front.
  $styles['partner_logo_front'] = array(
    'label' => 'partner_logo_front',
    'effects' => array(
      1 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 170,
          'height' => 128,
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
function hwc_homepage_node_info() {
  $items = array(
    'frontpage_slider' => array(
      'name' => 'Frontpage Banner',
      'base' => 'node_content',
      'description' => 'Frontpage banner content',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

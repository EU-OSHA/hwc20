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

  // Exported nodequeues: good_practice_exchange_events
  $nodequeues['good_practice_exchange_events'] = array(
    'name' => 'good_practice_exchange_events',
    'title' => 'Good Practice Exchange events',
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
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'events',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: homepage_banners
  $nodequeues['homepage_banners'] = array(
    'name' => 'homepage_banners',
    'title' => 'Homepage banners',
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
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'frontpage_slider',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: press_room_events
  $nodequeues['press_room_events'] = array(
    'name' => 'press_room_events',
    'title' => 'Press room events',
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
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'events',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: splash_banners
  $nodequeues['splash_banners'] = array(
    'name' => 'splash_banners',
    'title' => 'Splash banners',
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
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'frontpage_slider',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: splash_campaign_material
  $nodequeues['splash_campaign_material'] = array(
    'name' => 'splash_campaign_material',
    'title' => 'Splash campaign material',
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
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'campaign_materials',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: splash_events
  $nodequeues['splash_events'] = array(
    'name' => 'splash_events',
    'title' => 'Splash events',
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
    'insert_at_front' => 0,
    'unique_entries' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'events',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: splash_news
  $nodequeues['splash_news'] = array(
    'name' => 'splash_news',
    'title' => 'Splash news',
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
    'insert_at_front' => 0,
    'unique_entries' => 0,
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
function hwc_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: banner_1.
  $styles['banner_1'] = array(
    'label' => 'Banner',
    'effects' => array(
      12 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'banner_1',
        ),
        'weight' => 0,
      ),
    ),
  );

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

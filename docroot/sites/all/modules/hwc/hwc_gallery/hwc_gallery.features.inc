<?php
/**
 * @file
 * hwc_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
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
function hwc_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function hwc_gallery_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_gallery
  $nodequeues['featured_gallery'] = array(
    'name' => 'featured_gallery',
    'title' => 'featured_gallery',
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
      0 => 'hwc_gallery',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function hwc_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: gallery_cover_image.
  $styles['gallery_cover_image'] = array(
    'label' => 'Gallery cover image',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1170,
          'height' => 555,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'gallery_cover_image',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: medium_thumbnail_mc_340.
  $styles['medium_thumbnail_mc_340'] = array(
    'label' => 'Medium thumbnail manual crop (340 X 220)',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 340,
          'height' => 220,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'medium_thumbnail_mc_340',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: small_thumb_from_medium_crop.
  $styles['small_thumb_from_medium_crop'] = array(
    'label' => 'Small thumb from medium crop (110px wide)',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'medium_thumbnail_mc_340',
          'apply_all_effects' => 0,
        ),
        'weight' => 0,
      ),
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 110,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: xl_image.
  $styles['xl_image'] = array(
    'label' => 'XL image (1200px wide)',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 0,
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
function hwc_gallery_node_info() {
  $items = array(
    'hwc_gallery' => array(
      'name' => 'Gallery',
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

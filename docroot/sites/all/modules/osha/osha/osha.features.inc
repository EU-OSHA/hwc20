<?php
/**
 * @file
 * osha.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  if ($module == "entity_collection" && $api == "entity_collection_bundles_default") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
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
function osha_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function osha_image_default_styles() {
  $styles = array();

  // Exported image style: article_crop_1920.
  $styles['article_crop_1920'] = array(
    'label' => 'Article Crop 1920',
    'effects' => array(
      20 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'manual_crop',
          'apply_all_effects' => 0,
        ),
        'weight' => 0,
      ),
      21 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1920,
          'height' => 595,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: article_image.
  $styles['article_image'] = array(
    'label' => 'Article image',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1920,
          'height' => 595,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'article_image',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: large_crop_480.
  $styles['large_crop_480'] = array(
    'label' => 'Large Crop 480',
    'effects' => array(
      17 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'manual_crop',
          'apply_all_effects' => 0,
        ),
        'weight' => 1,
      ),
      19 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: manual_crop.
  $styles['manual_crop'] = array(
    'label' => 'Manual Crop',
    'effects' => array(
      11 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'manual_crop',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: medium_crop_220.
  $styles['medium_crop_220'] = array(
    'label' => 'Medium Crop 220',
    'effects' => array(
      18 => array(
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reuse_crop_style' => 'manual_crop',
          'apply_all_effects' => 0,
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => '',
          'upscale' => 0,
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
function osha_node_info() {
  $items = array(
    'article' => array(
      'name' => 'Article',
      'base' => 'node_content',
      'description' => 'Introductions and Sections',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'internal_url' => array(
      'name' => 'Internal URL',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'webform' => array(
      'name' => 'Webform',
      'base' => 'node_content',
      'description' => 'Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

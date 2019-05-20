<?php
/**
 * @file
 * hwc_toolkit.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_toolkit_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function hwc_toolkit_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function hwc_toolkit_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: most_popular_tools_and_examples
  $nodequeues['most_popular_tools_and_examples'] = array(
    'name' => 'most_popular_tools_and_examples',
    'title' => 'Most Popular Tools and Examples',
    'subqueue_title' => '',
    'size' => 5,
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
      0 => 'tk_example',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: tools_and_examples
  $nodequeues['tools_and_examples'] = array(
    'name' => 'tools_and_examples',
    'title' => 'Tools and Examples',
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
      0 => 'tk_tool',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function hwc_toolkit_image_default_styles() {
  $styles = array();

  // Exported image style: tkit_example_detail.
  $styles['tkit_example_detail'] = array(
    'label' => 'tkit_example_detail',
    'effects' => array(),
  );

  // Exported image style: toolkit.
  $styles['toolkit'] = array(
    'label' => 'toolkit',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 237,
          'height' => 252,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'toolkit',
        ),
        'weight' => 0,
      ),
      6 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 235,
          'height' => 250,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: toolkit_example.
  $styles['toolkit_example'] = array(
    'label' => 'toolkit example',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 286,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 284,
            'height' => 250,
            'xpos' => -1,
            'ypos' => -1,
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
      9 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 280,
          'height' => 250,
          'anchor' => 'center-center',
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: toolkit_example_detail.
  $styles['toolkit_example_detail'] = array(
    'label' => 'toolkit_example_detail',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function hwc_toolkit_node_info() {
  $items = array(
    'tk_article' => array(
      'name' => 'Toolkit Article',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'tk_example' => array(
      'name' => 'Toolkit Example',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'tk_section' => array(
      'name' => 'TK Toolkit',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'tk_tool' => array(
      'name' => 'Toolkit Tool',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
    'tk_topic' => array(
      'name' => 'Toolkit Topic',
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

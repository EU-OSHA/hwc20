<?php
/**
 * @file
 * hwc_toolkit.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_toolkit_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc_toolkit-toolkit_go_back'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'toolkit_go_back',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_toolkit',
    'node_types' => array(
      0 => 'tk_example',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'below_title',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['hwc_toolkit-toolkit_left_menu'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'toolkit_left_menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_toolkit',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-tool_examples_carousel-block'] = array(
    'cache' => -1,
    'css_class' => 'col-xs-12 col-sm-12 col-md-12',
    'custom' => 0,
    'delta' => 'tool_examples_carousel-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'tk_article',
      1 => 'tk_tool',
      2 => 'tk_topic',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 17,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-tool_examples_carousel-popular'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'tool_examples_carousel-popular',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'tk_article',
    ),
    'pages' => 'node/6321',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 16,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}

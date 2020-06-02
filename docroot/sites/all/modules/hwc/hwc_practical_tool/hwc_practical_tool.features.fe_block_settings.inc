<?php
/**
 * @file
 * hwc_practical_tool.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_practical_tool_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc_practical_tool-hwc_practical_tool_less'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_practical_tool_less',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_practical_tool',
    'node_types' => array(),
    'pages' => 'tools-and-publications/practical-tools',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 35,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['hwc_practical_tool-hwc_practical_tool_more'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_practical_tool_more',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_practical_tool',
    'node_types' => array(),
    'pages' => 'tools-and-publications/practical-tools',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 10,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}

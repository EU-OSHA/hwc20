<?php
/**
 * @file
 * hwc_priority_areas.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_priority_areas_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc_priority_areas-hwc_pa_case_studies'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_pa_case_studies',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_priority_areas',
    'node_types' => array(
      0 => 'priority_area',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 15,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['hwc_priority_areas-hwc_pa_publications'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_pa_publications',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_priority_areas',
    'node_types' => array(
      0 => 'priority_area',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
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
    'visibility' => 0,
  );

  $export['hwc_priority_areas-hwc_pa_tools_and_guidance'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_pa_tools_and_guidance',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_priority_areas',
    'node_types' => array(
      0 => 'priority_area',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 6,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

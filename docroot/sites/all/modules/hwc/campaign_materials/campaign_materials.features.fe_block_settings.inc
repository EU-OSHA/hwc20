<?php
/**
 * @file
 * campaign_materials.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function campaign_materials_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-view_campaign_materials-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'view_campaign_materials-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
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
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

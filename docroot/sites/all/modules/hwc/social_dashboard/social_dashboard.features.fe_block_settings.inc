<?php
/**
 * @file
 * social_dashboard.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function social_dashboard_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['social_dashboard-media_centre_form'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'media_centre_form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'social_dashboard',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

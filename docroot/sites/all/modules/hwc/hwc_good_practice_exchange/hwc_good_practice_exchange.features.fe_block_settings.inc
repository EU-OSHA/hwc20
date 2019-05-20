<?php
/**
 * @file
 * hwc_good_practice_exchange.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_good_practice_exchange_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['facetapi-k0hWqhTI8R0yy5qQwUQWpEM1BT0nBoL9'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'k0hWqhTI8R0yy5qQwUQWpEM1BT0nBoL9',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'good-practice-exchange-platform',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -91,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Type:',
    'visibility' => 1,
  );

  $export['views--exp-documents-gpep'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '-exp-documents-gpep',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'good-practice-exchange-platform',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -97,
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

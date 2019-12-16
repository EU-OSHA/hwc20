<?php
/**
 * @file
 * hwc_glossary.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_glossary_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc_glossary-hwc_glossary_page'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_glossary_page',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_glossary',
    'node_types' => array(),
    'pages' => 'glossary
glossary/*',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 20,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['hwc_glossary-hwc_glossary_search'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_glossary_search',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_glossary',
    'node_types' => array(),
    'pages' => 'glossary-search
glossary-search/*',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 21,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}

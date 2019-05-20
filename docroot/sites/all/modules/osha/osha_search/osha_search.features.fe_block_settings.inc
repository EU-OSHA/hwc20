<?php
/**
 * @file
 * osha_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['facetapi-0CytJ17GKzhRj01QOSWuDS3Op30a9Ojl'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '0CytJ17GKzhRj01QOSWuDS3Op30a9Ojl',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -86,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Language:',
    'visibility' => 1,
  );

  $export['facetapi-C8eorcVV3vQafgn7Jly2bqKGXShnYglD'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'C8eorcVV3vQafgn7Jly2bqKGXShnYglD',
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
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Organisation:',
    'visibility' => 1,
  );

  $export['facetapi-azovHlgKCMoXFeRqtkoZUGezu72WIJwb'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'azovHlgKCMoXFeRqtkoZUGezu72WIJwb',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search
practical-tools
tools-and-publications/practical-tools',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -89,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Priority areas:',
    'visibility' => 1,
  );

  $export['facetapi-bhmRHTzU2n0ejKZP9wDI0S1oi2DgbSDm'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'bhmRHTzU2n0ejKZP9wDI0S1oi2DgbSDm',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'search',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -90,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Show:',
    'visibility' => 1,
  );

  $export['menu-menu-search'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-search',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'search/site
search/wiki',
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
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_search-osha_search_clear_filters'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_search_clear_filters',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_search',
    'node_types' => array(),
    'pages' => 'search
search/*
tools-and-publications/seminars
legislation/directives/*
safety-and-health-legislation/european-directives
node/2544
legislation/guidelines/*
practical-tools
tools-and-publications/practical-tools
good-practice-exchange-platform',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -92,
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

  $export['search-form'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -69,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -10,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views--exp-search-site'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '-exp-search-site',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'search',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -94,
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

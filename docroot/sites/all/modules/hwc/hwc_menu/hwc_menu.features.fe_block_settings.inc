<?php
/**
 * @file
 * hwc_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu_block-1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'campaign_16',
      1 => 'campaign_18',
    ),
    'pages' => 'previous-campaigns/*/about-the-topic
node/8013
node/8006',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 19,
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

  $export['menu_block-2'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 2,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-3'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 3,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'article',
    ),
    'pages' => 'node/169
node/3292
about-topic/priority-areas',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 20,
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

  $export['menu_block-4'] = array(
    'cache' => -1,
    'css_class' => 'left-menu',
    'custom' => 0,
    'delta' => 4,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => 'about-topic/w*
about-topic/h*
about-topic/t*
about-topic/g*
about-topic/business-case',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 24,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'About the topic',
    'visibility' => 1,
  );

  $export['menu_block-5'] = array(
    'cache' => -1,
    'css_class' => 'left-menu accordion-menu',
    'custom' => 0,
    'delta' => 5,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'campaign_16',
      1 => 'campaign_18',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 26,
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

  $export['menu_block-6'] = array(
    'cache' => -1,
    'css_class' => 'left-menu pa-menu',
    'custom' => 0,
    'delta' => 6,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => 'about-topic/priority-area/*
about-topic/priority-areas',
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
    'title' => 'About the topic',
    'visibility' => 1,
  );

  $export['menu_block-7'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 7,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => 'about-topic/priority-areas',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 5,
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

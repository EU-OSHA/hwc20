<?php
/**
 * @file
 * osha_press_release.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_press_release_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_press_release-osha_press_kit'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_press_kit',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_press_release',
    'node_types' => array(
      0 => 'press_release',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Press kit',
    'visibility' => 0,
  );

  $export['osha_press_release-osha_press_rel_become_partner'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_press_rel_become_partner',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_press_release',
    'node_types' => array(
      0 => 'press_release',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -51,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 4,
      ),
    ),
    'title' => 'Become a media partner',
    'visibility' => 0,
  );

  $export['osha_press_release-osha_press_rel_join_list'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_press_rel_join_list',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_press_release',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => 3,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 3,
      ),
    ),
    'title' => 'Join our news distribution list',
    'visibility' => 0,
  );

  $export['panels_mini-press_room_blocks'] = array(
    'cache' => -1,
    'css_class' => 'container',
    'custom' => 0,
    'delta' => 'press_room_blocks',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'panels_mini',
    'node_types' => array(
      0 => 'press_release',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 11,
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

  $export['views-press_contacts-block'] = array(
    'cache' => -1,
    'css_class' => 'col-sm-3',
    'custom' => 0,
    'delta' => 'press_contacts-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'press_release',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -50,
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

  $export['views-press_releases-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'press_releases-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'inside-eu-osha/press-room',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => 22,
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

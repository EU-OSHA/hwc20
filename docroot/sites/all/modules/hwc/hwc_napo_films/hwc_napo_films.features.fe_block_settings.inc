<?php
/**
 * @file
 * hwc_napo_films.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_napo_films_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-napo_film_carousel-slidehow'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'napo_film_carousel-slidehow',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/160',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -79,
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

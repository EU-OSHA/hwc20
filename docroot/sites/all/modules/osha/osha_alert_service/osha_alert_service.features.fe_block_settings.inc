<?php
/**
 * @file
 * osha_alert_service.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function osha_alert_service_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['osha_alert_service-osha_alert_block_front_view'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_alert_block_front_view',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -28,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_alert_service_subscribe'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_alert_service_subscribe',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'alertservice
node/50',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -60,
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

  $export['osha_alert_service-osha_calls_rss'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_calls_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'node/1472',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_events_rss'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_events_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'oshevents
node/5322',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -33,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 1,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_job_vacancies_rss'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_job_vacancies_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'node/21',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -10,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 1,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_news_rss'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_news_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'oshnews',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -5,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['osha_alert_service-osha_publication_rss'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'osha_publication_rss',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'osha_alert_service',
    'node_types' => array(),
    'pages' => 'tools-and-publications/publications',
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
        'weight' => 1,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}

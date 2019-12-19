<?php
/**
 * @file
 * hwc.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc-article_related_resources'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'article_related_resources',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc',
    'node_types' => array(),
    'pages' => 'node/184',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 1,
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

  $export['hwc-content_related_resources'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'content_related_resources',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc',
    'node_types' => array(),
    'pages' => 'node/184',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 29,
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

  $export['hwc-european_week_news_events'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'european_week_news_events',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc',
    'node_types' => array(),
    'pages' => 'node/164',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'below_content',
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
    'title' => '',
    'visibility' => 1,
  );

  $export['hwc-hwc_footer_data'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_footer_data',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'footer',
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
    'title' => '',
    'visibility' => 0,
  );

  $export['hwc-page_share_widget'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'page_share_widget',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc',
    'node_types' => array(),
    'pages' => 'node/179',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 28,
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

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'footer',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['panels_mini-news_and_events'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'news_and_events',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'panels_mini',
    'node_types' => array(),
    'pages' => 'how-get-involved',
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

  $export['views-frontpage_events-press_room'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'frontpage_events-press_room',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/179',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 2,
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

  $export['views-news-press_room'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'news-press_room',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/179',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 25,
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

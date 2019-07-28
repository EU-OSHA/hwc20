<?php
/**
 * @file
 * hwc_homepage.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_homepage_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc_homepage-article_nav'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'article_nav',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_homepage',
    'node_types' => array(),
    'pages' => 'about-topic/*',
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

  $export['hwc_homepage-footer_section'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'footer_section',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_homepage',
    'node_types' => array(),
    'pages' => '<front>',
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

  $export['hwc_homepage-splash_browsing_content'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'splash_browsing_content',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_homepage',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => 3,
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

  $export['hwc_homepage-splash_download_news_campaign'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'splash_download_news_campaign',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_homepage',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
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

  $export['hwc_homepage-splash_title_banner_countdown'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'splash_title_banner_countdown',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_homepage',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
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
    'visibility' => 1,
  );

  $export['panels_mini-splash_page'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'splash_page',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'panels_mini',
    'node_types' => array(),
    'pages' => '<front>',
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
    'title' => 'Before the Campaign starts, here is what you can do',
    'visibility' => 1,
  );

  $export['views-cd72cedd59cdde6e501529c8e7edf1d4'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'cd72cedd59cdde6e501529c8e7edf1d4',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-frontpage_events-block'] = array(
    'cache' => -1,
    'css_class' => 'col-md-4',
    'custom' => 0,
    'delta' => 'frontpage_events-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -66,
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

  $export['views-frontpage_events-splash'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'frontpage_events-splash',
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

  $export['views-frontpage_slider-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'frontpage_slider-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-news-splash'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'news-splash',
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

  $export['views-partners-block_1'] = array(
    'cache' => -1,
    'css_class' => 'col-md-12',
    'custom' => 0,
    'delta' => 'partners-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => 13,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Partners',
    'visibility' => 1,
  );

  $export['views-splash_banners-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'splash_banners-block',
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

  $export['views-view_campaign_materials-splash'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'view_campaign_materials-splash',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}

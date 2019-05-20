<?php
/**
 * @file
 * hwc_partner.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function hwc_partner_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['hwc_partner-hwc_partner_login_text'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_partner_login_text',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_partner',
    'node_types' => array(),
    'pages' => 'user',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'below_title',
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
    'visibility' => 1,
  );

  $export['hwc_partner-hwc_partner_private_link_0'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_partner_private_link_0',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_partner',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -56,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Create an Event',
    'visibility' => 0,
  );

  $export['hwc_partner-hwc_partner_private_link_1'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_partner_private_link_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_partner',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -55,
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

  $export['hwc_partner-hwc_partner_private_link_2'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'hwc_partner_private_link_2',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'hwc_partner',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'hwc_frontend',
        'weight' => -54,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Private Area',
    'visibility' => 0,
  );

  $export['views-partners_list-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'partners_list-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/145',
    'roles' => array(),
    'themes' => array(
      'hwc_frontend' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'hwc_frontend',
        'weight' => -53,
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

<?php
/**
 * @file
 * hwc_partner.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function hwc_partner_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'partner_draft_events';
  $path_breadcrumb->name = 'Partner draft events';
  $path_breadcrumb->path = 'node/%node/events';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Campaign partners',
      1 => '%node:field-partner-type:name',
      2 => '%node:title',
      3 => 'Events',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'campaign-partners/national-focal-points',
      2 => 'node/%node:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['partner_draft_events'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'partner_draft_news';
  $path_breadcrumb->name = 'Partner draft news';
  $path_breadcrumb->path = 'node/%node/news';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Campaign partners',
      1 => '%node:field-partner-type:name',
      2 => '%node:title',
      3 => 'News',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'campaign-partners/national-focal-points',
      2 => 'node/%node:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['partner_draft_news'] = $path_breadcrumb;

  return $export;
}

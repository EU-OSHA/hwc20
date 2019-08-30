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
  $path_breadcrumb->machine_name = 'campaign_materials_details_page';
  $path_breadcrumb->name = 'Campaign materials details page';
  $path_breadcrumb->path = 'node/invalid/handled/from/code';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and publications',
      1 => 'Campaign materials',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'campaign-materials',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['campaign_materials_details_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'campaign_media_partners';
  $path_breadcrumb->name = 'campaign-media-partners';
  $path_breadcrumb->path = 'campaign-partners/campaign-media-partners';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['campaign_media_partners'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'enterprise_europe_network';
  $path_breadcrumb->name = 'enterprise-europe-network';
  $path_breadcrumb->path = 'campaign-partners/enterprise-europe-network';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['enterprise_europe_network'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'infographics_listing';
  $path_breadcrumb->name = 'Infographics listing';
  $path_breadcrumb->path = 'infographics';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and publications',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['infographics_listing'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'national_focal_points';
  $path_breadcrumb->name = 'national-focal-points';
  $path_breadcrumb->path = 'campaign-partners/national-focal-points';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['national_focal_points'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'official_campaign_partners';
  $path_breadcrumb->name = 'official-campaign-partners';
  $path_breadcrumb->path = 'campaign-partners/official-campaign-partners';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['official_campaign_partners'] = $path_breadcrumb;

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

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'practical_tools_details_page';
  $path_breadcrumb->name = 'Practical tools details page';
  $path_breadcrumb->path = 'node/invalid/handled/from/code';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and publications',
      1 => 'Practical tools',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'practical-tools',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['practical_tools_details_page'] = $path_breadcrumb;

  return $export;
}

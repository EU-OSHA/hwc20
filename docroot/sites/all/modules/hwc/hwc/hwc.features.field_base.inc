<?php
/**
 * @file
 * hwc.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hwc_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_migration_source'.
  $field_bases['field_migration_source'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_migration_source',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'ncw' => 'NCW',
        'oira' => 'Oira',
        'napo' => 'Napo',
        'hwc' => 'HWC',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_nodequeue'.
  $field_bases['field_nodequeue'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_nodequeue',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'case_studies_slideshow_' => 'Case studies Slideshow',
        'european_week_events' => 'European Week events',
        'european_week_news' => 'European Week news',
        'featured_gallery' => 'featured_gallery',
        'featured_partner_frontpage' => 'Featured Partner Frontpage',
        'featured_press_release' => 'Featured Press Release',
        'good_practice_examples' => 'Good Practice Examples',
        'good_practice_exchange' => 'Good Practice Exchange news',
        'good_practice_exchange_events' => 'Good Practice Exchange events',
        'good_practice_exchange_intro' => 'Good practice exchange intro',
        'homepage_about_the_topic' => 'Homepage about the topic',
        'homepage_banners' => 'Homepage banners',
        'homepage_events' => 'Homepage events',
        'homepage_news' => 'Homepage news',
        'homepage_recommended' => 'Homepage Recommended tools and resources',
        'most_popular_tools_and_examples' => 'Most Popular Tools and Examples',
        'press_contacts_queue' => 'Press contacts',
        'press_room_events' => 'Press room events',
        'press_room_news' => 'Press room news',
        'publication_queue' => 'Publication Slideshow',
        'splash_banners' => 'Splash banners',
        'splash_campaign_material' => 'Splash campaign material',
        'splash_events' => 'Splash events',
        'splash_news' => 'Splash news',
        'tools_and_examples' => 'Tools and Examples',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_show_in_ncw'.
  $field_bases['field_show_in_ncw'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_show_in_ncw',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}

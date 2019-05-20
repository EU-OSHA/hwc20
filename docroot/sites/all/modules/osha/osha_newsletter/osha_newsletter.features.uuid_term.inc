<?php
/**
 * @file
 * osha_newsletter.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function osha_newsletter_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'News',
    'description' => NULL,
    'format' => NULL,
    'weight' => 5,
    'uuid' => '04648f6e-d60f-4ce7-b800-e7842ad4f320',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'News',
          'format' => NULL,
          'safe_value' => 'News',
        ),
      ),
    ),
    'name_original' => 'News',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 11,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Events',
    'description' => NULL,
    'format' => NULL,
    'weight' => 6,
    'uuid' => '9bbceb37-cc1f-4bc1-99a0-0222105568a1',
    'language' => 'en',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'newsletter_sections',
    'description_field' => array(),
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Upcoming events',
          'format' => NULL,
          'safe_value' => 'Upcoming events',
        ),
      ),
    ),
    'name_original' => 'Upcoming events',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 15,
          'language' => 'en',
          'source' => '',
          'uid' => 0,
          'status' => 1,
          'translate' => 0,
          'created' => 1410881110,
          'changed' => 1410881110,
        ),
      ),
    ),
    'description_original' => NULL,
    'metatags' => array(),
  );
  return $terms;
}

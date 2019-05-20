<?php
/**
 * @file
 * osha_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_search_ac_categ_limit';
  $strongarm->value = '3';
  $export['osha_search_ac_categ_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_search_ac_fields';
  $strongarm->value = array(
    'attachments_field_file' => 'attachments_field_file',
    'attachments_field_publication_related_res' => 'attachments_field_publication_related_res',
    'attachments_field_related_documents' => 'attachments_field_related_documents',
    'body:value' => 'body:value',
    'title' => 'title',
    'title_field' => 'title_field',
  );
  $export['osha_search_ac_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_search_ac_index';
  $strongarm->value = 'default_multilingual_node_index';
  $export['osha_search_ac_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_search_ac_items_limit';
  $strongarm->value = '3';
  $export['osha_search_ac_items_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_search_bundles';
  $strongarm->value = array(
    'article' => 'article',
    'campaign_materials' => 'campaign_materials',
    'events' => 'events',
    'infographic' => 'infographic',
    'news' => 'news',
    'partner' => 'partner',
    'practical_tool' => 'practical_tool',
    'press_contact' => 'press_contact',
    'press_release' => 'press_release',
    'publication' => 'publication',
    'tk_article' => 'tk_article',
    'tk_example' => 'tk_example',
    'tk_tool' => 'tk_tool',
    'tk_topic' => 'tk_topic',
    'audio_visual' => 0,
    'document' => 0,
    'event_speaker' => 0,
    'external_url' => 0,
    'file' => 0,
    'flickr' => 0,
    'flickr_gallery' => 0,
    'frontpage_slider' => 0,
    'hwc_gallery' => 0,
    'internal_url' => 0,
    'napo_film' => 0,
    'note_to_editor' => 0,
    'private_aria_article' => 0,
    'slideshare' => 0,
    'tk_section' => 0,
    'topic_related' => 0,
    'twitter_tweet_feed' => 0,
    'twitter_user_profile' => 0,
    'webform' => 0,
    'youtube' => 0,
  );
  $export['osha_search_bundles'] = $strongarm;

  return $export;
}

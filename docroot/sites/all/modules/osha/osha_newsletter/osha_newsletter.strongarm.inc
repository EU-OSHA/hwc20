<?php
/**
 * @file
 * osha_newsletter.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_newsletter_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_spotlight';
  $strongarm->value = '0';
  $export['comment_anonymous_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_spotlight';
  $strongarm->value = 0;
  $export['comment_default_mode_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_spotlight';
  $strongarm->value = '50';
  $export['comment_default_per_page_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_spotlight';
  $strongarm->value = 1;
  $export['comment_form_location_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_spotlight';
  $strongarm->value = '1';
  $export['comment_preview_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_spotlight';
  $strongarm->value = '1';
  $export['comment_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_spotlight';
  $strongarm->value = 1;
  $export['comment_subject_field_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_view_modes_spotlight';
  $strongarm->value = array(
    0 => 'default',
    1 => 'teaser',
    2 => 'body',
    3 => 'osha_slideshow',
    4 => 'highlights_item',
    5 => 'newsletter_item',
    6 => 'highlights_item_alternative',
  );
  $export['ds_extras_view_modes_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_extras_view_modes_spotlights';
  $strongarm->value = array(
    0 => 'default',
    1 => 'teaser',
    2 => 'title_body',
    3 => 'body',
    4 => 'priority_areas',
    5 => 'hwc_teaser',
    6 => 'osha_slideshow',
    7 => 'highlights_item',
    8 => 'newsletter_item',
    9 => 'highlights_item_alternative',
    10 => 'pub_teaser',
    11 => 'osha_resources',
  );
  $export['ds_extras_view_modes_spotlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_entity_collection__newsletter_content_collection';
  $strongarm->value = array(
    'view_modes' => array(
      'block' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_entity_collection__newsletter_content_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__spotlight';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'body' => array(
        'custom_settings' => TRUE,
      ),
      'osha_slideshow' => array(
        'custom_settings' => TRUE,
      ),
      'highlights_item' => array(
        'custom_settings' => TRUE,
      ),
      'newsletter_item' => array(
        'custom_settings' => TRUE,
      ),
      'highlights_item_alternative' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'title_body' => array(
        'custom_settings' => FALSE,
      ),
      'priority_areas' => array(
        'custom_settings' => FALSE,
      ),
      'hwc_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'pub_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'osha_resources' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '9',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
        'workbench_access' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
        'language' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__newsletter_sections';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(
        'description' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'token' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__newsletter_sections'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_spotlight';
  $strongarm->value = '4';
  $export['language_content_type_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_spotlights';
  $strongarm->value = '4';
  $export['language_content_type_spotlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_spotlight';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_spotlight';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletters_no';
  $strongarm->value = '1';
  $export['newsletters_no'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_items_date_enable';
  $strongarm->value = 0;
  $export['newsletter_items_date_enable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_items_no';
  $strongarm->value = '0';
  $export['newsletter_items_no'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_spotlight';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_spotlights';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_spotlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_spotlight';
  $strongarm->value = '0';
  $export['node_preview_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_spotlight';
  $strongarm->value = 0;
  $export['node_submitted_spotlight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_spotlights';
  $strongarm->value = 0;
  $export['node_submitted_spotlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_after_max_nodes';
  $strongarm->value = '19';
  $export['osha_newsletter_after_max_nodes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_allowed_bundles';
  $strongarm->value = array(
    'events' => 'events',
    'news' => 'news',
    'twitter_tweet_feed' => 'twitter_tweet_feed',
    'article' => 0,
    'campaign_16' => 0,
    'campaign_18' => 0,
    'audio_visual' => 0,
    'campaign_materials' => 0,
    'document' => 0,
    'event_speaker' => 0,
    'external_url' => 0,
    'file' => 0,
    'flickr' => 0,
    'flickr_gallery' => 0,
    'frontpage_slider' => 0,
    'gpa' => 0,
    'hwc_gallery' => 0,
    'home_page_sections' => 0,
    'infographic' => 0,
    'internal_url' => 0,
    'musculoskeletal_disorders' => 0,
    'napo_film' => 0,
    'note_to_editor' => 0,
    'pa_highlights' => 0,
    'partner' => 0,
    'practical_tool' => 0,
    'press_contact' => 0,
    'press_release' => 0,
    'priority_area' => 0,
    'private_aria_article' => 0,
    'publication' => 0,
    'slideshare' => 0,
    'spotlight' => 0,
    'tk_section' => 0,
    'tk_article' => 0,
    'tk_example' => 0,
    'tk_tool' => 0,
    'tk_topic' => 0,
    'topic_related' => 0,
    'twitter_user_profile' => 0,
    'webform' => 0,
    'youtube' => 0,
  );
  $export['osha_newsletter_allowed_bundles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_background_img';
  $strongarm->value = 0;
  $export['osha_newsletter_image_block_background_img'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_details_link_label';
  $strongarm->value = 'Privacy policy';
  $export['osha_newsletter_image_block_details_link_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_details_link_url';
  $strongarm->value = 'node/1015';
  $export['osha_newsletter_image_block_details_link_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_intro_text';
  $strongarm->value = '';
  $export['osha_newsletter_image_block_intro_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_text_end';
  $strongarm->value = 'subscribers';
  $export['osha_newsletter_image_block_text_end'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_text_start';
  $strongarm->value = 'Join';
  $export['osha_newsletter_image_block_text_start'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_listserv';
  $strongarm->value = 'crm-campaign@osha.europa.eu';
  $export['osha_newsletter_listserv'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_listserv_from';
  $strongarm->value = 'hwc-newsletter@osha.europa.eu';
  $export['osha_newsletter_listserv_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_node_view_mode';
  $strongarm->value = 'newsletter_item';
  $export['osha_newsletter_node_view_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_term_ct_map';
  $strongarm->value = array(
    'article' => '',
    'view_mode_article' => 'newsletter_item',
    'campaign_16' => '',
    'view_mode_campaign_16' => 'newsletter_item',
    'campaign_18' => '',
    'view_mode_campaign_18' => 'newsletter_item',
    'audio_visual' => '',
    'view_mode_audio_visual' => 'newsletter_item',
    'campaign_materials' => '',
    'view_mode_campaign_materials' => 'newsletter_item',
    'document' => '',
    'view_mode_document' => 'newsletter_item',
    'event_speaker' => '',
    'view_mode_event_speaker' => 'newsletter_item',
    'events' => '184c62a6-3f57-4551-9e82-5308affcd5c3',
    'view_mode_events' => 'newsletter_item',
    'external_url' => '',
    'view_mode_external_url' => 'newsletter_item',
    'file' => '',
    'view_mode_file' => 'newsletter_item',
    'flickr' => '',
    'view_mode_flickr' => 'newsletter_item',
    'flickr_gallery' => '',
    'view_mode_flickr_gallery' => 'newsletter_item',
    'frontpage_slider' => '',
    'view_mode_frontpage_slider' => 'newsletter_item',
    'gpa' => '',
    'view_mode_gpa' => 'newsletter_item',
    'hwc_gallery' => '',
    'view_mode_hwc_gallery' => 'newsletter_item',
    'home_page_sections' => '',
    'view_mode_home_page_sections' => 'newsletter_item',
    'infographic' => '',
    'view_mode_infographic' => 'newsletter_item',
    'internal_url' => '',
    'view_mode_internal_url' => 'newsletter_item',
    'musculoskeletal_disorders' => '',
    'view_mode_musculoskeletal_disorders' => 'newsletter_item',
    'napo_film' => '',
    'view_mode_napo_film' => 'newsletter_item',
    'news' => '4f57cadd-a3dd-406d-981a-dfea0853c54e',
    'view_mode_news' => 'highlights_item',
    'note_to_editor' => '',
    'view_mode_note_to_editor' => 'newsletter_item',
    'pa_highlights' => '',
    'view_mode_pa_highlights' => 'newsletter_item',
    'partner' => '',
    'view_mode_partner' => 'newsletter_item',
    'practical_tool' => '',
    'view_mode_practical_tool' => 'newsletter_item',
    'press_contact' => '',
    'view_mode_press_contact' => 'newsletter_item',
    'press_release' => '',
    'view_mode_press_release' => 'newsletter_item',
    'priority_area' => '',
    'view_mode_priority_area' => 'newsletter_item',
    'private_aria_article' => '',
    'view_mode_private_aria_article' => 'newsletter_item',
    'publication' => '',
    'view_mode_publication' => 'newsletter_item',
    'slideshare' => '',
    'view_mode_slideshare' => 'newsletter_item',
    'spotlight' => 'd376d4c6-e759-4f19-b6b1-17f867092220',
    'view_mode_spotlight' => 'highlights_item',
    'tk_section' => '',
    'view_mode_tk_section' => 'newsletter_item',
    'tk_article' => '',
    'view_mode_tk_article' => 'newsletter_item',
    'tk_example' => '',
    'view_mode_tk_example' => 'newsletter_item',
    'tk_tool' => '',
    'view_mode_tk_tool' => 'newsletter_item',
    'tk_topic' => '',
    'view_mode_tk_topic' => 'newsletter_item',
    'topic_related' => '',
    'view_mode_topic_related' => 'newsletter_item',
    'twitter_tweet_feed' => 'a6a6367d-5b41-441e-9006-492e818020c2',
    'view_mode_twitter_tweet_feed' => 'newsletter_item',
    'twitter_user_profile' => '',
    'view_mode_twitter_user_profile' => 'newsletter_item',
    'webform' => '',
    'view_mode_webform' => 'newsletter_item',
    'youtube' => '734723f4-916a-40f3-be74-cf39f6f6a356',
    'view_mode_youtube' => 'highlights_item',
  );
  $export['osha_newsletter_term_ct_map'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_details_link_label';
  $strongarm->value = 'Privacy policy';
  $export['subscribe_block_details_link_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_details_link_url';
  $strongarm->value = 'https://osha.europa.eu/en/oshmail-newsletter/privacy-statement-oshmail';
  $export['subscribe_block_details_link_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_intro_text';
  $strongarm->value = 'Once a month, OSHmail keeps you updated on occupational safety and health in general.';
  $export['subscribe_block_intro_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_intro_text_second_line_end';
  $strongarm->value = '';
  $export['subscribe_block_intro_text_second_line_end'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_intro_text_second_line_start';
  $strongarm->value = '';
  $export['subscribe_block_intro_text_second_line_start'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_newsletter_page_url';
  $strongarm->value = '';
  $export['subscribe_block_newsletter_page_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_subscribers_no';
  $strongarm->value = '';
  $export['subscribe_block_subscribers_no'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_extra_block_details_link_label';
  $strongarm->value = 'Privacy policy';
  $export['subscribe_extra_block_details_link_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_extra_block_details_link_url';
  $strongarm->value = 'node/1015';
  $export['subscribe_extra_block_details_link_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_extra_block_intro_text';
  $strongarm->value = 'To get the latest news from the Healthy Workplaces Campaign 2020–22 direct to your inbox, sign up for our bimonthly newsletter. We’ll cover all the big events and key issues to keep you up to date.';
  $export['subscribe_extra_block_intro_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_spotlight';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_spotlight'] = $strongarm;

  return $export;
}

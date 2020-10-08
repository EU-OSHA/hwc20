<?php
/**
 * @file
 * hwc_priority_areas.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_priority_areas_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_pa_highlights';
  $strongarm->value = '0';
  $export['comment_anonymous_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_priority_area';
  $strongarm->value = '0';
  $export['comment_anonymous_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_pa_highlights';
  $strongarm->value = 1;
  $export['comment_default_mode_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_priority_area';
  $strongarm->value = 1;
  $export['comment_default_mode_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_pa_highlights';
  $strongarm->value = '50';
  $export['comment_default_per_page_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_priority_area';
  $strongarm->value = '50';
  $export['comment_default_per_page_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_pa_highlights';
  $strongarm->value = 1;
  $export['comment_form_location_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_priority_area';
  $strongarm->value = 1;
  $export['comment_form_location_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_pa_highlights';
  $strongarm->value = '1';
  $export['comment_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_pa_highlights';
  $strongarm->value = '1';
  $export['comment_preview_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_priority_area';
  $strongarm->value = '1';
  $export['comment_preview_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_priority_area';
  $strongarm->value = '1';
  $export['comment_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_pa_highlights';
  $strongarm->value = 1;
  $export['comment_subject_field_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_priority_area';
  $strongarm->value = 1;
  $export['comment_subject_field_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__pa_highlights';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'title_body' => array(
        'custom_settings' => TRUE,
      ),
      'body' => array(
        'custom_settings' => TRUE,
      ),
      'priority_areas' => array(
        'custom_settings' => TRUE,
      ),
      'hwc_teaser' => array(
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
      'pub_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'osha_resources' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
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
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '4',
        ),
        'path' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
        'workbench_access' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '7',
        ),
        'language' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'share_widget' => array(
          'priority_areas' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'bottom_share_widget' => array(
          'priority_areas' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__priority_area';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'title_body' => array(
        'custom_settings' => TRUE,
      ),
      'body' => array(
        'custom_settings' => TRUE,
      ),
      'priority_areas' => array(
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
      'pub_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'osha_resources' => array(
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
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'hwc_teaser' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '12',
        ),
        'path' => array(
          'weight' => '11',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
        'xmlsitemap' => array(
          'weight' => '9',
        ),
        'language' => array(
          'weight' => '8',
        ),
        'workbench_access' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'share_widget' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'bottom_share_widget' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_pa_highlights';
  $strongarm->value = '4';
  $export['language_content_type_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_priority_area';
  $strongarm->value = '4';
  $export['language_content_type_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_pa_highlights';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_priority_area';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_pa_highlights';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_priority_area';
  $strongarm->value = 'main-menu:32374';
  $export['menu_parent_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_pa_highlights';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_priority_area';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_pa_highlights';
  $strongarm->value = '0';
  $export['node_preview_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_priority_area';
  $strongarm->value = '1';
  $export['node_preview_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_pa_highlights';
  $strongarm->value = 0;
  $export['node_submitted_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_priority_area';
  $strongarm->value = 0;
  $export['node_submitted_priority_area'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_pa_highlights';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_pa_highlights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_priority_area';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_priority_area'] = $strongarm;

  return $export;
}

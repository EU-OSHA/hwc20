<?php
/**
 * @file
 * hwc_practical_tool.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_practical_tool_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_practical_tool';
  $strongarm->value = '0';
  $export['comment_anonymous_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_practical_tool';
  $strongarm->value = 1;
  $export['comment_default_mode_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_practical_tool';
  $strongarm->value = '50';
  $export['comment_default_per_page_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_practical_tool';
  $strongarm->value = 1;
  $export['comment_form_location_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_practical_tool';
  $strongarm->value = '1';
  $export['comment_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_practical_tool';
  $strongarm->value = '1';
  $export['comment_preview_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_practical_tool';
  $strongarm->value = 1;
  $export['comment_subject_field_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_practical_tool';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__practical_tool_types';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 0,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_taxonomy_term__practical_tool_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__segment';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 0,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_taxonomy_term__segment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'exclude_node_title_content_type_modes_practical_tool';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'diff_standard' => 0,
    'title_body' => 0,
    'body' => 0,
    'priority_areas' => 0,
    'hwc_teaser' => 0,
    'osha_slideshow' => 0,
    'highlights_item' => 0,
    'newsletter_item' => 0,
    'highlights_item_alternative' => 0,
    'pub_teaser' => 0,
    'osha_resources' => 0,
    'print' => 0,
    'token' => 0,
    'revision' => 0,
    'nodeform' => 0,
  );
  $export['exclude_node_title_content_type_modes_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'exclude_node_title_content_type_value_practical_tool';
  $strongarm->value = 'all';
  $export['exclude_node_title_content_type_value_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__practical_tool';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'osha_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'highlights_item' => array(
        'custom_settings' => TRUE,
      ),
      'newsletter_item' => array(
        'custom_settings' => TRUE,
      ),
      'pub_teaser' => array(
        'custom_settings' => FALSE,
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
      'title_body' => array(
        'custom_settings' => FALSE,
      ),
      'body' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'priority_areas' => array(
        'custom_settings' => TRUE,
      ),
      'highlights_item_alternative' => array(
        'custom_settings' => TRUE,
      ),
      'hwc_teaser' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '50',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '47',
        ),
        'redirect' => array(
          'weight' => '49',
        ),
        'workbench_access' => array(
          'weight' => '46',
        ),
        'language' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '48',
        ),
      ),
      'display' => array(
        'share_widget' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'bottom_share_widget' => array(
          'default' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_audio_visual_url';
  $strongarm->value = '/export/audio_visual';
  $export['hwc_migration_audio_visual_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_dangerous_substances_url';
  $strongarm->value = '';
  $export['hwc_migration_dangerous_substances_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_events_url';
  $strongarm->value = '/export/event/list';
  $export['hwc_migration_events_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_gallery_url';
  $strongarm->value = '/export/gallery';
  $export['hwc_migration_gallery_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_highlights_add_res_url';
  $strongarm->value = '/export/list-additional-resources/campaign_2020-2022c';
  $export['hwc_migration_highlights_add_res_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_highlights_url';
  $strongarm->value = '/export/highlight/list/campaign_2020-2022';
  $export['hwc_migration_highlights_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_infographics_url';
  $strongarm->value = '/export/list/infographic/campaign_2020-2022';
  $export['hwc_migration_infographics_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_news_add_res_url';
  $strongarm->value = '/export/list-additional-resources/campaign_2020-2022d';
  $export['hwc_migration_news_add_res_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_news_url';
  $strongarm->value = '/export/news/list';
  $export['hwc_migration_news_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_notes_to_editor_url';
  $strongarm->value = '/export/notetoeditor';
  $export['hwc_migration_notes_to_editor_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_practical_tool_url';
  $strongarm->value = '/export/msd';
  $export['hwc_migration_practical_tool_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_press_contacts_url';
  $strongarm->value = '/export/presscontact';
  $export['hwc_migration_press_contacts_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_press_releases_add_res_url';
  $strongarm->value = '/export/list-additional-resources/campaign_2020-2022a';
  $export['hwc_migration_press_releases_add_res_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_press_releases_url';
  $strongarm->value = '/export/list/press_release/campaign_2020-2022';
  $export['hwc_migration_press_releases_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_publications_add_res_url';
  $strongarm->value = '/export/list-additional-resources/campaign_2020-2022b';
  $export['hwc_migration_publications_add_res_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_publications_url';
  $strongarm->value = '/export/list/publication_hwc20/campaign_2020-2022?2';
  $export['hwc_migration_publications_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_root_url';
  $strongarm->value = 'https://osha.europa.eu';
  $export['hwc_migration_root_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_activity_url';
  $strongarm->value = '/export/taxonomy/activity';
  $export['hwc_migration_tax_activity_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_biological_hazard_url';
  $strongarm->value = '/export/taxonomy/biological_hazard';
  $export['hwc_migration_tax_biological_hazard_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_country_status_url';
  $strongarm->value = '/export/taxonomy/country_status';
  $export['hwc_migration_tax_country_status_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_country_url';
  $strongarm->value = '/export/taxonomy/country';
  $export['hwc_migration_tax_country_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_evaluation_url';
  $strongarm->value = '/export/taxonomy/evaluation';
  $export['hwc_migration_tax_evaluation_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_exposure_route_url';
  $strongarm->value = '/export/taxonomy/exposure_route';
  $export['hwc_migration_tax_exposure_route_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_fop_link_sections_url';
  $strongarm->value = '/export/taxonomy/fop_link_sections';
  $export['hwc_migration_tax_fop_link_sections_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_hazards_url';
  $strongarm->value = '/export/taxonomy/hazards';
  $export['hwc_migration_tax_hazards_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_hazard_health_effects_url';
  $strongarm->value = '/export/taxonomy/hazard_health_effects';
  $export['hwc_migration_tax_hazard_health_effects_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_hazard_physical_state_url';
  $strongarm->value = '/export/taxonomy/hazard_physical_state';
  $export['hwc_migration_tax_hazard_physical_state_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_hazmap_categories_url';
  $strongarm->value = '/export/taxonomy/hazmap_categories';
  $export['hwc_migration_tax_hazmap_categories_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_health_effects_url';
  $strongarm->value = '/export/taxonomy/health_effects';
  $export['hwc_migration_tax_health_effects_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_material_objective_url';
  $strongarm->value = '/export/taxonomy/material_objective';
  $export['hwc_migration_tax_material_objective_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_material_purpose_url';
  $strongarm->value = '/export/taxonomy/material_purpose';
  $export['hwc_migration_tax_material_purpose_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_msd_glossary_url';
  $strongarm->value = '/export/taxonomy/msds_glossary';
  $export['hwc_migration_tax_msd_glossary_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_msd_priority_area_url';
  $strongarm->value = '/export/taxonomy/msd_priority_area';
  $export['hwc_migration_tax_msd_priority_area_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_msd_url';
  $strongarm->value = '/export/msd';
  $export['hwc_migration_tax_msd_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_nace_codes_url';
  $strongarm->value = '/export/taxonomy/nace_codes';
  $export['hwc_migration_tax_nace_codes_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_newsletter_sections_url';
  $strongarm->value = '/export/taxonomy/newsletter_sections';
  $export['hwc_migration_tax_newsletter_sections_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_prevention_measures_msd_url';
  $strongarm->value = '/export/taxonomy/prevention_measures_msd';
  $export['hwc_migration_tax_prevention_measures_msd_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_prevention_measures_url';
  $strongarm->value = '/export/taxonomy/prevention_measures_msd';
  $export['hwc_migration_tax_prevention_measures_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_priority_area_url';
  $strongarm->value = '/export/taxonomy/priority_area';
  $export['hwc_migration_tax_priority_area_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_provider_type_url';
  $strongarm->value = '/export/taxonomy/provider_type';
  $export['hwc_migration_tax_provider_type_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_publication_types_url';
  $strongarm->value = '/export/taxonomy/publication_types';
  $export['hwc_migration_tax_publication_types_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_purpose_of_material_url';
  $strongarm->value = '/export/taxonomy/purpose_of_material';
  $export['hwc_migration_tax_purpose_of_material_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_resource_type_url';
  $strongarm->value = '/export/taxonomy/resource_type';
  $export['hwc_migration_tax_resource_type_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_segment_url';
  $strongarm->value = '/export/taxonomy/relevant_for';
  $export['hwc_migration_tax_segment_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_tags_url';
  $strongarm->value = '/export/taxonomy/tags';
  $export['hwc_migration_tax_tags_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_target_audience_url';
  $strongarm->value = '/export/taxonomy/target_audience';
  $export['hwc_migration_tax_target_audience_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_target_group_url';
  $strongarm->value = '/export/taxonomy/target_group';
  $export['hwc_migration_tax_target_group_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_thesaurus_url';
  $strongarm->value = '/export/taxonomy/thesaurus';
  $export['hwc_migration_tax_thesaurus_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_worker_groups_covered_url';
  $strongarm->value = '/export/taxonomy/worker_groups_covered';
  $export['hwc_migration_tax_worker_groups_covered_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_worker_groups_url';
  $strongarm->value = '/export/taxonomy/worker_groups';
  $export['hwc_migration_tax_worker_groups_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_practical_tool';
  $strongarm->value = '4';
  $export['language_content_type_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_practical_tool';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_practical_tool';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_practical_tool';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_practical_tool';
  $strongarm->value = '1';
  $export['node_preview_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_practical_tool';
  $strongarm->value = 0;
  $export['node_submitted_practical_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_practical_tool_pattern';
  $strongarm->value = 'tools-and-publications/practical-tools/[node:title]';
  $export['pathauto_node_practical_tool_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_practical_tool';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_practical_tool'] = $strongarm;

  return $export;
}

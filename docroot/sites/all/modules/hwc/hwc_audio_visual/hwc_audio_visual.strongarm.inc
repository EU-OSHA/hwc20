<?php
/**
 * @file
 * hwc_audio_visual.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_audio_visual_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chosen_minimum_multiple';
  $strongarm->value = '20';
  $export['chosen_minimum_multiple'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'chosen_minimum_single';
  $strongarm->value = '20';
  $export['chosen_minimum_single'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_audio_visual';
  $strongarm->value = '-1';
  $export['comment_anonymous_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_audio_visual';
  $strongarm->value = '1';
  $export['comment_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_audio_visual';
  $strongarm->value = 0;
  $export['comment_default_mode_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_audio_visual';
  $strongarm->value = '50';
  $export['comment_default_per_page_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_audio_visual';
  $strongarm->value = 0;
  $export['comment_form_location_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_audio_visual';
  $strongarm->value = '0';
  $export['comment_preview_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_audio_visual';
  $strongarm->value = 0;
  $export['comment_subject_field_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__audio_visual';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
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
      'osha_resources' => array(
        'custom_settings' => TRUE,
      ),
      'osha_wiki' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'osha_search_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '2',
        ),
        'workbench_access' => array(
          'weight' => '0',
        ),
        'xmlsitemap' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_audio_visual_url';
  $strongarm->value = '/export/audio_visual';
  $export['hwc_migration_audio_visual_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_gallery_url';
  $strongarm->value = '/export/gallery';
  $export['hwc_migration_gallery_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_biological_hazard_url';
  $strongarm->value = '/export/taxonomy/biological_hazard';
  $export['hwc_migration_tax_biological_hazard_url'] = $strongarm;

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
  $strongarm->name = 'hwc_migration_tax_nace_codes_url';
  $strongarm->value = '/export/taxonomy/nace_codes';
  $export['hwc_migration_tax_nace_codes_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_prevention_measures_url';
  $strongarm->value = '/export/taxonomy/prevention_measures';
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
  $strongarm->name = 'hwc_migration_tax_target_group_url';
  $strongarm->value = '/export/taxonomy/target_group';
  $export['hwc_migration_tax_target_group_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_migration_tax_worker_groups_url';
  $strongarm->value = '/export/taxonomy/worker_groups';
  $export['hwc_migration_tax_worker_groups_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_audio_visual';
  $strongarm->value = '0';
  $export['language_content_type_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_audio_visual';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_audio_visual';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_audio_visual';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_audio_visual';
  $strongarm->value = '1';
  $export['node_preview_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_audio_visual';
  $strongarm->value = 0;
  $export['node_submitted_audio_visual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_audio_visual';
  $strongarm->value = 0;
  $export['workbench_access_node_type_audio_visual'] = $strongarm;

  return $export;
}

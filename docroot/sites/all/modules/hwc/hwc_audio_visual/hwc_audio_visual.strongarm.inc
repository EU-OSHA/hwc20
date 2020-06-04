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
  $strongarm->value = 1;
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

  return $export;
}

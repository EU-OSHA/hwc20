<?php
/**
 * @file
 * campaign_materials.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function campaign_materials_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_campaign_material_type'.
  $field_bases['field_campaign_material_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_campaign_material_type',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'campaign_material_types',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}

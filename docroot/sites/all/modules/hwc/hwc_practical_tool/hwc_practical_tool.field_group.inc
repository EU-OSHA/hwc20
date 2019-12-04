<?php
/**
 * @file
 * hwc_practical_tool.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hwc_practical_tool_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|practical_tool|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'practical_tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Detailed Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_priority_area',
      1 => 'field_hazard_health_other',
      2 => 'field_material_purpose_other',
      3 => 'field_prevention_measures_other',
      4 => 'field_publication_year',
      5 => 'field_sector_industry_covered',
      6 => 'field_target_group_other',
      7 => 'field_worker_groups_other',
      8 => 'field_hazards',
      9 => 'field_hazards_other',
      10 => 'field_health_effects',
      11 => 'field_msd_priority_area',
      12 => 'field_msd_resource_type',
      13 => 'field_msd_resource_type_other',
      14 => 'field_prevention_measures',
      15 => 'field_purpose_of_the_material',
      16 => 'field_target_audience',
      17 => 'field_worker_groups_covered',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Detailed Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_details|node|practical_tool|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detailed Information');

  return $field_groups;
}

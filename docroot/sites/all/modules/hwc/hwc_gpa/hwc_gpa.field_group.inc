<?php
/**
 * @file
 * hwc_gpa.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hwc_gpa_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_faq|node|gpa|default';
  $field_group->group_name = 'group_faq';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gpa';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'faq',
    'weight' => '18',
    'children' => array(
      0 => 'field_faq',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-faq field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_faq|node|gpa|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participate|node|gpa|default';
  $field_group->group_name = 'group_participate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gpa';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'How to participate	',
    'weight' => '5',
    'children' => array(
      0 => 'field_gpa_links',
      1 => 'field_participate_date',
      2 => 'field_participate_description',
      3 => 'field_participate_upcoming_descr',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-participate field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_participate|node|gpa|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participate|node|gpa|form';
  $field_group->group_name = 'group_participate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gpa';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'How to participate',
    'weight' => '5',
    'children' => array(
      0 => 'field_gpa_links',
      1 => 'field_participate_date',
      2 => 'field_participate_description',
      3 => 'field_participate_upcoming_descr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'How to participate',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-participate field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_participate|node|gpa|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('How to participate');
  t('How to participate	');
  t('faq');

  return $field_groups;
}

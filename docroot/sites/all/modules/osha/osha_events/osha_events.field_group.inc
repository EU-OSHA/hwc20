<?php
/**
 * @file
 * osha_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function osha_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|events|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '45',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_contact|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_description|node|events|default';
  $field_group->group_name = 'group_events_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '34',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => '',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_events_description|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_event_details|node|events|default';
  $field_group->group_name = 'group_events_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event details',
    'weight' => '33',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => '',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_events_event_details|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_links|node|events|default';
  $field_group->group_name = 'group_events_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '35',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-events-links field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_events_links|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_events_related_documents|node|events|default';
  $field_group->group_name = 'group_events_related_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related documents',
    'weight' => '31',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related documents',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-events-related-documents field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_events_related_documents|node|events|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notification_management|node|events|form';
  $field_group->group_name = 'group_notification_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Management',
    'weight' => '36',
    'children' => array(
      0 => 'field_approved_subject',
      1 => 'field_rejection_subject',
      2 => 'field_approved_body',
      3 => 'field_rejection_body',
      4 => 'field_supervisor_subject',
      5 => 'field_supervisor_body',
      6 => 'field_reviewer_subject',
      7 => 'field_reviewer_body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-notification-management field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_notification_management|node|events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notification_management|node|news|form';
  $field_group->group_name = 'group_notification_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Management',
    'weight' => '18',
    'children' => array(
      0 => 'field_approved_body',
      1 => 'field_approved_subject',
      2 => 'field_rejection_subject',
      3 => 'field_rejection_body',
      4 => 'field_supervisor_subject',
      5 => 'field_supervisor_body',
      6 => 'field_reviewer_subject',
      7 => 'field_reviewer_body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-notification-management field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_notification_management|node|news|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Description');
  t('Event details');
  t('Links');
  t('Notification Management');
  t('Related documents');

  return $field_groups;
}

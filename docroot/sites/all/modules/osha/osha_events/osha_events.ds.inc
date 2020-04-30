<?php
/**
 * @file
 * osha_events.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function osha_events_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|events|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'events';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'back_to_list' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'event_country_flag' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'event_location' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|events|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function osha_events_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'back_to_list';
  $ds_field->label = 'back to list';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'events|*
news|*
flickr_gallery|*
press_release|*';
  $ds_field->properties = array();
  $export['back_to_list'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_country_flag';
  $ds_field->label = 'event_country_flag';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'events|*';
  $ds_field->properties = array();
  $export['event_country_flag'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_location';
  $ds_field->label = 'event_location';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'events|*';
  $ds_field->properties = array();
  $export['event_location'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function osha_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|events|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'events';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'hwc_2col_stacked_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'back_to_list',
      ),
      'right' => array(
        1 => 'share_widget',
      ),
      'center' => array(
        2 => 'title_field',
      ),
      'left2' => array(
        3 => 'body',
        4 => 'field_speaker',
        5 => 'field_organizer',
        6 => 'field_gallery',
        7 => 'field_schedule',
      ),
      'right2' => array(
        8 => 'event_country_flag',
        9 => 'field_start_date',
        10 => 'event_location',
        11 => 'bottom_share_widget',
      ),
      'footer' => array(
        12 => 'field_contact_name',
        13 => 'field_contact_phone',
        14 => 'field_contact_email',
        15 => 'field_website_of_event',
        16 => 'field_related_documents',
      ),
    ),
    'fields' => array(
      'back_to_list' => 'left',
      'share_widget' => 'right',
      'title_field' => 'center',
      'body' => 'left2',
      'field_speaker' => 'left2',
      'field_organizer' => 'left2',
      'field_gallery' => 'left2',
      'field_schedule' => 'left2',
      'event_country_flag' => 'right2',
      'field_start_date' => 'right2',
      'event_location' => 'right2',
      'bottom_share_widget' => 'right2',
      'field_contact_name' => 'footer',
      'field_contact_phone' => 'footer',
      'field_contact_email' => 'footer',
      'field_website_of_event' => 'footer',
      'field_related_documents' => 'footer',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'center' => 'div',
      'left2' => 'div',
      'right2' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|events|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|events|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'events';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'hwc_2col_stacked_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title_field',
        1 => 'field_organizer',
        2 => 'field_start_date',
        3 => 'field_type_event',
      ),
      'right' => array(
        4 => 'field_location',
        5 => 'field_city',
        6 => 'field_country_code',
      ),
      'center' => array(
        7 => 'body',
        8 => 'field_related_documents',
        9 => 'field_schedule',
        10 => 'field_speaker',
        11 => 'field_partner_id',
        12 => 'field_activity',
        13 => 'metatags',
        14 => 'path',
        15 => 'redirect',
        16 => 'workbench_access',
      ),
      'left2' => array(
        17 => 'field_contact_name',
        18 => 'field_contact_phone',
      ),
      'right2' => array(
        19 => 'field_contact_email',
      ),
      'footer' => array(
        20 => 'field_website_of_event',
        21 => 'field_gallery',
        22 => 'field_tags',
        23 => 'field_for_the_web',
        24 => 'field_key_performance',
        25 => 'field_adonis',
        26 => 'field_unit_ref',
        27 => 'field_agency_role',
        28 => 'field_agenda',
        29 => 'field_agency_rep_confirmed',
        30 => 'field_publications_exhibition_su',
        31 => 'field_media_promotion',
        32 => 'field_agency_contact_reply',
        33 => 'field_color',
        34 => 'field_modified_on',
        35 => 'field_notification_comment',
        36 => 'field_show_in_ncw',
        37 => 'field_show_eu_flag',
      ),
      'hidden' => array(
        38 => 'field_agency_initial_contact',
        39 => 'field_satisfaction_rate',
        40 => 'field_event_in_amp',
        41 => 'field_number_of_attendees',
        42 => 'field_modified_by',
        43 => 'field_wf_notification',
        44 => 'group_contact',
        45 => 'field_migration_source',
        46 => 'xmlsitemap',
        47 => 'field_first_publication_date',
        48 => 'field_migration_path_alias',
        49 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title_field' => 'left',
      'field_organizer' => 'left',
      'field_start_date' => 'left',
      'field_type_event' => 'left',
      'field_location' => 'right',
      'field_city' => 'right',
      'field_country_code' => 'right',
      'body' => 'center',
      'field_related_documents' => 'center',
      'field_schedule' => 'center',
      'field_speaker' => 'center',
      'field_partner_id' => 'center',
      'field_activity' => 'center',
      'metatags' => 'center',
      'path' => 'center',
      'redirect' => 'center',
      'workbench_access' => 'center',
      'field_contact_name' => 'left2',
      'field_contact_phone' => 'left2',
      'field_contact_email' => 'right2',
      'field_website_of_event' => 'footer',
      'field_gallery' => 'footer',
      'field_tags' => 'footer',
      'field_for_the_web' => 'footer',
      'field_key_performance' => 'footer',
      'field_adonis' => 'footer',
      'field_unit_ref' => 'footer',
      'field_agency_role' => 'footer',
      'field_agenda' => 'footer',
      'field_agency_rep_confirmed' => 'footer',
      'field_publications_exhibition_su' => 'footer',
      'field_media_promotion' => 'footer',
      'field_agency_contact_reply' => 'footer',
      'field_color' => 'footer',
      'field_modified_on' => 'footer',
      'field_notification_comment' => 'footer',
      'field_show_in_ncw' => 'footer',
      'field_show_eu_flag' => 'footer',
      'field_agency_initial_contact' => 'hidden',
      'field_satisfaction_rate' => 'hidden',
      'field_event_in_amp' => 'hidden',
      'field_number_of_attendees' => 'hidden',
      'field_modified_by' => 'hidden',
      'field_wf_notification' => 'hidden',
      'group_contact' => 'hidden',
      'field_migration_source' => 'hidden',
      'xmlsitemap' => 'hidden',
      'field_first_publication_date' => 'hidden',
      'field_migration_path_alias' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        'container' => 'container',
      ),
      'left' => array(
        'col-sm-6' => 'col-sm-6',
      ),
      'right' => array(
        'col-sm-6' => 'col-sm-6',
      ),
      'center' => array(
        'col-md-12' => 'col-md-12',
      ),
      'left2' => array(
        'col-sm-6' => 'col-sm-6',
      ),
      'right2' => array(
        'col-sm-6' => 'col-sm-6',
      ),
      'footer' => array(
        'col-md-12' => 'col-md-12',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'center' => 'div',
      'left2' => 'div',
      'right2' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|events|form'] = $ds_layout;

  return $export;
}

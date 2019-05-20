<?php
/**
 * @file
 * osha_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    10 => '10',
    7 => '7',
    9 => '9',
    8 => '8',
    14 => '14',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: For the web / Public */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'Country code';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  /* Field: Content: Ares/Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['element_label_colon'] = FALSE;
  /* Field: Content: Unit Ref */
  $handler->display->display_options['fields']['field_unit_ref']['id'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['table'] = 'field_data_field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['field'] = 'field_unit_ref';
  $handler->display->display_options['fields']['field_unit_ref']['element_label_colon'] = FALSE;
  /* Field: Content: Agency Role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Content: Agency Initial Contact */
  $handler->display->display_options['fields']['field_agency_initial_contact']['id'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['table'] = 'field_data_field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['field'] = 'field_agency_initial_contact';
  $handler->display->display_options['fields']['field_agency_initial_contact']['element_label_colon'] = FALSE;
  /* Field: Content: Agency Rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['element_label_colon'] = FALSE;
  /* Field: Content: Event in AMP */
  $handler->display->display_options['fields']['field_event_in_amp']['id'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['table'] = 'field_data_field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['field'] = 'field_event_in_amp';
  $handler->display->display_options['fields']['field_event_in_amp']['element_label_colon'] = FALSE;
  /* Field: Content: Comments */
  $handler->display->display_options['fields']['field_agency_contact_reply']['id'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['table'] = 'field_data_field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['field'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['element_label_colon'] = FALSE;
  /* Field: Content: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Satisfaction rate */
  $handler->display->display_options['fields']['field_satisfaction_rate']['id'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['table'] = 'field_data_field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['field'] = 'field_satisfaction_rate';
  $handler->display->display_options['fields']['field_satisfaction_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_satisfaction_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );

  /* Display: Events */
  $handler = $view->new_display('page', 'Events', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_color' => 'field_color',
    'title_field' => 'title_field',
    'field_organizer' => 'field_organizer',
    'field_for_the_web' => 'field_for_the_web',
    'field_country_code' => 'field_country_code',
    'field_city' => 'field_city',
    'field_start_date' => 'field_start_date',
    'field_start_date_1' => 'field_start_date_1',
    'field_website_of_event' => 'field_website_of_event',
    'field_adonis' => 'field_adonis',
    'field_unit_ref' => 'field_unit_ref',
    'field_activity' => 'field_activity',
    'field_tags' => 'field_tags',
    'field_agency_role' => 'field_agency_role',
    'field_agency_initial_contact' => 'field_agency_initial_contact',
    'field_agency_rep_confirmed' => 'field_agency_rep_confirmed',
    'field_event_in_amp' => 'field_event_in_amp',
    'field_agency_contact_reply' => 'field_agency_contact_reply',
    'field_number_of_attendees' => 'field_number_of_attendees',
    'field_satisfaction_rate' => 'field_satisfaction_rate',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
    'name' => 'name',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_color' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organizer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_for_the_web' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_start_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_start_date_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website_of_event' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_adonis' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_unit_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_role' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_initial_contact' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_rep_confirmed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_in_amp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_contact_reply' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_number_of_attendees' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_satisfaction_rate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>
<a href="/en/node/add/events">Add event</a>
</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total: @total';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'Colours';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<div class="colours">
<div class="red"></div><p">TBD - TBC<p>
<div class="black"></div><p>Confirmed<p>
<div class="grey"></div><p>Only web or not attendance<p>
</div>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<span class="result_summary">Displaying @start - @end of @total</span>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Color */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_color']['alter']['text'] = '[field_color]';
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  /* Field: Content: For the web / Public */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['element_label_colon'] = FALSE;
  /* Field: Content: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['element_label_colon'] = FALSE;
  /* Field: Content: Type of event */
  $handler->display->display_options['fields']['field_type_event']['id'] = 'field_type_event';
  $handler->display->display_options['fields']['field_type_event']['table'] = 'field_data_field_type_event';
  $handler->display->display_options['fields']['field_type_event']['field'] = 'field_type_event';
  $handler->display->display_options['fields']['field_type_event']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Organisation */
  $handler->display->display_options['fields']['field_organizer']['id'] = 'field_organizer';
  $handler->display->display_options['fields']['field_organizer']['table'] = 'field_data_field_organizer';
  $handler->display->display_options['fields']['field_organizer']['field'] = 'field_organizer';
  $handler->display->display_options['fields']['field_organizer']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country_code']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = 'Start date';
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
    'field_formatter_class' => '',
  );
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'End date';
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  /* Field: Content: Agenda */
  $handler->display->display_options['fields']['field_agenda']['id'] = 'field_agenda';
  $handler->display->display_options['fields']['field_agenda']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['fields']['field_agenda']['field'] = 'field_agenda';
  $handler->display->display_options['fields']['field_agenda']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Agency Role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['label'] = 'Agency role';
  $handler->display->display_options['fields']['field_agency_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_role']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Content: Agency Rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['label'] = 'Agency rep confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Publications/exhibition support */
  $handler->display->display_options['fields']['field_publications_exhibition_su']['id'] = 'field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['field'] = 'field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Media/promotion */
  $handler->display->display_options['fields']['field_media_promotion']['id'] = 'field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['field'] = 'field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Comments */
  $handler->display->display_options['fields']['field_agency_contact_reply']['id'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['table'] = 'field_data_field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['field'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Key Performance Indicator */
  $handler->display->display_options['fields']['field_key_performance']['id'] = 'field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['field'] = 'field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Ares/Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['element_label_colon'] = FALSE;
  /* Field: Content: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['label'] = 'Number of participants';
  $handler->display->display_options['fields']['field_number_of_attendees']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="links inline">
<li>[edit_node]</li>
<li>[delete_node]</li>
</ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Color (field_color) */
  $handler->display->display_options['filters']['field_color_value']['id'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['table'] = 'field_data_field_color';
  $handler->display->display_options['filters']['field_color_value']['field'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['group'] = 1;
  $handler->display->display_options['filters']['field_color_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_color_value']['expose']['operator_id'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['label'] = 'Color';
  $handler->display->display_options['filters']['field_color_value']['expose']['operator'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['identifier'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Organisation (field_organizer) */
  $handler->display->display_options['filters']['field_organizer_value']['id'] = 'field_organizer_value';
  $handler->display->display_options['filters']['field_organizer_value']['table'] = 'field_data_field_organizer';
  $handler->display->display_options['filters']['field_organizer_value']['field'] = 'field_organizer_value';
  $handler->display->display_options['filters']['field_organizer_value']['group'] = 1;
  $handler->display->display_options['filters']['field_organizer_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organizer_value']['expose']['operator_id'] = 'field_organizer_value_op';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['operator'] = 'field_organizer_value_op';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['identifier'] = 'field_organizer_value';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  /* Filter criterion: Content: Country (field_country_code) */
  $handler->display->display_options['filters']['field_country_code_value']['id'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['filters']['field_country_code_value']['field'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['group'] = 1;
  $handler->display->display_options['filters']['field_country_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator_id'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['identifier'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: City (field_city) */
  $handler->display->display_options['filters']['field_city_value']['id'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['table'] = 'field_data_field_city';
  $handler->display->display_options['filters']['field_city_value']['field'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_city_value']['expose']['operator_id'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_city_value']['expose']['operator'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['identifier'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Starting date - end date (field_start_date:value2) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator_id'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['identifier'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value2']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Ares/Adonis (field_adonis) */
  $handler->display->display_options['filters']['field_adonis_value']['id'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['filters']['field_adonis_value']['field'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_adonis_value']['group'] = 1;
  $handler->display->display_options['filters']['field_adonis_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator_id'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['label'] = 'Ares/Adonis';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['identifier'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Activity (field_activity) */
  $handler->display->display_options['filters']['field_activity_tid']['id'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['table'] = 'field_data_field_activity';
  $handler->display->display_options['filters']['field_activity_tid']['field'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_tid']['expose']['operator_id'] = 'field_activity_tid_op';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['label'] = 'Activity';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['operator'] = 'field_activity_tid_op';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['identifier'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
  $handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Agency Role (field_agency_role) */
  $handler->display->display_options['filters']['field_agency_role_value']['id'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['filters']['field_agency_role_value']['field'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_role_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator_id'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['label'] = 'Agency role';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['identifier'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Agenda (field_agenda) */
  $handler->display->display_options['filters']['field_agenda_value']['id'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['filters']['field_agenda_value']['field'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agenda_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator_id'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['label'] = 'Agenda';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['identifier'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Publications/exhibition support (field_publications_exhibition_su) */
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['id'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['field'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator_id'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['label'] = 'Publications/exhibition support';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['identifier'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Media/promotion (field_media_promotion) */
  $handler->display->display_options['filters']['field_media_promotion_value']['id'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['field'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['group'] = 1;
  $handler->display->display_options['filters']['field_media_promotion_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator_id'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['label'] = 'Media/promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['identifier'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Key Performance Indicator (field_key_performance) */
  $handler->display->display_options['filters']['field_key_performance_value']['id'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['filters']['field_key_performance_value']['field'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['group'] = 1;
  $handler->display->display_options['filters']['field_key_performance_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator_id'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['label'] = 'Key Performance Indicator';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['identifier'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Agency Rep confirmed (field_agency_rep_confirmed) */
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['id'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['field'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator_id'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['label'] = 'Agency rep confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['identifier'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Type of event (field_type_event) */
  $handler->display->display_options['filters']['field_type_event_value']['id'] = 'field_type_event_value';
  $handler->display->display_options['filters']['field_type_event_value']['table'] = 'field_data_field_type_event';
  $handler->display->display_options['filters']['field_type_event_value']['field'] = 'field_type_event_value';
  $handler->display->display_options['filters']['field_type_event_value']['group'] = 1;
  $handler->display->display_options['filters']['field_type_event_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_event_value']['expose']['operator_id'] = 'field_type_event_value_op';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['label'] = 'Type of event';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['operator'] = 'field_type_event_value_op';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['identifier'] = 'field_type_event_value';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Migrate Source (field_migration_source) */
  $handler->display->display_options['filters']['field_migration_source_value']['id'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['table'] = 'field_data_field_migration_source';
  $handler->display->display_options['filters']['field_migration_source_value']['field'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_migration_source_value']['value'] = array(
    'hwc' => 'hwc',
  );
  $handler->display->display_options['filters']['field_migration_source_value']['group'] = 1;
  $handler->display->display_options['filters']['field_migration_source_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator_id'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['label'] = 'Not from';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
  );
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['label'] = 'Source';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'HWC event',
      'operator' => 'or',
      'value' => array(
        'hwc' => 'hwc',
      ),
    ),
    2 => array(
      'title' => 'Corporate Event',
      'operator' => 'empty',
      'value' => array(
        'hwc' => 'hwc',
      ),
    ),
  );
  /* Filter criterion: Content: For the web / Public (field_for_the_web) */
  $handler->display->display_options['filters']['field_for_the_web_value']['id'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['filters']['field_for_the_web_value']['field'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['group'] = 1;
  $handler->display->display_options['filters']['field_for_the_web_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator_id'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['label'] = 'For the web';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['identifier'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
  );
  $handler->display->display_options['filters']['field_for_the_web_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['path'] = 'admin/content/events';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'events.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: For the web */
  $handler->display->display_options['fields']['field_for_the_web']['id'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['field'] = 'field_for_the_web';
  $handler->display->display_options['fields']['field_for_the_web']['ui_name'] = 'For the web';
  $handler->display->display_options['fields']['field_for_the_web']['element_label_colon'] = FALSE;
  /* Field: Activity */
  $handler->display->display_options['fields']['field_activity']['id'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['table'] = 'field_data_field_activity';
  $handler->display->display_options['fields']['field_activity']['field'] = 'field_activity';
  $handler->display->display_options['fields']['field_activity']['ui_name'] = 'Activity';
  $handler->display->display_options['fields']['field_activity']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_activity']['delta_offset'] = '0';
  /* Field: Content: Type of event */
  $handler->display->display_options['fields']['field_type_event']['id'] = 'field_type_event';
  $handler->display->display_options['fields']['field_type_event']['table'] = 'field_data_field_type_event';
  $handler->display->display_options['fields']['field_type_event']['field'] = 'field_type_event';
  $handler->display->display_options['fields']['field_type_event']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Organisation */
  $handler->display->display_options['fields']['field_organizer']['id'] = 'field_organizer';
  $handler->display->display_options['fields']['field_organizer']['table'] = 'field_data_field_organizer';
  $handler->display->display_options['fields']['field_organizer']['field'] = 'field_organizer';
  $handler->display->display_options['fields']['field_organizer']['ui_name'] = 'Organisation';
  $handler->display->display_options['fields']['field_organizer']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['ui_name'] = 'Country';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country_code']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['ui_name'] = 'City';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Event date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['ui_name'] = 'Event date';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'End date';
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
    'field_formatter_class' => '',
  );
  /* Field: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['ui_name'] = 'Website of event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_of_event']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_website_of_event']['delta_offset'] = '0';
  /* Field: Content: Agenda */
  $handler->display->display_options['fields']['field_agenda']['id'] = 'field_agenda';
  $handler->display->display_options['fields']['field_agenda']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['fields']['field_agenda']['field'] = 'field_agenda';
  $handler->display->display_options['fields']['field_agenda']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Agency role */
  $handler->display->display_options['fields']['field_agency_role']['id'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['field'] = 'field_agency_role';
  $handler->display->display_options['fields']['field_agency_role']['ui_name'] = 'Agency role';
  $handler->display->display_options['fields']['field_agency_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_role']['delta_offset'] = '0';
  /* Field: Agency rep confirmed */
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['id'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['field'] = 'field_agency_rep_confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['ui_name'] = 'Agency rep confirmed';
  $handler->display->display_options['fields']['field_agency_rep_confirmed']['element_label_colon'] = FALSE;
  /* Field: Content: Publications/exhibition support */
  $handler->display->display_options['fields']['field_publications_exhibition_su']['id'] = 'field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['field'] = 'field_publications_exhibition_su';
  $handler->display->display_options['fields']['field_publications_exhibition_su']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Media/promotion */
  $handler->display->display_options['fields']['field_media_promotion']['id'] = 'field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['field'] = 'field_media_promotion';
  $handler->display->display_options['fields']['field_media_promotion']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Comments */
  $handler->display->display_options['fields']['field_agency_contact_reply']['id'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['table'] = 'field_data_field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['field'] = 'field_agency_contact_reply';
  $handler->display->display_options['fields']['field_agency_contact_reply']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Key Performance Indicator */
  $handler->display->display_options['fields']['field_key_performance']['id'] = 'field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['field'] = 'field_key_performance';
  $handler->display->display_options['fields']['field_key_performance']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Adonis */
  $handler->display->display_options['fields']['field_adonis']['id'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['fields']['field_adonis']['field'] = 'field_adonis';
  $handler->display->display_options['fields']['field_adonis']['ui_name'] = 'Adonis';
  $handler->display->display_options['fields']['field_adonis']['element_label_colon'] = FALSE;
  /* Field: Number of attendees */
  $handler->display->display_options['fields']['field_number_of_attendees']['id'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['table'] = 'field_data_field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['field'] = 'field_number_of_attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['ui_name'] = 'Number of attendees';
  $handler->display->display_options['fields']['field_number_of_attendees']['label'] = 'Number of participants';
  $handler->display->display_options['fields']['field_number_of_attendees']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_of_attendees']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Username */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['ui_name'] = 'Username';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['ui_name'] = 'Published';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Color (field_color) */
  $handler->display->display_options['filters']['field_color_value']['id'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['table'] = 'field_data_field_color';
  $handler->display->display_options['filters']['field_color_value']['field'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['group'] = 1;
  $handler->display->display_options['filters']['field_color_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_color_value']['expose']['operator_id'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['label'] = 'Color (field_color)';
  $handler->display->display_options['filters']['field_color_value']['expose']['operator'] = 'field_color_value_op';
  $handler->display->display_options['filters']['field_color_value']['expose']['identifier'] = 'field_color_value';
  $handler->display->display_options['filters']['field_color_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Organisation (field_organizer) */
  $handler->display->display_options['filters']['field_organizer_value']['id'] = 'field_organizer_value';
  $handler->display->display_options['filters']['field_organizer_value']['table'] = 'field_data_field_organizer';
  $handler->display->display_options['filters']['field_organizer_value']['field'] = 'field_organizer_value';
  $handler->display->display_options['filters']['field_organizer_value']['group'] = 1;
  $handler->display->display_options['filters']['field_organizer_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organizer_value']['expose']['operator_id'] = 'field_organizer_value_op';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['operator'] = 'field_organizer_value_op';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['identifier'] = 'field_organizer_value';
  $handler->display->display_options['filters']['field_organizer_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  /* Filter criterion: Content: Country (field_country_code) */
  $handler->display->display_options['filters']['field_country_code_value']['id'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['filters']['field_country_code_value']['field'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['group'] = 1;
  $handler->display->display_options['filters']['field_country_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator_id'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['operator'] = 'field_country_code_value_op';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['identifier'] = 'field_country_code_value';
  $handler->display->display_options['filters']['field_country_code_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: City (field_city) */
  $handler->display->display_options['filters']['field_city_value']['id'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['table'] = 'field_data_field_city';
  $handler->display->display_options['filters']['field_city_value']['field'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_city_value']['group'] = 1;
  $handler->display->display_options['filters']['field_city_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_city_value']['expose']['operator_id'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_city_value']['expose']['operator'] = 'field_city_value_op';
  $handler->display->display_options['filters']['field_city_value']['expose']['identifier'] = 'field_city_value';
  $handler->display->display_options['filters']['field_city_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Starting date - end date (field_start_date:value2) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator_id'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['identifier'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value2']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Ares/Adonis (field_adonis) */
  $handler->display->display_options['filters']['field_adonis_value']['id'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['table'] = 'field_data_field_adonis';
  $handler->display->display_options['filters']['field_adonis_value']['field'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_adonis_value']['group'] = 1;
  $handler->display->display_options['filters']['field_adonis_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator_id'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['label'] = 'Adonis';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['operator'] = 'field_adonis_value_op';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['identifier'] = 'field_adonis_value';
  $handler->display->display_options['filters']['field_adonis_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Activity (field_activity) */
  $handler->display->display_options['filters']['field_activity_tid']['id'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['table'] = 'field_data_field_activity';
  $handler->display->display_options['filters']['field_activity_tid']['field'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_tid']['expose']['operator_id'] = 'field_activity_tid_op';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['label'] = 'Activity';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['operator'] = 'field_activity_tid_op';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['identifier'] = 'field_activity_tid';
  $handler->display->display_options['filters']['field_activity_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_activity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_tid']['vocabulary'] = 'activity';
  $handler->display->display_options['filters']['field_activity_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Agency Role (field_agency_role) */
  $handler->display->display_options['filters']['field_agency_role_value']['id'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['table'] = 'field_data_field_agency_role';
  $handler->display->display_options['filters']['field_agency_role_value']['field'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_role_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator_id'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['label'] = 'Agency role';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['operator'] = 'field_agency_role_value_op';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['identifier'] = 'field_agency_role_value';
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_agency_role_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Agenda (field_agenda) */
  $handler->display->display_options['filters']['field_agenda_value']['id'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['table'] = 'field_data_field_agenda';
  $handler->display->display_options['filters']['field_agenda_value']['field'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agenda_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator_id'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['label'] = 'Agenda';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['operator'] = 'field_agenda_value_op';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['identifier'] = 'field_agenda_value';
  $handler->display->display_options['filters']['field_agenda_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Publications/exhibition support (field_publications_exhibition_su) */
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['id'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['table'] = 'field_data_field_publications_exhibition_su';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['field'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator_id'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['label'] = 'Publications/exhibition support';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['operator'] = 'field_publications_exhibition_su_value_op';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['identifier'] = 'field_publications_exhibition_su_value';
  $handler->display->display_options['filters']['field_publications_exhibition_su_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Media/promotion (field_media_promotion) */
  $handler->display->display_options['filters']['field_media_promotion_value']['id'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['table'] = 'field_data_field_media_promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['field'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['group'] = 1;
  $handler->display->display_options['filters']['field_media_promotion_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator_id'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['label'] = 'Media/promotion';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['operator'] = 'field_media_promotion_value_op';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['identifier'] = 'field_media_promotion_value';
  $handler->display->display_options['filters']['field_media_promotion_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Key Performance Indicator (field_key_performance) */
  $handler->display->display_options['filters']['field_key_performance_value']['id'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['table'] = 'field_data_field_key_performance';
  $handler->display->display_options['filters']['field_key_performance_value']['field'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['group'] = 1;
  $handler->display->display_options['filters']['field_key_performance_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator_id'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['label'] = 'Key Performance Indicator';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['operator'] = 'field_key_performance_value_op';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['identifier'] = 'field_key_performance_value';
  $handler->display->display_options['filters']['field_key_performance_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Agency Rep confirmed (field_agency_rep_confirmed) */
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['id'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['table'] = 'field_data_field_agency_rep_confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['field'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator_id'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['label'] = 'Agency rep confirmed';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['operator'] = 'field_agency_rep_confirmed_value_op';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['identifier'] = 'field_agency_rep_confirmed_value';
  $handler->display->display_options['filters']['field_agency_rep_confirmed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
  );
  /* Filter criterion: Content: Type of event (field_type_event) */
  $handler->display->display_options['filters']['field_type_event_value']['id'] = 'field_type_event_value';
  $handler->display->display_options['filters']['field_type_event_value']['table'] = 'field_data_field_type_event';
  $handler->display->display_options['filters']['field_type_event_value']['field'] = 'field_type_event_value';
  $handler->display->display_options['filters']['field_type_event_value']['group'] = 1;
  $handler->display->display_options['filters']['field_type_event_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_event_value']['expose']['operator_id'] = 'field_type_event_value_op';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['label'] = 'Type of event';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['operator'] = 'field_type_event_value_op';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['identifier'] = 'field_type_event_value';
  $handler->display->display_options['filters']['field_type_event_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Migrate Source (field_migration_source) */
  $handler->display->display_options['filters']['field_migration_source_value']['id'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['table'] = 'field_data_field_migration_source';
  $handler->display->display_options['filters']['field_migration_source_value']['field'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_migration_source_value']['value'] = array(
    'hwc' => 'hwc',
    'oira' => 'oira',
    'napo' => 'napo',
  );
  $handler->display->display_options['filters']['field_migration_source_value']['group'] = 1;
  $handler->display->display_options['filters']['field_migration_source_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator_id'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['label'] = 'Source not in';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['operator'] = 'field_migration_source_value_op';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
  );
  $handler->display->display_options['filters']['field_migration_source_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['label'] = 'Source';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['identifier'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'HWC',
      'operator' => 'or',
      'value' => array(
        'hwc' => 'hwc',
      ),
    ),
    2 => array(
      'title' => 'Osha',
      'operator' => 'empty',
      'value' => array(
        'hwc' => 'hwc',
        'oira' => 'oira',
        'napo' => 'napo',
      ),
    ),
  );
  /* Filter criterion: Content: For the web / Public (field_for_the_web) */
  $handler->display->display_options['filters']['field_for_the_web_value']['id'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['table'] = 'field_data_field_for_the_web';
  $handler->display->display_options['filters']['field_for_the_web_value']['field'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['group'] = 1;
  $handler->display->display_options['filters']['field_for_the_web_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator_id'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['label'] = 'For the web / Public';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['operator'] = 'field_for_the_web_value_op';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['identifier'] = 'field_for_the_web_value';
  $handler->display->display_options['filters']['field_for_the_web_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  /* Filter criterion: Field: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
    17 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['path'] = 'admin/content/events-export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'block_1' => 0,
  );
  $translatables['admin_events'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('author'),
    t('For the web / Public'),
    t('Country code'),
    t('City'),
    t('Starting date'),
    t('Website of event'),
    t('Ares/Adonis'),
    t('Unit Ref'),
    t('Agency Role'),
    t('Agency Initial Contact'),
    t('Agency Rep confirmed'),
    t('Event in AMP'),
    t('Comments'),
    t('Number of attendees'),
    t('Satisfaction rate'),
    t('Published'),
    t('<p>
<a href="/en/node/add/events">Add event</a>
</p>'),
    t('Total: @total'),
    t('Colours'),
    t('<div class="colours">
<div class="red"></div><p">TBD - TBC<p>
<div class="black"></div><p>Confirmed<p>
<div class="grey"></div><p>Only web or not attendance<p>
</div>'),
    t('<span class="result_summary">Displaying @start - @end of @total</span>'),
    t('Color'),
    t('[field_color]'),
    t('Activity'),
    t('Type of event'),
    t('Organisation'),
    t('Title'),
    t('Country'),
    t('Start date'),
    t('End date'),
    t('Agenda'),
    t('Agency role'),
    t('Agency rep confirmed'),
    t('Publications/exhibition support'),
    t('Media/promotion'),
    t('Key Performance Indicator'),
    t('Number of participants'),
    t('Created by'),
    t('Action'),
    t('<ul class="links inline">
<li>[edit_node]</li>
<li>[delete_node]</li>
</ul>'),
    t('Not from'),
    t('Source'),
    t('For the web'),
    t('Tags'),
    t('Data export'),
    t('Color (field_color)'),
    t('Adonis'),
    t('Source not in'),
  );
  $export['admin_events'] = $view;

  $view = new view();
  $view->name = 'event_schedule';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Event schedule';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field collection item: Entity with the Schedule (field_schedule) */
  $handler->display->display_options['relationships']['field_schedule_node']['id'] = 'field_schedule_node';
  $handler->display->display_options['relationships']['field_schedule_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_schedule_node']['field'] = 'field_schedule_node';
  $handler->display->display_options['relationships']['field_schedule_node']['required'] = TRUE;
  /* Field: Field collection item: Speech date */
  $handler->display->display_options['fields']['field_talking_date']['id'] = 'field_talking_date';
  $handler->display->display_options['fields']['field_talking_date']['table'] = 'field_data_field_talking_date';
  $handler->display->display_options['fields']['field_talking_date']['field'] = 'field_talking_date';
  $handler->display->display_options['fields']['field_talking_date']['label'] = '';
  $handler->display->display_options['fields']['field_talking_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_talking_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_talking_date']['settings'] = array(
    'format_type' => 'day_month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_talking_date']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Speech title */
  $handler->display->display_options['fields']['field_talking_title']['id'] = 'field_talking_title';
  $handler->display->display_options['fields']['field_talking_title']['table'] = 'field_data_field_talking_title';
  $handler->display->display_options['fields']['field_talking_title']['field'] = 'field_talking_title';
  $handler->display->display_options['fields']['field_talking_title']['label'] = '';
  $handler->display->display_options['fields']['field_talking_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_talking_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_talking_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_talking_title']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_talking_title']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Presentation */
  $handler->display->display_options['fields']['field_talking_files']['id'] = 'field_talking_files';
  $handler->display->display_options['fields']['field_talking_files']['table'] = 'field_data_field_talking_files';
  $handler->display->display_options['fields']['field_talking_files']['field'] = 'field_talking_files';
  $handler->display->display_options['fields']['field_talking_files']['label'] = '';
  $handler->display->display_options['fields']['field_talking_files']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_talking_files']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_talking_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_talking_files']['type'] = 'field_file';
  $handler->display->display_options['fields']['field_talking_files']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_talking_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_talking_files']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Speaker */
  $handler->display->display_options['fields']['field_talking_speaker']['id'] = 'field_talking_speaker';
  $handler->display->display_options['fields']['field_talking_speaker']['table'] = 'field_data_field_talking_speaker';
  $handler->display->display_options['fields']['field_talking_speaker']['field'] = 'field_talking_speaker';
  $handler->display->display_options['fields']['field_talking_speaker']['label'] = '';
  $handler->display->display_options['fields']['field_talking_speaker']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_talking_speaker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_talking_speaker']['settings'] = array(
    'link' => 0,
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_talking_speaker']['field_api_classes'] = TRUE;
  /* Field: Field collection item: Conference Room */
  $handler->display->display_options['fields']['field_venue']['id'] = 'field_venue';
  $handler->display->display_options['fields']['field_venue']['table'] = 'field_data_field_venue';
  $handler->display->display_options['fields']['field_venue']['field'] = 'field_venue';
  $handler->display->display_options['fields']['field_venue']['label'] = '';
  $handler->display->display_options['fields']['field_venue']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_venue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_venue']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_venue']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_venue']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-3 col-sm-4 talking-date">
[field_talking_date]
</div>
<div class="col-md-9 col-sm-8 talking-details">
[field_talking_title]
[field_talking_speaker]
[field_venue]
[field_talking_files]
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Field collection item: Speech date -  start date (field_talking_date) */
  $handler->display->display_options['sorts']['field_talking_date_value']['id'] = 'field_talking_date_value';
  $handler->display->display_options['sorts']['field_talking_date_value']['table'] = 'field_data_field_talking_date';
  $handler->display->display_options['sorts']['field_talking_date_value']['field'] = 'field_talking_date_value';
  /* Sort criterion: Field collection item: Speech title (field_talking_title) */
  $handler->display->display_options['sorts']['field_talking_title_value']['id'] = 'field_talking_title_value';
  $handler->display->display_options['sorts']['field_talking_title_value']['table'] = 'field_data_field_talking_title';
  $handler->display->display_options['sorts']['field_talking_title_value']['field'] = 'field_talking_title_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_schedule_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $translatables['event_schedule'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_schedule'),
    t('<div class="col-md-3 col-sm-4 talking-date">
[field_talking_date]
</div>
<div class="col-md-9 col-sm-8 talking-details">
[field_talking_title]
[field_talking_speaker]
[field_venue]
[field_talking_files]
</div>'),
    t('All'),
  );
  $export['event_schedule'] = $view;

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create events content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'Country code';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );

  /* Display: Events - admin view */
  $handler = $view->new_display('page', 'Events - admin view', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_color' => 'field_color',
    'title_field' => 'title_field',
    'field_for_the_web' => 'field_for_the_web',
    'field_organization' => 'field_organization',
    'field_country_code' => 'field_country_code',
    'field_city' => 'field_city',
    'field_start_date' => 'field_start_date',
    'field_start_date_1' => 'field_start_date_1',
    'field_website_of_event' => 'field_website_of_event',
    'field_adonis' => 'field_adonis',
    'field_unit_ref' => 'field_unit_ref',
    'field_activity' => 'field_activity',
    'field_agency_role' => 'field_agency_role',
    'field_agency_initial_contact' => 'field_agency_initial_contact',
    'field_agency_rep_confirmed' => 'field_agency_rep_confirmed',
    'field_organised_by' => 'field_organised_by',
    'field_event_in_amp' => 'field_event_in_amp',
    'field_agency_contact_reply' => 'field_agency_contact_reply',
    'field_comments_summary_after_eve' => 'field_comments_summary_after_eve',
    'field_number_of_attendees' => 'field_number_of_attendees',
    'field_satisfaction_rate' => 'field_satisfaction_rate',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
    'name' => 'name',
    'field_agency_rep_confirmed_1' => 'field_agency_rep_confirmed_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_color' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_for_the_web' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_city' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_start_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_start_date_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website_of_event' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_adonis' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_unit_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_role' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_initial_contact' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_rep_confirmed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organised_by' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_in_amp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_contact_reply' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_comments_summary_after_eve' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_number_of_attendees' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_satisfaction_rate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agency_rep_confirmed_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>
<a href="/en/node/add/events">Add event</a>
</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total: @total';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'field_data_field_country_code';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'Country code';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'field_data_field_city';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'End date';
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'field_data_field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="links inline">
<li>[edit_node]</li>
<li>[delete_node]</li>
</ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'Start date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Starting date - end date (field_start_date:value2) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value2']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator_id'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['label'] = 'End date';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['identifier'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/content/events';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Filter by date upcoming */
  $handler = $view->new_display('block', 'Filter by date upcoming', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Calendar filter';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_start_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['wrapper_class'] = 'events-filter-by-date';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Start date for grouping */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['ui_name'] = 'Start date for grouping';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['text'] = '[field_start_date_1]';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_start_date_value']['year_range'] = '-10:+10';

  /* Display: Filter by date past events */
  $handler = $view->new_display('block', 'Filter by date past events', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Calendar filter';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_start_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['wrapper_class'] = 'events-filter-by-date';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Start date for grouping */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['ui_name'] = 'Start date for grouping';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['text'] = '[field_start_date_1]';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
    'field_formatter_class' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_start_date_value']['year_range'] = '-10:+10';
  $translatables['events'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('author'),
    t('Country code'),
    t('City'),
    t('Starting date'),
    t('Website of event'),
    t('Events - admin view'),
    t('<p>
<a href="/en/node/add/events">Add event</a>
</p>'),
    t('Total: @total'),
    t('Title'),
    t('End date'),
    t('Operations'),
    t('<ul class="links inline">
<li>[edit_node]</li>
<li>[delete_node]</li>
</ul>'),
    t('Name'),
    t('Published'),
    t('Start date'),
    t('Filter by date upcoming'),
    t('Calendar filter'),
    t('[field_start_date_1]'),
    t('Filter by date past events'),
  );
  $export['events'] = $view;

  $view = new view();
  $view->name = 'events_index';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Events Index';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events Index';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Indexed Multilingual Content: Publication date */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'OSH events';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear filter';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_start_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Starting date: Start date (indexed) */
  $handler->display->display_options['fields']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['fields']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['fields']['field_start_date_value']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_value']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_value']['alter']['text'] = '[field_start_date_value] - ';
  $handler->display->display_options['fields']['field_start_date_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_value']['date_format'] = 'osha_day_only';
  $handler->display->display_options['fields']['field_start_date_value']['second_date_format'] = 'year';
  $handler->display->display_options['fields']['field_start_date_value']['link_to_entity'] = 0;
  /* Field: Starting date: End date (indexed) */
  $handler->display->display_options['fields']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['fields']['field_start_date_value2']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['fields']['field_start_date_value2']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_value2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_value2']['date_format'] = 'osha_day_only';
  $handler->display->display_options['fields']['field_start_date_value2']['second_date_format'] = 'year';
  $handler->display->display_options['fields']['field_start_date_value2']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = 'LOCATION';
  /* Field: Indexed Multilingual Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Start date for grouping */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['ui_name'] = 'Start date for grouping';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date_1']['alter']['text'] = '[field_start_date_1] - Events';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'year_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'See details';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    3 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_summary' => 'field_summary',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Country */
  $handler->display->display_options['filters']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['filters']['field_country_code']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['filters']['field_country_code']['group'] = 1;
  $handler->display->display_options['filters']['field_country_code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_country_code']['expose']['operator_id'] = 'field_country_code_op';
  $handler->display->display_options['filters']['field_country_code']['expose']['label'] = 'Search by country';
  $handler->display->display_options['filters']['field_country_code']['expose']['operator'] = 'field_country_code_op';
  $handler->display->display_options['filters']['field_country_code']['expose']['identifier'] = 'field_country_code';
  $handler->display->display_options['filters']['field_country_code']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 3;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['label'] = 'From date';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Starting date: End date (indexed) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value2']['group'] = 3;
  $handler->display->display_options['filters']['field_start_date_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator_id'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['label'] = 'To date';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['operator'] = 'field_start_date_value2_op';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['identifier'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  /* Filter criterion: Indexed Multilingual Content: Publication date */
  $handler->display->display_options['filters']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date']['value'] = 'now';
  $handler->display->display_options['filters']['field_publication_date']['group'] = 2;
  /* Filter criterion: Indexed Multilingual Content: Publication date */
  $handler->display->display_options['filters']['field_publication_date_1']['id'] = 'field_publication_date_1';
  $handler->display->display_options['filters']['field_publication_date_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_publication_date_1']['field'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_1']['group'] = 2;
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['path'] = 'oshevents';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_country_code']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_country_code']['element_class'] = 'country';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country_code']['settings'] = array(
    'title_style' => 'div',
    'title_link' => '',
    'title_class' => 'country',
  );
  /* Field: Indexed Multilingual Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_city']['element_class'] = 'city';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_city']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => 'city',
  );
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'div';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'title';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => 'title',
  );
  /* Field: Indexed Multilingual Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Starting date: End date (indexed) */
  $handler->display->display_options['filters']['field_start_date_value2']['id'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_start_date_value2']['field'] = 'field_start_date_value2';
  $handler->display->display_options['filters']['field_start_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value2']['value'] = 'now';
  $handler->display->display_options['block_description'] = 'Upcoming events';
  $translatables['events_index'] = array(
    t('Master'),
    t('Events Index'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Multilingual ID'),
    t('Page'),
    t('OSH events'),
    t('Search'),
    t('Clear filter'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('No results'),
    t('[field_start_date_value] - '),
    t('LOCATION'),
    t('[field_start_date_1] - Events'),
    t('See details'),
    t('Search by country'),
    t('From date'),
    t('To date'),
    t('Block'),
    t('Upcoming events'),
    t('View all'),
  );
  $export['events_index'] = $view;

  $view = new view();
  $view->name = 'events_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Events Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Past events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'X';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'container';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Relationship: Indexed Multilingual Content: Country */
  $handler->display->display_options['relationships']['field_country']['id'] = 'field_country';
  $handler->display->display_options['relationships']['field_country']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['relationships']['field_country']['field'] = 'field_country';
  /* Field: Indexed Multilingual Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'day_month_year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'div',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Content: Starting date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = 'Event date';
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'month_day_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: Website of event */
  $handler->display->display_options['fields']['field_website_of_event']['id'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_website_of_event']['field'] = 'field_website_of_event';
  $handler->display->display_options['fields']['field_website_of_event']['label'] = '';
  $handler->display->display_options['fields']['field_website_of_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_of_event']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_of_event']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'See more';
  /* Sort criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  /* Filter criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_start_date_value']['value'] = 'now';

  /* Display: Upcoming events */
  $handler = $view->new_display('page', 'Upcoming events', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code_1']['id'] = 'field_country_code_1';
  $handler->display->display_options['fields']['field_country_code_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code_1']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code_1']['label'] = '';
  $handler->display->display_options['fields']['field_country_code_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country_code_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country_code_1']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_country_code_1']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['alter']['text'] = '[field_start_date]
[field_country_code_1]';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Starting date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => 'with_time',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
    'field_formatter_class' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'See more';
  /* Field: Indexed Multilingual Content: Show EU flag */
  $handler->display->display_options['fields']['field_show_eu_flag']['id'] = 'field_show_eu_flag';
  $handler->display->display_options['fields']['field_show_eu_flag']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_show_eu_flag']['field'] = 'field_show_eu_flag';
  $handler->display->display_options['fields']['field_show_eu_flag']['label'] = '';
  $handler->display->display_options['fields']['field_show_eu_flag']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_show_eu_flag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_show_eu_flag']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['sorts']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  /* Filter criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_start_date_value']['value'] = 'today';
  $handler->display->display_options['path'] = 'media-centre/events';

  /* Display: Past events */
  $handler = $view->new_display('page', 'Past events', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past events';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code_1']['id'] = 'field_country_code_1';
  $handler->display->display_options['fields']['field_country_code_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code_1']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code_1']['label'] = '';
  $handler->display->display_options['fields']['field_country_code_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country_code_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country_code_1']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_country_code_1']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_start_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_start_date']['alter']['text'] = '[field_start_date]
[field_country_code_1]';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Starting date */
  $handler->display->display_options['fields']['field_start_date_1']['id'] = 'field_start_date_1';
  $handler->display->display_options['fields']['field_start_date_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_start_date_1']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_start_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date_1']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => 'with_time',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country_code']['id'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country_code']['field'] = 'field_country_code';
  $handler->display->display_options['fields']['field_country_code']['label'] = '';
  $handler->display->display_options['fields']['field_country_code']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: City */
  $handler->display->display_options['fields']['field_city']['id'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_city']['field'] = 'field_city';
  $handler->display->display_options['fields']['field_city']['label'] = '';
  $handler->display->display_options['fields']['field_city']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
    'field_formatter_class' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'See more';
  /* Field: Indexed Multilingual Content: Show EU flag */
  $handler->display->display_options['fields']['field_show_eu_flag']['id'] = 'field_show_eu_flag';
  $handler->display->display_options['fields']['field_show_eu_flag']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_show_eu_flag']['field'] = 'field_show_eu_flag';
  $handler->display->display_options['fields']['field_show_eu_flag']['label'] = '';
  $handler->display->display_options['fields']['field_show_eu_flag']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_show_eu_flag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_show_eu_flag']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  /* Filter criterion: Indexed Multilingual Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  /* Filter criterion: Starting date: Start date (indexed) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_start_date_value']['value'] = 'today';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'title_field' => 'title_field',
  );
  $handler->display->display_options['path'] = 'media-centre/past-events';
  $translatables['events_search'] = array(
    t('Master'),
    t('Past events'),
    t('more'),
    t('Apply'),
    t('X'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('No results'),
    t('Country'),
    t('Event date'),
    t('See more'),
    t('Upcoming events'),
    t('[field_start_date]
[field_country_code_1]'),
  );
  $export['events_search'] = $view;

  $view = new view();
  $view->name = 'reporting_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reporting View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reporting View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create events content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_activity',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Total: @end
';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Starting date */
  $handler->display->display_options['fields']['field_start_date']['id'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['fields']['field_start_date']['field'] = 'field_start_date';
  $handler->display->display_options['fields']['field_start_date']['label'] = 'Start date:';
  $handler->display->display_options['fields']['field_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_start_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'events' => 'events',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Starting date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator_id'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['operator'] = 'field_start_date_value_op';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['label'] = 'Start date (field_start_date)';
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['identifier'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_start_date_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_start_date_value']['form_type'] = 'date_popup';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/reporting-view';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Events-reports';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['reporting_view'] = array(
    t('Master'),
    t('Reporting View'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Total: @end
'),
    t('Start date:'),
    t('Start date (field_start_date)'),
    t('Page'),
    t('Block'),
  );
  $export['reporting_view'] = $view;

  return $export;
}

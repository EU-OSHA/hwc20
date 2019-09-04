<?php
/**
 * @file
 * hwc_previous_campaigns.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hwc_previous_campaigns_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'related_resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Entiy Reference View Widget Related Resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Entity Reference View Widget Checkbox: Taxonomy term */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'related_resources' => 'related_resources',
  );
  /* Filter criterion: Taxonomy term: Resource type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_value']['id'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_value']['field'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['value'] = array(
    'HWC16' => 'HWC16',
  );

  /* Display: Related resources 16-17 */
  $handler = $view->new_display('entityreference_view_widget', 'Related resources 16-17', 'relres16');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Related resources 18-19 */
  $handler = $view->new_display('entityreference_view_widget', 'Related resources 18-19', 'relres18');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'related_resources' => 'related_resources',
  );
  /* Filter criterion: Taxonomy term: Resource type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_value']['id'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_value']['field'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['value'] = array(
    'HWC18' => 'HWC18',
  );

  /* Display: Related resources 20-22 */
  $handler = $view->new_display('entityreference_view_widget', 'Related resources 20-22', 'relres20');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'related_resources' => 'related_resources',
  );
  /* Filter criterion: Taxonomy term: Resource type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_value']['id'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_value']['field'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['value'] = array(
    'HWC20' => 'HWC20',
  );
  $translatables['related_resources'] = array(
    t('Master'),
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
    t('Related resources 16-17'),
    t('Related resources 18-19'),
    t('Related resources 20-22'),
  );
  $export['related_resources'] = $view;

  return $export;
}

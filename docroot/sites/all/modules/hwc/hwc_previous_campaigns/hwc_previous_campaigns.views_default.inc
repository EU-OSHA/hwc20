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
  $view->name = 'rel_res';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Related resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related resources';
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
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_icon' => 'field_icon',
    'field_resource_link' => 'field_resource_link',
    'field_resource_type' => 'field_resource_type',
    'edit_term' => 'edit_term',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_icon' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_link' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_term' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Field: Section icon */
  $handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
  $handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
  $handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
  $handler->display->display_options['fields']['field_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
    'field_formatter_class' => '',
  );
  /* Field: Taxonomy term: Link */
  $handler->display->display_options['fields']['field_resource_link']['id'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['table'] = 'field_data_field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['field'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_resource_link']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Taxonomy term: Resource type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Taxonomy term: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'related_resources' => 'related_resources',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'field_resource_type' => 'field_resource_type',
  );
  /* Filter criterion: Taxonomy term: Resource type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_value']['id'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_value']['field'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_resource_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_value']['expose']['operator_id'] = 'field_resource_type_value_op';
  $handler->display->display_options['filters']['field_resource_type_value']['expose']['label'] = 'Resource type';
  $handler->display->display_options['filters']['field_resource_type_value']['expose']['operator'] = 'field_resource_type_value_op';
  $handler->display->display_options['filters']['field_resource_type_value']['expose']['identifier'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_value']['expose']['remember_roles'] = array(
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/related-resources';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Related resources';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['rel_res'] = array(
    t('Master'),
    t('Related resources'),
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
    t('Name'),
    t('Section icon'),
    t('Link'),
    t('Resource type'),
    t('Term edit link'),
    t('Search'),
    t('Page'),
  );
  $export['rel_res'] = $view;

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

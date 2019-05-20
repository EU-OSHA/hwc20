<?php
/**
 * @file
 * hwc.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hwc_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'first_publication_date_update';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'first publication date update';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'nid' => 'nid',
    'from_state' => 'from_state',
    'published' => 'published',
    'state' => 'state',
    'stamp' => 'stamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'from_state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'published' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: From state */
  $handler->display->display_options['fields']['from_state']['id'] = 'from_state';
  $handler->display->display_options['fields']['from_state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['from_state']['field'] = 'from_state';
  /* Field: Workbench Moderation: Timestamp */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'year';
  $handler->display->display_options['fields']['stamp']['second_date_format'] = 'year';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'campaign_materials' => 'campaign_materials',
    'events' => 'events',
    'infographic' => 'infographic',
    'news' => 'news',
    'practical_tool' => 'practical_tool',
    'press_release' => 'press_release',
    'publication' => 'publication',
  );
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'published' => 'published',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: First publication date (field_first_publication_date) */
  $handler->display->display_options['filters']['field_first_publication_date_value']['id'] = 'field_first_publication_date_value';
  $handler->display->display_options['filters']['field_first_publication_date_value']['table'] = 'field_data_field_first_publication_date';
  $handler->display->display_options['filters']['field_first_publication_date_value']['field'] = 'field_first_publication_date_value';
  $handler->display->display_options['filters']['field_first_publication_date_value']['operator'] = 'empty';
  $translatables['first_publication_date_update'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Nid'),
    t('State'),
    t('From state'),
    t('Timestamp'),
  );
  $export['first_publication_date_update'] = $view;

  $view = new view();
  $view->name = 'get_your_certificate';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Get your certificate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Get your certificate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'completed' => array(
      'bef_format' => 'bef_datepicker',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'completed_1' => array(
      'bef_format' => 'bef_datepicker',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'view_submission' => 'view_submission',
    'completed' => 'completed',
    'value' => 'value',
    'value_1' => 'value_1',
    'value_2' => 'value_2',
    'value_3' => 'value_3',
    'value_4' => 'value_4',
    'value_5' => 'value_5',
    'download_pdf' => 'download_pdf',
    'value_6' => 'value_6',
    'value_7' => 'value_7',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'view_submission' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_4' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_5' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'download_pdf' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_6' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_7' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  /* Field: Webform submissions: Completed */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['date_format'] = 'osha_day_only';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'year';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = 'Company / Organisation';
  $handler->display->display_options['fields']['value']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value']['webform_cid'] = '1';
  /* Field: Company / Organisation */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['ui_name'] = 'Company / Organisation';
  $handler->display->display_options['fields']['value_1']['label'] = 'Country';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '2';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['label'] = '';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '3';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['label'] = '';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '4';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['label'] = '';
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '5';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['label'] = '';
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '6';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['label'] = '';
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '7';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_7']['id'] = 'value_7';
  $handler->display->display_options['fields']['value_7']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_7']['field'] = 'value';
  $handler->display->display_options['fields']['value_7']['label'] = 'Other';
  $handler->display->display_options['fields']['value_7']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_7']['webform_cid'] = '8';
  /* Field: Webform submissions: Download PDF */
  $handler->display->display_options['fields']['download_pdf']['id'] = 'download_pdf';
  $handler->display->display_options['fields']['download_pdf']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['download_pdf']['field'] = 'download_pdf';
  $handler->display->display_options['fields']['download_pdf']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['download_pdf']['access_check'] = 1;
  /* Filter criterion: Webform submissions: Completed */
  $handler->display->display_options['filters']['completed']['id'] = 'completed';
  $handler->display->display_options['filters']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['completed']['field'] = 'completed';
  $handler->display->display_options['filters']['completed']['operator'] = '>=';
  $handler->display->display_options['filters']['completed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['completed']['expose']['operator_id'] = 'completed_op';
  $handler->display->display_options['filters']['completed']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['completed']['expose']['operator'] = 'completed_op';
  $handler->display->display_options['filters']['completed']['expose']['identifier'] = 'completed';
  $handler->display->display_options['filters']['completed']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Webform submissions: Completed */
  $handler->display->display_options['filters']['completed_1']['id'] = 'completed_1';
  $handler->display->display_options['filters']['completed_1']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['completed_1']['field'] = 'completed';
  $handler->display->display_options['filters']['completed_1']['operator'] = '<=';
  $handler->display->display_options['filters']['completed_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['completed_1']['expose']['operator_id'] = 'completed_1_op';
  $handler->display->display_options['filters']['completed_1']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['completed_1']['expose']['operator'] = 'completed_1_op';
  $handler->display->display_options['filters']['completed_1']['expose']['identifier'] = 'completed_1';
  $handler->display->display_options['filters']['completed_1']['expose']['remember_roles'] = array(
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
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  /* Field: Webform submissions: Completed */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['date_format'] = 'osha_day_only';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'year';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = 'Company / Organisation';
  $handler->display->display_options['fields']['value']['custom_label'] = 'custom';
  $handler->display->display_options['fields']['value']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value']['webform_cid'] = '1';
  /* Field: Company / Organisation */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['ui_name'] = 'Company / Organisation';
  $handler->display->display_options['fields']['value_1']['label'] = 'Country';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '2';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['label'] = '';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '3';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['label'] = '';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '4';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['label'] = '';
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '5';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['label'] = '';
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '6';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['label'] = 'I/we participated in the Healthy Workplaces Campaign and organised the following activities:';
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '7';
  /* Field: Webform submission data: Value */
  $handler->display->display_options['fields']['value_7']['id'] = 'value_7';
  $handler->display->display_options['fields']['value_7']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_7']['field'] = 'value';
  $handler->display->display_options['fields']['value_7']['label'] = 'Other';
  $handler->display->display_options['fields']['value_7']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_7']['webform_cid'] = '8';
  /* Field: Webform submissions: Download PDF */
  $handler->display->display_options['fields']['download_pdf']['id'] = 'download_pdf';
  $handler->display->display_options['fields']['download_pdf']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['download_pdf']['field'] = 'download_pdf';
  $handler->display->display_options['fields']['download_pdf']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['download_pdf']['access_check'] = 1;
  $handler->display->display_options['path'] = 'admin/content/get_your_certificate';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xlsx';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Submissions */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['ui_name'] = 'Submissions';
  $handler->display->display_options['fields']['completed']['date_format'] = 'osha_day_only';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'year';
  /* Field: Company / Organisation */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['ui_name'] = 'Company / Organisation';
  $handler->display->display_options['fields']['value']['label'] = 'Company / Organisation';
  $handler->display->display_options['fields']['value']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value']['webform_cid'] = '1';
  /* Field: Country */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['ui_name'] = 'Country';
  $handler->display->display_options['fields']['value_1']['label'] = 'Country';
  $handler->display->display_options['fields']['value_1']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_1']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_1']['webform_cid'] = '2';
  /* Field: First name of contact person */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['ui_name'] = 'First name of contact person';
  $handler->display->display_options['fields']['value_2']['label'] = 'First name of contact person';
  $handler->display->display_options['fields']['value_2']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_2']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_2']['webform_cid'] = '3';
  /* Field: Last name */
  $handler->display->display_options['fields']['value_3']['id'] = 'value_3';
  $handler->display->display_options['fields']['value_3']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_3']['field'] = 'value';
  $handler->display->display_options['fields']['value_3']['ui_name'] = 'Last name';
  $handler->display->display_options['fields']['value_3']['label'] = 'Last name';
  $handler->display->display_options['fields']['value_3']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_3']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_3']['webform_cid'] = '4';
  /* Field: Business sector */
  $handler->display->display_options['fields']['value_4']['id'] = 'value_4';
  $handler->display->display_options['fields']['value_4']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_4']['field'] = 'value';
  $handler->display->display_options['fields']['value_4']['ui_name'] = 'Business sector';
  $handler->display->display_options['fields']['value_4']['label'] = 'Business sector';
  $handler->display->display_options['fields']['value_4']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_4']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_4']['webform_cid'] = '5';
  /* Field: E-mail address */
  $handler->display->display_options['fields']['value_5']['id'] = 'value_5';
  $handler->display->display_options['fields']['value_5']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_5']['field'] = 'value';
  $handler->display->display_options['fields']['value_5']['ui_name'] = 'E-mail address';
  $handler->display->display_options['fields']['value_5']['label'] = 'E-mail address';
  $handler->display->display_options['fields']['value_5']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_5']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_5']['webform_cid'] = '6';
  /* Field: I/we participated in the Healthy Workplaces Campaign and organized the following activities: */
  $handler->display->display_options['fields']['value_6']['id'] = 'value_6';
  $handler->display->display_options['fields']['value_6']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_6']['field'] = 'value';
  $handler->display->display_options['fields']['value_6']['ui_name'] = 'I/we participated in the Healthy Workplaces Campaign and organized the following activities:';
  $handler->display->display_options['fields']['value_6']['label'] = '';
  $handler->display->display_options['fields']['value_6']['format'] = 'text';
  $handler->display->display_options['fields']['value_6']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_6']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_6']['webform_cid'] = '7';
  /* Field: Other */
  $handler->display->display_options['fields']['value_7']['id'] = 'value_7';
  $handler->display->display_options['fields']['value_7']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['value_7']['field'] = 'value';
  $handler->display->display_options['fields']['value_7']['ui_name'] = 'Other';
  $handler->display->display_options['fields']['value_7']['label'] = 'Other';
  $handler->display->display_options['fields']['value_7']['custom_label'] = 'none';
  $handler->display->display_options['fields']['value_7']['webform_nid'] = '240';
  $handler->display->display_options['fields']['value_7']['webform_cid'] = '8';
  $handler->display->display_options['path'] = 'admin/content/get_your_certificate/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['get_your_certificate'] = array(
    t('Master'),
    t('Get your certificate'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Advanced options'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('view'),
    t('Completed'),
    t('Company / Organisation'),
    t('Country'),
    t('Other'),
    t('download pdf'),
    t('From'),
    t('To'),
    t('Page'),
    t('I/we participated in the Healthy Workplaces Campaign and organised the following activities:'),
    t('Data export'),
    t('First name of contact person'),
    t('Last name'),
    t('Business sector'),
    t('E-mail address'),
  );
  $export['get_your_certificate'] = $view;

  $view = new view();
  $view->name = 'ncw_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'NCW Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'NCW Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'items';
  $handler->display->display_options['style_options']['top_child_object'] = 'item';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 1;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
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
  /* Filter criterion: Content: Migrate Source (field_migration_source) */
  $handler->display->display_options['filters']['field_migration_source_value']['id'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['table'] = 'field_data_field_migration_source';
  $handler->display->display_options['filters']['field_migration_source_value']['field'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_migration_source_value']['value'] = array(
    'ncw' => 'ncw',
  );

  /* Display: Events */
  $handler = $view->new_display('page', 'Events', 'page');
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
  /* Filter criterion: Content: Migrate Source (field_migration_source) */
  $handler->display->display_options['filters']['field_migration_source_value']['id'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['table'] = 'field_data_field_migration_source';
  $handler->display->display_options['filters']['field_migration_source_value']['field'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_migration_source_value']['value'] = array(
    'ncw' => 'ncw',
  );
  /* Filter criterion: Content: Show in NCW (field_show_in_ncw) */
  $handler->display->display_options['filters']['field_show_in_ncw_value']['id'] = 'field_show_in_ncw_value';
  $handler->display->display_options['filters']['field_show_in_ncw_value']['table'] = 'field_data_field_show_in_ncw';
  $handler->display->display_options['filters']['field_show_in_ncw_value']['field'] = 'field_show_in_ncw_value';
  $handler->display->display_options['filters']['field_show_in_ncw_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'ncw-export/events';

  /* Display: News */
  $handler = $view->new_display('page', 'News', 'page_1');
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
    'news' => 'news',
  );
  /* Filter criterion: Content: Migrate Source (field_migration_source) */
  $handler->display->display_options['filters']['field_migration_source_value']['id'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['table'] = 'field_data_field_migration_source';
  $handler->display->display_options['filters']['field_migration_source_value']['field'] = 'field_migration_source_value';
  $handler->display->display_options['filters']['field_migration_source_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_migration_source_value']['value'] = array(
    'ncw' => 'ncw',
  );
  $handler->display->display_options['path'] = 'ncw-export/news';
  $translatables['ncw_export'] = array(
    t('Master'),
    t('NCW Export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('nid'),
    t('Events'),
    t('News'),
  );
  $export['ncw_export'] = $view;

  return $export;
}

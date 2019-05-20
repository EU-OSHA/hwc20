<?php

$view = new view();
$view->name = 'osha_translation_job_overview';
$view->description = 'Gives a bulk operation overview of translation jobs in the system.';
$view->tag = 'Translation Management';
$view->base_table = 'tmgmt_job';
$view->human_name = 'OSHA Translation Job Overview';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Job overview';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'tmgmt_views_job_access';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'label' => 'label',
  'state' => 'state',
  'priority' => 'priority',
  'page_count' => 'page_count',
  'character_count' => 'character_count',
  'progress' => 'progress',
  'changed' => 'changed',
  'operations' => 'operations',
);
$handler->display->display_options['style_options']['default'] = 'changed';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'label' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'state' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'priority' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'page_count' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'character_count' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'progress' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['content'] = 'There are no translation jobs that match the specified filter criteria.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Relationship: Translator */
$handler->display->display_options['relationships']['translator']['id'] = 'translator';
$handler->display->display_options['relationships']['translator']['table'] = 'tmgmt_job';
$handler->display->display_options['relationships']['translator']['field'] = 'translator';
$handler->display->display_options['relationships']['translator']['ui_name'] = 'Translator';
$handler->display->display_options['relationships']['translator']['label'] = 'Translator';
/* Field: Bulk operations */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['ui_name'] = 'Bulk operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
  'rules_component::rules_tmgmt_job_accept_translation' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 1,
    'override_label' => 0,
    'label' => '',
  ),
  'rules_component::rules_tmgmt_job_abort_translation' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 1,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_delete_item' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 1,
    'label' => 'Delete Job',
  ),
  'rules_component::rules_tmgmt_job_delete' => array(
    'selected' => 1,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_script_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'action::views_bulk_operations_modify_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'show_all_tokens' => 1,
      'display_values' => array(
        '_all_' => '_all_',
      ),
    ),
  ),
  'action::views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'action::system_send_email_action' => array(
    'selected' => 0,
    'postpone_processing' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
/* Field: Label */
$handler->display->display_options['fields']['label']['id'] = 'label';
$handler->display->display_options['fields']['label']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['label']['field'] = 'label';
$handler->display->display_options['fields']['label']['ui_name'] = 'Label';
/* Field: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['ui_name'] = 'State';
/* Field: Translation Management Job: Priority */
$handler->display->display_options['fields']['priority']['id'] = 'priority';
$handler->display->display_options['fields']['priority']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['priority']['field'] = 'priority';
/* Field: Translation Management Job: Page count */
$handler->display->display_options['fields']['page_count']['id'] = 'page_count';
$handler->display->display_options['fields']['page_count']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['page_count']['field'] = 'page_count';
$handler->display->display_options['fields']['page_count']['set_precision'] = TRUE;
$handler->display->display_options['fields']['page_count']['precision'] = '2';
$handler->display->display_options['fields']['page_count']['decimal'] = ',';
$handler->display->display_options['fields']['page_count']['separator'] = '';
/* Field: Translation Management Job: Character count */
$handler->display->display_options['fields']['character_count']['id'] = 'character_count';
$handler->display->display_options['fields']['character_count']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['character_count']['field'] = 'character_count';
/* Field: Translation Management Job: Progress items */
$handler->display->display_options['fields']['progress_job_items']['id'] = 'progress_job_items';
$handler->display->display_options['fields']['progress_job_items']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['progress_job_items']['field'] = 'progress_job_items';
$handler->display->display_options['fields']['progress_job_items']['label'] = 'Progress';
$handler->display->display_options['fields']['progress_job_items']['element_label_colon'] = FALSE;
/* Field: Changed */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['ui_name'] = 'Changed';
/* Field: Translation Management Job: Has File uploaded */
$handler->display->display_options['fields']['has_file_uploaded']['id'] = 'has_file_uploaded';
$handler->display->display_options['fields']['has_file_uploaded']['table'] = 'views_entity_tmgmt_job';
$handler->display->display_options['fields']['has_file_uploaded']['field'] = 'has_file_uploaded';
$handler->display->display_options['fields']['has_file_uploaded']['label'] = 'File uploaded';
$handler->display->display_options['fields']['has_file_uploaded']['not'] = 0;
$handler->display->display_options['fields']['has_file_uploaded']['link_to_entity'] = 0;
/* Field: Translation Management Job: Has File Sent to CDT */
$handler->display->display_options['fields']['file_sent']['id'] = 'file_sent';
$handler->display->display_options['fields']['file_sent']['table'] = 'views_entity_tmgmt_job';
$handler->display->display_options['fields']['file_sent']['field'] = 'file_sent';
$handler->display->display_options['fields']['file_sent']['label'] = 'File Sent to CDT';
$handler->display->display_options['fields']['file_sent']['not'] = 0;
$handler->display->display_options['fields']['file_sent']['link_to_entity'] = 0;
/* Field: Operations */
$handler->display->display_options['fields']['operations']['id'] = 'operations';
$handler->display->display_options['fields']['operations']['table'] = 'tmgmt_job';
$handler->display->display_options['fields']['operations']['field'] = 'operations';
$handler->display->display_options['fields']['operations']['ui_name'] = 'Operations';
/* Sort criterion: Changed */
$handler->display->display_options['sorts']['changed']['id'] = 'changed';
$handler->display->display_options['sorts']['changed']['table'] = 'tmgmt_job';
$handler->display->display_options['sorts']['changed']['field'] = 'changed';
$handler->display->display_options['sorts']['changed']['ui_name'] = 'Changed';
$handler->display->display_options['sorts']['changed']['order'] = 'DESC';
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'word';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Label';
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
);
$handler->display->display_options['filters']['combine']['fields'] = array(
  'label' => 'label',
);
/* Filter criterion: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'tmgmt_job';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['ui_name'] = 'State';
$handler->display->display_options['filters']['state']['group'] = 1;
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
/* Filter criterion: Translation Management Job: Priority */
$handler->display->display_options['filters']['priority']['id'] = 'priority';
$handler->display->display_options['filters']['priority']['table'] = 'tmgmt_job';
$handler->display->display_options['filters']['priority']['field'] = 'priority';
$handler->display->display_options['filters']['priority']['value'] = array(
  2 => '2',
  1 => '1',
  0 => '0',
);
$handler->display->display_options['filters']['priority']['exposed'] = TRUE;
$handler->display->display_options['filters']['priority']['expose']['operator_id'] = 'priority_op';
$handler->display->display_options['filters']['priority']['expose']['label'] = 'Priority';
$handler->display->display_options['filters']['priority']['expose']['operator'] = 'priority_op';
$handler->display->display_options['filters']['priority']['expose']['identifier'] = 'priority';
$handler->display->display_options['filters']['priority']['expose']['remember_roles'] = array(
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
$handler->display->display_options['filters']['priority']['expose']['reduce'] = TRUE;
/* Filter criterion: Translation Management Job: Has File uploaded */
$handler->display->display_options['filters']['has_file_uploaded']['id'] = 'has_file_uploaded';
$handler->display->display_options['filters']['has_file_uploaded']['table'] = 'tmgmt_job';
$handler->display->display_options['filters']['has_file_uploaded']['field'] = 'has_file_uploaded';
$handler->display->display_options['filters']['has_file_uploaded']['value'] = 'All';
$handler->display->display_options['filters']['has_file_uploaded']['exposed'] = TRUE;
$handler->display->display_options['filters']['has_file_uploaded']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['has_file_uploaded']['expose']['label'] = 'File Uploaded';
$handler->display->display_options['filters']['has_file_uploaded']['expose']['operator'] = 'has_file_uploaded_op';
$handler->display->display_options['filters']['has_file_uploaded']['expose']['identifier'] = 'has_file_uploaded';
$handler->display->display_options['filters']['has_file_uploaded']['expose']['remember_roles'] = array(
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
/* Filter criterion: Translation Management Job: Has File Sent to CDT */
$handler->display->display_options['filters']['file_sent']['id'] = 'file_sent';
$handler->display->display_options['filters']['file_sent']['table'] = 'tmgmt_job';
$handler->display->display_options['filters']['file_sent']['field'] = 'file_sent';
$handler->display->display_options['filters']['file_sent']['value'] = 'All';
$handler->display->display_options['filters']['file_sent']['exposed'] = TRUE;
$handler->display->display_options['filters']['file_sent']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['file_sent']['expose']['label'] = 'File Sent to CDT';
$handler->display->display_options['filters']['file_sent']['expose']['operator'] = 'file_sent_op';
$handler->display->display_options['filters']['file_sent']['expose']['identifier'] = 'file_sent';
$handler->display->display_options['filters']['file_sent']['expose']['remember_roles'] = array(
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

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/tmgmt/overview';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Jobs';
$handler->display->display_options['menu']['weight'] = '-1';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Translation';
$handler->display->display_options['tab_options']['description'] = 'Translation overview';
$handler->display->display_options['tab_options']['weight'] = -9;
$handler->display->display_options['tab_options']['name'] = 'management';
$translatables['osha_translation_job_overview'] = array(
  t('Master'),
  t('Job overview'),
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
  t('There are no translation jobs that match the specified filter criteria.'),
  t('Translator'),
  t('- Choose an operation -'),
  t('Delete Job'),
  t('Label'),
  t('State'),
  t('Priority'),
  t('Page count'),
  t(','),
  t('Character count'),
  t('.'),
  t('Progress'),
  t('Changed'),
  t('File uploaded'),
  t('File Sent to CDT'),
  t('Operations'),
  t('File Uploaded'),
  t('Page'),
);

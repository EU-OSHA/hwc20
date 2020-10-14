<?php
/**
 * @file
 * hwc_glossary.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hwc_glossary_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'glossary_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Glossary';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Glossary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 1;
  /* Field: Taxonomy term: Description */
  $handler->display->display_options['fields']['description_field']['id'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['table'] = 'field_data_description_field';
  $handler->display->display_options['fields']['description_field']['field'] = 'description_field';
  $handler->display->display_options['fields']['description_field']['label'] = '';
  $handler->display->display_options['fields']['description_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['description_field']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['description_field']['link_to_entity'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_glossary_type']['id'] = 'field_glossary_type';
  $handler->display->display_options['fields']['field_glossary_type']['table'] = 'field_data_field_glossary_type';
  $handler->display->display_options['fields']['field_glossary_type']['field'] = 'field_glossary_type';
  $handler->display->display_options['fields']['field_glossary_type']['label'] = '';
  $handler->display->display_options['fields']['field_glossary_type']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Name (name_field) */
  $handler->display->display_options['sorts']['name_field_value']['id'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value']['table'] = 'field_data_name_field';
  $handler->display->display_options['sorts']['name_field_value']['field'] = 'name_field_value';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'msd_glossary' => 'msd_glossary',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_glossary_type_tid']['id'] = 'field_glossary_type_tid';
  $handler->display->display_options['filters']['field_glossary_type_tid']['table'] = 'field_data_field_glossary_type';
  $handler->display->display_options['filters']['field_glossary_type_tid']['field'] = 'field_glossary_type_tid';
  $handler->display->display_options['filters']['field_glossary_type_tid']['relationship'] = 'field_glossary_type_tid';
  /* Filter criterion: Taxonomy term: Name (name_field:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_name_field';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'about-topic/glossary-list';
  $translatables['glossary_list'] = array(
    t('Master'),
    t('Glossary'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
  );
  $export['glossary_list'] = $view;

  return $export;
}

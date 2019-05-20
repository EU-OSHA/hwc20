<?php
/**
 * @file
 * hwc_practical_tool.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hwc_practical_tool_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'practical_tools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Practical tools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Practical tools and guidance';
  $handler->display->display_options['css_class'] = 'view-search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@order Showing @start - @end from @total';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_et_id']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'practical_tool_title';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '1',
    'more_text' => 'See more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
    'field_formatter_class' => '',
  );
  /* Field: Search: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['label'] = '';
  $handler->display->display_options['fields']['search_api_relevance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['alter']['text'] = '<a href=\'[url]?destination=/en/tools-and-publications/practical-tools\'>See more</a>';
  $handler->display->display_options['fields']['search_api_relevance']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_country']['alter']['text'] = '<span class="views-label">Country: </span><span>[field_country]</span>';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_country']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_country']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Available in languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['label'] = '';
  $handler->display->display_options['fields']['field_available_in_languages']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_available_in_languages']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_available_in_languages']['alter']['text'] = '[field_available_in_languages]';
  $handler->display->display_options['fields']['field_available_in_languages']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_available_in_languages']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_available_in_languages']['delta_offset'] = '0';
  /* Field: Indexed Multilingual Content: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['label'] = '';
  $handler->display->display_options['fields']['field_provider']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_provider']['alter']['text'] = '<span class="views-label">Provider1:</span><span>[field_provider-value]</span>';
  $handler->display->display_options['fields']['field_provider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_provider']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Provider */
  $handler->display->display_options['fields']['field_fc_provider']['id'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_fc_provider']['field'] = 'field_fc_provider';
  $handler->display->display_options['fields']['field_fc_provider']['label'] = '';
  $handler->display->display_options['fields']['field_fc_provider']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fc_provider']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fc_provider']['alter']['text'] = '<span class="views-label">Provider:</span><span>[field_fc_provider]</span>';
  $handler->display->display_options['fields']['field_fc_provider']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_fc_provider']['alter']['preserve_tags'] = '<span>';
  $handler->display->display_options['fields']['field_fc_provider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fc_provider']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_fc_provider']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_fc_provider']['display'] = 'view';
  $handler->display->display_options['fields']['field_fc_provider']['view_mode'] = 'title_only';
  $handler->display->display_options['fields']['field_fc_provider']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Type of visualisation material */
  $handler->display->display_options['fields']['field_visualisation_material_typ']['id'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['field'] = 'field_visualisation_material_typ';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['label'] = '';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_visualisation_material_typ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_visualisation_material_typ']['alter']['text'] = '<span class="views-label">Type: </span><span>[field_visualisation_material_typ]</span>';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_visualisation_material_typ']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_visualisation_material_typ']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_visualisation_material_typ']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Year of publication */
  $handler->display->display_options['fields']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['fields']['field_publication_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
    'field_formatter_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="av-type">
[field_provider]
[field_fc_provider]<br />
[field_visualisation_material_typ]
[field_country]
<span class="views-label">Language: </span><span>[field_available_in_languages]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed Multilingual Content: Year of publication */
  $handler->display->display_options['sorts']['field_publication_year']['id'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_publication_year']['field'] = 'field_publication_year';
  $handler->display->display_options['sorts']['field_publication_year']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_publication_year']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_year']['expose']['label'] = 'Year of publication';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    12 => 0,
    13 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'title' => 'title',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'audio_visual' => 'audio_visual',
    'practical_tool' => 'practical_tool',
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
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 2;
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language_1']['id'] = 'search_api_language_1';
  $handler->display->display_options['filters']['search_api_language_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language_1']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language_1']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language_1']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'tools-and-publications/practical-tools';
  $translatables['practical_tools'] = array(
    t('Master'),
    t('Practical tools and guidance'),
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
    t('@order Showing @start - @end from @total'),
    t('No results'),
    t('Multilingual ID'),
    t('<a href=\'[url]?destination=/en/tools-and-publications/practical-tools\'>See more</a>'),
    t('.'),
    t(','),
    t('<span class="views-label">Country: </span><span>[field_country]</span>'),
    t('[field_available_in_languages]'),
    t('<span class="views-label">Provider1:</span><span>[field_provider-value]</span>'),
    t('<span class="views-label">Provider:</span><span>[field_fc_provider]</span>'),
    t('<span class="views-label">Type: </span><span>[field_visualisation_material_typ]</span>'),
    t('Year of publication'),
    t('<div class="av-type">
[field_provider]
[field_fc_provider]<br />
[field_visualisation_material_typ]
[field_country]
<span class="views-label">Language: </span><span>[field_available_in_languages]</span>
</div>'),
    t('Relevance'),
    t('Search'),
    t('Page'),
  );
  $export['practical_tools'] = $view;

  return $export;
}

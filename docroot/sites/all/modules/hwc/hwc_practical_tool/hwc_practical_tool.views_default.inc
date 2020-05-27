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
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'audio_visual',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 0,
      ),
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
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
      ),
    ),
    'field_available_in_languages_value' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
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
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '<div class="pager-total"><span>@start - @end / @total</span></div>';
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
  /* Field: Indexed Multilingual Content: Language of original language description	 */
  $handler->display->display_options['fields']['field_original_desc_language']['id'] = 'field_original_desc_language';
  $handler->display->display_options['fields']['field_original_desc_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_original_desc_language']['field'] = 'field_original_desc_language';
  $handler->display->display_options['fields']['field_original_desc_language']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
    'field_formatter_class' => '',
  );
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
  /* Field: Indexed Multilingual Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['label'] = '';
  $handler->display->display_options['fields']['field_title_original']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title_original']['element_wrapper_class'] = 'views-field-title-field';
  $handler->display->display_options['fields']['field_title_original']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_title_original']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Type of item */
  $handler->display->display_options['fields']['field_type_of_item']['id'] = 'field_type_of_item';
  $handler->display->display_options['fields']['field_type_of_item']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_type_of_item']['field'] = 'field_type_of_item';
  $handler->display->display_options['fields']['field_type_of_item']['label'] = '';
  $handler->display->display_options['fields']['field_type_of_item']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_type_of_item']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_type_of_item']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_type_of_item']['delta_offset'] = '0';
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['label'] = '';
  $handler->display->display_options['fields']['field_material_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_material_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_material_country']['alter']['text'] = '<span class="views-label">Country </span><span>[field_material_country]</span>';
  $handler->display->display_options['fields']['field_material_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_material_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_material_country']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_material_country']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['label'] = '';
  $handler->display->display_options['fields']['field_available_in_languages']['exclude'] = TRUE;
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
  /* Field: Indexed Multilingual Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="views-field">
<span class="views-label first">Type </span><span>[field_type_of_item]</span>
[field_material_country]
<span class="views-label">Language</span><span>[field_available_in_languages]</span>
';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  /* Field: Indexed Multilingual Content: Provider */
  $handler->display->display_options['fields']['field_msd_provider']['id'] = 'field_msd_provider';
  $handler->display->display_options['fields']['field_msd_provider']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_msd_provider']['field'] = 'field_msd_provider';
  $handler->display->display_options['fields']['field_msd_provider']['label'] = '';
  $handler->display->display_options['fields']['field_msd_provider']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_msd_provider']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_msd_provider']['alter']['preserve_tags'] = '<span>';
  $handler->display->display_options['fields']['field_msd_provider']['element_type'] = '0';
  $handler->display->display_options['fields']['field_msd_provider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_msd_provider']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_msd_provider']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_msd_provider']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_msd_provider']['display'] = 'id';
  $handler->display->display_options['fields']['field_msd_provider']['view_mode'] = 'title_only';
  $handler->display->display_options['fields']['field_msd_provider']['bypass_access'] = 0;
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
  /* Field: Indexed Multilingual Content: Description (original language) */
  $handler->display->display_options['fields']['field_body_original']['id'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_body_original']['field'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['label'] = '';
  $handler->display->display_options['fields']['field_body_original']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_body_original']['element_wrapper_class'] = 'views-field-body';
  $handler->display->display_options['fields']['field_body_original']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_body_original']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '1',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
    'field_formatter_class' => '',
  );
  /* Sort criterion: Indexed Multilingual Content: Date of Publication / Year  */
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
  /* Filter criterion: Languages: ISO 639 code (indexed) */
  $handler->display->display_options['filters']['field_available_in_languages_value']['id'] = 'field_available_in_languages_value';
  $handler->display->display_options['filters']['field_available_in_languages_value']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_available_in_languages_value']['field'] = 'field_available_in_languages_value';
  $handler->display->display_options['filters']['field_available_in_languages_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['operator_id'] = 'field_available_in_languages_value_op';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['operator'] = 'field_available_in_languages_value_op';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['identifier'] = 'field_available_in_languages_value';
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_available_in_languages_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_et_id']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Language of original language description	 */
  $handler->display->display_options['fields']['field_original_desc_language']['id'] = 'field_original_desc_language';
  $handler->display->display_options['fields']['field_original_desc_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_original_desc_language']['field'] = 'field_original_desc_language';
  $handler->display->display_options['fields']['field_original_desc_language']['settings'] = array(
    'format' => array(
      'name' => 'name',
      'iso' => 0,
      'name_native' => 0,
    ),
    'field_formatter_class' => '',
  );
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
  /* Field: Indexed Multilingual Content: Title (original) */
  $handler->display->display_options['fields']['field_title_original']['id'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_title_original']['field'] = 'field_title_original';
  $handler->display->display_options['fields']['field_title_original']['label'] = '';
  $handler->display->display_options['fields']['field_title_original']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title_original']['element_wrapper_class'] = 'views-field-title-field';
  $handler->display->display_options['fields']['field_title_original']['type'] = 'title_linked';
  $handler->display->display_options['fields']['field_title_original']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Type of item */
  $handler->display->display_options['fields']['field_type_of_item']['id'] = 'field_type_of_item';
  $handler->display->display_options['fields']['field_type_of_item']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_type_of_item']['field'] = 'field_type_of_item';
  $handler->display->display_options['fields']['field_type_of_item']['label'] = '';
  $handler->display->display_options['fields']['field_type_of_item']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_type_of_item']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_type_of_item']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_type_of_item']['delta_offset'] = '0';
  /* Field: Indexed Multilingual Content: Country */
  $handler->display->display_options['fields']['field_material_country']['id'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_material_country']['field'] = 'field_material_country';
  $handler->display->display_options['fields']['field_material_country']['label'] = '';
  $handler->display->display_options['fields']['field_material_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_material_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_material_country']['alter']['text'] = '<div class="conten-tags"><span class="views-label">Country </span><span>[field_material_country]</span></div>';
  $handler->display->display_options['fields']['field_material_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_material_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_material_country']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_material_country']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Languages */
  $handler->display->display_options['fields']['field_available_in_languages']['id'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_available_in_languages']['field'] = 'field_available_in_languages';
  $handler->display->display_options['fields']['field_available_in_languages']['label'] = '';
  $handler->display->display_options['fields']['field_available_in_languages']['exclude'] = TRUE;
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
  /* Field: Indexed Multilingual Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="views-field">
<div class="conten-tags"><span class="views-label first">Type </span><span>[field_type_of_item]</span></div>
[field_material_country]
<div class="conten-tags"><span class="views-label">Language</span><span>[field_available_in_languages]</span></div>
';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  /* Field: Indexed Multilingual Content: Provider */
  $handler->display->display_options['fields']['field_msd_provider']['id'] = 'field_msd_provider';
  $handler->display->display_options['fields']['field_msd_provider']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_msd_provider']['field'] = 'field_msd_provider';
  $handler->display->display_options['fields']['field_msd_provider']['label'] = '';
  $handler->display->display_options['fields']['field_msd_provider']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_msd_provider']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_msd_provider']['alter']['preserve_tags'] = '<span>';
  $handler->display->display_options['fields']['field_msd_provider']['element_type'] = '0';
  $handler->display->display_options['fields']['field_msd_provider']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_msd_provider']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_msd_provider']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_msd_provider']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_msd_provider']['display'] = 'id';
  $handler->display->display_options['fields']['field_msd_provider']['view_mode'] = 'title_only';
  $handler->display->display_options['fields']['field_msd_provider']['bypass_access'] = 0;
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
      'text' => 'text',
    ),
    'trim_preserve_tags' => '',
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Content: Description (original language) */
  $handler->display->display_options['fields']['field_body_original']['id'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_body_original']['field'] = 'field_body_original';
  $handler->display->display_options['fields']['field_body_original']['label'] = '';
  $handler->display->display_options['fields']['field_body_original']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_body_original']['element_wrapper_class'] = 'views-field-body';
  $handler->display->display_options['fields']['field_body_original']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['field_body_original']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '300',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '1',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 'text',
      'use_field_summary' => 0,
    ),
    'trim_preserve_tags' => '',
    'field_formatter_class' => '',
  );
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
    t('Select any filter and click on Apply to see results'),
    t('Advanced options'),
    t('Sort options'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('@total'),
    t('<div class="pager-total"><span>@start - @end / @total</span></div>'),
    t('No results'),
    t('Multilingual ID'),
    t('Language of original language description	'),
    t('<span class="views-label">Country </span><span>[field_material_country]</span>'),
    t('<div class="views-field">
<span class="views-label first">Type </span><span>[field_type_of_item]</span>
[field_material_country]
<span class="views-label">Language</span><span>[field_available_in_languages]</span>
'),
    t('Year of publication'),
    t('Relevance'),
    t('Search'),
    t('Language'),
    t('Page'),
    t('<div class="conten-tags"><span class="views-label">Country </span><span>[field_material_country]</span></div>'),
    t('<div class="views-field">
<div class="conten-tags"><span class="views-label first">Type </span><span>[field_type_of_item]</span></div>
[field_material_country]
<div class="conten-tags"><span class="views-label">Language</span><span>[field_available_in_languages]</span></div>
'),
  );
  $export['practical_tools'] = $view;

  return $export;
}

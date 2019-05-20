<?php
/**
 * @file
 * social_dashboard.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function social_dashboard_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'social_dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dashboard_item';
  $view->human_name = 'Social Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Social media centre';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'More Tweets';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'source' => array(
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
    'tags' => array(
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
  );
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'social_dashboard_column_plugin_style';
  $handler->display->display_options['row_plugin'] = 'social_dashboard_column_plugin_rows';
  $handler->display->display_options['row_options']['content'] = array(
    'name' => 'name',
    'content' => 'content',
    'social_id' => 'social_id',
    'source' => 'source',
    'tags' => 'tags',
    'timestamp' => 'timestamp',
    'dashboard_item_id' => 'dashboard_item_id',
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  /* Field: Dashboard item: Machine-readable name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'dashboard_item';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Dashboard item: Content */
  $handler->display->display_options['fields']['content']['id'] = 'content';
  $handler->display->display_options['fields']['content']['table'] = 'dashboard_item';
  $handler->display->display_options['fields']['content']['field'] = 'content';
  /* Field: Dashboard item: Social_id */
  $handler->display->display_options['fields']['social_id']['id'] = 'social_id';
  $handler->display->display_options['fields']['social_id']['table'] = 'dashboard_item';
  $handler->display->display_options['fields']['social_id']['field'] = 'social_id';
  /* Field: Dashboard item: Source */
  $handler->display->display_options['fields']['source']['id'] = 'source';
  $handler->display->display_options['fields']['source']['table'] = 'dashboard_item';
  $handler->display->display_options['fields']['source']['field'] = 'source';
  /* Field: Dashboard item: Tags */
  $handler->display->display_options['fields']['tags']['id'] = 'tags';
  $handler->display->display_options['fields']['tags']['table'] = 'dashboard_item';
  $handler->display->display_options['fields']['tags']['field'] = 'tags';
  /* Field: Dashboard item: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'dashboard_item';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  /* Field: Dashboard item: Internal, numeric dashboard item ID */
  $handler->display->display_options['fields']['dashboard_item_id']['id'] = 'dashboard_item_id';
  $handler->display->display_options['fields']['dashboard_item_id']['table'] = 'dashboard_item';
  $handler->display->display_options['fields']['dashboard_item_id']['field'] = 'dashboard_item_id';
  $handler->display->display_options['fields']['dashboard_item_id']['separator'] = '';
  /* Sort criterion: Dashboard item: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'dashboard_item';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  /* Filter criterion: Dashboard item: Source */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'dashboard_item';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['group'] = 1;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'Source';
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More Tweets';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['path'] = 'old-social-dashboard';
  $handler->display->display_options['menu']['title'] = 'Social media centre';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Latest Tweets */
  $handler = $view->new_display('block', 'Latest Tweets', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Tweets';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More social media';
  $handler->display->display_options['link_url'] = 'media-centre/social-media-centre';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Dashboard item: Source */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'dashboard_item';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['value'] = 'twitter';
  $handler->display->display_options['filters']['source']['group'] = 1;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'Source';
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
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
    17 => 0,
    16 => 0,
    14 => 0,
    15 => 0,
  );

  /* Display: Facebook world */
  $handler = $view->new_display('block', 'Facebook world', 'facebook');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More Tweets';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2><a href="__social_link__">Facebook</a></h2>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="more-link">
  <a href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork" target="_blank">
    See more on Facebook  </a>
</div>
';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Dashboard item: Source */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'dashboard_item';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['value'] = 'facebook';
  $handler->display->display_options['filters']['source']['group'] = 1;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'Source';
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
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

  /* Display: Twitter world */
  $handler = $view->new_display('block', 'Twitter world', 'twitter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More Tweets';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2><a href="__social_link__">Twitter</a></h2>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="more-link">
  <a href="https://twitter.com/eu_osha" target="_blank">
    See more on Twitter  </a>
</div>
';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Dashboard item: Source */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'dashboard_item';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['value'] = 'twitter';
  $handler->display->display_options['filters']['source']['group'] = 1;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'Source';
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
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

  /* Display: Linkedin world */
  $handler = $view->new_display('block', 'Linkedin world', 'linkedin');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More Tweets';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h2><a href="__social_link__">Linkedin</a></h2>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<div class="more-link">
  <a href="https://www.linkedin.com/company-beta/73952/" target="_blank">
    See more on Linkedin  </a>
</div>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Dashboard item: Source */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'dashboard_item';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['value'] = 'linkedin';
  $handler->display->display_options['filters']['source']['group'] = 1;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'Source';
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
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
  $translatables['social_dashboard'] = array(
    t('Master'),
    t('Social media centre'),
    t('More Tweets'),
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
    t('Load more'),
    t('Machine-readable name'),
    t('Content'),
    t('Social_id'),
    t('Source'),
    t('Tags'),
    t('Timestamp'),
    t('Internal, numeric dashboard item ID'),
    t('.'),
    t('Page'),
    t('Latest Tweets'),
    t('More social media'),
    t('Facebook world'),
    t('<h2><a href="__social_link__">Facebook</a></h2>'),
    t('<div class="more-link">
  <a href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork" target="_blank">
    See more on Facebook  </a>
</div>
'),
    t('Twitter world'),
    t('<h2><a href="__social_link__">Twitter</a></h2>'),
    t('<div class="more-link">
  <a href="https://twitter.com/eu_osha" target="_blank">
    See more on Twitter  </a>
</div>
'),
    t('Linkedin world'),
    t('<h2><a href="__social_link__">Linkedin</a></h2>'),
    t('<div class="more-link">
  <a href="https://www.linkedin.com/company-beta/73952/" target="_blank">
    See more on Linkedin  </a>
</div>'),
  );
  $export['social_dashboard'] = $view;

  return $export;
}

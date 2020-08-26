<?php
/**
 * @file
 * hwc_gpa.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hwc_gpa_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'gpexamples';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Good Practice Examples';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Good Practice Examples';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '999';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'good_practice_examples' => 'good_practice_examples',
    'publication_queue' => 0,
    'featured_press_release' => 0,
    'press_contacts_queue' => 0,
    'featured_partner_frontpage' => 0,
    'featured_gallery' => 0,
    'good_practice_exchange' => 0,
    'good_practice_exchange_intro' => 0,
    'homepage_about_the_topic' => 0,
    'most_popular_tools_and_examples' => 0,
    'tools_and_examples' => 0,
    'splash_campaign_material' => 0,
    'splash_banners' => 0,
    'splash_news' => 0,
    'splash_events' => 0,
    'press_room_news' => 0,
    'press_room_events' => 0,
    'european_week_events' => 0,
    'european_week_news' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<div class="slider-item">
    <div>
      <p>[title_field]</p>
    </div>
</div>';
  $handler->display->display_options['fields']['title_field']['alter']['max_length'] = '70';
  $handler->display->display_options['fields']['title_field']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '135',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Sort criterion: Content: Booklet (field_booklet) */
  $handler->display->display_options['sorts']['field_booklet_value']['id'] = 'field_booklet_value';
  $handler->display->display_options['sorts']['field_booklet_value']['table'] = 'field_data_field_booklet';
  $handler->display->display_options['sorts']['field_booklet_value']['field'] = 'field_booklet_value';
  $handler->display->display_options['sorts']['field_booklet_value']['order'] = 'DESC';
  /* Sort criterion: Nodequeue: In queue */
  $handler->display->display_options['sorts']['in_queue']['id'] = 'in_queue';
  $handler->display->display_options['sorts']['in_queue']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['in_queue']['field'] = 'in_queue';
  $handler->display->display_options['sorts']['in_queue']['relationship'] = 'nodequeue_rel';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Show on (field_show_on) */
  $handler->display->display_options['filters']['field_show_on_value']['id'] = 'field_show_on_value';
  $handler->display->display_options['filters']['field_show_on_value']['table'] = 'field_data_field_show_on';
  $handler->display->display_options['filters']['field_show_on_value']['field'] = 'field_show_on_value';
  $handler->display->display_options['filters']['field_show_on_value']['value'] = array(
    'GP Awards' => 'GP Awards',
  );
  /* Filter criterion: Content: Publication Type (field_publication_type) */
  $handler->display->display_options['filters']['field_publication_type_tid']['id'] = 'field_publication_type_tid';
  $handler->display->display_options['filters']['field_publication_type_tid']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['filters']['field_publication_type_tid']['field'] = 'field_publication_type_tid';
  $handler->display->display_options['filters']['field_publication_type_tid']['value'] = array(
    521 => '521',
  );
  $handler->display->display_options['filters']['field_publication_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_publication_type_tid']['vocabulary'] = 'publication_types';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['gpexamples'] = array(
    t('Master'),
    t('Good Practice Examples'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('<div class="slider-item">
    <div>
      <p>[title_field]</p>
    </div>
</div>'),
    t('Block'),
  );
  $export['gpexamples'] = $view;

  return $export;
}

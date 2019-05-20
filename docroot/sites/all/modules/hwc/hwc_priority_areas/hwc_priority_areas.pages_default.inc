<?php
/**
 * @file
 * hwc_priority_areas.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hwc_priority_areas_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_b2a712c5-d2ec-4e5a-8819-7725801aa458';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Priority area',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'priority-detail',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'priority_area' => 'priority_area',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'About the topic
Topics
%term:name_field',
    'panels_breadcrumbs_paths' => '<none>
topics
<none>
',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
    'center' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '44fe0d5e-a782-4a04-9c93-ff1874ad4bb5';
  $display->storage_type = 'unknown';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-232855d9-0adc-41cf-a050-f78c365d0426';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'field_formatter_class' => '',
      'image_style' => 'article_crop_1920',
      'image_link' => '',
    ),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '232855d9-0adc-41cf-a050-f78c365d0426';
  $display->content['new-232855d9-0adc-41cf-a050-f78c365d0426'] = $pane;
  $display->panels['center'][0] = 'new-232855d9-0adc-41cf-a050-f78c365d0426';
  $pane = new stdClass();
  $pane->pid = 'new-2b3436b0-cae6-4242-94b7-a7ab34fb5580';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:name_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => 'h1',
      'title_link' => '',
      'title_class' => '',
      'field_formatter_class' => '',
      'trim_length' => '600',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
    ),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'term_title topic_title',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2b3436b0-cae6-4242-94b7-a7ab34fb5580';
  $display->content['new-2b3436b0-cae6-4242-94b7-a7ab34fb5580'] = $pane;
  $display->panels['center'][1] = 'new-2b3436b0-cae6-4242-94b7-a7ab34fb5580';
  $pane = new stdClass();
  $pane->pid = 'new-cfe72b59-3899-4d8e-a789-9bc596640000';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_introduction_text';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '300',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'intro_text term_intro_text col-sm-12 col-md-10 col-md-offset-1',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cfe72b59-3899-4d8e-a789-9bc596640000';
  $display->content['new-cfe72b59-3899-4d8e-a789-9bc596640000'] = $pane;
  $display->panels['center'][2] = 'new-cfe72b59-3899-4d8e-a789-9bc596640000';
  $pane = new stdClass();
  $pane->pid = 'new-24f5a734-25a7-43d0-8984-23bfc1e4b712';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_links_and_info';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '24f5a734-25a7-43d0-8984-23bfc1e4b712';
  $display->content['new-24f5a734-25a7-43d0-8984-23bfc1e4b712'] = $pane;
  $display->panels['center'][3] = 'new-24f5a734-25a7-43d0-8984-23bfc1e4b712';
  $pane = new stdClass();
  $pane->pid = 'new-521bab7b-ff93-477c-89ab-c94f70f631e0';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'topic_related';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'hwc_priority_areas',
        'settings' => array(
          'checkbox' => 'highlights',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '2',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'highlights',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'highlights col-sm-12 col-md-10 col-md-offset-1',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '521bab7b-ff93-477c-89ab-c94f70f631e0';
  $display->content['new-521bab7b-ff93-477c-89ab-c94f70f631e0'] = $pane;
  $display->panels['center'][4] = 'new-521bab7b-ff93-477c-89ab-c94f70f631e0';
  $pane = new stdClass();
  $pane->pid = 'new-a9d10346-b230-4170-8fee-b4a2b27fdfd8';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'topic_related';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'hwc_priority_areas',
        'settings' => array(
          'checkbox' => 'case_studies',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '20',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'case_studies',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'case_studies col-sm-12 col-md-10 col-md-offset-1',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a9d10346-b230-4170-8fee-b4a2b27fdfd8';
  $display->content['new-a9d10346-b230-4170-8fee-b4a2b27fdfd8'] = $pane;
  $display->panels['center'][5] = 'new-a9d10346-b230-4170-8fee-b4a2b27fdfd8';
  $pane = new stdClass();
  $pane->pid = 'new-cc8679eb-3fca-47b3-860e-9679e824098d';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'topic_related';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'hwc_priority_areas',
        'settings' => array(
          'checkbox' => 'tools_guidance',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '20',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'tools_and_guidance',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'tools_and_guidance col-sm-12 col-md-10 col-md-offset-1',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'cc8679eb-3fca-47b3-860e-9679e824098d';
  $display->content['new-cc8679eb-3fca-47b3-860e-9679e824098d'] = $pane;
  $display->panels['center'][6] = 'new-cc8679eb-3fca-47b3-860e-9679e824098d';
  $pane = new stdClass();
  $pane->pid = 'new-3419489e-f8e4-4e04-ba2b-afb0f0f06544';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'topic_related';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'hwc_priority_areas',
        'settings' => array(
          'checkbox' => 'publications',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '20',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'publications',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'publications col-sm-12 col-md-10 col-md-offset-1',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '3419489e-f8e4-4e04-ba2b-afb0f0f06544';
  $display->content['new-3419489e-f8e4-4e04-ba2b-afb0f0f06544'] = $pane;
  $display->panels['center'][7] = 'new-3419489e-f8e4-4e04-ba2b-afb0f0f06544';
  $pane = new stdClass();
  $pane->pid = 'new-3612da0a-99af-4965-af71-093a59605e52';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_etool';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'hwc_priority_areas',
        'settings' => array(
          'checkbox' => 'e_tool',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'e_tools col-sm-12 col-md-10 col-md-offset-1',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '3612da0a-99af-4965-af71-093a59605e52';
  $display->content['new-3612da0a-99af-4965-af71-093a59605e52'] = $pane;
  $display->panels['center'][8] = 'new-3612da0a-99af-4965-af71-093a59605e52';
  $pane = new stdClass();
  $pane->pid = 'new-181b6a0c-9a3e-4d64-88b5-2287352c1203';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_priority_areas-hwc_pa_related_links';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'hwc_priority_areas',
        'settings' => array(
          'checkbox' => 'related_links',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'related_links col-sm-12 col-md-10 col-md-offset-1',
  );
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '181b6a0c-9a3e-4d64-88b5-2287352c1203';
  $display->content['new-181b6a0c-9a3e-4d64-88b5-2287352c1203'] = $pane;
  $display->panels['center'][9] = 'new-181b6a0c-9a3e-4d64-88b5-2287352c1203';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_b2a712c5-d2ec-4e5a-8819-7725801aa458'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hwc_priority_areas_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'priority_areas';
  $page->task = 'page';
  $page->admin_title = 'Priority areas';
  $page->admin_description = '';
  $page->path = 'about-topic/priority-areas';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_priority_areas__panel_context_c3833a65-5d26-4679-bf4e-f10d7e52171f';
  $handler->task = 'page';
  $handler->subtask = 'priority_areas';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Content',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '3291',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'About the topic
Priority areas',
    'panels_breadcrumbs_paths' => '<none>
<none>
',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'container page-topics',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
        'hide_empty' => 0,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
    'center' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'feb09f9c-dfae-4f43-bc0d-ca2a7b2ece37';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_topics__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-93f0db8a-ee08-490f-8fc1-f06581dd6878';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '300',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'summary_handler' => 'full',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'context_entity:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '93f0db8a-ee08-490f-8fc1-f06581dd6878';
  $display->content['new-93f0db8a-ee08-490f-8fc1-f06581dd6878'] = $pane;
  $display->panels['center'][0] = 'new-93f0db8a-ee08-490f-8fc1-f06581dd6878';
  $pane = new stdClass();
  $pane->pid = 'new-b60bf7ab-e6fb-4e7c-907e-30413b66de89';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'topics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b60bf7ab-e6fb-4e7c-907e-30413b66de89';
  $display->content['new-b60bf7ab-e6fb-4e7c-907e-30413b66de89'] = $pane;
  $display->panels['center'][1] = 'new-b60bf7ab-e6fb-4e7c-907e-30413b66de89';
  $pane = new stdClass();
  $pane->pid = 'new-6a55c468-41d8-420a-9dc4-451692b5fa73';
  $pane->panel = 'center';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title_field | [site:name]',
    'form_build_id' => 'form-OaVywIV8FHhAv6txtxWr_minuq4CRFXpEROSFnQVAHI',
    'form_token' => 'kjaBuDPfwwk9IOgu2xytFpt-cEcnpH8UHOvPU-FJ6fY',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6a55c468-41d8-420a-9dc4-451692b5fa73';
  $display->content['new-6a55c468-41d8-420a-9dc4-451692b5fa73'] = $pane;
  $display->panels['center'][2] = 'new-6a55c468-41d8-420a-9dc4-451692b5fa73';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['priority_areas'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'topics';
  $page->task = 'page';
  $page->admin_title = 'Topics';
  $page->admin_description = '';
  $page->path = 'topics';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_topics__panel';
  $handler->task = 'page';
  $handler->subtask = 'topics';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Content',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '3291',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'About the topic
Topics',
    'panels_breadcrumbs_paths' => '<none>
<none>
',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'container',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
        'hide_empty' => 0,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
    'center' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'feb09f9c-dfae-4f43-bc0d-ca2a7b2ece37';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_topics__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-93f0db8a-ee08-490f-8fc1-f06581dd6878';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '300',
      'trim_type' => 'chars',
      'trim_suffix' => '...',
      'trim_link' => '0',
      'more_link' => '0',
      'more_text' => 'Read more',
      'summary_handler' => 'full',
      'trim_options' => array(
        'text' => 0,
      ),
      'trim_preserve_tags' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'context_entity:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '93f0db8a-ee08-490f-8fc1-f06581dd6878';
  $display->content['new-93f0db8a-ee08-490f-8fc1-f06581dd6878'] = $pane;
  $display->panels['center'][0] = 'new-93f0db8a-ee08-490f-8fc1-f06581dd6878';
  $pane = new stdClass();
  $pane->pid = 'new-b60bf7ab-e6fb-4e7c-907e-30413b66de89';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'topics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b60bf7ab-e6fb-4e7c-907e-30413b66de89';
  $display->content['new-b60bf7ab-e6fb-4e7c-907e-30413b66de89'] = $pane;
  $display->panels['center'][1] = 'new-b60bf7ab-e6fb-4e7c-907e-30413b66de89';
  $pane = new stdClass();
  $pane->pid = 'new-6a55c468-41d8-420a-9dc4-451692b5fa73';
  $pane->panel = 'center';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title_field | [site:name]',
    'form_build_id' => 'form-OaVywIV8FHhAv6txtxWr_minuq4CRFXpEROSFnQVAHI',
    'form_token' => 'kjaBuDPfwwk9IOgu2xytFpt-cEcnpH8UHOvPU-FJ6fY',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6a55c468-41d8-420a-9dc4-451692b5fa73';
  $display->content['new-6a55c468-41d8-420a-9dc4-451692b5fa73'] = $pane;
  $display->panels['center'][2] = 'new-6a55c468-41d8-420a-9dc4-451692b5fa73';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['topics'] = $page;

  return $pages;

}

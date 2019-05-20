<?php
/**
 * @file
 * osha_publication.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function osha_publication_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__publication_detail';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Publication detail',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'publication_detail',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'publication' => 'publication',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
          0 => 2,
          1 => 'main-row',
          2 => 1,
          3 => 3,
        ),
        'parent' => 'canvas',
        'class' => '',
        'hide_empty' => 0,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-9',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-3',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_content',
        ),
        'parent' => 'main',
        'class' => 'Middle row',
        'hide_empty' => 0,
      ),
      'middle_content' => array(
        'type' => 'region',
        'title' => 'Middle content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'title',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'title' => array(
        'type' => 'region',
        'title' => 'Title',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'additional_resources',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'additional_resources' => array(
        'type' => 'region',
        'title' => 'Additional resources',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'center' => NULL,
      'middle_content' => NULL,
      'title' => NULL,
      'additional_resources' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '6e25d777-3a5d-4043-8d80-fcd57f19c458';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__publication_detail';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-249e5039-acb1-431a-88ef-b9e74027f48a';
  $pane->panel = 'additional_resources';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_aditional_resources';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'field_formatter_class' => '',
      'view_mode' => 'default',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '249e5039-acb1-431a-88ef-b9e74027f48a';
  $display->content['new-249e5039-acb1-431a-88ef-b9e74027f48a'] = $pane;
  $display->panels['additional_resources'][0] = 'new-249e5039-acb1-431a-88ef-b9e74027f48a';
  $pane = new stdClass();
  $pane->pid = 'new-ca8d0cda-8c56-4d8c-a00f-579070d4cd5a';
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
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'ca8d0cda-8c56-4d8c-a00f-579070d4cd5a';
  $display->content['new-ca8d0cda-8c56-4d8c-a00f-579070d4cd5a'] = $pane;
  $display->panels['center'][0] = 'new-ca8d0cda-8c56-4d8c-a00f-579070d4cd5a';
  $pane = new stdClass();
  $pane->pid = 'new-c45d4b5a-33fa-4f5a-9759-b17183eb9d1e';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_file';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_all_group_mimetype',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'c45d4b5a-33fa-4f5a-9759-b17183eb9d1e';
  $display->content['new-c45d4b5a-33fa-4f5a-9759-b17183eb9d1e'] = $pane;
  $display->panels['center'][1] = 'new-c45d4b5a-33fa-4f5a-9759-b17183eb9d1e';
  $pane = new stdClass();
  $pane->pid = 'new-591e90db-25af-449e-a621-b9b57508ccaa';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_cover_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'large_crop_480',
      'image_link' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '591e90db-25af-449e-a621-b9b57508ccaa';
  $display->content['new-591e90db-25af-449e-a621-b9b57508ccaa'] = $pane;
  $display->panels['left'][0] = 'new-591e90db-25af-449e-a621-b9b57508ccaa';
  $pane = new stdClass();
  $pane->pid = 'new-7b48525d-dd43-4a0f-abb7-ea6da1bc1890';
  $pane->panel = 'middle_content';
  $pane->type = 'summary_label';
  $pane->subtype = 'summary_label';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7b48525d-dd43-4a0f-abb7-ea6da1bc1890';
  $display->content['new-7b48525d-dd43-4a0f-abb7-ea6da1bc1890'] = $pane;
  $display->panels['middle_content'][0] = 'new-7b48525d-dd43-4a0f-abb7-ea6da1bc1890';
  $pane = new stdClass();
  $pane->pid = 'new-282b4a45-002d-45fb-924b-2e48fdf50bd1';
  $pane->panel = 'middle_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_related_publications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'publication_twin_publications',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
      'links' => 1,
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '282b4a45-002d-45fb-924b-2e48fdf50bd1';
  $display->content['new-282b4a45-002d-45fb-924b-2e48fdf50bd1'] = $pane;
  $display->panels['middle_content'][1] = 'new-282b4a45-002d-45fb-924b-2e48fdf50bd1';
  $pane = new stdClass();
  $pane->pid = 'new-09c435fb-7a35-4031-9793-ffc9ff133f02';
  $pane->panel = 'middle_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_publication_related_res';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'field_file',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '09c435fb-7a35-4031-9793-ffc9ff133f02';
  $display->content['new-09c435fb-7a35-4031-9793-ffc9ff133f02'] = $pane;
  $display->panels['middle_content'][2] = 'new-09c435fb-7a35-4031-9793-ffc9ff133f02';
  $pane = new stdClass();
  $pane->pid = 'new-b06a0bea-1c65-46a2-9e97-a27764fa2bb7';
  $pane->panel = 'title';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'osha_day_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'osha_date_theme' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'b06a0bea-1c65-46a2-9e97-a27764fa2bb7';
  $display->content['new-b06a0bea-1c65-46a2-9e97-a27764fa2bb7'] = $pane;
  $display->panels['title'][0] = 'new-b06a0bea-1c65-46a2-9e97-a27764fa2bb7';
  $pane = new stdClass();
  $pane->pid = 'new-3c002ad1-74fe-4ad1-9a02-a6a97b5f53ce';
  $pane->panel = 'title';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => 'h2',
      'title_link' => '',
      'title_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '3c002ad1-74fe-4ad1-9a02-a6a97b5f53ce';
  $display->content['new-3c002ad1-74fe-4ad1-9a02-a6a97b5f53ce'] = $pane;
  $display->panels['title'][1] = 'new-3c002ad1-74fe-4ad1-9a02-a6a97b5f53ce';
  $pane = new stdClass();
  $pane->pid = 'new-7dd000ef-5677-4c38-965a-dd0004e3a412';
  $pane->panel = 'title';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_publication_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7dd000ef-5677-4c38-965a-dd0004e3a412';
  $display->content['new-7dd000ef-5677-4c38-965a-dd0004e3a412'] = $pane;
  $display->panels['title'][2] = 'new-7dd000ef-5677-4c38-965a-dd0004e3a412';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-591e90db-25af-449e-a621-b9b57508ccaa';
  $handler->conf['display'] = $display;
  $export['node_view__publication_detail'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function osha_publication_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'case_studies';
  $page->task = 'page';
  $page->admin_title = 'Case studies';
  $page->admin_description = '';
  $page->path = 'tools-and-publications/case-studies';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_case_studies__panel_context_68462a27-ad1d-4253-b1a2-93f849f2c5a3';
  $handler->task = 'page';
  $handler->subtask = 'case_studies';
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
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '11a635b4-1f19-4fe1-930e-1a26cb5c344a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_case_studies__panel_context_68462a27-ad1d-4253-b1a2-93f849f2c5a3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f9e6150c-417b-46b1-ad86-5cbe6cbbf358';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '140',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'section-introduction',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f9e6150c-417b-46b1-ad86-5cbe6cbbf358';
  $display->content['new-f9e6150c-417b-46b1-ad86-5cbe6cbbf358'] = $pane;
  $display->panels['center'][0] = 'new-f9e6150c-417b-46b1-ad86-5cbe6cbbf358';
  $pane = new stdClass();
  $pane->pid = 'new-4989b0bb-baba-4d1a-9ca8-a3b068672c20';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'osha_publication-osha_case_studies_listing';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4989b0bb-baba-4d1a-9ca8-a3b068672c20';
  $display->content['new-4989b0bb-baba-4d1a-9ca8-a3b068672c20'] = $pane;
  $display->panels['center'][1] = 'new-4989b0bb-baba-4d1a-9ca8-a3b068672c20';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-f9e6150c-417b-46b1-ad86-5cbe6cbbf358';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['case_studies'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'publications_listing';
  $page->task = 'page';
  $page->admin_title = 'Publications listing';
  $page->admin_description = '';
  $page->path = 'tools-and-publications/publications';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_publications_listing__panel_context_03338832-cd5a-4fcc-9e3c-e69cbf5fb5e1';
  $handler->task = 'page';
  $handler->subtask = 'publications_listing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Publications listing',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Publications';
  $display->uuid = '928827f4-5866-4902-8a91-a325c693a5ce';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_publications_listing__panel_context_03338832-cd5a-4fcc-9e3c-e69cbf5fb5e1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e7a9ab38-c830-4b2e-9e23-f49f161509c1';
  $pane->panel = 'middle';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '105',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'section-introduction',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e7a9ab38-c830-4b2e-9e23-f49f161509c1';
  $display->content['new-e7a9ab38-c830-4b2e-9e23-f49f161509c1'] = $pane;
  $display->panels['middle'][0] = 'new-e7a9ab38-c830-4b2e-9e23-f49f161509c1';
  $pane = new stdClass();
  $pane->pid = 'new-0982669a-0bb3-4fb4-ac9b-818d02386d48';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'osha_publication-osha_publicatio_slideshow';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0982669a-0bb3-4fb4-ac9b-818d02386d48';
  $display->content['new-0982669a-0bb3-4fb4-ac9b-818d02386d48'] = $pane;
  $display->panels['middle'][1] = 'new-0982669a-0bb3-4fb4-ac9b-818d02386d48';
  $pane = new stdClass();
  $pane->pid = 'new-f5de493b-9610-4004-94cd-4bdb77aebd96';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'osha_publication-osha_publication_listing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f5de493b-9610-4004-94cd-4bdb77aebd96';
  $display->content['new-f5de493b-9610-4004-94cd-4bdb77aebd96'] = $pane;
  $display->panels['middle'][2] = 'new-f5de493b-9610-4004-94cd-4bdb77aebd96';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-e7a9ab38-c830-4b2e-9e23-f49f161509c1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['publications_listing'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tools_publications';
  $page->task = 'page';
  $page->admin_title = 'Tools&Publications';
  $page->admin_description = '';
  $page->path = 'tools-and-publications';
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
  $handler->name = 'page_tools_publications__panel';
  $handler->task = 'page';
  $handler->subtask = 'tools_publications';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Publications landing page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'page-publications',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Content',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '3026',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Token',
        'keyword' => 'token',
        'name' => 'token',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => '%node:title_field',
    'panels_breadcrumbs_paths' => '<none>',
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
  $display->title = '%node:title-field';
  $display->uuid = '4dca828e-d49f-4084-86ac-d3ee676fbd4e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_tools_publications__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-04e92c42-5718-45fe-be2f-bd65740f2b86';
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
    'formatter_settings' => array(),
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
  $pane->uuid = '04e92c42-5718-45fe-be2f-bd65740f2b86';
  $display->content['new-04e92c42-5718-45fe-be2f-bd65740f2b86'] = $pane;
  $display->panels['center'][0] = 'new-04e92c42-5718-45fe-be2f-bd65740f2b86';
  $pane = new stdClass();
  $pane->pid = 'new-6ce70762-490d-4762-aa31-cc8a80c809ee';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'publication_type';
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
  $pane->uuid = '6ce70762-490d-4762-aa31-cc8a80c809ee';
  $display->content['new-6ce70762-490d-4762-aa31-cc8a80c809ee'] = $pane;
  $display->panels['center'][1] = 'new-6ce70762-490d-4762-aa31-cc8a80c809ee';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tools_publications'] = $page;

  return $pages;

}

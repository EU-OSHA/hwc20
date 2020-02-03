<?php
/**
 * @file
 * hwc_good_practice_exchange.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hwc_good_practice_exchange_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__document';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 8;
  $handler->conf = array(
    'title' => 'Document',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'document',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'document' => 'document',
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
  $pane->pid = 'new-6b8463b6-4dbd-4dc0-9dd0-f20b068ff349';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_summary';
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
  $pane->uuid = '6b8463b6-4dbd-4dc0-9dd0-f20b068ff349';
  $display->content['new-6b8463b6-4dbd-4dc0-9dd0-f20b068ff349'] = $pane;
  $display->panels['center'][0] = 'new-6b8463b6-4dbd-4dc0-9dd0-f20b068ff349';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ca8d0cda-8c56-4d8c-a00f-579070d4cd5a';
  $display->content['new-ca8d0cda-8c56-4d8c-a00f-579070d4cd5a'] = $pane;
  $display->panels['center'][1] = 'new-ca8d0cda-8c56-4d8c-a00f-579070d4cd5a';
  $pane = new stdClass();
  $pane->pid = 'new-cbd97dbd-1d00-4bdd-b5ee-29b2a01b2972';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_good_practice_exchange-gpep_document_organisation';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cbd97dbd-1d00-4bdd-b5ee-29b2a01b2972';
  $display->content['new-cbd97dbd-1d00-4bdd-b5ee-29b2a01b2972'] = $pane;
  $display->panels['center'][2] = 'new-cbd97dbd-1d00-4bdd-b5ee-29b2a01b2972';
  $pane = new stdClass();
  $pane->pid = 'new-24a5223b-1e11-41eb-a85b-96b5289b8786';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_document_files';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'field_collection_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => '',
      'translate' => 'Translate',
      'delete' => '',
      'add' => '',
      'description' => 1,
      'field_formatter_class' => '',
      'view_mode' => 'full',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '24a5223b-1e11-41eb-a85b-96b5289b8786';
  $display->content['new-24a5223b-1e11-41eb-a85b-96b5289b8786'] = $pane;
  $display->panels['center'][3] = 'new-24a5223b-1e11-41eb-a85b-96b5289b8786';
  $pane = new stdClass();
  $pane->pid = 'new-51e8633a-63eb-4c3c-9312-f2d93599044f';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_good_practice_exchange-gpep_document_links';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '51e8633a-63eb-4c3c-9312-f2d93599044f';
  $display->content['new-51e8633a-63eb-4c3c-9312-f2d93599044f'] = $pane;
  $display->panels['center'][4] = 'new-51e8633a-63eb-4c3c-9312-f2d93599044f';
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
  $pane->pid = 'new-a7a838d1-9404-4e02-9bd8-ed5473648df6';
  $pane->panel = 'title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_good_practice_exchange-gpepbacklink';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a7a838d1-9404-4e02-9bd8-ed5473648df6';
  $display->content['new-a7a838d1-9404-4e02-9bd8-ed5473648df6'] = $pane;
  $display->panels['title'][0] = 'new-a7a838d1-9404-4e02-9bd8-ed5473648df6';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b06a0bea-1c65-46a2-9e97-a27764fa2bb7';
  $display->content['new-b06a0bea-1c65-46a2-9e97-a27764fa2bb7'] = $pane;
  $display->panels['title'][1] = 'new-b06a0bea-1c65-46a2-9e97-a27764fa2bb7';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3c002ad1-74fe-4ad1-9a02-a6a97b5f53ce';
  $display->content['new-3c002ad1-74fe-4ad1-9a02-a6a97b5f53ce'] = $pane;
  $display->panels['title'][2] = 'new-3c002ad1-74fe-4ad1-9a02-a6a97b5f53ce';
  $pane = new stdClass();
  $pane->pid = 'new-938184b7-4c8d-4cdd-9fd0-39031998af2c';
  $pane->panel = 'title';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_document_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'taxonomy_term_reference_plain',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '938184b7-4c8d-4cdd-9fd0-39031998af2c';
  $display->content['new-938184b7-4c8d-4cdd-9fd0-39031998af2c'] = $pane;
  $display->panels['title'][3] = 'new-938184b7-4c8d-4cdd-9fd0-39031998af2c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-591e90db-25af-449e-a621-b9b57508ccaa';
  $handler->conf['display'] = $display;
  $export['node_view__document'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hwc_good_practice_exchange_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'good_practice_exchange_initiative_page';
  $page->task = 'page';
  $page->admin_title = 'Good practice exchange initiative page';
  $page->admin_description = '';
  $page->path = 'good-practice-exchange-initiative';
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
  $handler->name = 'page_good_practice_exchange_initiative_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'good_practice_exchange_initiative_page';
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
        'identifier' => 'Get involved in Good Practice exchange initiative',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '3301',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Campaign Partners
Get involved in Good Practice exchange initiative
',
    'panels_breadcrumbs_paths' => '<none>
<none>',
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
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = 'Get involved in Good Practice exchange initiative';
  $display->uuid = '72d72c0a-0a8f-4e93-b39f-1a905949c656';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_good_practice_exchange_initiative_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-258be0c5-d49a-4898-b207-8b1b2d5d37f3';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc-page_share_widget';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '258be0c5-d49a-4898-b207-8b1b2d5d37f3';
  $display->content['new-258be0c5-d49a-4898-b207-8b1b2d5d37f3'] = $pane;
  $display->panels['center'][0] = 'new-258be0c5-d49a-4898-b207-8b1b2d5d37f3';
  $pane = new stdClass();
  $pane->pid = 'new-d7c8c160-16f0-403a-bea5-0b0bac791b1c';
  $pane->panel = 'center';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'context_entity:node_1',
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
  $pane->uuid = 'd7c8c160-16f0-403a-bea5-0b0bac791b1c';
  $display->content['new-d7c8c160-16f0-403a-bea5-0b0bac791b1c'] = $pane;
  $display->panels['center'][1] = 'new-d7c8c160-16f0-403a-bea5-0b0bac791b1c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['good_practice_exchange_initiative_page'] = $page;

  return $pages;

}

<?php
/**
 * @file
 * osha_newsletter.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function osha_newsletter_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_e5608b83-de87-4dc2-b38d-a924687f8249';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Newsletter custom page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Content: ID',
        'keyword' => 'node_nid',
        'name' => 'entity:node',
        'entity_id' => '129',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'node/129',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
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
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'left',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-6 col-sm-6 col-xs-12',
        'hide_empty' => 1,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-6 col-sm-6 col-xs-12',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'title',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 1,
      ),
      'title' => array(
        'type' => 'region',
        'title' => 'title',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-md-12',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'bottom' => array(
        'type' => 'region',
        'title' => 'Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'share-bottom',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'title' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'adc7b505-859a-4f9b-b4c8-d4521309bbbe';
  $display->storage_type = 'unknown';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6d2d9e1e-9d24-49fb-a150-f65f9a820d65';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'osha_newsletter-osha_newsletter_subscribe_extra';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
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
  $pane->uuid = '6d2d9e1e-9d24-49fb-a150-f65f9a820d65';
  $display->content['new-6d2d9e1e-9d24-49fb-a150-f65f9a820d65'] = $pane;
  $display->panels['center'][0] = 'new-6d2d9e1e-9d24-49fb-a150-f65f9a820d65';
  $pane = new stdClass();
  $pane->pid = 'new-13da2bb0-64c7-4864-bfa1-3e0097a1a771';
  $pane->panel = 'center';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:share_widget';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
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
  $pane->uuid = '13da2bb0-64c7-4864-bfa1-3e0097a1a771';
  $display->content['new-13da2bb0-64c7-4864-bfa1-3e0097a1a771'] = $pane;
  $display->panels['center'][1] = 'new-13da2bb0-64c7-4864-bfa1-3e0097a1a771';
  $pane = new stdClass();
  $pane->pid = 'new-2222cba6-cbc9-482c-b9aa-11c6e7aaee39';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'osha_newsletter-osha_newsletter_latest';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Latest newsletters',
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
  $pane->uuid = '2222cba6-cbc9-482c-b9aa-11c6e7aaee39';
  $display->content['new-2222cba6-cbc9-482c-b9aa-11c6e7aaee39'] = $pane;
  $display->panels['left'][0] = 'new-2222cba6-cbc9-482c-b9aa-11c6e7aaee39';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_e5608b83-de87-4dc2-b38d-a924687f8249'] = $handler;

  return $export;
}

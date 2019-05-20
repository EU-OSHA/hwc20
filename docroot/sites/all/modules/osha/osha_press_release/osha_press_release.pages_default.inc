<?php
/**
 * @file
 * osha_press_release.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function osha_press_release_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'press_room';
  $page->task = 'page';
  $page->admin_title = 'Press room';
  $page->admin_description = '';
  $page->path = 'media-centre/press-room';
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
  $handler->name = 'page_press_room__panel_context_dc272202-981f-4f4f-a5a9-77d618920cda';
  $handler->task = 'page';
  $handler->subtask = 'press_room';
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
          0 => 'main-row',
          1 => 1,
        ),
        'parent' => 'canvas',
        'class' => '',
        'hide_empty' => 0,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 2,
        ),
        'parent' => 'main',
        'class' => 'press-room-blocks-row container',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 4,
          1 => 5,
        ),
        'class' => 'press-room-block-column',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_content',
        ),
        'parent' => '2',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'press_room_content',
        ),
        'parent' => '2',
        'class' => 'press-room-content-row',
        'hide_empty' => 0,
      ),
      'press_room_content' => array(
        'type' => 'region',
        'title' => 'Press Room content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => 'press-room-content-region container',
        'hide_empty' => 0,
      ),
      'middle_content' => array(
        'type' => 'region',
        'title' => 'Middle content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'content' => NULL,
      'content_' => NULL,
      'press_room_content' => NULL,
      'middle_content' => NULL,
      'right_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Press room';
  $display->uuid = '10d09353-21ff-4a10-998c-3270e13d7521';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_press_room__panel_context_dc272202-981f-4f4f-a5a9-77d618920cda';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9d10b397-49da-4a63-ba51-0166313a0939';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '179',
    'links' => 0,
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
  $pane->uuid = '9d10b397-49da-4a63-ba51-0166313a0939';
  $display->content['new-9d10b397-49da-4a63-ba51-0166313a0939'] = $pane;
  $display->panels['center'][0] = 'new-9d10b397-49da-4a63-ba51-0166313a0939';
  $pane = new stdClass();
  $pane->pid = 'new-9859b6ee-8b24-4df5-92eb-e866629be34d';
  $pane->panel = 'middle_content';
  $pane->type = 'panels_mini';
  $pane->subtype = 'press_room_blocks';
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
  $pane->uuid = '9859b6ee-8b24-4df5-92eb-e866629be34d';
  $display->content['new-9859b6ee-8b24-4df5-92eb-e866629be34d'] = $pane;
  $display->panels['middle_content'][0] = 'new-9859b6ee-8b24-4df5-92eb-e866629be34d';
  $pane = new stdClass();
  $pane->pid = 'new-c79a41b1-35b5-4f7f-a5f5-c26d6c4892dd';
  $pane->panel = 'press_room_content';
  $pane->type = 'views';
  $pane->subtype = 'press_releases';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page',
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
  $pane->uuid = 'c79a41b1-35b5-4f7f-a5f5-c26d6c4892dd';
  $display->content['new-c79a41b1-35b5-4f7f-a5f5-c26d6c4892dd'] = $pane;
  $display->panels['press_room_content'][0] = 'new-c79a41b1-35b5-4f7f-a5f5-c26d6c4892dd';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-9d10b397-49da-4a63-ba51-0166313a0939';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['press_room'] = $page;

  return $pages;

}

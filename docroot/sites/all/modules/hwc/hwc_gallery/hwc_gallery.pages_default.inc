<?php
/**
 * @file
 * hwc_gallery.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hwc_gallery_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'photo_gallery';
  $page->task = 'page';
  $page->admin_title = 'Photo gallery';
  $page->admin_description = '';
  $page->path = 'media-center/photo-gallery';
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
  $handler->name = 'page_photo_gallery__panel_context_65a187a2-6b2c-4848-9c3e-1a7099fb526e';
  $handler->task = 'page';
  $handler->subtask = 'photo_gallery';
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
  $display->uuid = '4b23c6cb-a20f-4872-8a99-ead56b1a2290';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_photo_gallery__panel_context_65a187a2-6b2c-4848-9c3e-1a7099fb526e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ec013956-6cd0-4b7d-b279-f3c1dc11daf2';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '237',
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
    'css_class' => 'section-introduction"',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ec013956-6cd0-4b7d-b279-f3c1dc11daf2';
  $display->content['new-ec013956-6cd0-4b7d-b279-f3c1dc11daf2'] = $pane;
  $display->panels['center'][0] = 'new-ec013956-6cd0-4b7d-b279-f3c1dc11daf2';
  $pane = new stdClass();
  $pane->pid = 'new-cbfd7b45-80b6-4996-af95-f5b964bb7cab';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'gallery';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
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
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'cbfd7b45-80b6-4996-af95-f5b964bb7cab';
  $display->content['new-cbfd7b45-80b6-4996-af95-f5b964bb7cab'] = $pane;
  $display->panels['center'][1] = 'new-cbfd7b45-80b6-4996-af95-f5b964bb7cab';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-ec013956-6cd0-4b7d-b279-f3c1dc11daf2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['photo_gallery'] = $page;

  return $pages;

}

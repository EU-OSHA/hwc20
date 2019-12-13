<?php
/**
 * @file
 * hwc_priority_areas.pages_default.inc
 */

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
  $handler->name = 'page_priority_areas__panel_context_14442c6c-5cf3-4063-b15c-c6adb65b8de8';
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
  $pane->pid = 'new-2f34a859-a2ef-4731-96a0-f9ccee83df38';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'msd_priority_areas';
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
  $pane->uuid = '2f34a859-a2ef-4731-96a0-f9ccee83df38';
  $display->content['new-2f34a859-a2ef-4731-96a0-f9ccee83df38'] = $pane;
  $display->panels['center'][1] = 'new-2f34a859-a2ef-4731-96a0-f9ccee83df38';
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

  return $pages;

}

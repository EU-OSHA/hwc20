<?php
/**
 * @file
 * hwc_toolkit.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hwc_toolkit_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_106e85f7-f6ea-4a87-a34e-3643d8850d28';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Tools and examples',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
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
              'tools_and_examples' => 'tools_and_examples',
            ),
          ),
          'context' => 'argument_term_1',
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
        'class' => 'key-content col-md-9 col-sm-12',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'key-menu-container col-md-3 col-sm-12 well',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'image' => NULL,
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f28329e8-73c2-40e3-a342-f51048b664f6';
  $display->storage_type = 'unknown';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a9d289cb-6f53-46e8-a51e-4d8e6b81e2f2';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:name_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'hwc_toolkit_term_title',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a9d289cb-6f53-46e8-a51e-4d8e6b81e2f2';
  $display->content['new-a9d289cb-6f53-46e8-a51e-4d8e6b81e2f2'] = $pane;
  $display->panels['center'][0] = 'new-a9d289cb-6f53-46e8-a51e-4d8e6b81e2f2';
  $pane = new stdClass();
  $pane->pid = 'new-862664fa-d3e8-4f07-830a-ebffe6f1cf77';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'tk_tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '862664fa-d3e8-4f07-830a-ebffe6f1cf77';
  $display->content['new-862664fa-d3e8-4f07-830a-ebffe6f1cf77'] = $pane;
  $display->panels['center'][1] = 'new-862664fa-d3e8-4f07-830a-ebffe6f1cf77';
  $pane = new stdClass();
  $pane->pid = 'new-99d30471-1e13-4067-8655-0acbed43c2a0';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_toolkit-toolkit_nav';
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
  $pane->uuid = '99d30471-1e13-4067-8655-0acbed43c2a0';
  $display->content['new-99d30471-1e13-4067-8655-0acbed43c2a0'] = $pane;
  $display->panels['center'][2] = 'new-99d30471-1e13-4067-8655-0acbed43c2a0';
  $pane = new stdClass();
  $pane->pid = 'new-4623ca35-85b7-494a-b36f-229dc12489e0';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'hwc_toolkit-toolkit_left_menu';
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
    'css_id' => 'block-hwc-toolkit-toolkit-left-menu',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4623ca35-85b7-494a-b36f-229dc12489e0';
  $display->content['new-4623ca35-85b7-494a-b36f-229dc12489e0'] = $pane;
  $display->panels['left'][0] = 'new-4623ca35-85b7-494a-b36f-229dc12489e0';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_106e85f7-f6ea-4a87-a34e-3643d8850d28'] = $handler;

  return $export;
}

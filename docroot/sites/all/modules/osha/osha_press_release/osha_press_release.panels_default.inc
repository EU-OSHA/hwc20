<?php
/**
 * @file
 * osha_press_release.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function osha_press_release_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'press_room_blocks';
  $mini->category = '';
  $mini->admin_title = 'Press room blocks';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
          2 => 'right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '32.8442591105857',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '33.38067025187042',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '33.77507063754388',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2147ed37-2ccf-4019-8535-24cf3585802a';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'press_room_blocks';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0cff7b35-d027-43f1-b5fa-a9600a325e90';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'press_contacts';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0cff7b35-d027-43f1-b5fa-a9600a325e90';
  $display->content['new-0cff7b35-d027-43f1-b5fa-a9600a325e90'] = $pane;
  $display->panels['center'][0] = 'new-0cff7b35-d027-43f1-b5fa-a9600a325e90';
  $pane = new stdClass();
  $pane->pid = 'new-db068cdc-8c3d-4240-8d9a-9f8b906effd0';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'osha_press_release-osha_press_rel_become_partner';
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
  $pane->uuid = 'db068cdc-8c3d-4240-8d9a-9f8b906effd0';
  $display->content['new-db068cdc-8c3d-4240-8d9a-9f8b906effd0'] = $pane;
  $display->panels['left'][0] = 'new-db068cdc-8c3d-4240-8d9a-9f8b906effd0';
  $pane = new stdClass();
  $pane->pid = 'new-b8349e8d-566e-48ef-b4ed-d85fd71c357c';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'osha_press_release-osha_press_kit';
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
  $pane->uuid = 'b8349e8d-566e-48ef-b4ed-d85fd71c357c';
  $display->content['new-b8349e8d-566e-48ef-b4ed-d85fd71c357c'] = $pane;
  $display->panels['right'][0] = 'new-b8349e8d-566e-48ef-b4ed-d85fd71c357c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-db068cdc-8c3d-4240-8d9a-9f8b906effd0';
  $mini->display = $display;
  $export['press_room_blocks'] = $mini;

  return $export;
}

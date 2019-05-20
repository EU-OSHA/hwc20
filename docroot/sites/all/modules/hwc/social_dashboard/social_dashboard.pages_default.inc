<?php
/**
 * @file
 * social_dashboard.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function social_dashboard_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'media_centre';
  $page->task = 'page';
  $page->admin_title = 'Media centre';
  $page->admin_description = '';
  $page->path = 'media-centre/social-media-centre';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'Social Media',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_media_centre__panel';
  $handler->task = 'page';
  $handler->subtask = 'media_centre';
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
    'name' => 'panel',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Media centre
Social media centre',
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
        'class' => 'page-media-centre-social-media-centre',
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
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'facebook',
          1 => 'center',
          2 => 'twitter',
        ),
        'parent' => 'main',
        'class' => 'social-media-row',
        'hide_empty' => 1,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Linkedin',
        'width' => '24.90981240981241',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-sm-12 col-md-4 linkedin-column',
        'hide_empty' => 1,
      ),
      'facebook' => array(
        'type' => 'region',
        'title' => 'Facebook',
        'width' => '50',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-sm-12 col-md-4 facebook-column',
        'hide_empty' => 1,
      ),
      'twitter' => array(
        'type' => 'region',
        'title' => 'Twitter',
        'width' => '25.09018759018759',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-sm-12 col-md-4 twitter-column',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'form',
        ),
        'parent' => 'main',
        'class' => 'Form',
        'hide_empty' => 0,
      ),
      'form' => array(
        'type' => 'region',
        'title' => 'Form',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'facebook' => NULL,
      'twitter' => NULL,
      'form' => NULL,
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Social media centre';
  $display->uuid = '089aaecf-f766-459b-8a64-eafde9db10c9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_media_centre__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bbe2491d-1bd4-48ed-8c2f-5a9553663964';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'social_dashboard';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '15',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'linkedin',
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
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bbe2491d-1bd4-48ed-8c2f-5a9553663964';
  $display->content['new-bbe2491d-1bd4-48ed-8c2f-5a9553663964'] = $pane;
  $display->panels['center'][0] = 'new-bbe2491d-1bd4-48ed-8c2f-5a9553663964';
  $pane = new stdClass();
  $pane->pid = 'new-724fc1cd-a394-43ee-8625-39b3f82a32ee';
  $pane->panel = 'facebook';
  $pane->type = 'views';
  $pane->subtype = 'social_dashboard';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '15',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'facebook',
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
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '724fc1cd-a394-43ee-8625-39b3f82a32ee';
  $display->content['new-724fc1cd-a394-43ee-8625-39b3f82a32ee'] = $pane;
  $display->panels['facebook'][0] = 'new-724fc1cd-a394-43ee-8625-39b3f82a32ee';
  $pane = new stdClass();
  $pane->pid = 'new-35c5ee95-80d9-4f23-b7d2-d1698f319a2e';
  $pane->panel = 'form';
  $pane->type = 'block';
  $pane->subtype = 'social_dashboard-media_centre_form';
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
  $pane->uuid = '35c5ee95-80d9-4f23-b7d2-d1698f319a2e';
  $display->content['new-35c5ee95-80d9-4f23-b7d2-d1698f319a2e'] = $pane;
  $display->panels['form'][0] = 'new-35c5ee95-80d9-4f23-b7d2-d1698f319a2e';
  $pane = new stdClass();
  $pane->pid = 'new-05fea4f3-03bc-4eca-ab58-52b1d0badba1';
  $pane->panel = 'twitter';
  $pane->type = 'views';
  $pane->subtype = 'social_dashboard';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '15',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'twitter',
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
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '05fea4f3-03bc-4eca-ab58-52b1d0badba1';
  $display->content['new-05fea4f3-03bc-4eca-ab58-52b1d0badba1'] = $pane;
  $display->panels['twitter'][0] = 'new-05fea4f3-03bc-4eca-ab58-52b1d0badba1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['media_centre'] = $page;

  return $pages;

}

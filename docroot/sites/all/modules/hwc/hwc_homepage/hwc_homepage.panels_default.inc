<?php
/**
 * @file
 * hwc_homepage.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function hwc_homepage_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'front_page_blocks_set';
  $mini->category = '';
  $mini->admin_title = 'Front page blocks set';
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
          1 => 5,
        ),
        'parent' => 'canvas',
        'class' => 'col-sm-12',
        'hide_empty' => 0,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'home_left',
          1 => 'center',
          2 => 'home_right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '34.31325959046965',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-sm-6 col-md-4 panels-flexible-region-new-center',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 6,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'home_left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '34.05934343434343',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-sm-6 col-md-4 panels-flexible-region-new-home_left',
        'hide_empty' => 0,
      ),
      'home_right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '31.62739697518692',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-sm-12 col-md-4 panels-flexible-region-new-home_right',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'children' => array(
          0 => 7,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'content__',
        ),
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
      'content__' => array(
        'type' => 'region',
        'title' => 'Content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'left' => NULL,
      'default' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'center' => NULL,
      'content' => NULL,
      'content_' => NULL,
      'home_left' => NULL,
      'home_right' => NULL,
      'content__' => NULL,
    ),
    'left' => array(
      'style' => '-1',
    ),
    'center' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a027fda3-4ff0-4ff5-8da8-fad45303fba9';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'front_page_blocks_set';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
  $pane->pid = 'new-fe8c4144-a902-44fd-b7ca-9cd5a6dcfccc';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
    'override_pager_settings' => 1,
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
    'display' => 'oshnews_latest',
      'override_title' => 1,
    'override_title_text' => '%title',
      'override_title_heading' => 'div',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
  $pane->uuid = 'fe8c4144-a902-44fd-b7ca-9cd5a6dcfccc';
  $display->content['new-fe8c4144-a902-44fd-b7ca-9cd5a6dcfccc'] = $pane;
  $display->panels['center'][0] = 'new-fe8c4144-a902-44fd-b7ca-9cd5a6dcfccc';
    $pane = new stdClass();
    $pane->pid = 'new-5af75913-e8bf-4ede-a5c1-c66882f4f0a0';
  $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'frontpage_events';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
    'override_pager_settings' => 1,
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
      'display' => 'block',
      'override_title' => 1,
    'override_title_text' => '%title',
      'override_title_heading' => 'div',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
  $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5af75913-e8bf-4ede-a5c1-c66882f4f0a0';
    $display->content['new-5af75913-e8bf-4ede-a5c1-c66882f4f0a0'] = $pane;
  $display->panels['center'][1] = 'new-5af75913-e8bf-4ede-a5c1-c66882f4f0a0';
  $pane = new stdClass();
  $pane->pid = 'new-fb9dd05c-3e4a-45cf-9a57-a760e61585d0';
  $pane->panel = 'content__';
  $pane->type = 'block';
  $pane->subtype = 'hwc_homepage-hwc_homepage_tools_and_resources';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => 'Tools and publications',
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
  $pane->uuid = 'fb9dd05c-3e4a-45cf-9a57-a760e61585d0';
  $display->content['new-fb9dd05c-3e4a-45cf-9a57-a760e61585d0'] = $pane;
  $display->panels['content__'][0] = 'new-fb9dd05c-3e4a-45cf-9a57-a760e61585d0';
  $pane = new stdClass();
  $pane->pid = 'new-f85d57d2-0e59-4122-859c-d360248ed81c';
  $pane->panel = 'content__';
  $pane->type = 'block';
  $pane->subtype = 'hwc_homepage-hwc_homepage_topics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => 'Topics',
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
  $pane->uuid = 'f85d57d2-0e59-4122-859c-d360248ed81c';
  $display->content['new-f85d57d2-0e59-4122-859c-d360248ed81c'] = $pane;
  $display->panels['content__'][1] = 'new-f85d57d2-0e59-4122-859c-d360248ed81c';
  $pane = new stdClass();
  $pane->pid = 'new-74d15e2b-823d-4d4c-b7af-fe34ffe384b5';
  $pane->panel = 'home_left';
  $pane->type = 'views';
  $pane->subtype = 'homepage_about_topics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
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
  $pane->uuid = '74d15e2b-823d-4d4c-b7af-fe34ffe384b5';
  $display->content['new-74d15e2b-823d-4d4c-b7af-fe34ffe384b5'] = $pane;
  $display->panels['home_left'][0] = 'new-74d15e2b-823d-4d4c-b7af-fe34ffe384b5';
  $pane = new stdClass();
  $pane->pid = 'new-bc348162-1a49-4fbf-bd60-8a6300ff6ba8';
  $pane->panel = 'home_right';
  $pane->type = 'views';
  $pane->subtype = 'social_dashboard';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
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
  $pane->uuid = 'bc348162-1a49-4fbf-bd60-8a6300ff6ba8';
  $display->content['new-bc348162-1a49-4fbf-bd60-8a6300ff6ba8'] = $pane;
  $display->panels['home_right'][0] = 'new-bc348162-1a49-4fbf-bd60-8a6300ff6ba8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['front_page_blocks_set'] = $mini;

  return $export;
}

<?php
/**
 * @file
 * osha_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function osha_events_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: homepage_events
  $nodequeues['homepage_events'] = array(
    'name' => 'homepage_events',
    'title' => 'Homepage events',
    'subqueue_title' => '',
    'size' => 4,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'events',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: press_room_news
  $nodequeues['press_room_news'] = array(
    'name' => 'press_room_news',
    'title' => 'Press room news',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function osha_events_node_info() {
  $items = array(
    'event_speaker' => array(
      'name' => 'Event speaker',
      'base' => 'node_content',
      'description' => 'Event speaker',
      'has_title' => '1',
      'title_label' => 'Name of the speaker',
      'help' => '',
    ),
    'events' => array(
      'name' => 'Events',
      'base' => 'node_content',
      'description' => 'Events',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

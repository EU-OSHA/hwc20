<?php
/**
 * @file
 * hwc_practical_tool.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function hwc_practical_tool_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'practical_tools_listing';
  $path_breadcrumb->name = 'Practical tools listing';
  $path_breadcrumb->path = 'tools-and-publications/practical-tools';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and publications',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['practical_tools_listing'] = $path_breadcrumb;

  return $export;
}

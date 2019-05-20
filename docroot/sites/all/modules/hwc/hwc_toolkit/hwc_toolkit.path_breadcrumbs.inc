<?php
/**
 * @file
 * hwc_toolkit.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function hwc_toolkit_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_toolkit_examples';
  $path_breadcrumb->name = 'Search toolkit examples';
  $path_breadcrumb->path = 'tools-and-publications/campaign-toolkit/search-toolkit-examples';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and publications',
      1 => 'Campaign toolkit',
      2 => 'Campaign examples and tools',
      3 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
      2 => '<none>',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['search_toolkit_examples'] = $path_breadcrumb;

  return $export;
}

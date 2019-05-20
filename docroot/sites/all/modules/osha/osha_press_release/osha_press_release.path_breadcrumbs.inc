<?php
/**
 * @file
 * osha_press_release.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function osha_press_release_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'press_room';
  $path_breadcrumb->name = 'Press room';
  $path_breadcrumb->path = 'media-centre/press-room';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%site:current-page:menu-link:pb-join:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%site:current-page:menu-link:pb-join:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['press_room'] = $path_breadcrumb;

  return $export;
}

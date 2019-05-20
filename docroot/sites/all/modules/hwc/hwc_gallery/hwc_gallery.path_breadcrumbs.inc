<?php
/**
 * @file
 * hwc_gallery.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function hwc_gallery_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'gallery';
  $path_breadcrumb->name = 'Gallery';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Media centre',
      1 => 'Photo gallery',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'hwc_gallery' => 'hwc_gallery',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['gallery'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'photo_gallery';
  $path_breadcrumb->name = 'Photo gallery';
  $path_breadcrumb->path = 'media-centre/photo-gallery';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Media centre',
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
  $export['photo_gallery'] = $path_breadcrumb;

  return $export;
}

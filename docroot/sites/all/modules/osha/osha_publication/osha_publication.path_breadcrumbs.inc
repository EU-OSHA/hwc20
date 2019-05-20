<?php
/**
 * @file
 * osha_publication.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function osha_publication_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'case_studies';
  $path_breadcrumb->name = 'Case studies';
  $path_breadcrumb->path = 'tools-and-publications/case-studies';
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
  $export['case_studies'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'case_studies_detail_page';
  $path_breadcrumb->name = 'Case studies detail page';
  $path_breadcrumb->path = 'node/invalid/handled/from/code';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and publications',
      1 => 'Case studies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'tools-and-publications/case-studies',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['case_studies_detail_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'publications_detail_page';
  $path_breadcrumb->name = 'Publications detail page';
  $path_breadcrumb->path = 'node/invalid/handled/from/code';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Tools and publications',
      1 => 'Publications',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'tools-and-publications/publications',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['publications_detail_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'publications_listing';
  $path_breadcrumb->name = 'Publications listing';
  $path_breadcrumb->path = 'tools-and-publications/publications';
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
  $export['publications_listing'] = $path_breadcrumb;

  return $export;
}

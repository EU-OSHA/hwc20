<?php
/**
 * @file
 * osha_musculoskeletal_disorders.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_musculoskeletal_disorders_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_musculoskeletal_disorders_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

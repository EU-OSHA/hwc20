<?php
/**
 * @file
 * hwc_audio_visual.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_audio_visual_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hwc_audio_visual_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

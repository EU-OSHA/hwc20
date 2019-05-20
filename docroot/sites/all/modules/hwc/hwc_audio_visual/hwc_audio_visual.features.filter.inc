<?php
/**
 * @file
 * hwc_audio_visual.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function hwc_audio_visual_filter_default_formats() {
  $formats = array();

  // Exported format: Audio Visual.
  $formats['audio_visual'] = array(
    'format' => 'audio_visual',
    'name' => 'Audio Visual',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}

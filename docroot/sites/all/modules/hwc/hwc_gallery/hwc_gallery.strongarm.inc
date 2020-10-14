<?php
/**
 * @file
 * hwc_gallery.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_gallery_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_gallery_usable_fields_bundles';
  $strongarm->value = array(
    'hwc_gallery|field_images' => 'hwc_gallery|field_images',
  );
  $export['osha_gallery_usable_fields_bundles'] = $strongarm;

  return $export;
}

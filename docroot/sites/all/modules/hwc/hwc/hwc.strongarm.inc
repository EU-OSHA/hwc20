<?php
/**
 * @file
 * hwc.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_classes_fields';
  $strongarm->value = 'col-md-2
col-sm-2
col-md-3
col-sm-3
col-md-4
col-sm-4
col-md-6
col-sm-6
col-md-8
col-sm-8
col-md-10
col-sm-10
col-md-12
row
container';
  $export['ds_classes_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ds_classes_regions';
  $strongarm->value = 'col-md-2
col-sm-2
col-md-3
col-sm-3
col-md-4
col-sm-4
col-md-6
col-sm-6
col-md-8
col-sm-8
col-md-10
col-sm-10
col-md-12
row
container';
  $export['ds_classes_regions'] = $strongarm;

  return $export;
}

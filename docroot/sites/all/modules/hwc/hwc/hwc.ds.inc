<?php
/**
 * @file
 * hwc.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function hwc_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'top_anchor';
  $ds_field->label = 'Top anchor';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '*|*';
  $ds_field->properties = array();
  $export['top_anchor'] = $ds_field;

  return $export;
}

<?php
/**
 * @file
 * osha_slideshare.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function osha_slideshare_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|slideshare|osha_resources';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'slideshare';
  $ds_layout->view_mode = 'osha_resources';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slideshare',
        1 => 'title_field',
      ),
    ),
    'fields' => array(
      'field_slideshare' => 'ds_content',
      'title_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'col-sm-4' => 'col-sm-4',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|slideshare|osha_resources'] = $ds_layout;

  return $export;
}

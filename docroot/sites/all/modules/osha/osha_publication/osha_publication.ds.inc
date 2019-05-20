<?php
/**
 * @file
 * osha_publication.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function osha_publication_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|publication|osha_resources';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'publication';
  $ds_layout->view_mode = 'osha_resources';
  $ds_layout->layout = 'hwc_2col_stacked_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_cover_image',
      ),
      'right' => array(
        1 => 'title_field',
        2 => 'field_publication_date',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_cover_image' => 'left',
      'title_field' => 'right',
      'field_publication_date' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'left' => array(
        'col-sm-2' => 'col-sm-2',
      ),
      'right' => array(
        'col-sm-10' => 'col-sm-10',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'center' => 'div',
      'left2' => 'div',
      'right2' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|publication|osha_resources'] = $ds_layout;

  return $export;
}

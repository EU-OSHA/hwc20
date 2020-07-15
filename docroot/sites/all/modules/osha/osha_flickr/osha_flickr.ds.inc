<?php
/**
 * @file
 * osha_flickr.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function osha_flickr_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|flickr_gallery|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'flickr_gallery';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'back_to_list',
        1 => 'field_publication_date',
        2 => 'title_field',
        3 => 'field_cover_flickr',
        4 => 'share_widget',
        5 => 'field_flickr',
      ),
    ),
    'fields' => array(
      'back_to_list' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'title_field' => 'ds_content',
      'field_cover_flickr' => 'ds_content',
      'share_widget' => 'ds_content',
      'field_flickr' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'container' => 'container',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|flickr_gallery|default'] = $ds_layout;

  return $export;
}

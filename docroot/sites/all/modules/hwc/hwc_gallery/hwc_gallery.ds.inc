<?php
/**
 * @file
 * hwc_gallery.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function hwc_gallery_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'gallery_cover_image';
  $ds_field->label = 'gallery_cover_image';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'hwc_gallery|*';
  $ds_field->properties = array();
  $export['gallery_cover_image'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hwc_gallery_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|hwc_gallery|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'hwc_gallery';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_publication_date',
        1 => 'title_field',
        2 => 'gallery_cover_image',
        3 => 'share_widget',
        4 => 'body',
        5 => 'field_images',
      ),
    ),
    'fields' => array(
      'field_publication_date' => 'ds_content',
      'title_field' => 'ds_content',
      'gallery_cover_image' => 'ds_content',
      'share_widget' => 'ds_content',
      'body' => 'ds_content',
      'field_images' => 'ds_content',
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
  );
  $export['node|hwc_gallery|default'] = $ds_layout;

  return $export;
}

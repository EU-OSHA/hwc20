<?php
/**
 * @file
 * osha_newsletter.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function osha_newsletter_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|spotlight|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'spotlight';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'back_to_list' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|spotlight|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function osha_newsletter_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|spotlight|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'spotlight';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'back_to_list',
        1 => 'field_image',
        2 => 'field_publication_date',
        3 => 'field_summary',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'back_to_list' => 'ds_content',
      'field_image' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'field_summary' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
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
  $export['node|spotlight|default'] = $ds_layout;

  return $export;
}

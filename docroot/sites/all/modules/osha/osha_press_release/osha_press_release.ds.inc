<?php
/**
 * @file
 * osha_press_release.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function osha_press_release_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press_release|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press_release';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'back_to_list',
        1 => 'share_widget',
        2 => 'field_publication_date',
        3 => 'title_field',
        4 => 'field_summary',
        5 => 'field_quote',
        6 => 'field_image',
        7 => 'body',
        8 => 'field_pr_notes_to_editor',
        9 => 'field_aditional_resources',
      ),
    ),
    'fields' => array(
      'back_to_list' => 'ds_content',
      'share_widget' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'title_field' => 'ds_content',
      'field_summary' => 'ds_content',
      'field_quote' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'field_pr_notes_to_editor' => 'ds_content',
      'field_aditional_resources' => 'ds_content',
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
  $export['node|press_release|default'] = $ds_layout;

  return $export;
}

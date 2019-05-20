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
        0 => 'field_publication_date',
        1 => 'title_field',
        2 => 'share_widget',
        3 => 'field_summary',
        4 => 'body',
        5 => 'field_pr_notes_to_editor',
      ),
    ),
    'fields' => array(
      'field_publication_date' => 'ds_content',
      'title_field' => 'ds_content',
      'share_widget' => 'ds_content',
      'field_summary' => 'ds_content',
      'body' => 'ds_content',
      'field_pr_notes_to_editor' => 'ds_content',
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
  $export['node|press_release|default'] = $ds_layout;

  return $export;
}

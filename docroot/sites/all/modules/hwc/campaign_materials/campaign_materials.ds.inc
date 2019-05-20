<?php
/**
 * @file
 * campaign_materials.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function campaign_materials_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|campaign_materials|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'campaign_materials';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_publication_date',
        1 => 'title_field',
      ),
      'left' => array(
        2 => 'field_image',
      ),
      'right' => array(
        3 => 'body',
        4 => 'field_related_documents',
        5 => 'field_campaign_material_type',
      ),
    ),
    'fields' => array(
      'field_publication_date' => 'header',
      'title_field' => 'header',
      'field_image' => 'left',
      'body' => 'right',
      'field_related_documents' => 'right',
      'field_campaign_material_type' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'container' => 'container',
      ),
      'left' => array(
        'col-sm-4' => 'col-sm-4',
      ),
      'right' => array(
        'col-sm-8' => 'col-sm-8',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 1,
  );
  $export['node|campaign_materials|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|campaign_materials|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'campaign_materials';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'field_publication_date',
        2 => 'title_field',
        3 => 'body',
        4 => 'field_related_documents',
        5 => 'field_campaign_material_type',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'field_publication_date' => 'right',
      'title_field' => 'right',
      'body' => 'right',
      'field_related_documents' => 'right',
      'field_campaign_material_type' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        'row' => 'row',
      ),
      'left' => array(
        'col-md-3 col-sm-4' => 'col-md-3 col-sm-4',
      ),
      'right' => array(
        'col-md-9 col-sm-8' => 'col-md-9 col-sm-8',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 1,
  );
  $export['node|campaign_materials|teaser'] = $ds_layout;

  return $export;
}

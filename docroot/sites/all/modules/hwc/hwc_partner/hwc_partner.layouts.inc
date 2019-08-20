<?php
/**
 * @file
 * hwc_partner.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function hwc_partner_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'partner_detail';
  $layout->admin_title = 'Partner detail';
  $layout->admin_description = '';
  $layout->category = 'Partner';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 6,
          1 => 5,
          3 => 2,
          4 => 3,
        ),
        'parent' => 'canvas',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 7,
          1 => 9,
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-3',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left__',
          1 => 'right__',
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-3',
        'hide_empty' => 0,
      ),
      'left__' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '25.091027461588755',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'col-sm-6 profile-col-left-3',
        'hide_empty' => 0,
      ),
      'right__' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '24.908972538411245',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'col-sm-6 profile-col-right-3',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_top_left',
          1 => 'right_top_left',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center__',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'My Profile Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'my_title',
        ),
        'parent' => 'main',
        'class' => 'profile-edit-links-container',
        'hide_empty' => 0,
      ),
      'my_title' => array(
        'type' => 'region',
        'title' => 'Top Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'column',
        'width' => '66.05339105339105',
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 15,
          1 => 4,
          2 => 14,
          3 => 10,
          4 => 13,
        ),
        'class' => 'col-sm-8',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'column',
        'width' => '33.946608946608954',
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 12,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 1,
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_left',
          1 => 'left_right',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_',
        ),
        'parent' => '9',
        'class' => '',
        'hide_empty' => 1,
      ),
      'left_right' => array(
        'type' => 'region',
        'title' => 'Left Middle Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '10',
        'class' => 'profile-col-left-middle-2',
        'hide_empty' => 0,
      ),
      'right_' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '12',
        'class' => 'profile-col-left-middle-2',
        'hide_empty' => 1,
      ),
      'left_left' => array(
        'type' => 'region',
        'title' => 'Left Middle Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '10',
        'class' => '',
        'hide_empty' => 0,
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_bottom',
        ),
        'parent' => '7',
        'class' => 'top',
        'hide_empty' => 0,
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_top',
        ),
        'parent' => '7',
        'class' => 'top',
        'hide_empty' => 0,
      ),
      15 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_init',
        ),
        'parent' => '7',
        'class' => 'top',
        'hide_empty' => 0,
      ),
      'left_init' => array(
        'type' => 'region',
        'title' => 'Left Init',
        'width' => 100,
        'width_type' => '%',
        'parent' => '15',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_top' => array(
        'type' => 'region',
        'title' => 'Left Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_bottom' => array(
        'type' => 'region',
        'title' => 'Left Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_top_left' => array(
        'type' => 'region',
        'title' => 'Left-Top-Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right_top_left' => array(
        'type' => 'region',
        'title' => 'Right-Top-Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $export['partner_detail'] = $layout;

  return $export;
}

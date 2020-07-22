<?php
/**
 * @file
 * hwc_audio_visual.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hwc_audio_visual_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format audio_visual'.
  $permissions['use text format audio_visual'] = array(
    'name' => 'use text format audio_visual',
    'roles' => array(
      'Approver' => 'Approver',
      'Audio Visual' => 'Audio Visual',
      'Content Validator' => 'Content Validator',
      'Editor' => 'Editor',
      'External Provider' => 'External Provider',
      'HWC Staff - Reviewers' => 'HWC Staff - Reviewers',
      'Layout Validator' => 'Layout Validator',
      'Project Manager' => 'Project Manager',
      'Superadministrators' => 'Superadministrators',
      'Translation Liaison' => 'Translation Liaison',
      'Translation Manager' => 'Translation Manager',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
      'campaign partner' => 'campaign partner',
    ),
    'module' => 'filter',
  );

  return $permissions;
}

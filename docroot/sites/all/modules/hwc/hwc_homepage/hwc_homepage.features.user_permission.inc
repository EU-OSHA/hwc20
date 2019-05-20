<?php
/**
 * @file
 * hwc_homepage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hwc_homepage_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block_class',
  );

  return $permissions;
}

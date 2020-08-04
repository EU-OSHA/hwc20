<?php
/**
 * @file
 * hwc_toolkit.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hwc_toolkit_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tk_example content'.
  $permissions['create tk_example content'] = array(
    'name' => 'create tk_example content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create tk_topic content'.
  $permissions['create tk_topic content'] = array(
    'name' => 'create tk_topic content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tk_example content'.
  $permissions['delete any tk_example content'] = array(
    'name' => 'delete any tk_example content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tk_topic content'.
  $permissions['delete any tk_topic content'] = array(
    'name' => 'delete any tk_topic content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tk_example content'.
  $permissions['delete own tk_example content'] = array(
    'name' => 'delete own tk_example content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tk_topic content'.
  $permissions['delete own tk_topic content'] = array(
    'name' => 'delete own tk_topic content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tk_example content'.
  $permissions['edit any tk_example content'] = array(
    'name' => 'edit any tk_example content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tk_topic content'.
  $permissions['edit any tk_topic content'] = array(
    'name' => 'edit any tk_topic content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tk_example content'.
  $permissions['edit own tk_example content'] = array(
    'name' => 'edit own tk_example content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tk_topic content'.
  $permissions['edit own tk_topic content'] = array(
    'name' => 'edit own tk_topic content',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'hwc access administration pages'.
  $permissions['hwc access administration pages'] = array(
    'name' => 'hwc access administration pages',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'hwc',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'External Provider' => 'External Provider',
      'Website Managers' => 'Website Managers',
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  return $permissions;
}

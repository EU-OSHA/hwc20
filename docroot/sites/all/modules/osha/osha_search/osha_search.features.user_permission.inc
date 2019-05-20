<?php
/**
 * @file
 * osha_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function osha_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer Search Autocomplete'.
  $permissions['administer Search Autocomplete'] = array(
    'name' => 'administer Search Autocomplete',
    'roles' => array(
      'Superadministrators' => 'Superadministrators',
      'administrator' => 'administrator',
    ),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Superadministrators' => 'Superadministrators',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'Superadministrators' => 'Superadministrators',
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use Search Autocomplete'.
  $permissions['use Search Autocomplete'] = array(
    'name' => 'use Search Autocomplete',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_autocomplete',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Superadministrators' => 'Superadministrators',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  return $permissions;
}

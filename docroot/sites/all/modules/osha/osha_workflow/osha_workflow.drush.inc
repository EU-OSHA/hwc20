<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function osha_workflow_drush_command() {
  $items = array();
  $items['osha-workflow-permisions'] = array(
    'description' => 'Configure workflow permissions for each role',
  );
  return $items;
}

/**
 * Implements COMMANDFILE_drush_help().
 */
function osha_workflow_drush_help($section) {
  switch ($section) {
    case 'drush:osha-create-users':
      return 'This command will create a group of test users assigned to the workflow roles';
  }
  return NULL;
}

/**
 * Drush command to create OSHA workflow users.
 *
 * @throws Exception
 */
function drush_osha_workflow_permisions() {
  module_load_include('module', 'osha_workflow');
  osha_workflow_setup_role_permissions();
}

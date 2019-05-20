<?php

/**
 * @file
 * Reset Drupal variables command for Drush
 */

/**
 * Implements hook_drush_command().
 */
function reset_variables_drush_command() {
  $items = array();
  $items['osha-reset-variables'] = array(
    'description' => 'Replace variables with those from config.json',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

function drush_reset_variables_osha_reset_variables() {
    if ($json_path = realpath(dirname(__FILE__) . '/../../conf/config.json')) {
    if (file_exists($json_path)) {
      $cfg = json_decode(file_get_contents($json_path), TRUE);
      $variables = $cfg['variables'];
      foreach ($variables as $k => $v) {
        if (drush_get_option('verbose', FALSE)) {
          drush_log(sprintf('Setting %s = %s', $k, $v));
        }
        variable_set($k, $v);
      }
    }
  }
}

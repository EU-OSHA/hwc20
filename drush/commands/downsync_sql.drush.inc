<?php

/**
 * @file
 * Downsync_sql command for Drush
 *
 * Copied from downsync - removed rsync.
 */

/**
 * Implements hook_drush_command().
 */
function downsync_sql_drush_command() {
  $items = array();
  $items['downsync_sql'] = array(
    'description' => "Sync one environment's db and files to another.",
    'arguments' => array(
      'source-alias' => 'Alias of the source site to copy from.',
      'destination-alias' => 'Alias of the destination site to copy to.',
    ),
    'examples' => array(
      'drush downsync_sql @prod @local' => 'sql-sync the database from @prod to @local',
    ),
    'aliases' => array('dsyncsql'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'drush dependencies' => array('sql', 'core'),
  );
  return $items;
}

/**
 * Actual function run by the downsync command.
 */
function drush_downsync_sql($source = NULL, $destination = NULL) {
  include __DIR__ . '/../aliases/hwc.aliases.drushrc.php';
  // Make sure we have the source-dump and target-dump options.
  $destination_name = substr($destination, 1);
  $source_name = substr($source, 1);

  $source_dump = drush_get_option('source-dump');
  if (!isset($source_dump)) {
    if (isset($aliases[$source_name]['command-specific']['sql-sync']['source-dump'])) {
      drush_set_option('source-dump', $aliases[$source_name]['command-specific']['sql-sync']['source-dump']);
    }
    else {
      drush_set_option('source-dump', '/tmp/source-dump.sql');
    }
  }

  $target_dump = drush_get_option('target-dump');
  if (!isset($target_dump)) {
    if (isset($aliases[$destination_name]['command-specific']['sql-sync']['target-dump'])) {
      drush_set_option('target-dump', $aliases[$destination_name]['command-specific']['sql-sync']['target-dump']);
    }
    else {
      drush_set_option('target-dump', '/tmp/target-dump.sql.gz');
    }
  }

  // Execute a drush sql-sync
  print dt('SQL Sync running... NOTE: if you do not have ssh passwordless logins setup, you may be asked for your password multiple times.');

  drush_invoke('sql-sync', array($source, $destination));
}

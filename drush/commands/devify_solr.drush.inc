<?php

/**
 * @file
 * Devify Solr command for Drush
 */

/**
 * Implements hook_drush_command().
 */
function devify_solr_drush_command() {
  $items = array();
  $items['devify_solr'] = array(
    'description' => "Devify Solr Server with default configs + extended ones",
    'examples' => array(
      'drush devify_solr' => 'devify solr server',
    ),
    'aliases' => array('devify_solr'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

/**
 * Actual function run by the devify_solr command.
 */
function drush_devify_solr($source = NULL, $destination = NULL) {
  print 'Devify Solr Server';
  $solr_server = drush_get_option('solr_server');
  $cfg = array_merge(
    array(
      'name' => 'Solr server',
      'enabled' => 1,
      'description' => 'Search server',
      'scheme' => 'http',
      'host' => 'localhost',
      'port' => '8983',
      'path' => '/solr',
      'http_user' => '',
      'http_password' => '',
      'excerpt' => NULL,
      'retrieve_data' => NULL,
      'highlight_data' => NULL,
      'skip_schema_check' => NULL,
      'solr_version' => '',
      'http_method' => 'AUTO',
    ), $solr_server
  );
  $server = search_api_server_load('solr_server');
  if (!empty($server)) {
    $server->name = $cfg['name'];
    $server->enabled = $cfg['enabled'];
    $server->description = $cfg['description'];
    $server->options = array(
      'scheme' => $cfg['scheme'],
      'host' => $cfg['host'],
      'port' => $cfg['port'],
      'path' => $cfg['path'],
      'http' => array(
        'http_user' => $cfg['http_user'],
        'http_pass' => $cfg['http_pass'],
      ),
      'excerpt' => $cfg['excerpt'],
      'retrieve_data' => $cfg['retrieve_data'],
      'highlight_data' => $cfg['highlight_data'],
      'skip_schema_check' => $cfg['skip_schema_check'],
      'solr_version' => $cfg['solr_version'],
      'http_method' => $cfg['http_method'],
    );
    $server->save();
  }
  else {
    print 'No Solr Server (machine name: solr_server) found in database';
  }

}

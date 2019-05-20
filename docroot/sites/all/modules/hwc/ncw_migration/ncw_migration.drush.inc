<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function ncw_migration_drush_command() {
  return array(
    'hwc-migrate-av-related' => array(
      'description' => 'Import audio-video related taxonomies from the corporate website',
    ),
    'hwc-migrate-ds' => array(
      'description' => 'Import DS from the corporate website',
    ),
    'hwc-migrate-all' => array(
      'description' => 'Import all content from the corporate website',
    ),
    'hwc-migrate-node' => array(
      'description' => 'Import single node',
      'arguments' => array(
        'nid' => 'Node ID in NCW',
      ),
      'required-arguments' => TRUE,
      'options' => array(
        'update' => 'Update existing migrated node',
      ),
    ),
  );
}

function drush_ncw_migration_hwc_migrate_ds() {
  $migrations = array(
    'dangerous_substances',
  );
  foreach ($migrations as $migration) {
    ncw_migration_run_single($migration);
  }
}

function drush_ncw_migration_hwc_migrate_av_related() {
  $migrations = array(
    'tax_priority_area',
    'tax_provider_type',
    'tax_hazmap_categories',
    'tax_biological_hazard',
    'tax_hazard_physical_state',
    'tax_hazard_health_effects',
    'tax_exposure_route',
    'tax_worker_groups',
    'tax_prevention_measures',
    'tax_material_purpose',
    'tax_target_group',
    'tax_evaluation',
    'tax_material_objective',

    'dangerous_substances',
  );
  foreach ($migrations as $migration) {
    ncw_migration_run_single($migration);
  }
}

function drush_ncw_migration_hwc_migrate_all() {
  /* BE AWARE OF THE MIGRATIONS ORDERING! */
  $migrations = array(
    'tax_country_status',
    'tax_country',
    'tax_fop_link_sections',
    'tax_newsletter_sections',
    'tax_publication_types',
    'tax_tags',
    'tax_segment',

    'highlights_add_res',
    'press_releases_add_res',
    'news_add_res',
    'publications_add_res',
    'infographics',
    'press_contacts',
  );
  foreach ($migrations as $migration) {
    ncw_migration_run_single($migration);
  }
}

function drush_ncw_migration_hwc_migrate_node($nid) {
  module_load_include('inc', 'ncw_migration', 'ncw_migration.migrate');
  $url = ncw_migration_datasource_url() . '/export/node/' . $nid;
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 0);
  curl_setopt($ch, CURLOPT_FILETIME, TRUE);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
  $content = curl_exec($ch);
  $info = curl_getinfo($ch);
  curl_close($ch);
  if ($info['http_code'] == 200) {
    $node = json_decode($content);
    define('SINGLE_NODE_MIGRATION_NID', $nid);
    if ($m = Migration::getInstance($node->type)) {
      if (drush_get_option('update', FALSE)) {
        $m->prepareUpdate();
      }
      $m->processImport();
    }
  }
  else {
    drush_set_error("Cannot stat remote node $url (HTTP status: {$info['http_code']})");
  }
}

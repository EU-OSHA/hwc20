<?php
/**
 * @file
 * hwc_workflow.entity_collection_bundles_default.inc
 */

/**
 * Implements hook_entity_collection_bundles_default().
 */
function hwc_workflow_entity_collection_bundles_default() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'campaigns_partner_list';
  $preset->storage = 'entity_collection_storage_db';
  $preset->label = 'Campaigns partner list';
  $preset->description = '';
  $preset->settings = array();
  $export['campaigns_partner_list'] = $preset;

  return $export;
}

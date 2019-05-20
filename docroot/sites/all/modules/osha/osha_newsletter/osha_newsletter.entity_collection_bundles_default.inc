<?php
/**
 * @file
 * osha_newsletter.entity_collection_bundles_default.inc
 */

/**
 * Implements hook_entity_collection_bundles_default().
 */
function osha_newsletter_entity_collection_bundles_default() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'newsletter_content_collection';
  $preset->storage = 'entity_collection_storage_db';
  $preset->label = 'Newsletter Content Collection';
  $preset->description = 'This collection type stores newsletters (Issues of newsletter). Each collection per newsletter issue';
  $preset->settings = array();
  $export['newsletter_content_collection'] = $preset;

  return $export;
}

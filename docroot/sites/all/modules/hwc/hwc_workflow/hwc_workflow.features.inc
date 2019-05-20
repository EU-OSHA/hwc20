<?php
/**
 * @file
 * hwc_workflow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_workflow_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "entity_collection" && $api == "entity_collection_bundles_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entity_collection().
 */
function hwc_workflow_default_entity_collection() {
  $items = array();
  $items['campaigns_partner_default_list'] = entity_import('entity_collection', '{
    "type" : null,
    "name" : "campaigns_partner_default_list",
    "bid" : null,
    "title" : "Campaigns partner managers default list",
    "cache" : null,
    "requiredcontexts" : [],
    "contexts" : [],
    "bundle" : "campaigns_partner_list",
    "style" : "entity_collection_style_flat",
    "row" : "entity_collection_row_view_mode",
    "settings" : {
      "row_settings" : { "style_per_row" : 1 },
      "style_settings" : [],
      "allowed_bundles" : {
        "node" : [],
        "taxonomy_term" : [],
        "comment" : [],
        "entity_collection" : [],
        "field_collection_item" : [],
        "i18n_translation" : [],
        "osha_alert_service" : [],
        "linkchecker_link" : [],
        "linkchecker_node" : [],
        "redirect" : [],
        "search_api_server" : [],
        "search_api_index" : [],
        "file" : [],
        "taxonomy_vocabulary" : [],
        "tmgmt_job" : [],
        "tmgmt_job_item" : [],
        "tmgmt_message" : [],
        "tmgmt_translator" : [],
        "tmgmt_remote" : [],
        "tmgmt_local_task" : [],
        "tmgmt_local_task_item" : [],
        "user" : [ "user" ],
        "wysiwyg_profile" : [],
        "workbench_moderation_transition" : [],
        "node_project_managers" : [],
        "node_approval" : [],
        "translation_validator" : [],
        "rules_config" : []
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}

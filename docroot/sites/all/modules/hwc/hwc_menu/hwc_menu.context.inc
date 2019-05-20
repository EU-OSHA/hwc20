<?php
/**
 * @file
 * hwc_menu.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hwc_menu_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'introduction_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:28:{s:4:"node";s:4:"node";s:13:"taxonomy_term";i:0;s:7:"comment";i:0;s:17:"entity_collection";i:0;s:21:"field_collection_item";i:0;s:16:"i18n_translation";i:0;s:18:"osha_alert_service";i:0;s:16:"linkchecker_link";i:0;s:16:"linkchecker_node";i:0;s:8:"redirect";i:0;s:17:"search_api_server";i:0;s:16:"search_api_index";i:0;s:4:"file";i:0;s:19:"taxonomy_vocabulary";i:0;s:9:"tmgmt_job";i:0;s:14:"tmgmt_job_item";i:0;s:13:"tmgmt_message";i:0;s:16:"tmgmt_translator";i:0;s:12:"tmgmt_remote";i:0;s:16:"tmgmt_local_task";i:0;s:21:"tmgmt_local_task_item";i:0;s:4:"user";i:0;s:15:"wysiwyg_profile";i:0;s:31:"workbench_moderation_transition";i:0;s:21:"node_project_managers";i:0;s:13:"node_approval";i:0;s:21:"translation_validator";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_article_type',
        'field_value' => '73',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['introduction_page'] = $context;

  return $export;
}

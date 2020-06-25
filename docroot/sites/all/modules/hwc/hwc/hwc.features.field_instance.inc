<?php
/**
 * @file
 * hwc.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hwc_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-nodequeue_help_text-field_nodequeue'.
  $field_instances['taxonomy_term-nodequeue_help_text-field_nodequeue'] = array(
    'bundle' => 'nodequeue_help_text',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_formatter_class' => '',
        ),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_nodequeue',
    'label' => 'Nodequeue',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Nodequeue');

  return $field_instances;
}

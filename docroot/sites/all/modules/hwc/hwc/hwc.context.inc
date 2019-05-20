<?php
/**
 * @file
 * hwc.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hwc_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'segmentation_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        215 => 215,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;
  $export['segmentation_page'] = $context;

  return $export;
}

<?php
/**
 * @file
 * osha_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function osha_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_events';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'events' => 'events',
        'news' => 'news',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['context_events'] = $context;

  return $export;
}

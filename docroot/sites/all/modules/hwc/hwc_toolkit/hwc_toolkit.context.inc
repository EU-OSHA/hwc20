<?php
/**
 * @file
 * hwc_toolkit.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hwc_toolkit_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'toolkit';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'tk_article' => 'tk_article',
        'tk_example' => 'tk_example',
        'tk_section' => 'tk_section',
        'tk_tool' => 'tk_tool',
        'tk_topic' => 'tk_topic',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'tools-and-publications/campaign-toolkit/tools-and-examples/search-toolkit-examples' => 'tools-and-publications/campaign-toolkit/tools-and-examples/search-toolkit-examples',
        'tools-and-publications/campaign-toolkit/tools-and-examples/search-toolkit-examples/*' => 'tools-and-publications/campaign-toolkit/tools-and-examples/search-toolkit-examples/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'search_toolkit_examples' => 'search_toolkit_examples',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['toolkit'] = $context;

  return $export;
}

<?php
/**
 * @file
 * osha_press_release.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function osha_press_release_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_osha_in_the_media';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'press_release' => 'press_release',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'inside-eu-osha/press-room' => 'inside-eu-osha/press-room',
        'inside-eu-osha/press-releases' => 'inside-eu-osha/press-releases',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['context_osha_in_the_media'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_press_room';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'press_release' => 'press_release',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'inside-eu-osha/press-room' => 'inside-eu-osha/press-room',
        'inside-eu-osha/press-releases' => 'inside-eu-osha/press-releases',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $export['context_press_room'] = $context;

  return $export;
}

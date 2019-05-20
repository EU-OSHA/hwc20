<?php

/**
 * @file
 * Plugin to check if the title has configured string.
 */

$plugin = array(
  'title' => 'Hide content',
  'description' => t('Hide content in if not checked show checkbox.'),
  'callback' => 'hwc_priority_areas_ctools_access_check',
  'default' => array('negate' => 0),
  'summary' => 'hwc_priority_areas_ctools_access_summary',
  'settings form' => 'hwc_priority_areas_ctools_access_settings',
);

/**
 * Settings form for the 'title hide' access plugin.
 */
function hwc_priority_areas_ctools_access_settings($form, &$form_state, $conf) {
  $form['settings']['checkbox'] = array(
    '#title' => t('Show Checkbox'),
    '#type' => 'select',
    '#options' => array(
      'highlights' => 'Show Highlights',
      'case_studies' => 'Show Case studies',
      'tools_guidance' => 'Show Tools and Guidance',
      'publications' => 'Show Publications',
      'e_tool' => 'Show E-tool',
      'related_links' => 'Show Related links',
    ),
    '#description' => t('Select checkbox to check.'),
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Check for access.
 */
function hwc_priority_areas_ctools_access_check($conf, $context) {
  return hwc_priority_areas_get_topic_related_show_checkbox($conf['checkbox']);
}

/**
 * Provide a summary description.
 */
function hwc_priority_areas_ctools_access_summary($conf, $context) {
  $replacement = array('@checkbox' => $conf['checkbox']);
  return t('"@checkbox" checkbox.', $replacement);
}

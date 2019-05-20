<?php

/**
 * Module's configuration form.
 */
function osha_search_admin_form($form, &$form_state) {
  $form['osha_search_autocomplete'] = array(
    '#title' => 'Search autocomplete',
    '#type' => 'fieldset',
  );
  $form['osha_search_autocomplete']['osha_search_bundles'] = array(
    '#title' => 'Node types to search trough',
    '#type' => 'checkboxes',
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('osha_search_bundles', array()),
  );
  $form['osha_search_autocomplete']['osha_search_ac_categ_limit'] = array(
    '#title' => 'Search AC categories',
    '#description' => 'Number of categories to show in Search Autocomplete',
    '#type' => 'textfield',
    '#default_value' => variable_get('osha_search_ac_categ_limit', 3),
  );
  $form['osha_search_autocomplete']['osha_search_ac_items_limit'] = array(
    '#title' => 'Search AC items',
    '#description' => 'Number of items per category to show in Search Autocomplete',
    '#type' => 'textfield',
    '#default_value' => variable_get('osha_search_ac_items_limit', 3),
  );
  $index_id = variable_get('osha_search_ac_index', 'default_multilingual_node_index');
  $form['osha_search_autocomplete']['osha_search_ac_index'] = array(
    '#title' => 'Search AC index',
    '#description' => 'Number of items per category to show in Search Autocomplete',
    '#type' => 'select',
    '#options' => search_api_index_options_list(),
    '#default_value' => $index_id,
  );
  $index = search_api_index_load($index_id);
  $search_fields = $index->getFulltextFields();
  $form['osha_search_autocomplete']['osha_search_ac_fields'] = array(
    '#title' => 'Search AC index',
    '#description' => 'Number of items per category to show in Search Autocomplete',
    '#type' => 'select',
    '#options' => drupal_map_assoc($search_fields),
    '#default_value' => variable_get('osha_search_ac_fields', array()),
    '#multiple' => TRUE,
  );
  return system_settings_form($form);
}

<?php

/**
 * @file
 * Views integration for Workbench.
 *
 * Provides an argument to display nodes by assigned section.
 */

class osha_workflow_access_handler_argument_access extends views_handler_argument_many_to_one {

  function option_definition() {
    $options = parent::option_definition();

    // Default argument is a passed node id.
    $options['workbench_access_context'] = array('default' => 'nid');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = array(
      'access_id' => t('Access id(s) of current page'),
      'nid' => t('Current node access id(s)'),
    );
    // Our options form.
    $form['workbench_access_context'] = array(
      '#title' => t('Context type'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['workbench_access_context'],
    );

  }

  function query($group_by = FALSE) {
    $active = workbench_access_get_active_tree();
    if ($this->options['workbench_access_context'] == 'nid') {
      $node = node_load($this->argument);
      if (empty($node->workbench_access)) {
        // Break the query?
        return;
      }
      $ids = array_keys($node->workbench_access);
    }
    else {
      if (!isset($active['active'][$this->argument])) {
        return;
      }
      $ids = $active['tree'][$this->argument]['children'];
      $ids[] = $this->argument;
    }
    // Build the query. Since we allow multi-select, this has to be a subquery.
    if (empty($ids)) {
      return;
    }

    // Now add the subquery.
    $table = $active['access_scheme']['field_table'];
    $subquery = db_select($table, $table);
    $subquery->addField($table, 'nid');
    $subquery->distinct();
    $subquery->condition($table . '.' . $active['access_scheme']['query_field'], $ids, 'IN');
    $subquery->condition($table . '.access_scheme', $active['access_scheme']['access_scheme']);

    // Now alter the query, which must have an nid in the base table.
    $this->query->add_where(0, $this->query->base_table . '.nid', $subquery, 'IN');
    return;
  }
}
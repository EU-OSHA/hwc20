<?php
/**
 * @file
 */

class hwc_partner_workbench_partner_type_filter extends views_handler_filter_many_to_one {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->value = array($options['partner_type_tid']);
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['partner_type_tid'] = array('default' => NULL);
    return $options;
  }

  function operator_options($which = 'title') {
    return array(
      'or' => t('Is one of'),
    );
  }

  function get_value_options() {
    $terms = taxonomy_term_load_multiple([], ['vid' => 20]);
    $options = [
      'All' => t('- Any -'),
    ];
    foreach ($terms as $tid => $term) {
      $options[$tid] = $term->name;
    }
    return $options;
  }

  function value_form(&$form, &$form_state) {
    $options = $this->get_value_options();
    $form['partner_type_tid'] = array(
      '#type' => 'select',
      '#title' => t('Sections'),
      '#multiple' => FALSE,
      '#options' => $options,
      '#default_value' => $this->options['partner_type_tid'],
    );
  }

  function value_submit($form, &$form_state) {
    $this->value = $form_state['values']['partner_type_tid'];
  }

  function exposed_form(&$form, &$form_state) {
    // Prevent parent form errors by using a value.
    $form['value'] = array('#type' => 'value', '#value' => '');

    parent::exposed_form($form, $form_state);

    // Build our form element.
    $options = $this->get_value_options();

    $form['partner_type_tid'] = array(
      '#type' => 'select',
      '#multiple' => FALSE,
      '#options' => $options,
      '#default_value' => $this->options['partner_type_tid'],
    );
  }

  function exposed_submit(&$form, &$form_state) {
    if (empty($form_state['values']['partner_type_tid'])) {
      $form_state['values']['partner_type_tid'] = -5;
    }
  }

  function query() {
    if (empty($this->value[0])) {
      return;
    }

    $q = db_select('field_data_field_partner_type', 'w');
    $q->innerJoin('node', 'n', 'w.entity_id = n.nid');
    $q->innerJoin('workbench_access_node', 'a', 'a.nid = n.nid');

    $q->fields('a', ['access_id'])
      ->condition('w.field_partner_type_tid', $this->value[0]);
    $uids = $q->execute()->fetchAllKeyed(0, 0);

    // If workbench_access is not configured, do nothing.
    $active = workbench_access_get_active_tree();

    $ids = array_keys($uids);
    if (!$ids) {
      return;
    }
    $table = $active['access_scheme']['field_table'];
    $subquery = db_select($table, $table);
    $subquery->addField($table, 'nid');
    $subquery->distinct();
    $subquery->condition($table . '.' . $active['access_scheme']['query_field'], $ids, 'IN');
    $subquery->condition($table . '.access_scheme', $active['access_scheme']['access_scheme']);

    $group = $this->query->set_where_group('AND');
    $this->query->add_where($group, "{$this->query->base_table}.nid", $subquery, 'IN');

    $group = $this->query->set_where_group('AND');
    $this->query->add_where($group, "{$this->query->base_table}.type", 'partner', '!=');
  }

}

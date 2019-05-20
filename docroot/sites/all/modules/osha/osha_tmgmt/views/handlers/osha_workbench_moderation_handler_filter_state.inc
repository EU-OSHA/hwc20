<?php
/**
 * @file
 */

/**
 * Filter based on moderation state, override for OSHA content selection
 */
class osha_workbench_moderation_handler_filter_state extends workbench_moderation_handler_filter_state {

  /**
   * Override op_simple from the base class.
   *
   * We need to alter the query to:
   * 1. Remove duplicates - one node published with revision ready_to_publish
   *    appears twice - we add workbench_moderation_node_history.current <> 0
   * 2. When filtering by Published content add also non-workflow nodes in
   *    state published (node.status = 1 and node.type in (non-workflow items))
   *
   * @see op_simple()
   */
  function op_simple() {
    if (empty($this->value)) {
      return;
    }
    $this->ensure_my_table();
    // We use array_values() because the checkboxes keep keys and that can cause
    // array addition problems.

    // Limit the damage to tmgmt_node_selection_view.
    if ((in_array(OSHA_WORKFLOW_STATE_PUBLISHED, $this->value)
        && $this->view->name == 'tmgmt_node_selection_view')
        || (in_array(OSHA_WORKFLOW_STATE_PUBLISHED, $this->value)
            &&$this->view->name == 'administration_content')
    ) {

      $unmoderated = array();
      $types = node_type_get_types();
      foreach ($types as $type) {
        if (!workbench_moderation_node_type_moderated($type->type)) {
          $unmoderated[] = $type->type;
        }
      }
      $this->query->add_where($this->options['group'],
        // ((workbench_moderation_node_history.state IN
        // ('ready_to_publish', 'published'))
        // AND (workbench_moderation_node_history.current <> '0')).
        db_or()
          ->condition(
            db_and()
              ->condition("$this->table_alias.$this->real_field", array_values($this->value), $this->operator)
              ->condition("$this->table_alias.current", '0', '<>')
          )
          ->condition(
            // ((node.type IN
            // ('banner', 'page', 'wiki_page'))
            // AND (node.status = '1')).
            db_and()
              ->condition(
                'node.type',
                $unmoderated,
                'IN'
              )
              ->condition('node.status', 1)
          )
      );
    }
    else {
      // Normal flow of execution ...
      $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", array_values($this->value), $this->operator);
    }
  }
}

<?php

/**
 * Field handler which shows the progressbar.
 *
 * @ingroup views_field_handlers
 */
class osha_tmgmt_handler_field_tmgmt_progress_items extends views_handler_field_entity {

  /**
   * Prefetch statistics for all jobs.
   */
  function pre_render(&$values) {
    parent::pre_render($values);

    // In case of jobs, pre-fetch the statistics in a single query and add them
    // to the static cache.
    if ($this->entity_type == 'tmgmt_job') {
      $tjids = array();
      foreach ($values as $value) {
        // Do not load statistics for aborted jobs.
        if ($value->tmgmt_job_state == TMGMT_JOB_STATE_ABORTED) {
          continue;
        }
        $tjids[] = $value->tjid;
      }
      osha_tmgmt_job_statistics_items_load($tjids);
    }
  }

  /**
   * {@inheritdoc}
   */
  function render($values) {
    $object = $this->get_value($values);
    // If job has been aborted the status info is not applicable.
    if ($object->isAborted()) {
      return t('N/A');
    }
    $states = osha_tmgmt_get_job_item_states();

    $counts = array();
    $title = array();
    foreach ($states as $key => $state) {
      $counts['@' . $key] = $object->getCountofState($key);
      $title[] = $state . ': @' . $key;
    }
    $title = implode(', ', $title);
    $title = strtr($title, $counts);
    return sprintf('<span title="%s">%s</span>', $title, implode('/', $counts));
  }

}

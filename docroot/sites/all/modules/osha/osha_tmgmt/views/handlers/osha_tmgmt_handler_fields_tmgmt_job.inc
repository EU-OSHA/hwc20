<?php

/**
 * Field handler to show the target languages
 *
 * @ingroup views_field_handlers
 */
class tmgmt_handler_field_tmgmt_job_priority extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $object = $this->get_value($values);
    switch ($object) {
      case 1:
        return t('Low');

      case 2:
        return t('High');

      default:
        return t('Normal');
    }
  }

}

/**
 * Class tmgmt_handler_field_tmgmt_job_changed formats the date according to EU.
 */
class tmgmt_handler_field_tmgmt_job_changed extends views_handler_field {
  /**
   * {@inheritdoc}
   */
  public function render($obj) {
    if (!empty($obj->tmgmt_job_changed)) {
      return format_date($obj->tmgmt_job_changed, 'short_date_eu');
    }
    return '';
  }
}

<?php
/**
 * Expose Web Area Contact Form as a Context condition.
 */
class hwc_context_condition_partner_page extends context_condition {
  function condition_values() {
    return array(
      'TRUE' => t('Page belongs to partner'),
      'FALSE' => t('Page do not belongs to partner'),
    );
  }

  function condition_form($context) {
    $form = parent::condition_form($context);

    $form['#type'] = 'radios';
    if(empty($form['#default_value'])){
      $form['#default_value'] = 'TRUE';
    }
    else{
      $form['#default_value'] = current($form['#default_value']);
    }
    return $form;
  }

  /**
   * Condition form submit handler.
   *
   * Storing values in an array since that's what Context prefers
   */
  function condition_form_submit($values) {
    return array_filter(array($values => $values));
  }

  function execute() {
    global $user;
    if ($node = menu_get_object()) {
      foreach ($this->get_contexts() as $context) {
        $values = $this->fetch_from_context($context, 'values');
        if (count(array_intersect(array(HWC_ROLE_ADMIN), $user->roles))) {
          $this->condition_met($context);
        }
        else if (hwc_partner_match_user_partner($node) && !empty($values['TRUE'])) {
          $this->condition_met($context);
        }
        else if (!hwc_partner_match_user_partner($node) && !empty($values['FALSE'])) {
          $this->condition_met($context);
        }
      }
    }
  }
}
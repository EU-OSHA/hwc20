<?php

/**
 * Ajax endpoint to deliver the newsletter subscribe block with CAPTCHA.
 */
function osha_newsletter_block_subscribe_load_ajax() {
  $form = drupal_get_form('campaigns_newsletter_subscribe_captcha_form');
  $email_id = $form['email']['#id'];
  $content = drupal_render($form);
  $commands = array();
  $commands[] = ajax_command_replace('#newsletter-subscription-frontpage-form-wrapper', $content);
  $commands[] = ajax_command_invoke('#' . $email_id, 'focus');
  $commands[] = ajax_command_invoke(NULL, 'captcha_init');
  $page = array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
  ajax_deliver($page);
}

/**
 * Frontpage newsletter subscribe form.
 */
function campaigns_newsletter_subscribe_form() {
  $form['#prefix'] = '<div id="newsletter-subscription-frontpage-form-wrapper">';
  $form['#suffix'] = '</div>';

  $form['email'] = array(
    '#prefix' => '<div style="subscribe_block">',
    '#type' => 'textfield',
    '#size' => 30,
    '#attributes' => array('placeholder' => t('E-mail address'), 'title' => t('E-mail address')),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign up!'),
    '#submit' => array('campaigns_newsletter_subscribe_captcha_form_submit'),
  );
  $form['agree_processing_personal_data'] = array(
    '#suffix' => '</div>',
    '#type' => 'checkbox',
    '#title' => t('I agree to the processing of my personal data'),
    '#default_value' => 0,
  );
  $form['#validate'] = array('campaigns_newsletter_subscribe_captcha_form_validate');

  if (user_is_anonymous()) {
    drupal_add_library('system', 'drupal.ajax');
    drupal_add_library('system', 'jquery.form');
    drupal_add_js(drupal_get_path('module', 'osha_newsletter') . '/js/ajax.js');
  }

  return $form;
}

/**
 * Frontpage newsletter subscribe form with CAPTCHA loaded with ajax.
 */
function campaigns_newsletter_subscribe_captcha_form() {
  $form = array();

  $form['#prefix'] = '<div id="newsletter-subscription-frontpage-form-wrapper">';
  $form['#suffix'] = '</div>';
  $form['email'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#attributes' => array('placeholder' => t('E-mail address'), 'title' => t('E-mail address')),
  );

  $form['captcha'] = array(
    '#type' => 'captcha',
    '#captcha_type' => 'default',
  );

  $form['agree_processing_personal_data'] = array(
    '#suffix' => '</div>',
    '#type' => 'checkbox',
    '#title' => t('I agree to the processing of my personal data'),
    '#default_value' => 0,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign up!'),
    '#submit' => array('campaigns_newsletter_subscribe_captcha_form_submit'),
  );
  return $form;
}

/**
 * Newsletter subscribe form validation.
 */
function campaigns_newsletter_subscribe_captcha_form_validate($form, &$form_state) {
  // Need to redirect due to Ajax handling.
  $has_error = FALSE;
  $referer = empty($_SERVER['HTTP_REFERER']) ? '/' : $_SERVER['HTTP_REFERER'];
  if (form_get_errors()) {
    // Invalid CAPTCHA.
    $has_error = TRUE;
  }

  $agree = trim($form_state['values']['agree_processing_personal_data']);
  if (!$agree) {
    $has_error = TRUE;
    form_set_error('agree_processing_personal_data', t('Please, tick the box to agree in order to submit your email.'));
  }

  if (empty($form_state['values']['email']) || !valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('The e-mail address is not valid.'));
    $has_error = TRUE;
  }
  if ($has_error) {
    if (strpos($referer, '?')) {
      $referer = explode('?', $referer);
      $referer = $referer[0];
    }
    $options['query'] = [
      'agree' => intval($form_state['values']['agree_processing_personal_data']),
      'email' => $form_state['values']['email'],
    ];
    $fs['redirect'] = $referer;
    osha_newsletter_redirect_form($fs, $options);
  }
}

function osha_newsletter_redirect_form($form_state, $options = []) {
  // Skip redirection for form submissions invoked via drupal_form_submit().
  if (!empty($form_state['programmed'])) {
    return;
  }
  // Skip redirection if rebuild is activated.
  if (!empty($form_state['rebuild'])) {
    return;
  }
  // Skip redirection if it was explicitly disallowed.
  if (!empty($form_state['no_redirect'])) {
    return;
  }
  // Only invoke drupal_goto() if redirect value was not set to FALSE.
  if (!isset($form_state['redirect']) || $form_state['redirect'] !== FALSE) {
    if (isset($form_state['redirect'])) {
      if (is_array($form_state['redirect'])) {
        call_user_func_array('drupal_goto', $form_state['redirect'], $options);
      }
      else {
        // This function can be called from the installer, which guarantees
        // that $redirect will always be a string, so catch that case here
        // and use the appropriate redirect function.
        $function = drupal_installation_attempted() ? 'install_goto' : 'drupal_goto';
        $function($form_state['redirect'], $options);
      }
    }
    drupal_goto(current_path(), array('query' => drupal_get_query_parameters()));
  }
}

/**
 * Newsletter subscribe form submit.
 */
function campaigns_newsletter_subscribe_captcha_form_submit($form, &$form_state) {
  $email = $form_state['values']['email'];

  // Need to redirect due to Ajax handling.
  $referer = empty($_SERVER['HTTP_REFERER']) ? '/' : $_SERVER['HTTP_REFERER'];
  $form_state['redirect'] = $referer;

  // Anonymous could avoid click on input and submit form without capcha input
  // so check for captcha.
  if (user_is_anonymous() && !isset($form_state['values']['captcha'])) {
    drupal_set_message('You have sent the form without captcha.', 'error');
    return;
  }
  osha_newsletter_crm_subscribe($email);
}

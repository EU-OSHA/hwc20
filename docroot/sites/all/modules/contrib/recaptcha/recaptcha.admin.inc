<?php

/**
 * @file
 * Provides the Google No CAPTCHA administration settings.
 */

/**
 * Form callback; administrative settings for Google No CAPTCHA.
 */
function recaptcha_admin_settings() {
  // Load the recaptcha library. Error if library does not load.
  if (!_recaptcha_load_library()) {
    drupal_set_message(t('Error loading recaptchalib.'), 'error');
    return FALSE;
  }

  $form = array();
  $form['recaptcha_site_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Site Key'),
    '#default_value' => variable_get('recaptcha_site_key', ''),
    '#maxlength' => 40,
    '#description' => t('The public key given to you when you <a href="@url" target="_blank">register for reCAPTCHA</a>.', array('@url' => 'https://www.google.com/recaptcha/admin#createsite')),
    '#required' => TRUE,
  );
  $form['recaptcha_private_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Private Key'),
    '#default_value' => variable_get('recaptcha_private_key', ''),
    '#maxlength' => 40,
    '#description' => t('The public key given to you when you <a href="@url" target="_blank">register for reCAPTCHA</a>.', array('@url' => 'https://www.google.com/recaptcha/admin#createsite')),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

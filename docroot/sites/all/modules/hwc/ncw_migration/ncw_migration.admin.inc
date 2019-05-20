<?php

/**
 * Module's configuration form.
 */
function ncw_migration_admin_form($form, &$form_state) {
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Synchronisation notification settings'),
  );
  $form['settings']['ncw_migration_synchronisation_mails'] = array(
    '#type' => 'textarea',
    '#title' => t('E-mail addresses'),
    '#default_value' => variable_get('ncw_migration_synchronisation_mails', ''),
  );

  $form['settings']['ncw_migration_template_synchronisation_subject'] = array(
    '#type' => 'textfield',
    '#title' => 'Email subject',
    '#default_value' => variable_get('ncw_migration_template_synchronisation_subject', '[HWC Website] synchronisation notification'),
  );

  $form['settings']['ncw_migration_template_synchronisation_body'] = array(
    '#type' => 'textarea',
    '#title' => 'Email body',
    '#default_value' => variable_get('ncw_migration_template_synchronisation_body', ''),
    '#description' => 'Available tokens [stuck] [stuck_info] [outdated] [outdated_info]',
  );

  $form['settings']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['settings']['test'] = array(
    '#type' => 'submit',
    '#value' => t('Test mail'),
    '#submit' => array('ncw_migration_test_submit'),
  );

  return $form;
}


/**
 * Submit Callback for button Test mail.
 */
function ncw_migration_test_submit($form, &$form_submit) {
  if ($mail = variable_get('ncw_migration_test_mail', '')) {
    $language = language_default();
    $params['outdated'] = [];
    $params['stuck'] = [];
    $message = drupal_mail('ncw_migration', 'ncw_migration_synchronisation', $mail, $language, $params);
    if ($message['result'] === FALSE) {
      drupal_set_message(t('Error sending test mail to @mail', array('@mail' => $mail)));
    }
    else {
      drupal_set_message(t('Test mail sent to @mail', array('@mail' => $mail)));
    }
  }
}

/**
 * Submit callback for settings form of the module.
 */
function ncw_migration_admin_form_submit($form, &$form_state) {
  // Save settings.
  system_settings_form_submit($form, $form_state);
  drupal_set_message(t('Settings saved successfully'));
}


















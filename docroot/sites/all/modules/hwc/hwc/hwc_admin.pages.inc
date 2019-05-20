<?php

function hwc_admin_config_form() {
  $form['title'] = array(
    '#markup' => '<h1>HWC website configuration</h1>',
  );

  $form['hwc_old_site_url'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_old_site_url', ''),
    '#title' => 'Previous campaign site urls. One per line',
  );

  $form['hwc_prev_site_redirect_pages'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_prev_site_redirect_pages', ''),
    '#title' => 'URIs to redirect to previous website',
    '#description' => 'URIs that exists in current website but you want to redirect to the previous websites. One uri per line in format  path/to/page|redirect/to/full/url',
  );

  $form['disable_masquerading_notifications'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable notifications when acts as a partner'),
    '#default_value' => variable_get('disable_masquerading_notifications', FALSE),
    '#description' => t('Possibility to inactivate the notifications when Mostra / EU-OSHA acts as a partner (News and Events)'),
  );

  $form['hwc_mail_bottom_text'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_mail_bottom_text', ''),
    '#title' => 'Mail bottom text',
  );

  $form['fb_app_key'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('fb_app_key', ''),
    '#title' => 'Facebook application key',
  );
  // By default, render the form using theme_system_settings_form().
  if (!isset($form['#theme'])) {
    $form['#theme'] = 'system_settings_form';
  }

  $tags_voc = taxonomy_vocabulary_machine_name_load(OSHA_TAXONOMIES_TAGS);
  $tags = taxonomy_term_load_multiple(array(), array('vid' => $tags_voc->vid));
  $options = array();
  foreach ($tags as $tag) {
    $options[$tag->tid] = $tag->name;
  }
  $form['hwc_current_campaign_tags'] = array(
    '#title' => 'Current campaigns tags',
    '#type' => 'select',
    '#multiple' => TRUE,
    '#options' => $options,
    '#default_value' => variable_get('hwc_current_campaign_tags', array()),
  );
  $form['hwc_partner_registration_deadline'] = array(
    '#title' => 'Campaign partners registration deadline',
    '#description' => 'Starting from 12:00 AM of the date selected here, the registration is no longer visible',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_registration_deadline', ''),
  );
  $deadline_message = variable_get('hwc_partner_registration_deadline_message', '');
  $form['hwc_partner_registration_deadline_message'] = array(
    '#title' => 'Message to show after the registration deadline is over',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => $deadline_message,
  );
  $lid = db_select('locales_source', 'l')
    ->fields('l', ['lid'])
    ->condition('l.source', $deadline_message)
    ->orderBy('l.lid', 'DESC')
    ->execute()
    ->fetchField();
  if (!empty($lid)) {
    $form['hwc_partner_registration_deadline_message']['#description'] = t('!clickhere to translate this string.', ['!clickhere' => l(t('Click here'), '/admin/config/regional/translate/edit/' . $lid)]);
  }

  $form['site_hwc_mostra_mailbox'] = array(
    '#title' => 'Mostra mailbox',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('site_hwc_mostra_mailbox', ''),
  );

  // NCW migration
  if (module_exists('migrate')) {
    $form['migration'] = array(
      '#type' => 'fieldset',
      '#title' => 'Corporate content migration',
      '#collapsible' => TRUE,
      '#weight' => 100,
    );
    $note = 'To disable one of the migrations set the URL empty then Save. Endpoints should expose JSON data';
    if (module_exists('migrate_ui')) {
      $note .= ' ' . l('Visit migration status overview', 'admin/content/migrate/groups/ncw');
    }
    $form['migration']['note'] = array(
      '#type' => 'item',
      '#markup' => $note,
      '#weight' => -1,
    );

    foreach(migrate_migrations() as $machine_name => $meta) {
      $migration = MigrationBase::getInstance($machine_name);
      if ($group = $migration->getGroup()) {
        // Filter all migrations from NCW group
        if ('ncw' == $group->getName()) {
          $form['migration']["hwc_migration_${machine_name}_url"] = array(
            '#type' => 'textfield',
            '#title' => ucfirst(str_replace('_', ' ', $machine_name)) . ' endpoint URI',
            '#default_value' => variable_get("hwc_migration_${machine_name}_url", ''),
            '#description' => 'Uri that will be appended to the Root endpoint URL defined',
            '#size' => 90,
          );
        }
      }
      uksort($form['migration'], 'strcmp');
    }
  }

  $form['migration']["hwc_migration_root_url"] = array(
    '#type' => 'textfield',
    '#title' => 'Root endpoint URL',
    '#default_value' => variable_get("hwc_migration_root_url", ''),
    '#size' => 90,
  );

  $form['hwc_segmentation_urls'] = array(
    '#type' => 'textarea',
    '#title' => 'Segments used for PIWIK',
    '#description' => 'Enter one pair url|segment per line. URL must be current_path.',
    '#default_value' => variable_get("hwc_segmentation_urls", ''),
  );

  $form["hwc_piwik_segment_id"] = array(
    '#type' => 'textfield',
    '#title' => 'Piwik custom dimension ID for segment',
    '#default_value' => variable_get("hwc_piwik_segment_id", 1),
    '#size' => 90,
  );

  $form['hwc_toolkit_about_nid'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('hwc_toolkit_about_nid', 6746),
    '#title' => 'Toolkit about page node nid',
  );

  $form['workflow'] = array(
    '#type' => 'fieldset',
    '#title' => 'Workflow mail settings',
    '#collapsible' => TRUE,
    '#weight' => 101,
  );

  $form['workflow']['hwc_workflow_approved_subject'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('hwc_workflow_approved_subject', ''),
    '#title' => 'Approved subject',
  );

  $form['workflow']['hwc_workflow_approved_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_workflow_approved_body', ''),
    '#title' => 'Approved body',
  );

  $form['workflow']['hwc_workflow_rejection_subject'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('hwc_workflow_rejection_subject', ''),
    '#title' => 'Rejection subject',
  );

  $form['workflow']['hwc_workflow_rejection_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_workflow_rejection_body', ''),
    '#title' => 'Rejection body',
  );

  $form['workflow']['hwc_workflow_supervisor_subject'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('hwc_workflow_supervisor_subject', ''),
    '#title' => 'Supervisor subject',
  );

  $form['workflow']['hwc_workflow_supervisor_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_workflow_supervisor_body', ''),
    '#title' => 'Supervisor body',
  );

  $form['workflow']['hwc_workflow_reviewer_subject'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('hwc_workflow_reviewer_subject', ''),
    '#title' => 'Reviewer subject',
  );

  $form['workflow']['hwc_workflow_reviewer_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_workflow_reviewer_body', ''),
    '#title' => 'Reviewer body',
  );

  $form = system_settings_form($form);
  $form['actions']['#weight'] = 150;
  // Prepend this hook to the beginning of array because we need the unchanged
  // variables.
  array_unshift($form['#submit'], 'hwc_admin_config_form_submit');
  return $form;
}

/**
 * HWC admin configuration form submit.
 */
function hwc_admin_config_form_submit($form, &$form_state) {
  $old_message = variable_get('hwc_partner_registration_deadline_message', '');
  $new_message = $form_state['values']['hwc_partner_registration_deadline_message'];
  if ($old_message != $new_message) {
    locale($new_message);
    $lid = db_select('locales_source', 'l')
      ->fields('l', ['lid'])
      ->condition('l.source', $new_message)
      ->orderBy('l.lid', 'DESC')
      ->execute()
      ->fetchField();
    drupal_set_message(t('New translatable string was added. !clickhere to translate it.',
      [
        '!clickhere' => l(t('Click here'), '/admin/config/regional/translate/edit/' . $lid),
      ]
    ));
  }
}

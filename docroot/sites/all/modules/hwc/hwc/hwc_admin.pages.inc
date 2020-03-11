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

  $form['splash_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Splash mode'),
    '#default_value' => variable_get('splash_mode', FALSE),
  );

  $form['exceptions'] = array(
    '#type' => 'fieldset',
    '#title' => 'Exceptions',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['exceptions']['hwc_hide_meta_description_pages'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_hide_meta_description_pages', ''),
    '#title' => 'Do not show meta description for pages',
    '#description' => 'Page alias list to remove meta description. One alias per line',
  );

  $form['exceptions']['hwc_exclude_banner_titles'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_exclude_banner_titles', ''),
    '#title' => 'Exclude pages from banner titles changes',
    '#description' => 'Page alias nad node url list without banner titles changes. One alias or node/nid per line',
  );

  $form['exceptions']['hwc_exclude_top_share_widget'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_exclude_top_share_widget', ''),
    '#title' => 'Exclude top share widget from nodes',
    '#description' => 'Node list to exclude top share widget. One node id per line',
  );

  $form['exceptions']['hwc_exclude_bottom_share_widget'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('hwc_exclude_bottom_share_widget', ''),
    '#title' => 'Exclude bottom share widget from nodes',
    '#description' => 'Node list to exclude bottom share widget. One node id per line',
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

  $form['campaign_partner'] = array(
    '#type' => 'fieldset',
    '#title' => 'Campaign Partner',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['campaign_partner']['become_campaign_partner_download_title'] = array(
    '#title' => 'Download the Campaign Partnership offer title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_download_title', 'Download the Campaign Partnership offer'),
  );

  $form['campaign_partner']['become_campaign_partner_download_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('become_campaign_partner_download_body', 'Get to know more about the status and make sure you meet the requirements.'),
    '#title' => 'Download the Campaign Partnership offer body',
  );

  $form['campaign_partner']['become_campaign_partner_download_link'] = array(
    '#title' => 'Download the Campaign Partnership offer link',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_download_link', '#'),
  );

  $form['campaign_partner']['become_campaign_partner_download_link_title'] = array(
    '#title' => 'Download the Campaign Partnership offer link title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_download_link_title', 'Download the offer'),
  );

  $form['campaign_partner']['become_campaign_partner_register_title'] = array(
    '#title' => 'Download the Campaign Partnership register link',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_register_title', 'Apply here'),
  );

  $form['campaign_partner']['become_campaign_partner_application_form_title'] = array(
    '#title' => 'Fill up the online application form title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_application_form_title', 'Fill up the online application form'),
  );

  $form['campaign_partner']['become_campaign_partner_application_form_body'] = array(
    '#title' => 'Fill up the online application form body',
    '#type' => 'textarea',
    '#default_value' => variable_get('become_campaign_partner_application_form_body', 'The form will be available from the 6th of december 2020'),
  );

  $form['campaign_partner']['become_campaign_partner_see_results_title'] = array(
    '#title' => 'Get the result title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_see_results_title', 'Get the result'),
  );

  $form['campaign_partner']['become_campaign_partner_see_results_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('become_campaign_partner_see_results_body', 'The internal selection process will take place at the end of May 2020, and candidate organisations will be informed soon after that.'),
    '#title' => 'Get the result body',
  );

  $form['media_partner'] = array(
    '#type' => 'fieldset',
    '#title' => 'Media Partner',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['media_partner']['become_media_partner_download_title'] = array(
    '#title' => 'Download the Media Partnership offer title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_media_partner_download_title', 'Download the Media Partnership offer'),
  );

  $form['media_partner']['become_media_partner_download_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('become_media_partner_download_body', 'Get to know more about the status and make sure you meet the requirements.'),
    '#title' => 'Download the Media Partnership offer body',
  );

  $form['media_partner']['become_media_partner_download_link'] = array(
    '#title' => 'Download the Media Partnership offer link',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_media_partner_download_link', '#'),
  );

  $form['media_partner']['become_media_partner_download_link_title'] = array(
    '#title' => 'Download the Media Partnership offer link title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_media_partner_download_link_title', 'Download the offer'),
  );

  $form['media_partner']['become_media_partner_register_title'] = array(
    '#title' => 'Download the Media Partner register link title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_media_partner_register_title', 'Apply here'),
  );

  $form['media_partner']['become_media_partner_application_form_title'] = array(
    '#title' => 'Fill up the online application form title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_media_partner_application_form_title', 'Fill up the online application form'),
  );

  $form['media_partner']['become_media_partner_application_form_body'] = array(
    '#title' => 'Fill up the online application form body',
    '#type' => 'textarea',
    '#default_value' => variable_get('become_media_partner_application_form_body', 'The form will be available from the 6th of december 2020'),
  );

  $form['media_partner']['become_media_partner_see_results_title'] = array(
    '#title' => 'Get the result title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_media_partner_see_results_title', 'Get the result'),
  );

  $form['media_partner']['become_media_partner_see_results_body'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('become_media_partner_see_results_body', 'The internal selection process will take place at the end of May 2020, and candidate organisations will be informed soon after that.'),
    '#title' => 'Get the result body',
  );

  $form['hwc_partner_how_to_apply_first_date'] = array(
    '#title' => 'Deadline to Download information',
    '#description' => 'How to apply first date',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_how_to_apply_first_date', ''),
  );

  // Deadline to Download information.
  $form['hwc_partner_download_deadline'] = array(
    '#title' => 'Deadline to Download information',
    '#description' => 'Starting from 12:00 AM of the date selected here, the download is no longer visible',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_download_deadline', ''),
  );

  // Deadline for partner registration.
  $form['hwc_partner_registration_deadline'] = array(
    '#title' => 'Deadline for partner registration',
    '#description' => 'Starting from 12:00 AM of the date selected here, the registration is no longer visible',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_registration_deadline', ''),
  );

  $form['hwc_partner_how_to_apply_last_date'] = array(
    '#title' => 'Deadline for partner registration',
    '#description' => 'How to apply last date',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_how_to_apply_last_date', ''),
  );

//  $deadline_message = variable_get('hwc_partner_registration_deadline_message', '');
//  $form['hwc_partner_registration_deadline_message'] = array(
//    '#title' => 'Message to show after the registration deadline is over',
//    '#description' => '',
//    '#type' => 'textfield',
//    '#default_value' => $deadline_message,
//  );
//
//  $lid = db_select('locales_source', 'l')
//    ->fields('l', ['lid'])
//    ->condition('l.source', $deadline_message)
//    ->orderBy('l.lid', 'DESC')
//    ->execute()
//    ->fetchField();
//  if (!empty($lid)) {
//    $form['hwc_partner_registration_deadline_message']['#description'] = t('!clickhere to translate this string.', ['!clickhere' => l(t('Click here'), '/admin/config/regional/translate/edit/' . $lid)]);
//  }

  $form['site_hwc_mostra_mailbox'] = array(
    '#title' => 'Mostra mailbox',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('site_hwc_mostra_mailbox', ''),
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

  // NCW migration.
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

    foreach (migrate_migrations() as $machine_name => $meta) {
      $migration = MigrationBase::getInstance($machine_name);
      if ($group = $migration->getGroup()) {
        // Filter all migrations from NCW group.
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

  $form = system_settings_form($form);
  $form['actions']['#weight'] = 150;
  // Prepend this hook to the beginning of array because we need the unchanged
  // variables.
  array_unshift($form['#submit'], 'hwc_admin_config_form_submit');
  array_unshift($form['#validate'], 'hwc_admin_config_form_validate');
  return $form;
}

/**
 * Validate callback for replace submit.
 */
function hwc_admin_config_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (empty($values['hwc_partner_download_deadline'])) {
    form_set_error('hwc_partner_download_deadline', t('Please enter Deadline to Download information date.'));
    return;
  }
  if (empty($values['hwc_partner_registration_deadline'])) {
    form_set_error('hwc_partner_registration_deadline', t('Please enter Deadline for partner registration date.'));
    return;
  }
  $day = $values['hwc_partner_download_deadline']['day'];
  $month = $values['hwc_partner_download_deadline']['month'];
  $year = $values['hwc_partner_download_deadline']['year'];
  $download_deadline = mktime(0, 0, 0, $month, $day, $year);

  $day = $values['hwc_partner_registration_deadline']['day'];
  $month = $values['hwc_partner_registration_deadline']['month'];
  $year = $values['hwc_partner_registration_deadline']['year'];
  $registration_deadline = mktime(0, 0, 0, $month, $day, $year);
  if ($download_deadline >= $registration_deadline) {
    form_set_error('hwc_partner_download_deadline', t('Deadline to Download information date should be less Deadline for partner registration date.'));
  }
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

function hwc_splash_mode_form($form, &$form_state) {
  if (variable_get('splash_mode', FALSE)) {
    $mode = 'Splash mode ON!';
  }
  else {
    $mode = 'Splash mode OFF!';
  }
  $form['mode'] = array(
    '#markup' => '<h2>' . $mode . '</h2>',
  );
  $form['test'] = array(
    '#type' => 'submit',
    '#value' => t('Toogle splash mode'),
  );
  return $form;
}

function hwc_splash_mode_form_submit($form, &$form_state) {
  $splash_blocks = array(
    'splash_browsing_content',
    'splash_download_news_campaign',
    'splash_title_banner_countdown',
  );
  $home_blocks = array(
    'frontpage_slider-block',
    'front_page_blocks_set',
    'hwc_homepage_tools_and_resources',
    'hwc_homepage_topics',
    'osha_newsletter_image',
    'partners-block_1',
  );

  if (variable_get('splash_mode', FALSE)) {
    variable_set('splash_mode', FALSE);
    drupal_set_message('Splash mode turn off!');
    $enable = $home_blocks;
    $disable = $splash_blocks;
  }
  else {
    variable_set('splash_mode', TRUE);
    drupal_set_message('Splash mode turn on!');
    $enable = $splash_blocks;
    $disable = $home_blocks;
  }

  db_update('block')
    ->fields(array(
      'status' => 0,
    ))
    ->condition('delta', $disable, 'IN')
    ->execute();
  db_update('block')
    ->fields(array(
      'status' => 1,
    ))
    ->condition('delta', $enable, 'IN')
    ->condition('theme', 'hwc_frontend')
    ->execute();
}

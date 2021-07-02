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

  $file = variable_get('hwc_crm_data_dir', '') . '/PublicProfile_HW18.xml';
  $options = [
    'PublicProfile_20.xml' => 'PublicProfile_20.xml',
    'PublicProfile.xml' => 'PublicProfile.xml',
  ];
  if (file_exists($file)) {
    $options['PublicProfile_HW18.xml'] = 'PublicProfile_HW18.xml';
  }
  $form['hwc_crm_data_xml'] = array(
    '#title' => 'PublicProfile source',
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $options,
    '#default_value' => variable_get('hwc_crm_data_xml', ''),
  );

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
    '#title' => 'Download the Campaign Partnership register link title',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_register_title', 'Apply here'),
  );

  $form['campaign_partner']['become_campaign_partner_register_link'] = array(
    '#title' => 'Download the Campaign Partnership register link',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_campaign_partner_register_link', '/partner/register'),
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

  $form['media_partner']['become_media_partner_register_link'] = array(
    '#title' => 'Download the Media Partnership register link',
    '#description' => '',
    '#type' => 'textfield',
    '#default_value' => variable_get('become_media_partner_register_link', '/partner/register'),
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

  $form['hwc_partner_download_deadline'] = array(
    '#title' => 'Deadline to download information',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_download_deadline', ''),
  );

  $form['hwc_partner_registration_deadline'] = array(
    '#title' => 'Deadline for campaign partner registration',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_registration_deadline', ''),
  );

  $form['hwc_partner_media_registration_deadline'] = array(
    '#title' => 'Deadline for media partner registration',
    '#type' => 'date',
    '#default_value' => variable_get('hwc_partner_registration_deadline', ''),
  );

  $form['hwc_partner_registration_last_date_month'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show last date month'),
    '#default_value' => variable_get('hwc_partner_registration_last_date_month', FALSE),
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

  // NCW migration.
  if (module_exists('migrate')) {
    $form['migration'] = array(
      '#type' => 'fieldset',
      '#title' => 'Corporate content migration',
      '#collapsible' => TRUE,
      '#weight' => 100,
    );

    $form['migration']["hwc_migration_exclude_tag_name"] = array(
      '#type' => 'textfield',
      '#title' => 'Exclude tag name',
      '#default_value' => variable_get("hwc_migration_exclude_tag_name", 'Campaign 2020-2022'),
      '#description' => 'Additional resource exclude tag name',
      '#size' => 90,
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
  if (empty($form['#validate'])) {
    $form['#validate'] = [];
  }
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
//    form_set_error('hwc_partner_download_deadline', t('Deadline to Download information date should be less Deadline for partner registration date.'));
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
    'splash_banners-block' => 'views',
    'splash_browsing_content' => 'hwc_homepage',
    'splash_download_news_campaign' => 'hwc_homepage',
    'splash_title_banner_countdown' => 'hwc_homepage',
  );

  $home_blocks = array(
    'homepage_banners-block' => 'views',
    'hwc_homepage_news_events' => 'hwc_homepage',
    'hwc_homepage_newsletter_social' => 'hwc_homepage',
    'hwc_homepage_topics' => 'hwc_homepage',
    'partners-block_1' => 'views',
  );

  $pages_suffix = "\r\n<front>";

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

  foreach ($disable as $delta => $module) {
    $block = block_load($module, $delta);
    $pages = str_replace($pages_suffix, '', $block->pages);
    db_update('block')
      ->fields(['status' => 1, 'pages' => $pages])
      ->condition('bid', $block->bid)
      ->execute();
  }
  foreach ($enable as $delta => $module) {
    $block = block_load($module, $delta);
    $pages = $block->pages . $pages_suffix;
    db_update('block')
      ->fields(['status' => 1, 'pages' => $pages])
      ->condition('bid', $block->bid)
      ->execute();
  }
}

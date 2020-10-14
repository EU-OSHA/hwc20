<?php

/**
 * Implements hook_rules_event_info() on behalf of the node module.
 */
function hwc_workflow_rules_event_info() {
  $items = array(
    'node_cpm_approve' => array(
      'label' => t('After approving a node as CPM'),
      'group' => t('HWC workflow'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Approved node'),
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('Next approver'),
        ),
        'users' => array(
          'type' => 'list<user>',
          'label' => t('Remaining CPMs'),
        ),
      ),
      'access callback' => 'rules_node_integration_access',
    ),
    'node_to_be_approved' => array(
      'label' => t('When setting a node to be approved CPM'),
      'group' => t('HWC workflow'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('Next CPM'),
        ),
        'users' => array(
          'type' => 'list<user>',
          'label' => t('Remaining CPMs'),
        ),
      ),
      'access callback' => 'rules_node_integration_access',
    ),
  );
  return $items;
}

function hwc_workflow_settings_options() {
  return [
    'approve_partner' => 'Approve after partner (Please approve)',
    'rejection' => 'After rejection (Please update)',
    'published' => 'Published (Published)',
    'reviewer' => 'Review (Please review)',
    'approve_mostra' => 'Approve after review (Please approve)',
  ];
}

/**
 * Action Implementation: Send mail.
 */
function hwc_workflow_rules_action_mail($node, $to, $settings_type, $message, $from = NULL, $langcode, $settings, RulesState $state, RulesPlugin $element) {
  reset($settings_type);
  $type = current($settings_type);
  $subject = hwc_workflow_get_mail_subject_text($node, $type);
  $message = hwc_workflow_get_mail_body_text($message, $node, $type);

  $to = str_replace(array("\r", "\n"), '', $to);
  $from = !empty($from) ? str_replace(array("\r", "\n"), '', $from) : NULL;
  $params = array(
    'subject' => $subject,
    'message' => $message,
    'langcode' => $langcode,
    'node' => $node,
  );
  // Set a unique key for this mail.
  $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
  $key = 'rules_action_mail_' . $name . '_' . $element->elementId();
  $languages = language_list();
  $language = isset($languages[$langcode]) ? $languages[$langcode] : language_default();

  $message = drupal_mail('hwc_workflow', $key, $to, $language, $params, $from);
  if ($message['result']) {
    watchdog('hwc_workflow', 'Successfully sent email to %recipient', array('%recipient' => $to));
  }
}

/**
 * Action: Send mail to all users of a specific role group(s).
 */
function hwc_workflow_rules_action_mail_to_users_of_role($node, $settings_type, $roles, $message, $from = NULL, $settings, RulesState $state, RulesPlugin $element) {
  reset($settings_type);
  $type = current($settings_type);
  $subject = hwc_workflow_get_mail_subject_text($node, $type);
  $message = hwc_workflow_get_mail_body_text($message, $node, $type);

  $from = !empty($from) ? str_replace(array("\r", "\n"), '', $from) : NULL;

  // All authenticated users, which is everybody.
  if (in_array(DRUPAL_AUTHENTICATED_RID, $roles)) {
    $result = db_query('SELECT mail FROM {users} WHERE uid > 0');
  }
  else {
    $rids = implode(',', $roles);
    // Avoid sending emails to members of two or more target role groups.
    $result = db_query('SELECT DISTINCT u.mail FROM {users} u INNER JOIN {users_roles} r ON u.uid = r.uid WHERE r.rid IN (' . $rids . ')');
  }

  // Now, actually send the mails.
  $params = array(
    'subject' => $subject,
    'message' => $message,
    'node' => $node,
  );
  // Set a unique key for this mail.
  $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
  $key = 'rules_action_mail_to_users_of_role_' . $name . '_' . $element->elementId();  $languages = language_list();

  $message = array('result' => TRUE);
  foreach ($result as $row) {
    $message = drupal_mail('hwc_workflow', $key, $row->mail, language_default(), $params, $from);
    // If $message['result'] is FALSE, then it's likely that email sending is
    // failing at the moment, and we should just abort sending any more. If
    // however, $mesage['result'] is NULL, then it's likely that a module has
    // aborted sending this particular email to this particular user, and we
    // should just keep on sending emails to the other users.
    // For more information on the result value, see drupal_mail().
    if ($message['result'] === FALSE) {
      break;
    }
  }
  if ($message['result'] !== FALSE) {
    $role_names = array_intersect_key(user_roles(TRUE), array_flip($roles));
    watchdog('hwc_workflow', 'Successfully sent email to the role(s) %roles.', array('%roles' => implode(', ', $role_names)));
  }
}

/**
 * Implements hook_rules_action_info() on behalf of the system module.
 */
function hwc_workflow_rules_action_info() {
  return array(
    'hwc_mail' => array(
      'label' => t('Send custom mail'),
      'group' => t('HWC workflow'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t("The current node"),
        ),
        'to' => array(
          'type' => 'text',
          'label' => t('To'),
          'description' => t('The e-mail address or addresses where the message will be sent to. The formatting of this string must comply with RFC 2822.'),
        ),
        'settings_type' => array(
          'type' => 'list<text>',
          'label' => t('Settings type'),
          'restriction' => 'input',
          'options list' => 'hwc_workflow_settings_options',
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
          'optional' => TRUE,
        ),
        'language' => array(
          'type' => 'token',
          'label' => t('Language'),
          'description' => t('If specified, the language used for getting the mail message and subject.'),
          'options list' => 'entity_metadata_language_list',
          'optional' => TRUE,
          'default value' => LANGUAGE_NONE,
          'default mode' => 'selector',
        ),
      ),
      'base' => 'hwc_workflow_rules_action_mail',
      'access callback' => 'rules_system_integration_access',
    ),

    'hwc_mail_to_users_of_role' => array(
      'label' => t('Send custom mail to all users of a role'),
      'group' => t('HWC workflow'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t("The current node"),
        ),
        'settings_type' => array(
          'type' => 'list<text>',
          'label' => t('Settings type'),
          'restriction' => 'input',
          'options list' => 'hwc_workflow_settings_options',
        ),
        'roles' => array(
          'type' => 'list<integer>',
          'label' => t('Roles'),
          'options list' => 'entity_metadata_user_roles',
          'description' => t('Select the roles whose users should receive the mail.'),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
          'optional' => TRUE,
        ),
      ),
      'base' => 'hwc_workflow_rules_action_mail_to_users_of_role',
      'access callback' => 'rules_system_integration_access',
    ),

    'hwc_workflow_mail' => array(
      'label' => t('Send mail to ...'),
      'group' => t('HWC workflow'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t("The current node"),
        ),
        'settings_type' => array(
          'type' => 'list<text>',
          'label' => t('Settings type'),
          'restriction' => 'input',
          'options list' => 'hwc_workflow_settings_options',
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The mail's subject."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
      ),
      'base' => 'hwc_workflow_rules_mail_to_partners',
      'access callback' => 'rules_system_integration_access',
    ),

    'hwc_custom_mail_to_users_of_partner' => array(
      'label' => t('Send custom mail to all users of a partner'),
      'group' => t('HWC workflow'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t("The current node"),
        ),
        'settings_type' => array(
          'type' => 'list<text>',
          'label' => t('Settings type'),
          'restriction' => 'input',
          'options list' => 'hwc_workflow_settings_options',
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
      ),
      'base' => 'hwc_workflow_custom_mail_to_users_of_partner',
      'access callback' => 'rules_system_integration_access',
    ),

    'hwc_mail_to_users_of_partner' => array(
      'label' => t('Send mail to all users of a partner'),
      'group' => t('HWC workflow'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t("The current node"),
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The mail's subject."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
      ),
      'base' => 'hwc_workflow_rules_mail_to_partners',
      'access callback' => 'rules_system_integration_access',
    ),

    'hwc_mail_to_related_partners' => array(
      'label' => t('Send mail to related partners'),
      'group' => t('HWC workflow'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t("The current node"),
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The mail's subject."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
      ),
      'base' => 'hwc_workflow_rules_mail_to_related_partners',
      'access callback' => 'rules_system_integration_access',
    ),

  );
}

/**
 * Implements hook_rules_condition_info() on behalf of the entity module.
 */
function hwc_workflow_rules_condition_info() {
  return array(
    'node_een_partner' => array(
      'label' => t('Node has een partner type'),
      'parameter' => array(
        'entity' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t('Specifies the node for which to evaluate the condition.'),
        ),
      ),
      'group' => t('HWC workflow'),
      'base' => 'hwc_workflow_rules_condition_node_een_partner',
    ),
    'disable_masquerading_notifications' => array(
      'label' => t('Disable notifications when acts as a partner'),
      'group' => t('HWC workflow'),
      'base' => 'hwc_workflow_rules_condition_disable_masquerading_notifications',
    ),
    'node_has_partner_section' => array(
      'label' => t('Node has a partner section'),
      'parameter' => array(
        'entity' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t('Specifies the node for which to evaluate the condition.'),
        ),
      ),
      'group' => t('HWC workflow'),
      'base' => 'hwc_workflow_rules_condition_node_has_partner_section',
    ),
    'document_related_partner_notifications' => array(
      'label' => t('Disable notifications when no related partners'),
      'parameter' => array(
        'entity' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t('Specifies the node for which to evaluate the condition.'),
        ),
      ),
      'group' => t('HWC workflow'),
      'base' => 'hwc_workflow_rules_condition_document_related_partner_notifications',
    ),
  );
}

/**
 * Condition: Disable notifications when no related partners.
 */
function hwc_workflow_rules_condition_document_related_partner_notifications($node) {
  if ($node->type != 'document') {
    return FALSE;
  }
  $partner_types = _hwc_workflow_get_document_partner_types($node);
  if (!$partner_types) {
    return FALSE;
  }
  return TRUE;
}

/**
 * Condition: Node has een partner type.
 */
function hwc_workflow_rules_condition_node_een_partner($node) {
  return hwc_workflow_is_een_partner_type($node);
}

/**
 * Condition: Disable masquerading notifications.
 */
function hwc_workflow_rules_condition_disable_masquerading_notifications($node) {
  $allow_notification = TRUE;
  if (isset($_SESSION['masquerading']) && variable_get('disable_masquerading_notifications', 0)) {
    $allow_notification = FALSE;
  }
  return $allow_notification;
}

/**
 * Condition: Entity is of type.
 */
function hwc_workflow_rules_condition_node_has_partner_section($node) {
  if (!empty($node->workbench_access)) {
    $section_id = current($node->workbench_access);
    // If it's a partner section.
    if ($section_id != 'section') {
      return TRUE;
    }
  }
  return FALSE;
}

/*
 * Document partner types.
 */
function _hwc_workflow_get_document_partner_types($node) {
  reset($node->workbench_access);
  $access_id = current($node->workbench_access);
  if ($access_id != 'section') {
    return [];
  }
  $wrapper = entity_metadata_wrapper('node', $node);
  $share_partner_type = $wrapper->field_share_partner_type->value();
  $partner_types = [];
  foreach ($share_partner_type as $term) {
    $partner_types[] = $term->field_partner_type_code[LANGUAGE_NONE][0]['value'];
  }
  return $partner_types;
}

/*
 * Document partner types users.
 */
function _hwc_workflow_get_document_partner_types_users($partner_types) {
  $q = db_select('field_data_field_partner_type', 'w');
  $q->innerJoin('node', 'n', 'w.entity_id = n.nid');
  $q->innerJoin('workbench_access_node', 'a', 'a.nid = n.nid');
  $q->innerJoin('workbench_access_user', 'u', 'u.access_id = a.access_id');
  $q->innerJoin('users', 'us', 'us.uid = u.uid');

  $q->fields('u', ['uid'])
    ->condition('w.field_partner_type_tid', $partner_types)
    ->condition('n.type', 'partner', '=')
    ->condition('n.status', '1')
    ->condition('a.access_id', 'section', '!=')
    ->condition('u.access_scheme', 'taxonomy')
    ->condition('us.status', '1');
  $uids = $q->execute()->fetchAllKeyed(0, 0);
  return user_load_multiple($uids);
}

/**
 * Action: Send mail to related partners.
 */
function hwc_workflow_rules_mail_to_related_partners($node, $subject, $message, $settings, RulesState $state, RulesPlugin $element) {
  $partner_types = _hwc_workflow_get_document_partner_types($node);

  $users = _hwc_workflow_get_document_partner_types_users($partner_types);
  $params = array(
    'subject' => $subject,
    'message' => $message,
  );
  // Set a unique key for this mail.
  $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
  $key = 'rules_action_hwc_workflow_rules_mail_to_partners_' . $name . '_' . $element->elementId();

  $message = array('result' => TRUE);
  foreach ($users as $user) {
    $message = drupal_mail('hwc_workflow', $key, $user->mail, language_default(), $params);
    // If $message['result'] is FALSE, then it's likely that email sending is
    // failing at the moment, and we should just abort sending any more. If
    // however, $mesage['result'] is NULL, then it's likely that a module has
    // aborted sending this particular email to this particular user, and we
    // should just keep on sending emails to the other users.
    // For more information on the result value, see drupal_mail().
    if ($message['result'] === FALSE) {
      break;
    }
  }

  if ($message['result'] !== FALSE) {
    watchdog('hwc_workflow', 'Successfully sent email to the users of the partners.', array());
  }
}

function hwc_workflow_custom_mail_to_users_of_partner($node, $settings_type, $message, $settings, RulesState $state, RulesPlugin $element) {
  if (!empty($node->workbench_access)) {
    reset($node->workbench_access);
    $section_id = current($node->workbench_access);
    reset($settings_type);

    $type = current($settings_type);
    $subject = hwc_workflow_get_mail_subject_text($node, $type);
    $message = hwc_workflow_get_mail_body_text($message, $node, $type);

    // If it's a partner section.
    if ($section_id != 'section') {
      $users = _hwc_workflow_load_users_by_section($section_id);
      $params = array(
        'subject' => $subject,
        'message' => $message,
        'node' => $node,
      );
      // Set a unique key for this mail.
      $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
      $key = 'rules_action_hwc_workflow_rules_mail_to_partners_' . $name . '_' . $element->elementId();  $languages = language_list();

      $message = array('result' => TRUE);
      foreach ($users as $user) {
        $message = drupal_mail('hwc_workflow', $key, $user->mail, language_default(), $params);
        // If $message['result'] is FALSE, then it's likely that email sending is
        // failing at the moment, and we should just abort sending any more. If
        // however, $mesage['result'] is NULL, then it's likely that a module has
        // aborted sending this particular email to this particular user, and we
        // should just keep on sending emails to the other users.
        // For more information on the result value, see drupal_mail().
        if ($message['result'] === FALSE) {
          break;
        }
      }
      if ($message['result'] !== FALSE) {
        watchdog('hwc_workflow', 'Successfully sent email to the users of the partner %partner.', array('%partner' => $section_id));
      }
    }
  }
}

/**
 * Action: Send mail to all users of a partner.
 */
function hwc_workflow_rules_mail_to_partners($node, $subject, $message, $settings, RulesState $state, RulesPlugin $element) {
  if (!empty($node->workbench_access)) {
    reset($node->workbench_access);
    $section_id = current($node->workbench_access);
    // If it's a partner section.
    if ($section_id != 'section') {
      $users = _hwc_workflow_load_users_by_section($section_id);
      $params = array(
        'subject' => $subject,
        'message' => $message,
      );
      // Set a unique key for this mail.
      $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
      $key = 'rules_action_hwc_workflow_rules_mail_to_partners_' . $name . '_' . $element->elementId();  $languages = language_list();

      $message = array('result' => TRUE);
      foreach ($users as $user) {
        $message = drupal_mail('hwc_workflow', $key, $user->mail, language_default(), $params);
        // If $message['result'] is FALSE, then it's likely that email sending is
        // failing at the moment, and we should just abort sending any more. If
        // however, $mesage['result'] is NULL, then it's likely that a module has
        // aborted sending this particular email to this particular user, and we
        // should just keep on sending emails to the other users.
        // For more information on the result value, see drupal_mail().
        if ($message['result'] === FALSE) {
          break;
        }
      }
      if ($message['result'] !== FALSE) {
        watchdog('hwc_workflow', 'Successfully sent email to the users of the partner %partner.', array('%partner' => $section_id));
      }
    }
  }
}

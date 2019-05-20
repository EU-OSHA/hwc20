<?php

function hwc_workflow_node_ep_assign_form($form, &$form_state, $node) {
  global $user;
  $form =  array();
  $form['#tree'] = TRUE;
  $form['#theme'] = 'hwc_workflow_node_ep_assign_form';

  if (empty($node->workbench_access)) {
    drupal_set_message('No section assigned to the node.');
    return $form;
  }
  $can_edit = _hwc_workflow_can_edit_ep($node);
  $form['#node'] = $node;
  $form['#can_edit'] = $can_edit;
  $eps = OshaWorkflowPermissions::getUsersByRole(HWC_ROLE_HWC_STAFF_REVIEWERS);
  $options = array('' => t('-- Please select --'));
  foreach ($eps as $uid => $ep) {
    $options[$uid] = $ep->name;
  }
  $external_providers = _hwc_workflow_get_external_providers($node->nid);
  $ep_entries = _hwc_workflow_get_external_providers_entries($node->nid);
  if (!empty($ep_entries)) {
    $weight = 0;
    $form['rows']['#tree'] = TRUE;
    foreach ($ep_entries as $uid => $pm) {
      $form['rows'][$uid]['name'] = array(
        '#markup' => $external_providers[$uid]->name,
      );
      $form['rows'][$uid]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#title_display' => 'invisible',
        '#default_value' => $weight,
        '#access' => $can_edit,
        '#attributes' => array('class' => array('user-weight')),
      );
      $form['rows'][$uid]['uid'] = array(
        '#type' => 'hidden',
        '#value' => $uid,
      );
      $form['rows'][$uid]['approved'] = array(
        '#markup' => 'Waiting for approval',
      );
      if (!empty($pm->approved)) {
        $form['rows'][$uid]['approved']['#markup'] = ($pm->approved == 'approved') ? 'Approved' : 'Rejected';
      }
      $form['rows'][$uid]['message'] = array(
        '#markup' => $pm->message,
      );
      $form['rows'][$uid]['remove'] = array(
        '#type' => 'submit',
        '#name' => $uid,
        '#value' => t('Remove'),
        '#access' => $can_edit,
        '#submit' => array('hwc_workflow_admin_ep_remove_row_submit'),
      );
      $weight++;
    }
  }
  $form['add']['uid'] = array(
    '#type' => 'select',
    '#title' => t('Add a CPM'),
    '#options' => $options,
    '#access' => $can_edit,
  );
  $form['add']['submit'] = array(
    '#type' => 'submit',
    '#name' => 'adduser',
    '#value' => t('Add to queue'),
    '#access' => $can_edit,
    '#attributes' => array('class' => array('container-inline')),
    '#submit' => array('hwc_workflow_admin_ep_add_row_submit'),
  );
  $form['help'] = array(
    '#type' => 'markup',
    '#markup' =>
      t('<div><strong>Tip:</strong> Use the drag handlers to sort the users in the order you want them to have the content reviewed.
<br />Press Save to confirm your reordering!</div>'),
    '#access' => $can_edit,
  );
  $form['content'] = array(
    'actions' => array(
      '#type' => 'actions',
      '#weight' => 20,
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Save'),
        '#access' => $can_edit,
      ),
    ),
  );

  hwc_workflow_node_ep_actions_append($form, $node);

  return $form;
}

function hwc_workflow_node_ep_actions_append(&$form, $node) {
  global $user;
  if ($current_approver = _hwc_workflow_get_current_ep_approver($node->nid)) {
    // Approval settings.
    $form['ep_actions'] = array(
      '#type' => 'container',
      '#access' => _hwc_workflow_can_ep_approve($node),
    );
    $form['ep_actions']['approve'] = array(
      '#type' => 'submit',
      '#value' => 'Approve',
      '#submit' => array('hwc_workflow_ep_approve_submit'),
    );
    if ($current_approver->uid != $user->uid) {
      $form['ep_actions']['approve']['#suffix'] = t('You can approve on behalf of %user', array('%user' => $current_approver->name));
    }
    $form['ep_actions']['reject'] = array(
      '#type' => 'submit',
      '#value' => 'Reject',
      '#submit' => array('hwc_workflow_ep_reject_submit'),
      '#access' => $current_approver->uid == $user->uid,
    );
  }
}

function hwc_workflow_node_ep_assign_form_submit($form, $form_state) {
  if (!empty($form_state['input']['rows'])) {
    $entries = _hwc_workflow_get_external_providers_entries($form['#node']->nid);
    foreach ($form_state['input']['rows'] as $row) {
      if (!empty($entries[$row['uid']])) {
        $entries[$row['uid']]->weight = $row['weight'];
        _hwc_workflow_admin_ep_save_row($entries[$row['uid']]);
      }
    }
  }
}

/**
 * CPM Reject button callback.
 */
function hwc_workflow_ep_reject_submit($form, &$form_submit) {
  global $user;
  $row = _hwc_workflow_get_current_ep_approver_entry($form['#node']->nid);
  if (!empty($row)) {
    $row->approved = 'rejected';
    $row->message = t('!user rejected on !date', array('!user' => $user->name, '!date' => date('d-m-Y H:i:s')));
    _hwc_workflow_admin_ep_save_row($row);
    workbench_moderation_moderate($form['#node'], 'needs_review');
  }
  else {
    drupal_set_message('No current ep found.');
  }
}

/**
 * CPM Approve button.
 */
function hwc_workflow_ep_approve_submit($form, &$form_submit) {
  global $user;
  $row = _hwc_workflow_get_current_ep_approver_entry($form['#node']->nid);
  if (!empty($row)) {
    $row->approved = 'approved';
    if ($user->uid == $row->uid) {
      $message = t('!user approved on !date', array('!user' => $user->name, '!date' => date('d-m-Y H:i:s')));
    }
    else {
      $curr_approver = user_load($row->uid);
      $message = t('!user approved on behalf of !approver on !date', array('!user' => $user->name, '!date' => date('d-m-Y H:i:s'), '!approver' => $curr_approver->name));
    }
    $row->message = $message;
    _hwc_workflow_admin_ep_save_row($row);

    $next_approver = _hwc_workflow_get_current_ep_approver($form['#node']->nid);
    if (empty($next_approver)) {
      // If no any approver, publish the content.
      workbench_moderation_moderate($form['#node'], 'published');
      drupal_set_message(t('The content has been published'));
    }
    else {
      $remaining_approvers = _hwc_workflow_get_remaining_ep_approvers($form['#node']->nid);
      reset($remaining_approvers);
      $next_approver = array_shift($remaining_approvers);
      // Invoke the rule event
      rules_invoke_event('node_ep_approve', $form['#node'], $next_approver, $remaining_approvers);
    }
  }
  else {
    drupal_set_message('No current ep found.');
  }
}

/**
 * Form theme callback
 */
function theme_hwc_workflow_node_ep_assign_form($variables) {
  $form = $variables['form'];

  // Initialize the variable which will store our table rows.
  $rows = array();

  // Iterate over each element in our $form['example_items'] array.
  foreach (element_children($form['rows']) as $id) {
    $form['rows'][$id]['weight']['#attributes']['class'] = array('user-item-weight');
    $rows[] = array(
      'data' => array(
        // Add our 'name' column.
        drupal_render($form['rows'][$id]['name']),
        // Add our 'weight' column.
        drupal_render($form['rows'][$id]['approved']),

        drupal_render($form['rows'][$id]['message']),

        drupal_render($form['rows'][$id]['remove']),

        drupal_render($form['rows'][$id]['weight']),

      ),
      'class' => array('draggable'),
    );
  }
  $header = array(t('Name'), t('Approval'), t('Message'), t('Actions'), t('Weight'));

  $table_id = 'users-items-table';

  // We can render our tabledrag table for output.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));

  $output .= drupal_render_children($form);
  if ($form['#can_edit']) {
    drupal_add_tabledrag($table_id, 'order', 'sibling', 'user-item-weight');
  }


  return $output;
}

/**
 * Submit callback for remove button from a row.
 */
function hwc_workflow_admin_ep_remove_row_submit($form, &$form_state) {
  if (isset($form_state['triggering_element'])) {
    $triggering_element = $form_state['triggering_element'];
    if (isset($triggering_element['#name'])) {
      $uid = $triggering_element['#name'];
      db_delete('osha_workflow_node_external_providers')
        ->condition('nid', $form['#node']->nid)
        ->condition('uid', $uid)
        ->execute();
    }
  }
}

/**
 * Add external providers to node.
 */
function hwc_workflow_adde_ep_to_node($uid, $nid) {
  $existing_entries = _hwc_workflow_get_external_providers_entries($nid);
  $weight = 0;
  if (!empty($existing_entries)) {
    $last = end($existing_entries);
    $weight = $last->weight > 0 ? $last->weight + 1 : $last->weight - 1;
  }
  $row = array(
    'nid' => $nid,
    'uid' => $uid,
    'weight' => $weight,
  );
  _hwc_workflow_admin_ep_save_row($row);
}

/**
 * Remove external providers from node.
 */
function hwc_workflow_remove_ep_from_node($uid, $nid) {
  db_delete('osha_workflow_node_external_providers')
    ->condition('nid', $nid)
    ->condition('uid', $uid)
    ->execute();
}

/**
 * Submit callback for Add user button.
 */
function hwc_workflow_admin_ep_add_row_submit($form, &$form_state) {
  if (!empty($form_state['values']['add']['uid'])) {
    $moderator = user_load($form_state['input']['add']['uid']);
    if (!empty($moderator)) {
      $existing_entries = _hwc_workflow_get_external_providers_entries($form['#node']->nid);
      if ($existing_entries[$moderator->uid]) {
        drupal_set_message('This user is already assigned', 'warning');
        return;
      }
      $weight = 0;
      if (!empty($existing_entries)) {
        $last = end($existing_entries);
        $weight = $last->weight > 0 ? $last->weight + 1 : $last->weight -1;
      }
      $row = array(
        'nid' => $form['#node']->nid,
        'uid' => $moderator->uid,
        'weight' => $weight,
      );
      _hwc_workflow_admin_ep_save_row($row);
    }
  }
}

/**
 * Get ep users assigned for a node
 */
function _hwc_workflow_get_external_providers($nid) {
  return user_load_multiple(array_keys(_hwc_workflow_get_external_providers_entries($nid)));
}

/**
 * Get database entries for a node from osha_workflow_node_external_providers.
 */
function _hwc_workflow_get_external_providers_entries($nid) {
  $data = &drupal_static(__FUNCTION__);
  if (!isset($data[$nid])) {
    $data[$nid] = db_select('osha_workflow_node_external_providers', 'p')
      ->fields('p')
      ->condition('nid', $nid)
      ->orderBy('weight', 'ASC')
      ->execute()
      ->fetchAllAssoc('uid');
  }
  return $data[$nid];
}

/**
 * Insert or update an osha_workflow_node_external_providers entry.
 */
function _hwc_workflow_admin_ep_save_row($row) {
  if (is_object($row)) {
    $row = (array) $row;
  }
  if (isset($row['npmid'])) {
    return drupal_write_record('osha_workflow_node_external_providers', $row, array('npmid'));
  }
  else {
    return drupal_write_record('osha_workflow_node_external_providers', $row);
  }
}

function _hwc_workflow_node_has_ep($node, $account) {
  $cpms = _hwc_workflow_get_external_providers_entries($node->nid);
  return in_array($account->uid, array_keys($cpms));
}

function _hwc_workflow_can_edit_ep($node, $account = NULL) {
  if (!empty($node->workbench_moderation['current']) &&
    $node->workbench_moderation['current']->state != OSHA_WORKFLOW_STATE_TO_BE_REVIEWED) {
  }
  if (empty($account)) {
    global $user;
    $account = $user;
  }
  return user_access('assign external providers to node', $account);
}


function _hwc_workflow_get_current_ep_approver($nid) {
  $entry = _hwc_workflow_get_current_ep_approver_entry($nid);
  if (!empty($entry)) {
    return user_load($entry->uid);
  }
  return NULL;
}

function _hwc_workflow_get_current_ep_approver_entry($nid) {
  $entries = _hwc_workflow_get_external_providers_entries($nid);
  foreach ($entries as $entry) {
    if (empty($entry->approved)) {
      return $entry;
    }
  }
  return NULL;
}

function _hwc_workflow_get_remaining_ep_approvers($nid) {
  $remaining = db_select('osha_workflow_node_project_managers', 'pm')
    ->fields('pm')
    ->condition('nid', $nid)
    ->isNull('approved')
    ->execute()
    ->fetchAllAssoc('uid');
  if (!empty($remaining)) {
    return user_load_multiple(array_keys($remaining));
  }
  return NULL;
}

function _hwc_workflow_can_ep_approve($node, $account = NULL) {
  global $user;
  if (empty($account)) {
    $account = $user;
  }
  if (empty($node->workbench_moderation['current'])
    || $node->workbench_moderation['current']->state != OSHA_WORKFLOW_STATE_TO_BE_APPROVED) {
    return FALSE;
  }
  $is_admin = OshaWorkflowPermissions::userHasRole(HWC_ROLE_ADMIN, $account);
  // Remove rm and supervisor from approving on behalf - HCW-1126
  // not sure is really accurate this request
  if ($is_admin) {
    return TRUE;
  }
  if (OshaWorkflowPermissions::userHasRole(HWC_ROLE_HWC_STAFF_REVIEWERS, $account)
    && _hwc_workflow_node_has_ep($node, $account)) {
    return TRUE;
  }
  return FALSE;
}

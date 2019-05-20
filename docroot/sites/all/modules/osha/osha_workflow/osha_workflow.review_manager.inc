<?php

function osha_workflow_workbench_review_managers($access_type = NULL, $access_type_id = NULL) {
  if (is_null($access_type) || is_null($access_type_id)) {
    // Set proper breadcrumb trails.
    $breadcrumb[] = t('Review Managers');
    $current = drupal_get_breadcrumb();
    $current = array_merge($current, $breadcrumb);
    drupal_set_breadcrumb($current);

    // Ensure that we have configured access controls.
    if (!$active = workbench_access_get_active_tree()) {
      return workbench_access_configuration_needed_message();
    }
    $active['access_scheme']['access_id'] = NULL;
    $output = '<h2>' . t('Editorial assignments by review manager') . '</h2>';
    $output .= '<p>' . t('The following sections are currently active.');
    if (user_access('administer workbench access')) {
      $output .= ' ' . t('You may <a href="!url">enable or disable sections</a>.', array('!url' => url('admin/config/workbench/access/sections'))) . '</p>';
    }
    $rows = array();
    foreach ($active['tree'] as $access_id => $section) {
      if (!isset($active['active'][$access_id])) {
        continue;
      }
      // Nest the children so the user understands the hierarchy.
      if ($section['depth'] == 0 || !isset($active['active'][$section['parent']])) {
        $parent = $section['name'];
      }
      $row = array(
        str_repeat('-', $section['depth'] ) . ' ' . $section['name'],
      );
      $roles = workbench_access_get_roles('access workbench access by role');
      if (empty($roles)) {
        if (user_access('administer permissions')) {
          return t('To continue, at least one role must be have the <a href="!url">Allow all members of this role to be assigned to Workbench Access sections</a> permission', array('!url' => url('admin/people/permissions', array('fragment' => 'module-workbench_access'))));
        }
        else {
          return t('There are no roles who have permission to edit sections. Please contact a site administrator.');
        }
      }
      if (!isset($roles[DRUPAL_AUTHENTICATED_RID])) {
        $pms = db_query("SELECT wau.uid as uid, us.name as name FROM {osha_workflow_access_rm} wau
            INNER JOIN {users_roles} ur ON wau.uid = ur.uid
            INNER JOIN {users} us ON wau.uid = us.uid
            WHERE wau.access_scheme = :access_scheme AND wau.access_id = :access_id
            AND ur.rid IN (:rids)",
          array(':access_scheme' => $active['access_scheme']['access_type'], ':access_id' => $access_id, ':rids' => array_keys($roles))
        )->fetchAllKeyed();
      }
      else {
        $pms = db_query("SELECT wau.uid as uid, us.name as name FROM {osha_workflow_access_rm} wau
            INNER JOIN {users} us ON wau.uid = us.uid
            WHERE wau.access_scheme = :access_scheme AND wau.access_id = :access_id",
          array(':access_scheme' => $active['access_scheme']['access_type'], ':access_id' => $access_id)
        )->fetchAllKeyed();
      }
      $count = count($pms);
      $new_row = format_plural($count, '1 Review Manager', '@count Review Managers');
      if (!empty($pms)) {
        $new_row .= ' (' . implode(', ',$pms ) . ') ';
      }
      $row[] = $new_row;

      $rows[] = $row;
    }
    $header = array(t('Section'), t('Managers'));
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
    $build['content']['#markup'] = $output;
    return $build;
  }
  return drupal_get_form('osha_workflow_access_rm_form', $access_type, $access_type_id);
}

/**
 * Find the RM for a section. Look at given section or retrieve the root RMs.
 *
 * @param int|string $section_id
 *   Id of the section to search PM for
 *
 * @return array
 *   User objects
 */
function osha_workflow_access_find_section_rm($section_id) {
  $users = osha_workflow_access_get_section_rm($section_id);
  if (empty($users)) {
    $users = osha_workflow_access_get_section_rm('section');
  }
  else {
    return $users;
  }
  return $users;
}

/**
 * Get Review Managers for a section
 */
function osha_workflow_access_get_section_rm($section_id) {
  $section_tree = workbench_access_get_active_tree();
  $access = $section_tree['tree'][$section_id];
  $access_id = $access['access_id'];
  $access_scheme = $section_tree['access_scheme']['access_scheme'];

  $ret = array();
  $users = db_select('osha_workflow_access_rm', 'owa')
    ->fields('owa', array('uid'))
    ->condition('access_id', $access_id, '=')
    ->condition('access_scheme', $access_scheme)
    ->execute()
    ->fetchAllAssoc('uid');
  if (!empty($users)) {
    $ret = user_load_multiple(array_keys($users));
  }
  return $ret;
}

/**
 * Get sections ids of a rm.
 */
function osha_workflow_access_get_rm_sections($uid) {
  $sections = db_select('osha_workflow_access_rm', 'owa')
    ->fields('owa', array('access_id'))
    ->condition('uid', $uid)
    ->execute()
    ->fetchAllAssoc('access_id');
  if (in_array('section', array_keys($sections))) {
    $sections = db_select('workbench_access', 'wa')
      ->fields('wa', array('access_id'))
      ->condition('access_scheme', 'taxonomy')
      ->condition('access_type_id', 'section')
      ->execute()
      ->fetchAllAssoc('access_id');
  }
  return array_keys($sections);
}

/**
 * Compute the review managers in charge of the node. Check assigned section
 * @param $node
 *
 * @return array
 */
function osha_workflow_get_node_rm($node) {
  $users = array();
  if (!empty($node->workbench_access)) {
    reset($node->workbench_access);
    $section = current($node->workbench_access);
    $users = osha_workflow_access_find_section_rm($section);
  }
  return $users;
}

function osha_workflow_access_rm_form($form, &$form_state, $access_type, $access_type_id) {
  // Set proper breadcrumb trails.
  $breadcrumb[] = l(t('Workbench Access'), 'admin/config/workbench/access');
  $breadcrumb[] = l(t('Review Managers'), 'admin/config/workbench/access/review-managers');
  $current = drupal_get_breadcrumb();
  $current = array_merge($current, $breadcrumb);
  drupal_set_breadcrumb($current);

  $form = array();
  $active = workbench_access_get_active_tree();
  $active['access_scheme']['access_id'] = $access_type_id;
  if ($active['access_scheme']['access_type'] != $access_type || !isset($active['active'][$access_type_id])) {
    drupal_access_denied();
    drupal_exit();
  }

  // Get the list of user roles that can be assigned workbench access.
  $roles = workbench_access_get_roles('access workbench access by role');

  $query = db_select('users', 'u')
    ->fields('u', array('uid', 'name'));
  $query->join('osha_workflow_access_rm', 'wau', 'u.uid = wau.uid');
  $query->condition('wau.access_scheme', $access_type)
    ->condition('wau.access_id', $access_type_id)
    ->extend('PagerDefault')->limit(25);
  $result = $query->execute();
  $form['users']['#tree'] = TRUE;
  foreach ($result as $account) {
    $form['users'][$account->uid]['name'] = array('#markup' => l($account->name, 'user/' . $account->uid));
    $form['users'][$account->uid]['remove'] = array(
      '#type' => 'checkbox',
      '#title' => t('Remove'),
    );
  }
  $options = array('' => "Select a Review Manager");
  $options += osha_workflow_users_get_users_from_role_as_options(HWC_ROLE_WEBSITE_MANAGERS);
  $form['add_user'] = array(
    '#type' => 'select',
    '#title' => t('Add Project Manager'),
    '#options' => $options,
    '#default_value' => "",
  );
  $form['workbench_access'] = array(
    '#type' => 'value',
    '#value' => $active['access_scheme'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update Review Managers'),
  );
  return $form;
}

/**
 * Process form submission for adding editors.
 */
function osha_workflow_access_rm_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  // User handling.
  if (!empty($values['add_user'])) {
    $account = user_load($values['add_user']);
    $section_id = $values['workbench_access']['access_id'];
    $existing_users = osha_workflow_access_get_section_rm($section_id);
    if (empty($account)) {
      form_set_error('add_user', t('The selected user does not exist.'));
    }
    elseif (in_array($account->uid, array_keys($existing_users))) {
      form_set_error('add_user', t('The user already assigned.'));
    }
    elseif (!OshaWorkflowPermissions::userHasRole(
      HWC_ROLE_WEBSITE_MANAGERS, $account)) {
        form_set_error('add_user', t('You can assign here only Review Managers.'));
    }
  }
}

/**
 * Process form submission for adding editors.
 */
function osha_workflow_access_rm_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  // User handling.
  if (!empty($values['add_user'])) {
    $account = user_load($values['add_user']);
    $sections = $account->workbench_access;
    if (!empty($account->workbench_access_by_role)) {
      foreach ($account->workbench_access_by_role as $key) {
        unset($sections[$key]);
      }
    }
    // Add the access section.
    $record['uid'] = $account->uid;
    $record['access_id'] = $values['workbench_access']['access_id'];
    $record['access_scheme'] = $values['workbench_access']['access_scheme'];
    drupal_write_record('osha_workflow_access_rm', $record);
  }
  if (!empty($values['users'])) {
    foreach ($values['users'] as $key => $value) {
      if (!empty($value['remove'])) {
        // Remove the access section.
        db_delete('osha_workflow_access_rm')
          ->condition('access_id', $values['workbench_access']['access_id'])
          ->condition('access_scheme', $values['workbench_access']['access_scheme'])
          ->condition('uid', $key)
          ->execute();
      }
    }
  }
}

/**
 * Theme the editor list form.
 */
function theme_osha_workflow_access_rm_form($variables) {
  $form = $variables['form'];
  $scheme = $form['workbench_access']['#value'];
  $access_info = workbench_access_load_access_info($scheme);
  $output = '<h2>' . t('%name review managers by account', array('%name' => $access_info['name'])) . '</h2>';
  $header = array(t('Review managers'), t('Actions'));
  $rows = array();
  foreach (element_children($form['users']) as $key) {
    $rows[] = array(
      drupal_render($form['users'][$key]['name']),
      drupal_render($form['users'][$key]['remove']),
    );
  }
  $variables = array(
    'header' => $header,
    'rows' => $rows,
    'empty' => t('No active review managers have been found.'),
  );
  $output .= theme('table', $variables);
  $output .= drupal_render_children($form);
  return $output;
}

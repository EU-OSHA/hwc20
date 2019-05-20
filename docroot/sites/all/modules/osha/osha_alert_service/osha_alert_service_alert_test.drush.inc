<?php

/**
 * Implements hook_COMMAND_drush_command().
 */
function osha_alert_service_alert_test_drush_command() {
  $items = array();
  $items['osha-alert-service-test'] = array(
    'description' => 'Test the alert service by triggering one of the existing alerts',
    'examples' => array('drush osha-alert-test 21 30' => 'Send the alert no. 21 with items published for the last 30 days'),
    'arguments' => array(
      'alert_id' => 'Alert `id` from osha_alert_service table',
      'days' => 'Override the number of days since last alert was sent'
    ),
    'options' => array(),
    'sections' => array(),
  );
  return $items;
}

/**
 * Implements COMMANDFILE_drush_help().
 */
function osha_alert_service_alert_test_drush_help($section)
{
  switch ($section) {
    case 'drush:osha-alert-service-test':
      return <<<EOT
Test the alert service by triggering one of the existing alerts. The alert ID must exist, and you pass the number of the past days to filter the content';
Example:
drush osha-alert-service-test 23 100 - triggers the alert with id: #23 selecting all the content generated in the last 100 days.
EOT;

  }
  return NULL;
}

function drush_osha_alert_service_alert_test_osha_alert_service_test($id, $days = 30) {
  $entity = entity_load_single('osha_alert_service', $id);
  if ($entity) {
    $entity->last_alert = date('U') - ($days * 24 * 3600);
    entity_save('osha_alert_service', $entity);
    if (!osha_alert_service_send_alert($id)) {
      drush_log('Sending failed due to an error or because there was no new content found for the requested interval', 'warning');
    }
    else {
      drush_log('An alert was successfully sent to ' . $entity->email, 'status');
    }
  }
  else {
    drush_set_error('Cannot find the alert with ID: ' . $id);
  }
}

<?php
/**
 * @file
 * hwc_workflow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_workflow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_mail_bottom_text';
  $strongarm->value = 'This message is intended exclusively for its addressee and may contain information that is CONFIDENTIAL and protected by professional privilege. If you are not the intended recipient you are hereby notified that any dissemination, copy or disclosure of this communication is strictly prohibited by law. If this message has been received in error, please immediately notify us via e-mail and delete it.';
  $export['hwc_mail_bottom_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_mail_signature';
  $strongarm->value = 'Kind regards<br>
Heike Klempa<br>
Campaigns manager';
  $export['hwc_mail_signature'] = $strongarm;

  return $export;
}

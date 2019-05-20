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

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_workflow_approved_body';
  $strongarm->value = 'Dear HWC partner,
This email is just to confirm that the information uploaded by you on the HWC website has been published.
Best regards,
Your Healthy Workplaces Campaign team ';
  $export['hwc_workflow_approved_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_workflow_approved_subject';
  $strongarm->value = 'Your news/events has been published on the HWC website';
  $export['hwc_workflow_approved_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_workflow_rejection_body';
  $strongarm->value = ' Dear HWC partner,
Please review the news/event item uploaded by you on the HWC website.
(free text , explaining why)
Thank you very much for your cooperation.
Best regards,
Your Healthy Workplaces Campaign team ';
  $export['hwc_workflow_rejection_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_workflow_rejection_subject';
  $strongarm->value = 'Please review your news/events item on the HWC website';
  $export['hwc_workflow_rejection_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_workflow_reviewer_body';
  $strongarm->value = 'Please go to the back-office of the HWC website at https://healthy-workplaces.eu/en/admin/content and check the news/events item created by a HWC partner.';
  $export['hwc_workflow_reviewer_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hwc_workflow_reviewer_subject';
  $strongarm->value = 'Please review news/events item uploaded on HWC website';
  $export['hwc_workflow_reviewer_subject'] = $strongarm;

  return $export;
}

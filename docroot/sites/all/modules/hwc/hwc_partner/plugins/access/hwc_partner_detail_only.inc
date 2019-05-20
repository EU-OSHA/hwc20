<?php

/**
 * @file
 * Plugin to check if the title has configured string.
 */

$plugin = array(
  'title' => 'Show content on partner detail only',
  'callback' => 'hwc_partner_ctools_access_check',
  'default' => array('negate' => 0),
);

/**
 * Check for access.
 */
function hwc_partner_ctools_access_check($conf, $context) {
//  if (isset($_REQUEST['page']) && $_REQUEST['page'] == 'gpep') {
//    return FALSE;
//  }
  return TRUE;
}

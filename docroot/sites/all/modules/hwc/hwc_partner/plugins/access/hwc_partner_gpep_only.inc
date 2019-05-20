<?php

/**
 * @file
 * Plugin to check if the title has configured string.
 */

$plugin = array(
  'title' => 'Show content on GPEP only',
  'callback' => 'hwc_partner_gpep_ctools_access_check',
  'default' => array('negate' => 0),
);

/**
 * Check for access.
 */
function hwc_partner_gpep_ctools_access_check($conf, $context) {
//  if (isset($_REQUEST['page']) && $_REQUEST['page'] == 'gpep') {
//    return TRUE;
//  }
  return FALSE;
}

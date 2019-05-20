<?php
/**
 * @file
 * hwc_admin_reports.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_admin_reports_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_us_date_only_format';
  $strongarm->value = 'm/d/Y';
  $export['date_format_us_date_only_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_us_dt';
  $strongarm->value = 'm/d/Y - H:i:s';
  $export['date_format_us_dt'] = $strongarm;

  return $export;
}

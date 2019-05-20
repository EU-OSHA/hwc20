<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$parts = explode(' ', strip_tags($output));
$country_code = $row->field_field_country_code[0]['raw']['value'];
if ($row->field_field_show_eu_flag && $row->field_field_show_eu_flag[0]['raw']['value']) {
  $country_code = 'EU';
}

$content = '<div class="event_day_month">
  <div class="event_country code_' . $country_code . '"> </div>
</div>';

$tooltip = $row->field_field_country_code[0]['rendered']['#markup'];
echo hwc_qtip_text($content, $tooltip);

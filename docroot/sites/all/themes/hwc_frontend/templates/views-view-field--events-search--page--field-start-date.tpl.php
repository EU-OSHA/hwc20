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
$country_code = $row->_field_data['field_country_code']['entity']->field_country_code['und'][0]['value'];
if ($row->_entity_properties['entity object']->field_show_eu_flag && $row->_entity_properties['entity object']->field_show_eu_flag['und'][0]['value']) {
  $country_code = 'EU';
}

?>
<div class="event_day_month">
    <div class="event_country code_<?php print $country_code; ?>"> </div>
</div>

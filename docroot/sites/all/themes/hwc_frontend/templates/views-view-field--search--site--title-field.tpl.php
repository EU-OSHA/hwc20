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
?>
<?php
$search = [];
if (!empty($_REQUEST['search_block_form'])) {
  $search = explode(' ', $_REQUEST['search_block_form']);
}
$link_output = $output;
$output = $orig_output = strip_tags($output);
foreach($search as $word) {
  $output = str_replace(strtolower($word), '<strong>' . strtolower($word) . '</strong>', $output);
  $output = str_replace(ucfirst($word), '<strong>' . ucfirst($word) . '</strong>', $output);
}
$link_output = str_replace('>' . $orig_output . '<', '>' . $output . '<', $link_output);
print $link_output;
?>

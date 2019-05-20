<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?><?php
// Todo ...
$wrapper = entity_metadata_wrapper('node', $node);
$title = $wrapper->title->value();
$titleLink = hwc_toolkit_prepare_link(strtolower($title));
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="col-xs-12 col-sm-12 col-md-12 <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

<?php

print '<div id="' . $titleLink . '" class="title_link _close">';
print $ds_content;
print '</div>';

?>

</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>

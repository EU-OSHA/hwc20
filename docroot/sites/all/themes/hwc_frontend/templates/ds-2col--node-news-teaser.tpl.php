<?php

/**
 * @file
 * Display Suite 2 column template.
 */
if (arg(2) == 'press-room-news') {
  $url = url('node/' . $nid);
  $left = str_replace($url, $url . '?press-room-news', $left);
  $right = str_replace($url, $url . '?press-room-news', $right);
}
$right = str_replace('field-name-body', 'field-name-field-summary field-type-text-long', $right);
?>
<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-2col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $left_wrapper ?> class="group-left<?php print $left_classes; ?>">
    <?php print $left; ?>
  </<?php print $left_wrapper ?>>

  <<?php print $right_wrapper ?> class="group-right<?php print $right_classes; ?>">
    <?php print $right; ?>
  </<?php print $right_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>

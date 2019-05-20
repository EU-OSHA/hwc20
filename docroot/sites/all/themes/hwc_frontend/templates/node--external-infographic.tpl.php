<?php
/**
 * @file
 * Returns the HTML for an article node.
 */
global $language;
?>
<?php 
    drupal_add_css(drupal_get_path('theme', 'hwc_frontend') . '/css/external-infographic-css/custom.css'); 
    drupal_add_css(drupal_get_path('theme', 'hwc_frontend') . '/css/external-infographic-css/layout.css'); 

    drupal_add_js(drupal_get_path('theme', 'hwc_frontend') .'/js/external-infographic-js/ready.min.js');
    drupal_add_js(drupal_get_path('theme', 'hwc_frontend') .'/js/external-infographic-js/bootstrap.js');
    drupal_add_js(drupal_get_path('theme', 'hwc_frontend') .'/js/external-infographic-js/chart.bundle.js');
    drupal_add_js(drupal_get_path('theme', 'hwc_frontend') .'/js/external-infographic-js/script.js');
 ?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>
    </header>
  <?php endif; ?>
<?php

  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  print render($content['links']);
  print render($content['comments']);
?>
<?php include(drupal_get_path('theme', 'hwc_frontend').'/templates/external-infographic-tpl/'. $language->language .'-infographic.php'); ?>
</article>
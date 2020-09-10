<?php

/**
 * @see the core node.tpl.php
 *
 * Use this tpl to hide h2 title if $title is empty, not bu $page var
 * In some situations (like panels or DS) the $page is not set,
 * so an emtpy h2 would be rendered when
 */


$original_languages = [];
if ($node->field_original_desc_language && $node->field_original_desc_language['und'][0]['value']) {
  $original_languages = $node->field_original_desc_language['und'];
}
$exclude_fields = hwc_practical_tools_get_exclude_fields($original_languages);
$map = [
  'title_field' => 'field_title_original',
  'field_title_original' => 'title_field',
];
$show_title = '';
foreach ($exclude_fields as $exclude_field) {
  if (!empty($map[$exclude_field])) {
    $show_title = $map[$exclude_field];
  }
  unset($content[$exclude_field]);
}
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!empty($title)): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
  <?php endif; ?>

    <div class="content"<?php print $content_attributes; ?>>
      <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
      ?>
    </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>

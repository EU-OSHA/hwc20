<?php
/**
 * @file
 * Returns the HTML for an article node.
 */
?>
<?php
/** @var array $content */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
  print render($content['share_widget']);
  if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
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
  $gpa = block_load('views', 'gpexamples-block');
  $array = _block_get_renderable_array(_block_render_blocks([$gpa]));
  $gpa = render($array);

  unset($content['comments']);
  unset($content['links']);

  $date = $content['group_participate']['field_participate_date']['#items'][0]['value'];
  unset($content['group_participate']['field_participate_date']);
  if ($date < date('Y-m-d')) {
    unset($content['group_participate']['field_participate_description']);
  }
  else {
    unset($content['group_participate']['field_participate_upcoming_descr']);
  }
  foreach($content as $field => $row) {
    if ($field == 'field_faq') {
      print $gpa;
    }
    print render($row);
  }
  ?>
  <div>
    <?php
    print render($content['share_widget']);
    ?>
  </div>
</article>

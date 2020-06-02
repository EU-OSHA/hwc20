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

  unset($content['comments']);
  unset($content['links']);
  unset($content['share_widget']);
  $group_faq = '';
  if (!empty($content['group_faq'])) {
    $group_faq = render($content['group_faq']);
    unset($content['group_faq']);
  }
  $date = $content['group_participate']['field_participate_date']['#items'][0]['value'];
  unset($content['group_participate']['field_participate_date']);
  if ($date < date('Y-m-d')) {
    unset($content['group_participate']['field_participate_description']);
  }
  else {
    unset($content['group_participate']['field_participate_upcoming_descr']);
  }

  $group_participate = render($content['group_participate']);
  unset($content['group_participate']);

  $gpe = render($content['gpe']);
  unset($content['gpe']);

  $contact_details = '';
  if (!empty($content['field_contact_details'])) {
    $contact_details = render($content['field_contact_details']);
  }

  foreach($content as $field => $row) {
    print render($row);
  }
  print $group_participate;
  print $gpe;
  print $group_faq;
  print $contact_details;
  ?>
</article>

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
    print render($content['field_image']);
    print render($content['title_field']);
  ?>
  <div class="container-fluid">
    <?php
    print render($content['field_summary']);
    print render($content['body']);
    print render($content['share_widget']);
    // Additional resources
    if (!empty($content['field_recommended_resources']) || !empty($content['field_recommended_articles'])) {
      print '<div class="dot-separator green"></div><div class="icon recommended-resources"></div>' . '<h2>' . t('Recommended resources for you') . '</h2>';
      print render($content['field_recommended_resources']);
      print render($content['field_recommended_articles']);
    }
    // Additional resources
    if (!empty($content['field_aditional_resources'])) {
      print '<div class="dot-separator green"></div><div class="icon additional-resources"></div>' . '<h2>' . t('Additional resources') . '</h2>';
      print render($content['field_aditional_resources']);
    }

    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    //  print render($content['links']['#links']['addtoany']['title']);
    //  unset($content['links']['#links']['addtoany']);
    print render($content);

    print render($content['links']);
    print render($content['comments']);
    ?>
  </div>
</article>

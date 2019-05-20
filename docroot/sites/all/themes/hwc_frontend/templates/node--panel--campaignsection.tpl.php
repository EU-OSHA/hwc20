<div class="pane-content">
  <?php
  $parameters = drupal_get_query_parameters();
  ?>
  <?php// print render($content); ?>
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

    print render($content['field_image']);
    print render($content['title_field']);
    
    if(!isset($parameters['page'])) {
      $content['field_recommended_articles']['#title'] = t('Recommended resources for you');

      print render($content['field_summary']);
      print render($content['body']);

      print render($content['field_aditional_resources']);
      print render($content['field_recommended_articles']);
      print render($content['links']);
      print render($content['comments']);
    }
    ?>
  </article>
</div>

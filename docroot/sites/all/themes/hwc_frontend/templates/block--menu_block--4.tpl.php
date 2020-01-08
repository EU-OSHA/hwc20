<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 */
$translated = osha_tmgmt_literal_get_translation($title);
$node = menu_get_object();
if (isset($node) && isset($node->field_article_type) && $node->field_article_type[LANGUAGE_NONE][0]['tid'] == HWC_INTRODUCTION_ARTICLE) {
}
else {
  ?>
    <div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
      <?php print render($title_prefix); ?>
      <?php if ($translated): ?>
        <h2<?php print $title_attributes; ?>><?php print $translated; ?></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php print $content; ?>
    </div>
<?php
}

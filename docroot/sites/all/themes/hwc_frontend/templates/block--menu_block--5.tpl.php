<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 */
?>
<?php
$node = menu_get_object();
if (isset($node) && isset($node->field_article_type) && $node->field_article_type[LANGUAGE_NONE][0]['tid'] == HWC_INTRODUCTION_ARTICLE) {
}
else {
  ?>
    <div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
      <?php print $content; ?>
    </div>
<?php
}

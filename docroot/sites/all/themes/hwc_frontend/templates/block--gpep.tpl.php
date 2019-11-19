<?php
/**
 * @file
 * Returns the HTML for a block.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728246
 *
 */
?>
<?php
$translated = osha_tmgmt_literal_get_translation($title);
?>
<?php
$link_href = 'private_workbench';
$back_text = '<img alt="back page" src="/' . THEME_IMAGES_PATH . '/pag-back.png"><span>' . t('Back to Private Zone') . '</span>';
echo '<div class="back-links">' . l($back_text, $link_href, ['html' => TRUE]) . '</div>';
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($translated): ?>
    <h2<?php print $title_attributes; ?>><?php print $translated; ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php print $content; ?>

</div>

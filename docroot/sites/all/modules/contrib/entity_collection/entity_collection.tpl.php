<?php
/**
 * @file
 * Template for an entity collection.
 */
?>
<div class="<?php print $classes; ?>">
<?php print render($title_prefix); ?>
  <?php if ($show_title): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php foreach ($collection as $item): ?>
	<div class="container">
      <div class="item">
        <?php print render($item); ?>
      </div>
    </div>
  <?php endforeach; ?>
</div>

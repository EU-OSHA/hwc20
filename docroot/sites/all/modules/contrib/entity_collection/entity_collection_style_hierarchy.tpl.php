<?php
/**
 * @file
 * This is the template file for the hierarchy style plugin.
 */
?>
<div class="group">
  <?php if (!empty($parent)): ?>
    <div class="parent">
      <?php print render($parent) ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($children)): ?>
    <div class="children">
      <?php print render($children) ?>
    </div>
  <?php endif; ?>
</div>
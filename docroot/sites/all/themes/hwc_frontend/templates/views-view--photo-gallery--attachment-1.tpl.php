<?php if ($rows): ?>
  <div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  <div class="view-content">
    <?php print $rows; ?>
  </div>
  </div><?php /* class view */ ?>
<?php endif; ?>

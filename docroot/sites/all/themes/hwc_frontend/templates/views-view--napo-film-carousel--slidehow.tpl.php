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

<?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
<?php endif; ?>

<?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
<?php endif; ?>

<div id="napo_films" class="carousel slide" data-ride="carousel" data-interval="false">
    <div class="napo_films">
    <!-- Indicators -->
    <ol class="carousel-indicators jssorb03"><?php
      $total = hwc_napo_films_result_count();
      $class = "active";
      for ($i = 0; $i < $total; $i++) {
        echo '<li data-target="#napo_films" data-slide-to="' . $i . '" class="' . $class . '"></li>';
        $class = '';
      }
      ?>
    </ol>

    <!-- Wrapper for slides -->
    <div class="carousel-inner num_slides">
      <?php print str_replace('row-1', 'row-1 active', $rows); ?>
    </div>

    <!-- Left and right controls -->
    <a class="jssora03l left carousel-control" href="#napo_films" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left"></span>
        <span class="sr-only"><?php echo t('Previous'); ?></span>
    </a>
    <a class="jssora03r right carousel-control" href="#napo_films" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right"></span>
        <span class="sr-only"><?php echo t('Next'); ?></span>
    </a>
    </div>
</div>

<?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
<?php endif; ?>

<?php if ($more): ?>
  <?php print $more; ?>
<?php endif; ?>

<?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
<?php endif; ?>

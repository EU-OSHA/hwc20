<?php
$theme_dir = drupal_get_path('theme', 'hwc_frontend');
if ($prev || $next) {
  ?>
  <div class="previous-next hidden-xs">
    <?php  if ($prev) { ?>
      <div class="previous">
        <a href="<?php print url($prev['link_path']); ?>">
          <img src="/<?php print $theme_dir; ?>/images/previous.png">
          <span class="previous-text">
            <span><?php print t('Previous');?></span>
            <span><?php print $prev['title'] ?></span>
          </span>
        </a>
      </div>
    <?php }?>
    <?php  if ($next) {?>
      <div class="next">
        <a href="<?php print url($next['link_path']); ?>">
          <span class="next-text">
            <span><?php print t('Next');?></span>
            <span><?php print $next['title'] ?></span>
          </span>
          <img src="/<?php print $theme_dir; ?>/images/next.png"></a>
      </div>
    <?php }?>
  </div>
  <?php
}
?>

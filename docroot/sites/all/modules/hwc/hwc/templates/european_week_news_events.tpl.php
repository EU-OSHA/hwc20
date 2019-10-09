<div class="two-box-column">
  <div class="box-before news">
    <h3><span><?php echo t('News') ?></span></h3>
    <?php echo $news; ?>
  </div><?php if ($events) { ?>
  <div class="box-before events">
    <h3><span><?php echo t('Events'); ?></span></h3>
    <?php echo $events; ?>
  </div><?php }?>
</div>

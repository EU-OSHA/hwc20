<section class="before-the-campaign">
  <div class="content-box-before">
    <div class="box-before col-md-7 col-sm-12 col-xs-12">
      <div class="box-before news">
        <h3><span><?php print l(t('News'), 'media-centre/news'); ?></span></h3>
        <?php print $data['news']; ?>
      </div>
    </div>
    <div class="box-before col-md-5 col-sm-12 col-xs-12">
      <div class="box-before events">
        <h3><span><?php print l(t('Events'), 'media-centre/events'); ?></span></h3>
        <?php print $data['events']; ?>
      </div>
    </div>
</section>

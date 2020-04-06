<section class="before-the-campaign">
  <div class="col-md-12">
    <h2><?php print t('Before the campaign starts, here is what you can do:'); ?></h2>
  </div>
  <div class="content-box-before">
      <div class="box-before">
          <h3><?php print('Download campaign resources'); ?></h3>
      <?php print $data['download']; ?>
    </div>
    <div class="two-box-column">
        <div class="box-before news">
            <h3><span><?php print t('News'); ?></span></h3>
          <?php print $data['news']; ?>
        </div>
        <div class="box-before events">
            <h3><span><?php print t('Events'); ?></span></h3>
          <?php print $data['events']; ?>
        </div>
    </div>
    <div class="box-before">
      <h3><?php print t('Check out previous campaigns'); ?></h3>
      <?php print $data['campaign']; ?>
    </div>
  </div>
</section>

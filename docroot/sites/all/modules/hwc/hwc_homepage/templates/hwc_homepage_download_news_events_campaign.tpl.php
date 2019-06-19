<section class="before-the-campaign">
  <div class="col-md-12">
    <h2><?php print t('Before the Campaign starts, here is what you can do'); ?></h2>
  </div>
  <div class="content-box-before">
      <div class="box-before">
          <h3><?php print('Download Campaign resources'); ?></h3>
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
      <h3><?php print t('Check out previous campaign'); ?></h3>
      <?php print $data['campaign']; ?>
        <div class="content-buttom">
          <?php
          $options['attributes']['class'] = ['see-more-button-20'];
          $path = variable_get('about_the_campaigns_path', '');
          print l(t('About the Campaigns'), $path, $options);
          ?>
        </div>
    </div>
  </div>
</section>

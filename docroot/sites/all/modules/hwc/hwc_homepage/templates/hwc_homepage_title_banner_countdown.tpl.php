<section class="intro-splash-20">
  <?php print $data; ?>
</section>
<section class="comming-soon">
  <div class="content-counter">
    <h2><?php print t('Coming Soon') ?></h2>
    <time id="eventTime" datetime="2019-10-31T14:30:00+01:00"></time>
    <ul class="time-and-counters">
      <li id="count-days">
        <span class="counter-value"></span>
        <span class="counter-label"><?php print t('days'); ?></span>
      </li>
      <li id="count-hours">
        <span class="counter-value"></span>
        <span class="counter-label"><?php print t('hours'); ?></span>
      </li>
      <li id="count-minutes">
        <span class="counter-value"></span>
        <span class="counter-label"><?php print t('minutes'); ?></span>
      </li>
      <li id="count-seconds">
        <span class="counter-value"></span>
        <span class="counter-label"><?php print t('seconds'); ?></span>
      </li>
    </ul>
  </div>
</section>

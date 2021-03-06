<?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
<?php endif; ?>
<div class="multicarousel--block" id="multicarouselBlock1" data-items="1,2,3,4,5" data-slide="5" data-interval="1000">
  <?php if ($rows): ?>
      <div class="multicarousel--block--inner">
        <?php print $rows; ?>
      </div>
  <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print $empty; ?>
      </div>
  <?php endif; ?>
    <button class="btn btn-primary leftLst over"><img alt="Slider left" src="/sites/all/themes/hwc_frontend/images/slider-left.png" title="show more"></button>
    <button class="btn btn-primary rightLst"><img alt="Slider right" src="/sites/all/themes/hwc_frontend/images/slider-right.png" title="show more"></button>
</div>
<?php
echo l(t('See all partners'), variable_get('hwc_homepage_partners_see_more_link', 'campaign-partners/official-campaign-partners'),
  ['attributes' => ['class' => 'see-more-button-20']]
);

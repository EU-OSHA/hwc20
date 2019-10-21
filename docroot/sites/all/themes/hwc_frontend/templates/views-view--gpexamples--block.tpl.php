<div class="multicarousel--block" id="multicarouselBlock1" data-items="1,2,3,4" data-slide="3" data-interval="1000">
  <?php if ($rows): ?>
    <div class="multicarousel--block--inner">
      <?php print $rows; ?>
    </div>
    <ol class="multicarousel-indicators">
    </ol>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
  <button class="btn btn-primary leftLst over"><img src="/sites/all/themes/hwc_frontend/images/slider-left.png" title="show more"></button>
  <button class="btn btn-primary rightLst"><img src="/sites/all/themes/hwc_frontend/images/slider-right.png" title="show more"></button>
</div>


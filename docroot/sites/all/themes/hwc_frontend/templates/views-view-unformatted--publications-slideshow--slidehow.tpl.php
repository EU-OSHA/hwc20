<section class="slider--video--section">
  <div class="slider--video--block row">
    <div class="slider--video--items">
      <h2 class="block-title"><?php print t('Latest publications'); ?></h2>
      <div class="container">
        <div class="container content-fluid green-background multicarousel--block" id="multicarouselBlock1" data-items="1,2,2,3" data-slide="3" data-interval="1000">
          <div class="multicarousel--block--inner">
            <div class="wrapper-responsive-box">
              <?php
              foreach ($rows as $id => $row) {
                ?>
                <div <?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?> >
                  <?php print $row; ?>
                </div>
                <?php
              }
              ?>
            </div>
          </div>
          <ol class="multicarousel-indicators">
          </ol>
          <button class="btn btn-primary leftLst over"><img src="/sites/all/themes/hwc_frontend/images/slider-left.png" title="show more"></button>
          <button class="btn btn-primary rightLst"><img src="/sites/all/themes/hwc_frontend/images/slider-right.png" title="show more"></button>
        </div>
      </div>
    </div>
  </div>
</section>

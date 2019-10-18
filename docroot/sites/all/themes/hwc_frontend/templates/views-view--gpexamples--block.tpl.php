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

<style>
  ol.multicarousel-indicators li.active {
    background: #003399;
  }

  ol.multicarousel-indicators {
    left: 46%!important;
    top: 20px;
    position: absolute;
    display: block !important;
    z-index: 15;
    width: 60%;
    list-style: none;
    text-align: center;
  }

  ol.multicarousel-indicators li {
    vertical-align: middle;
    border: 1px solid #003399;
    display: inline-block;
    width: 10px;
    height: 10px;
    margin: 0px 2px;
    text-indent: -999px;
    border-radius: 10px;
    cursor: pointer;
    background-color: #000 \9;
    background-color: rgba(0,0,0,0);
  }


  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block {
    overflow: hidden;
    padding: 0 1.5rem;
    width: 100%;
    margin: auto;
    position: relative;
  }
  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .multicarousel--block--inner {
    transition: 1s ease all;
    float: left;
  }
  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .multicarousel--block--inner .item {
    float: left;
  }

  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .multicarousel--block--inner .item > .slider-item {
    text-align: center;
    padding: 0 0 0 1rem;
    margin: 1rem;
    color: #666;
    overflow: hidden;
    position: relative;
  }

  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .leftLst.over {
    pointer-events: none;
  }
  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .rightLst.over {
    pointer-events: none;
  }

  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .leftLst {
    position: absolute;
    top: 0;
    left: 0;
  }
  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .rightLst {
    position: absolute;
    top: 0;
    right: 0;
  }

  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .btn-primary {
    background: #EDECED;
    height: 100%;
  }

  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .leftLst.over img {
    opacity: 0.4;
  }
  .slider--video--section .slider--video--block .slider--video--items .multicarousel--block .rightLst.over img {
    opacity: 0.4;
  }
</style>

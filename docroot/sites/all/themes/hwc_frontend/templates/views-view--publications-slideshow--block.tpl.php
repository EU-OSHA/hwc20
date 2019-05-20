<div id="publications_slideshow" class="carousel slide" data-ride="carousel" data-interval="false">
    <!-- Indicators -->
    <ol class="carousel-indicators jssorb03"><?php
      $total = osha_publication_result_count();
      $class = "active";
      for ($i = 0; $i < $total; $i++) {
        echo '<li data-target="#publications_slideshow" data-slide-to="' . $i . '" class="' . $class . '"></li>';
        $class = '';
      }
      ?>
    </ol>

    <!-- Wrapper for slides -->
    <div class="carousel-inner" id="num_slides">
      <?php print str_replace('row-1', 'row-1 active', $rows); ?>
    </div>

    <!-- Left and right controls -->
    <a class="jssora03l left carousel-control" href="#publications_slideshow" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left"></span>
        <span class="sr-only"><?php echo t('Previous'); ?></span>
    </a>
    <a class="jssora03r right carousel-control" href="#publications_slideshow" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right"></span>
        <span class="sr-only"><?php echo t('Next'); ?></span>
    </a>
</div>

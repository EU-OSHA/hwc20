<div id="latest-newsletters-block">
  <?php
  if (!empty($items)) {
     $idx = 0;
     foreach($items as $item) {
       echo '<div class="newsletter-item" id="newsletter-item-' . ++$idx . '">';
      ?>
      <h2><?php print l($item['title'], url($item['url'], array('absolute' => TRUE)), array(
          'attributes' => array('style' => 'color: #003399; text-decoration: none;'),
          'external' => TRUE
        )); ?></h2>
      <?php
      if ($newsletter_items_no > 0) {
          if (isset($item['items'])){
            foreach($item['items'] as $element) {
              print(render($element));
            }
          }
      }
       echo '</div>';
    }
    if ($newsletters_no < count($items)) {
      $options['attributes']['class'] = 'more_newsletters';
      $options['attributes']['onclick'] = 'return see_more_newsletters()';
      echo l(t('See more newsletters'), '', $options);
      $options['attributes']['class'] = 'less_newsletters';
      $options['attributes']['onclick'] = 'return see_less_newsletters()';
      echo l(t('See less newsletters'), '', $options);
    }
  } else {
    print t('No newsletters available.');
  }
  ?>
</div>
<script>
function see_more_newsletters() {
    return false;
}
function see_less_newsletters() {
    return false;
}
</script>

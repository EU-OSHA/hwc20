<div class="practical-tool-languages">
  <b>Languages: </b>
  <?php
  foreach($languages as $key => $language) {
    print $language->name . ' (' . $language->language . ')';
    if($key < count($languages) - 1) {
      print ', ';
    }
  }
  ?>
</div>
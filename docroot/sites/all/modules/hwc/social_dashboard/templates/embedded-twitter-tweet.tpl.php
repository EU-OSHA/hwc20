<?php
$data_cards = '';
if (drupal_is_front_page()) {
  $data_cards = 'data-cards="hidden"';
}
echo '<blockquote class="twitter-tweet" ' . $data_cards . ' data-lang="en">
<a href="' . "https://twitter.com/" . $content['name'] . "/status/" . $content['social_id'] . '" title="' . $content['name'] . '"> </a></blockquote>';

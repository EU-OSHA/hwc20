<?php

$prev = hwc_toolkit_nav_prev($nid);
$next = hwc_toolkit_nav_next($nid);
if ($prev || $next) {
  print '<div class="col-xs-12 col-sm-12 col-md-12">';
  print '<div class="key-next-prev-buttons">';
  if ($prev) {
    print '<span class="prev-button ' . $prev['color'] . '"><a href="' . $prev['href'] . '" class="previous-button"><span class="nav-info">' . t('Previous topic') . '</span><span class="nav-title">' . $prev['title'] . '</span></a></span>';
  }
  if ($next) {
    print '<span class="next-button ' . $next['color'] . '"><a href="' . $next['href'] . '" class="nexting-button"><span class="nav-info">' . t('Next topic') . '</span><span class="nav-title">' . $next['title'] . '</span></a></span>';
  }
  print '</div>';
  print '</div>';
}

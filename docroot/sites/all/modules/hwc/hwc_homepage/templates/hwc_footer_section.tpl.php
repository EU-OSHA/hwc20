<?php
$skip = variable_get('footer_section_skip_empty', FALSE);
$exclude_url = explode("\n", $skip);
?>
<div class="footer-section hidden-xs">
  <?php foreach ($data as $menu) {
    if ((!$menu['below'] && $skip) || (in_array($menu['link']['href'], $exclude_url))) {
      continue;
    }
    ?>
      <div class="col-md-2">
          <?php print l($menu['link']['title'], $menu['link']['href']); ?>
          <ul>
            <?php foreach ($menu['below'] as $submenu) {
              if (in_array($submenu['link']['href'], $exclude_url)) {
                continue;
              }
              ?>
                <li><?php print l($submenu['link']['title'], $submenu['link']['href']); ?></li>
            <?php } ?>
          </ul>
      </div>
  <?php } ?>
</div>

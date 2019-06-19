<?php
$skip = variable_get('browsing_content_skip_empty', FALSE);
$exclude_url = explode("\n", $skip);
?>
<section class="start-browsing">
    <div class="col-md-12">
        <h2><?php print t('Start browsing the content'); ?></h2>
    </div>
    <div class="content-boxes">
      <?php foreach ($data as $menu) {
        if ((!$menu['below'] && $skip) || (in_array($menu['link']['href'], $exclude_url))) {
          continue;
        }
        ?>
          <div class="start-browsing-box">
              <h3><?php  print l($menu['link']['title'], $menu['link']['href']); ?></h3>
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
</section>
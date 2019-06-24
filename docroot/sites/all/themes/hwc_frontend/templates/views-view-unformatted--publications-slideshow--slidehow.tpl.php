<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="content-fluid green-background">
    <div class="container">
        <h2><?php print t('Latest publications'); ?></h2>
        <div class="wrapper-responsive-box">
          <?php foreach ($rows as $id => $row): ?>
              <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
                <?php print $row; ?>
              </div>
          <?php endforeach; ?>
        </div>
    </div>
</div>
<?php
$translated = osha_tmgmt_literal_get_translation('Good practice examples');
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <section class="slider--video--section">
      <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
        <div class="slider--video--block row">
            <div class="slider--video--items">
                <h2 class="block-title"><?php print $translated; ?></h2>
              <?php print $content; ?>
            </div>
        </div>
    </section>
</div>
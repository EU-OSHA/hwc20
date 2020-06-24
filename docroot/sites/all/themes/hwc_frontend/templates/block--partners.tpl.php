<?php
$translated = osha_tmgmt_literal_get_translation($title);
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<section class="slider--video--section container">
      <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
    <div class="slider--video--block row">
        <div class="slider--video--items">
                <h2 class="block-title"><span><?php print l($translated, 'campaign-partners/official-campaign-partners'); ?></span></h2>
          <?php print $content; ?>
        </div>
    </div>
</section>
</div>
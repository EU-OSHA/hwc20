<?php
$translated = osha_tmgmt_literal_get_translation($title);
?>
<section class="slider--video--section container">
    <div class="slider--video--block row">
        <div class="slider--video--items">
            <h2 class="block-title"><?php print l($translated, 'campaign-partners/official-campaign-partners'); ?></h2>
          <?php print $content; ?>
        </div>
    </div>
</section>

<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php
$checked = hwc_priority_areas_is_selected_facet() ? '' : 'checked';
$link = hwc_priority_areas_generate_all_facet_link();
$title = str_replace(':', '', $title);
$title = osha_tmgmt_literal_get_translation($title);
?>
<h2 class="block-title"><?php print $title; ?>:</h2>
<ul class="facetapi-facetapi-checkbox-links facetapi-facet-field-priority-area facetapi-processed no-margin-bottom">
  <li class="leaf first">
    <input type="checkbox" class="facetapi-checkbox" id="facetapi-link--all--checkbox" <?php print $checked; ?>>
    <?php print $link; ?>
  </li>
</ul>
<?php print $content; ?>
<script>
  jQuery('#facetapi-link--all--checkbox').click(function(){
    window.location.href = jQuery(this).next().attr('href');
  });
</script>
</div>

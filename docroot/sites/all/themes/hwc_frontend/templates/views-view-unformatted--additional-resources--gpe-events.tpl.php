<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if ($rows) { ?>
<div class="container">
    <div class="node-type-article">
        <article>
            <div class="icon additional-resources"></div>
            <h2><?php print t('Additional resources') ?></h2>
            <div class="field field-name-field-aditional-resources field-type-entityreference field-label-hidden">
                <div id="additional-resources-events-pane">
                    <h4 class="pane-title"><?php print t('Events'); ?></h4>
                    <div class="pane-content">
<?php foreach ($rows as $id => $row){ ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php } ?>
                    </div>
                </div>
            </div>
        </article>
    </div>
</div>
<?php
}

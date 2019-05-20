<?php

/**
 * @file
 * Default simple view template to display a rows in a grid.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="<?php print $class; ?>"<?php print $attributes; ?>>
  <?php foreach ($rows as $row_number => $columns): ?>
    <?php $x = (int) (12 / $options['columns']); ?>
    <div <?php if ($row_classes[$row_number]) { print 'class="row ' . $row_classes[$row_number] .'"';  } ?>>
      <?php foreach ($columns as $column_number => $item): ?>
        <div <?php if ($column_classes[$row_number][$column_number]) { print 'class="col-md-' . $x . ' ' . $column_classes[$row_number][$column_number] .' col-sm-6 col-xs-12"';  } ?>>
          <div class="views-item-columns-container">
            <?php print $item; ?>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</div>

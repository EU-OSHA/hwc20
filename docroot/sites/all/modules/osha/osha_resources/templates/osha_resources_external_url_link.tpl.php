<?php
$wrapper = entity_metadata_wrapper('node', $entity);
foreach ($items as $item): ?>
  <?php print l($wrapper->title_field->value(), $item['url'], array('attributes' => array('class' => array('external_url'), 'target' => '_blank'))); ?>
<?php endforeach; ?>

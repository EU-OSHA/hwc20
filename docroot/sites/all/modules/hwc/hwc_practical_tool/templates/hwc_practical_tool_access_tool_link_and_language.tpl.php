<?php
$entities_to_load = array();
foreach ($items as $item) {
  $entities_to_load[] = $item['value'];
}
$entities = entity_load('field_collection_item', $entities_to_load);
?>
<div class="field field-access-tool-link field-type-field-collection field-label-inline clearfix">
  <div class="field-label"><?php print $label; ?>&nbsp;</div>
  <ul class="field-items">
    <?php foreach ($entities as $entity): ?>
      <li>
        <?php
        $language = $entity->field_available_languages['und'][0]['name'];
        $link = $entity->field_access_tool_link['und'][0]['url'];
        ?>
        <a href="<?php print $link; ?>" class="access-tool-link">
          <?php print $language; ?>
        </a>
      </li>
    <?php endforeach; ?>
  </ul>
</div>

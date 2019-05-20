<?php
$file_title = '';
$items = array();
foreach ($files as $f) {
  foreach($entity->field_document_file['und'] as $delta => $document_file) {
    if ($document_file['fid'] == $f['fid']) {
      $file_title = $entity->field_file_title['und'][$delta]['value'];
      $file_uri = file_create_url($f['uri']);
      $items[] = '<a href="' . $file_uri . '">' . strtoupper($entity->field_language['und'][$delta]['value']) . '<span class="glyphicon glyphicon-circle-arrow-down"></span></a>';
    }
  }
}
$file_items = theme('item_list', array('items' => $items));

$ext = pathinfo($entity->field_document_file['und'][0]['filename'], PATHINFO_EXTENSION);
$icon_directory = drupal_get_path('theme', 'hwc_frontend') . '/images/file_icons/';
$icon = $icon_directory . strtolower($ext) . '.png';
?>
<div class="publication-teaser">
  <div class="field field-files">
      <span class="publication-ext-type"><img src="/<?php print $icon; ?>"/> <?php echo $file_title ?></span>
      <span class="publication-download-label"><?php print t('Download in'); ?></span>
      <?php print $file_items; ?>
  </div>
</div>

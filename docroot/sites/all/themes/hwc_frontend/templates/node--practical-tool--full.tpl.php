<?php

$back_path = 'tools-and-publications/practical-tools';
$back_text = '<img alt="back page" src="/' . THEME_IMAGES_PATH . '/pag-back.png"><span>' . t('Back to practical tools list') . '</span>';

hide($content['comments']);
hide($content['links']);
hide($content['share_widget']);
hide($content['bottom_share_widget']);

if (!empty($content['field_type_of_item'])) {
  $content['field_type_of_item']['#title'] = t('Type');
}
if (!empty($content['body'])) {
  $content['body']['#title'] = t('Description');
}
if (!empty($content['field_body_original'])) {
  $content['field_body_original']['#title'] = t('Description');
}
$original_languages = [];
if ($node->field_original_desc_language && $node->field_original_desc_language['und'][0]['value']) {
  $original_languages = $node->field_original_desc_language['und'];
}
$exclude_fields = hwc_practical_tools_get_exclude_fields($original_languages);
$map = [
  'title_field' => 'field_title_original',
  'field_title_original' => 'title_field',
];
$show_title = '';
foreach ($exclude_fields as $exclude_field) {
  if (!empty($map[$exclude_field])) {
    $show_title = $map[$exclude_field];
  }
  unset($content[$exclude_field]);
}
$share_widget = $content['share_widget'];
unset($content['share_widget']);
unset($content['bottom_share_widget']);

?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content container clearfix"<?php print $content_attributes; ?>>
    <div class="publication-detail">
      <div class="back-to-publications"><?php print l($back_text, $back_path, ['html' => TRUE]); ?></div>
      <div class="share-this"><?php print render($share_widget); ?></div>
      <div class="col-md-12">
        <h2><?php print strip_tags(render($content[$show_title]), '<a>'); ?></h2>
      </div>
      <div class="col-md-12">
        <?php
        $map = [
          'body' => ['title' => t('Description'), 'id' => 'description'],
          'field_body_original' => ['title' => t('Description'), 'id' => 'description'],
          'field_sector_industry_covered' => ['title' => t('Other data'), 'id' => 'other_data'],
          'field_external_url' => ['title' => t('Access tool'), 'id' => 'access_tool'],
        ];

        hide($content[$show_title]);
        foreach($content as $field_name => $field) {
          if (isset($map[$field_name])) {
            print '<h3 id="' . $map[$field_name]['id'] . '">' . $map[$field_name]['title'] . '</h3>';
          }
          $output = render($field);
          if (in_array($field_name, ['field_type_of_item', 'field_material_country', 'field_available_in_languages', 'field_msd_provider'])) {
            $output = str_replace(':&nbsp;</div>', '</div>', $output);
          }
          print $output;
        }
        ?>
      </div>
      <div class="share-this"><?php print render($share_widget); ?></div>
    </div>
  </div>
</div>

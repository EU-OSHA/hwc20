<?php

/**
 * @see the core node.tpl.php
 *
 * Use this tpl to hide h2 title if $title is empty, not bu $page var
 * In some situations (like panels or DS) the $page is not set,
 * so an emtpy h2 would be rendered when
 */
?>
<?php
$tags = strip_tags(render($content['field_tags']));
$publication_type = '<strong>' . t('Type') . ': </strong>' . strip_tags(render($content['field_publication_type']));
$pages_count = strip_tags(render($content['field_pages_count']));
if ($pages_count) {
  $pages_count .= ' ' . t('pages');
}
$type = @$node->field_publication_type[LANGUAGE_NONE][0]['tid'];
$back_path = 'tools-and-publications/publications';
$back_text = '<img alt="back page" src="/' . THEME_IMAGES_PATH . '/pag-back.png"><span>' . t('Back to publications list') . '</span>';
if ($type == CAMPAIGN_MATERIALS_TID) {
  $back_path = 'tools-and-publications/campaign-materials';
  $back_text = '<img alt="back page" src="/' . THEME_IMAGES_PATH . '/pag-back.png"><span>' . t('Back to campaign materials list') . '</span>';
}
if ($type == CASE_STUDY_TID) {
  $back_path = 'tools-and-publications/case-studies';
  $back_text = '<img alt="back page" src="/' . THEME_IMAGES_PATH . '/pag-back.png"><span>' . t('Back to case studies list') . '</span>';
}
?>
<div class="container">
    <div class="publication-detail">
        <div class="back-to-publications"><?php print l($back_text, $back_path, ['html' => TRUE]); ?></div>
        <div class="share-this"><?php print render($content['share_widget']); ?></div>
        <div class="col-md-9">
            <h2><?php print strip_tags(render($content['title_field']), '<a>'); ?></h2>
        </div>
        <div class="col-md-12">
            <div class="publications-row">
                <div class="publications-left-column hidden-xs"><?php print render($content['field_cover_image']); ?></div>
                <div class="publications-detail-right-column">
                    <div class="content-publication-info">
                        <span class="date-display-single"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
                        <span><?php print $publication_type; ?></span>
                        <span class="pages"><?php print $pages_count; ?></span>
                    </div>
                  <?php
                    print render($content['body']);
                    print render($content['field_file']);
                  if ($content['field_banner_publications_office']['#items'][0]['value']) {
                    echo theme('osha_publication_bookshop_id_format', ['title' => $node->title]);
                  }
                  ?>
                </div>
            </div>
        </div>
    </div>
  <?php

  if (isset($content['field_aditional_resources'])) {
    print render($content['field_aditional_resources']);
  }
  if (isset($content['field_related_publications'])) {
    print render($content['field_related_publications']);
  }
  ?>
</div>

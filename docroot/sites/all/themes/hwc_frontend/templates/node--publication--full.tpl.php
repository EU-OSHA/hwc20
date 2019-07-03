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
$back_text = '<img alt="back page" src="/' . THEME_IMAGES_PATH . '/pag-back.png"><span>' . t('Back to publications list') . '</span>';
?>
<div class="container">
    <div class="publication-detail">
        <div class="back-to-publications"><?php print l($back_text, 'tools-and-publications/publications', ['html' => TRUE]); ?></div>
        <div class="share-this"><?php print render($content['share_widget']); ?></div>
        <div class="col-md-9">
            <h2><?php print strip_tags(render($content['title_field']), '<a>'); ?></h2>
        </div>
        <div class="col-md-9">
            <div class="publications-row">
                <div class="publications-left-column hidden-xs"><?php print render($content['field_cover_image']); ?></div>
                <div class="publications-detail-right-column">
                    <div class="content-publication-info">
                        <span class="date-display-single"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
                        <span><?php print $publication_type; ?></span>
                        <span class="pages"><?php print $pages_count; ?></span>
                    </div>
                  <?php print render($content['body']) ?>
                </div>
            </div>
        </div>
        <div class="col-md-3 content-downloads">
          <?php
          print render(drupal_get_form('osha_publication_download_form'));
          if ($content['field_banner_publications_office']['#items'][0]['value']) {
            echo theme('osha_publication_bookshop_id_format', ['title' => $node->title]);
          }
          ?>
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
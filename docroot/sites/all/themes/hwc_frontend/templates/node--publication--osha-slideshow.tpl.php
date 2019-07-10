<?php
/**
 * @file node--publication--pub--teaser.tpl.php
 * Default template implementation to display the value of a publication listing field.
 *
 * Available variables:
 * - $variables['content']: An array of field values. Use render() to output them.
 * - $variables['node']: Actual publication node
 *
 * @ingroup themeable
 */

$publication_type = '<strong>' . t('Type') . ': </strong>' . strip_tags(render($content['field_publication_type']));
$pages_count = strip_tags(render($content['field_pages_count']));
if ($pages_count) {
  $pages_count .= ' ' . t('pages');
}
?>
<div class="left-column visible-md visible-lg">
  <?php print render($content['field_cover_image']); ?>
</div>
<div class="right-column">
    <span class="publication-date"><?php print strip_tags(render($content['field_publication_date'])); ?></span>
    <span class="pages"><?php print $pages_count; ?></span>
    <h2><?php print strip_tags(render($content['title_field']), '<a>'); ?></h2>
    <span><?php print $publication_type; ?></span>
    <div class="publication-see-more-bottom-container">
      <?php
      print l(t('See more'), $node_url, array(
        'attributes' => array('class' => ['news-see-more-button']),
        'query' => $url_query,
        'external' => TRUE,
      ));
      ?></div>
</div>

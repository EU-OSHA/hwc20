<?php
/**
 * @file social-dashboard-column-plugin-rows.tpl.php
 * Default simple view template to display Socail Dashboard Columns.
 *
 * @ingroup views_templates
 */
?>
<?php
if ($content['source'] == 'facebook') {
  echo theme('embedded_facebook_post', ['content' => $content]);
}

if ($content['source'] == 'twitter') {
  echo theme('embedded_twitter_tweet', ['content' => $content]);
}

if ($content['source'] == 'linkedin') {
  echo theme('linkedin_update', ['content' => $content]);
}

<?php
$linkedin_link = social_dashboard_get_linkedin_link($content['social_id']);

$update_id = $content['dashboard_item_id'];
$entities = entity_load('dashboard_item', [$update_id]);
$variables = unserialize($entities[$update_id]->variables);

$company = $variables['company'];
$variables = $variables['companyStatusUpdate'];
$share = $variables['share'];

$main_title = @$share['comment'];
$title = @$share['content']['title'];
$submittedUrl = @$share['content']['submittedUrl'];
$background_image = @$share['content']['submittedImageUrl'];

// Fix https image visibility(Content Security Policy) because of http url.
$background_image = str_replace('http://image-store','https://image-store', $background_image);

if ($submittedUrl) {
  $parse = parse_url($submittedUrl);
  $host = $parse['host'];
}

$timestamp = '';
if ($content['timestamp']) {
  $timestamp = timeago_format_date(intval($content['timestamp']));
}

$company_name = $company['name'];
$avatar_image = variable_get('social_linkedin_company_avatar_image', '');

echo '
<div class="feed-s-update">
  <article>
    <div class="feed-s-update__scroll">
            
      <div class="feed-s-post-meta">
        <a href="' . $linkedin_link . '" class="feed-s-post-meta__actor-link" target="_blank">    
          <div class="feed-s-avatar-image">
            <img src="' . $avatar_image . '" class="avatar company" alt="' . htmlspecialchars($company_name) . '">
          </div>
        </a>
        <a href="' . $linkedin_link . '" class="feed-s-post-meta__profile-link" target="_blank">  
          <h3 class="feed-s-post-meta__actor">
            <span class="feed-s-post-meta__name">' . $company_name . '</span>
            <time class="feed-s-post-meta__timestamp">' . $timestamp . '</time>
          </h3>
        </a>
      </div>      
';

if ($main_title) {
  echo '<div class="feed-s-update__description">' . $main_title . '</div>';
}

if ($title || $background_image) {
echo '      <div class="feed-s-update__update-content-wrapper">
        <div class="feed-s-hero-entity__image-container">
          <a target="_blank" href="' . $linkedin_link . '">
              <div class="feed-s-hero-entity__image" style="background-image: url(&quot;' . $background_image . '&quot;);"> </div>
          </a>
        </div>
      </div>
';
}
?>
    </div>
  </article>  
</div>

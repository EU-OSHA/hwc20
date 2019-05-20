<?php
function social_dashboard_settings_form() {
  $form = array();
  $form['social_dashboard_limit'] = array(
    '#type' => 'textfield',
    '#description' => t('Download social data limit per source'),
    '#title' => t('Limit'),
    '#default_value' => variable_get('social_dashboard_limit', 20),
  );
  return system_settings_form($form);
}

function social_dashboard_social_facebook_form() {
  $form = array();
  $form['social_facebook_application_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Application ID'),
    '#default_value' => variable_get('social_facebook_application_id', ''),
    '#description' => t('Available on %url', array('%url' => 'http://www.facebook.com/developers/apps.php')),
  );
  $form['social_facebook_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Application secret'),
    '#default_value' => variable_get('social_facebook_consumer_secret', ''),
    '#description' => t('Available on %url', array('%url' => 'http://www.facebook.com/developers/apps.php')),
  );
  $form['social_facebook_page_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Page'),
    '#description' => t('Facebook page id'),
    '#default_value' => variable_get('social_facebook_page_id', ''),
  );
  $form['social_facebook_selected_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Selected Tag'),
    '#default_value' => variable_get('social_facebook_selected_tag', ''),
  );
  return system_settings_form($form);
}

function social_dashboard_social_twitter_form() {
  $form = array();
  $form['social_twitter_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer key'),
    '#default_value' => variable_get('social_twitter_consumer_key', ''),
    '#description' => t('Available on %url', array('%url' => 'https://dev.twitter.com/apps/')),
  );
  $form['social_twitter_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer secret'),
    '#default_value' => variable_get('social_twitter_consumer_secret', ''),
    '#description' => t('Available on %url', array('%url' => 'https://dev.twitter.com/apps/')),
  );
  $form['social_twitter_oauth_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth access token'),
    '#default_value' => variable_get('social_twitter_oauth_access_token', ''),
  );
  $form['social_twitter_oauth_access_token_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth access token secret'),
    '#default_value' => variable_get('social_twitter_oauth_access_token_secret', ''),
  );
  $form['social_twitter_screen_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Screen name'),
    '#default_value' => variable_get('social_twitter_screen_name', ''),
  );
  $form['social_twitter_selected_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Selected Tag'),
    '#default_value' => variable_get('social_twitter_selected_tag', ''),
  );
  return system_settings_form($form);
}

function social_dashboard_social_linkedin_form() {
  $form = array();
  $form['social_linkedin_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer key'),
    '#default_value' => variable_get('social_linkedin_consumer_key', ''),
    '#description' => t('Available on %url', array('%url' => 'https://www.linkedin.com/developer/apps')),
  );
  $form['social_linkedin_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer secret'),
    '#default_value' => variable_get('social_linkedin_consumer_secret', ''),
  );
  $form['social_linkedin_token'] = array(
    '#type' => 'textarea',
    '#title' => t('Token'),
    '#default_value' => variable_get('social_linkedin_token', ''),
  );
  $form['social_linkedin_company_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Company ID'),
    '#description' => t('Test company id = %company_id', array('%company_id' => '2414183')),
    '#default_value' => variable_get('social_linkedin_company_id', ''),
  );
  $form['social_linkedin_company_avatar_image'] = array(
    '#type' => 'textfield',
    '#title' => t('Company avatar image url'),
    '#default_value' => variable_get('social_linkedin_company_avatar_image', ''),
  );
  $form['social_linkedin_selected_tag'] = array(
    '#type' => 'textfield',
    '#title' => t('Selected Tag'),
    '#default_value' => variable_get('social_linkedin_selected_tag', ''),
  );
  return system_settings_form($form);
}

function social_dashboard_social_linkedin_login() {
  $library_path = (module_exists('libraries') && libraries_get_path('linkedin')) ? libraries_get_path('linkedin') : 'sites/all/libraries/linkedin';
  require_once $library_path . "/vendor/autoload.php";

  $consumer_key = variable_get('social_linkedin_consumer_key', '');
  $consumer_secret = variable_get('social_linkedin_consumer_secret', '');
  if (!$consumer_key || !$consumer_secret) {
    return;
  }

  $linkedIn = new Happyr\LinkedIn\LinkedIn($consumer_key, $consumer_secret);

  $token = '';
  $AccessToken = $linkedIn->getAccessToken();
  if ($AccessToken && isset($_REQUEST['code'])) {
    // __PHP_Incomplete_Class - fix
    $AccessToken = unserialize (serialize ($AccessToken));
    $token = (string)$AccessToken->getToken();
  }
  if ($token) {
    variable_set('social_linkedin_token', $token);
    drupal_set_message(t("Access token saved"));
  }

  $token = variable_get('social_linkedin_token');
  if ($token) {
    $linkedIn->setAccessToken($token);
  }
  $url = $linkedIn->getLoginUrl(array('scope' => array('rw_company_admin')));
  return "<a href='$url'>Login with LinkedIn</a>";
}

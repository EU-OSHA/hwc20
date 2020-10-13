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

<?php
/**
 * @file
 * osha.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function osha_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'osha_linkit_profile';
  $linkit_profile->admin_title = 'OSHA Linkit profile';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'full_html' => 'full_html',
      'filtered_html' => 'filtered_html',
      'plain_text' => 0,
    ),
    'search_plugins' => array(
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'article' => 0,
        'banner' => 0,
        'page' => 0,
        'calls' => 0,
        'directive' => 0,
        'events' => 0,
        'external_url' => 0,
        'file' => 0,
        'flickr' => 0,
        'guideline' => 0,
        'infographic' => 0,
        'job_vacancies' => 0,
        'news' => 0,
        'note_to_editor' => 0,
        'press_contact' => 0,
        'press_release' => 0,
        'publication' => 0,
        'slideshare' => 0,
        'wiki_page' => 0,
        'youtube' => 0,
      ),
      'group_by_bundle' => 1,
      'include_unpublished' => 1,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'tags' => 0,
        'activity' => 0,
        'article_types' => 0,
        'esener' => 0,
        'nace_codes' => 0,
        'section' => 0,
        'publication_types' => 0,
        'newsletter_sections' => 0,
        'flickr_tags' => 0,
        'attachment_file_type' => 0,
        'organised_by' => 0,
        'contact_topic' => 0,
        'contact_type_of_sender' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_article' => 0,
        'comment_node_banner' => 0,
        'comment_node_page' => 0,
        'comment_node_calls' => 0,
        'comment_node_directive' => 0,
        'comment_node_events' => 0,
        'comment_node_external_url' => 0,
        'comment_node_file' => 0,
        'comment_node_flickr' => 0,
        'comment_node_guideline' => 0,
        'comment_node_infographic' => 0,
        'comment_node_job_vacancies' => 0,
        'comment_node_news' => 0,
        'comment_node_note_to_editor' => 0,
        'comment_node_press_contact' => 0,
        'comment_node_press_release' => 0,
        'comment_node_publication' => 0,
        'comment_node_slideshare' => 0,
        'comment_node_wiki_page' => 0,
        'comment_node_youtube' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
      ),
      'group_by_bundle' => 1,
      'show_scheme' => 1,
      'group_by_scheme' => 1,
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'imce' => 1,
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['osha_linkit_profile'] = $linkit_profile;

  return $export;
}

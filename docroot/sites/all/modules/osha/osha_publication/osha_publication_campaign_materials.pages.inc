<?php
function osha_publication_menu_campaign_materials_form($form, $form_state) {
  $variables['form_state'] = $form_state;
  $variables['action'] = 'tools-and-publications/campaign-materials';
  $variables['facet_callback'] = '_osha_publication_menu_campaign_materials_get_facets_def';
  $variables['search_callback'] = 'osha_publication_menu_campaign_materials_search';
  return osha_publication_menu_campaign_materials_faceted_form($variables);
}

function osha_publication_menu_campaign_materials_search($form_state, $sort) {
  $facets_def = _osha_publication_menu_campaign_materials_get_facets_def();
  $text = hwc_req_param($form_state, 'text');
  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  list($server, $query) = _osha_publication_get_query();

  $query->condition('status', 1);
  $query->condition('type', 'publication');
  $query->condition('field_file:file', 0, '>');
  $query->condition('field_publication_type', CAMPAIGN_MATERIALS_TID);
  $query->condition('language', 'und', "<>");
  $query->keys($text);
  $query->fields(array('title_field', 'body:value'));

  if ($sort == 'alphabetically') {
    $query->sort('title2', 'ASC');
  }
  else {
    $query->sort('field_publication_date', 'DESC');
  }

  return $server->search($query);
}

function osha_publication_menu_campaign_materials_faceted_form($variables) {
  global $language, $current_page;

  $form_state = $variables['form_state'];
  $action = $variables['action'];
  $facet_callback = $variables['facet_callback'];
  $search_callback = $variables['search_callback'];

  drupal_set_title(t('Publications'));
  $sort = hwc_req_param($form_state, 'sort', 'date');
  $form = array(
    '#action' => '/' . $language->language . '/' . $action,
    '#method' => 'GET',
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-12')),
    ),
  );
  $form['#token'] = FALSE;
  $form['content']['sort_fieldset'] = array(
    '#type' => 'fieldset',
  );
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/form.js',
  );

  $per_page = 5;

  $response = call_user_func($search_callback, $form_state, $sort);
  $languages = hwc_req_param($form_state, 'languages', array($language->language));

  $restrict = array();
  if (!empty($response['results'])) {
    foreach ($response['results'] as $result) {
      list($lng, $nid) = explode('_', $result['id'], 2);
      $restrict[] = $nid;
    }
  }
  $nids = array_unique($restrict);
  $form['content']['results-native'] = array(
    '#nids' => '',
  );
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
  }

  $current_page = pager_default_initialize(count($nids), $per_page);
  $start = $current_page * $per_page;

  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  $shown = 0;
  if ($nodes) {
    foreach ($nodes as $node) {
      $node->filter_languages = $languages;
    }
    $pager_params = array('languages' => $languages);
    if (!empty($text)) {
      $pager_params['text'] = $text;
    }
    $form['content']['results-native'] = array(
      '#nids' => $nids,
      'results-native' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
      '#suffix' => theme('pager',
        array(
          'tags' => array('<', '<', '', '>', '>'),
          'quantity' => 9,
          'parameters' => $pager_params,
        )
      ),
    );
    $shown = count($nodes);
  }
  if (empty($form['content']['results-native']['#nids'])) {
    $form['content']['results-native']['#markup'] = '<p class="no-results">' . t('No results found to match your search.') . '</p>';
  }


  $form['content']['sort_fieldset']['search_summary'] = array(
    '#prefix' => '<span class="count-container pull-right">',
    '#suffix' => '</span>',
    '#type' => 'markup',
    '#markup' => t('Showing @start - @limit from @total',
      array('@start' => $start + 1, '@limit' => $start + $shown, '@total' => $response['result count'])),
  );

  return $form;
}

function _osha_publication_menu_campaign_materials_get_facets_def() {
  return [];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_menu_campaign_materials_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_form_osha_publication_menu_campaign_materials_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}


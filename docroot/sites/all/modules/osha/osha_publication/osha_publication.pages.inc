<?php

define('CASE_STUDY_TID', 521);

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_menu_publications_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_menu_case_studies_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_form_osha_publication_menu_publications_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function osha_publication_form_osha_publication_menu_case_studies_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

function osha_publication_menu_publications_form($form, $form_state) {
  $variables['form_state'] = $form_state;
  $variables['action'] = 'tools-and-publications/publications';
  $variables['facet_callback'] = '_osha_publication_menu_publications_get_facets_def';
  $variables['search_callback'] = 'osha_publication_menu_publications_search';

  return osha_publication_menu_publications_faceted_form($variables);
}

function osha_publication_menu_publications_faceted_form($variables) {
  global $current_page, $language;
  $form_state = $variables['form_state'];
  $action = $variables['action'];
  $facet_callback = $variables['facet_callback'];
  $search_callback = $variables['search_callback'];

  drupal_set_title(t('Publications'));
  $text = hwc_req_param($form_state, 'text');
  $sort = hwc_req_param($form_state, 'sort', 'date');

  $form = array(
    '#action' => '/' . $language->language . '/' . $action,
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-3')),
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-9')),
    ),
  );
  $form['left-column']['search']['text'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Search'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search')),
    '#prefix' => '<div id="search">',
  );
  $form['left-column']['search']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );
  if (!empty($text)) {
    $form['content']['search_phrase'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="results-for">' . t('Results for !text',
          array('!text' => '<span class="searched-text"> ' . check_plain($text) . '</span>')) . '</div>',
    );
  }
  $form['#token'] = FALSE;
  $form['content']['sort_fieldset'] = array(
    '#type' => 'fieldset',
  );
  $form['content']['sort_fieldset']['sort'] = array(
    '#type' => 'select',
    '#title' => t('Order'),
    '#default_value' => $sort,
    '#prefix' => '<div class="sort-container col-xs-3">',
    '#suffix' => '</div>',
    '#options' => array(
      'date' => t('Latest first'),
      'alphabetically' => t('Alphabetically'),
    ),
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/form.js',
  );
  if (!empty($text)) {
    $form['content']['search_phrase'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="results-for">' . t('Results for !text', array('!text' => '<span class="searched-text">' . check_plain($text) . '</span>')) . '</div>',
    );
  }

  $facets_def = call_user_func($facet_callback);

  $response = call_user_func($search_callback, $form_state, $sort);

  $per_page = 4;
  $form['content']['results-native'] = osha_publication_menu_publications_native_results($form_state, $response, $per_page, $sort);
  $start = $current_page * $per_page;
  $shown = 0;
  if (isset($form['content']['results-native']['#shown'])) {
    $shown = $form['content']['results-native']['#shown'];
  }

  $facets = array();
  if (!empty($response['search_api_facets'])) {
    $facets = $response['search_api_facets'];
    _osha_publication_facet_value_clear($facets);
  }

  $query_params = drupal_get_query_parameters();

  if (!empty($query_params)) {
    // Clear filter link
    // it's really just a link to current url without params.
    $form['left-column']['link'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="clear_filters">' . l(t('Clear filters'), current_path()) . '</div>',
    );
  }

  foreach ($facets_def as $field_name => $facet_def) {
    if (!empty($facets[$field_name])) {
      $values_list = call_user_func($facet_def['options_callback'], $facet_def['options_callback_args']);
      $options = array();
      foreach ($facets[$field_name] as $facet_value) {
        if (!empty($values_list[$facet_value['filter']])) {
          if ($facet_value['filter'] == CASE_STUDY_TID) {
            continue;
          }
          $options[$facet_value['filter']] = $values_list[$facet_value['filter']];
          $form['left-column'][$field_name] = array(
            '#type' => 'checkboxes',
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, array()),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array('search-facet-field')),
          );
        }
        elseif ($facet_value['filter'] == '!') {
          $options[$facet_value['filter']] = t('No specific group');
          $form['left-column'][$field_name] = array(
            '#type' => 'checkboxes',
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, array()),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array('search-facet-field')),
          );
        }
      }

      if (!empty($form['left-column'][$field_name]['#default_value'])) {
        foreach ($form['left-column'][$field_name]['#default_value'] as $val) {
          if (!empty($options[$val])) {
            $filter_label = '<span class="glyphicon glyphicon-remove"></span>' . $options[$val];
            $query = _osha_publication_strip_param_value($query_params, $field_name, $val) ?: ['text' => ''];
            $form['left-column']['search']['filters'][] = array(
              '#type' => 'markup',
              '#markup' => l($filter_label, $action, array('query' => $query, 'html' => TRUE)),
            );
          }
        }
      }
    }
  }

  $native_nids = [];
  if (isset($form['content']['results-native']['#nids'])) {
    $native_nids = $form['content']['results-native']['#nids'];
  }

  $form['content']['results-related'] = osha_publication_menu_publications_search_related($form_state, $native_nids, $sort);
  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
    $form['content']['results-related'] = $form_state['#results-related'];
  }
  if (empty($form['content']['results-native']['#nids'])) {
    $form['content']['results-native']['#markup'] =
      '<h3 class="no-results">' .
      t('Sorry, we couldn\'t find any results.') .
      '</h3>' .
      '<p class="no-results">' .
      t('You can try using some different keywords or filters to try to get better results.') .
      '</p>';
  }

  $form['content']['sort_fieldset']['search_summary'] = array(
    '#prefix' => '<span class="count-container pull-right">',
    '#suffix' => '</span>',
    '#type' => 'markup',
    '#markup' => t('Showing @start - @limit from @total',
      array(
        '@start' => $start + 1,
        '@limit' => $start + $shown,
        '@total' => $response['result count'],
      )
    ),
  );
  return $form;
}

function osha_publication_menu_publications_search($form_state, $sort) {
  $facets_def = _osha_publication_menu_publications_get_facets_def();
  $text = hwc_req_param($form_state, 'text');
  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  list($server, $query) = _osha_publication_get_query();

  $query->condition('status', 1);
  $query->condition('type', 'publication');
  $query->condition('field_file:file', 0, '>');
  $query->condition('field_publication_type', CASE_STUDY_TID, "<>");
  $query->condition('language', 'und', "<>");
  $query->keys($text);
  $query->fields(array('title_field', 'body:value'));
  if ($sort == 'alphabetically') {
    $query->sort('title2', 'ASC');
  }
  else {
    $query->sort('field_publication_date', 'DESC');
  }

  $query->setOption('search_api_facets', $facets_def);
  foreach ($facets_def as $field_name => $facet_def) {
    $selected_values = hwc_req_param($form_state, $field_name, array());
    if (!empty($selected_values) && is_array($selected_values)) {
      $filter = $query->createFilter($facet_def['operator'], ['facet:' . $field_name]);
      foreach ($selected_values as $value) {
        // No value.
        if ($value == '!') {
          $filter->condition($field_name, NULL);
        }
        else {
          $filter->condition($field_name, $value);
        }
        $query->filter($filter);
      }
    }
  }
  return $server->search($query);
}

function osha_publication_menu_publications_native_results($form_state, $results, $per_page, $sort) {
  global $language, $current_page;

  $restrict = [];
  if (!empty($results['results'])) {
    foreach ($results['results'] as $result) {
      list($lng, $nid) = explode('_', $result['id'], 2);
      $restrict[] = $nid;
    }
  }
  if (empty($restrict)) {
    return array(
      '#nids' => '',
    );
  }
  $restrict = array_unique($restrict);
  $languages = hwc_req_param($form_state, 'language', array($language->language));

  $nids = [];
  foreach ($restrict as $pnid) {
    $q = db_select('field_data_field_file', 'b');
    $q->fields('b', array('entity_id'));
    $q->innerJoin('node', 'a', 'a.nid = b.entity_id AND a.vid = b.revision_id');
    $q->condition('b.bundle', 'publication');
    $q->condition('b.entity_id', $pnid);
    $q->condition('b.language', $languages, 'IN');
    $c = $q->countQuery()->execute()->fetchField();
    if ($c >= count($languages)) {
      $nids[] = $pnid;
    }
  }
  $nids = array_unique($nids);
  if (empty($nids)) {
    return array();
  }

  // Order publications by publication_date.
  $q = db_select('field_data_field_publication_date', 'a');
  $q->innerJoin('field_data_title_field', 'b', 'a.entity_id = b.entity_id AND a.revision_id = b.revision_id');
  $q->fields('a', array('entity_id'));
  $q->condition('a.entity_id', $nids, 'IN');
  if ($sort == 'alphabetically') {
    $q->orderBy('title_field_value', 'ASC');
  }
  else {
    $q->orderBy('field_publication_date_value', 'DESC');
  }
  $nids = $q->execute()->fetchCol();
  $nids = array_unique($nids);

  $current_page = pager_default_initialize(count($nids), $per_page);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach ($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $pager_params = array('languages' => $languages);
  $text = hwc_req_param($form_state, 'text');
  $is_search = !empty($text);
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  $ret = array(
    '#nids' => $nids,
    '#shown' => count($nodes),
    '#prefix' => '<h2 class="h4-title">' . t('Publications available') . '</h2>',
    'results-native' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
    )),
  );
  return $ret;
}

function osha_publication_menu_publications_search_related($form_state, $native_nids, $sort) {
  global $language;
  $ret = array();
  $languages = hwc_req_param($form_state, 'language', array($language->language));
  if (!empty($languages)) {
    if (in_array('en', $languages)) {
      return $ret;
    }
  }
  else {
    if ($language->language == 'en') {
      return $ret;
    }
  }
  $text = hwc_req_param($form_state, 'text');
  $relevant_for = hwc_req_param($form_state, 'relevant_for', array());
  $publication_type = hwc_req_param($form_state, 'publication_type', array());
  $is_search = !empty($text);

  // Select all publications having field_file available in filtered languages.
  $q = db_select('node', 'a');
  $q->innerJoin('field_data_field_publication_type', 'b', 'a.nid = b.entity_id');
  $q->innerJoin('field_data_title_field', 'c', 'b.entity_id = c.entity_id AND b.revision_id = c.revision_id');
  $q->leftJoin('field_data_field_publication_date', 'pd', 'a.nid = pd.entity_id');
  $q->fields('a', array('nid', 'vid'));
  $q->condition('a.type', 'publication');
  $q->condition('a.status', 1);
  $q->condition('b.field_publication_type_tid', CASE_STUDY_TID, '!=');
  $q->distinct();
  if ($sort == 'alphabetically') {
    $q->orderBy('title_field_value', 'ASC');
  }
  else {
    $q->orderBy('field_publication_date_value', 'DESC');
  }
  if (!empty($restrict)) {
    $q->condition('a.nid', $restrict, 'IN');
  }
  if (!empty($publication_type)) {
    $q->condition('b.field_publication_type_tid', $publication_type, 'IN');
  }
  if (!empty($relevant_for)) {
    $q->innerJoin('field_data_field_priority_area', 'fs', 'fs.entity_id = a.nid AND fs.revision_id = a.vid');
    $q->condition('fs.field_priority_area_tid', $relevant_for, 'IN');
  }
  $nids = $q->execute()->fetchAllKeyed(0, 0);
  // Remove the nodes displayed above (native).
  if (!empty($native_nids)) {
    $nids = array_filter($nids, function ($nid) use ($native_nids) {
      return !in_array($nid, $native_nids);
    });
  }
  if (empty($nids)) {
    return array();
  }
  $per_page = 3;
  $current_page = pager_default_initialize(count($nids), $per_page, 1);
  $page = array_chunk($nids, $per_page, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  foreach ($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $languages = hwc_req_param($form_state, 'language', array($language->language));
  $pager_params = array('languages' => $languages);
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  $ret = array(
    '#prefix' => '<h4>' . t('Other relevant publications in English') . '</h4>',
    '#shown' => count($nodes),
    'results-related' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
      'element' => 1,
    )),
  );
  return $ret;
}

function osha_publication_menu_case_studies_form($form, $form_state) {
  $variables['form_state'] = $form_state;
  $variables['action'] = 'tools-and-publications/case-studies';
  $variables['facet_callback'] = '_osha_publication_menu_case_studies_get_facets_def';
  $variables['search_callback'] = 'osha_publication_menu_case_studies_search';
  return osha_publication_menu_case_studies_faceted_form($variables);
}

function osha_publication_menu_case_studies_search($form_state, $sort) {
  $facets_def = _osha_publication_menu_case_studies_get_facets_def();
  $text = hwc_req_param($form_state, 'text');
  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  list($server, $query) = _osha_publication_get_query();

  $query->condition('status', 1);
  $query->condition('type', 'publication');
  $query->condition('field_file:file', 0, '>');
  $query->condition('field_publication_type', CASE_STUDY_TID);
  $query->condition('language', 'und', "<>");
  $query->keys($text);
  $query->fields(array('title_field', 'body:value'));
  if ($sort == 'alphabetically') {
    $query->sort('title2', 'ASC');
  }
  else {
    $query->sort('field_publication_date', 'DESC');
  }

  $query->setOption('search_api_facets', $facets_def);
  foreach ($facets_def as $field_name => $facet_def) {
    $selected_values = hwc_req_param($form_state, $field_name, array());
    if (!empty($selected_values) && is_array($selected_values)) {
      $filter = $query->createFilter($facet_def['operator'], ['facet:' . $field_name]);
      foreach ($selected_values as $value) {
        // No value.
        if ($value == '!') {
          $filter->condition($field_name, NULL);
        }
        else {
          $filter->condition($field_name, $value);
        }
        $query->filter($filter);
      }
    }
  }
  return $server->search($query);
}

function osha_publication_menu_case_studies_faceted_form($variables) {
  global $language, $current_page;

  $form_state = $variables['form_state'];
  $action = $variables['action'];
  $facet_callback = $variables['facet_callback'];
  $search_callback = $variables['search_callback'];

  drupal_set_title(t('Publications'));
  $text = hwc_req_param($form_state, 'text');
  $sort = hwc_req_param($form_state, 'sort', 'date');
  $form = array(
    '#action' => '/' . $language->language . '/' . $action,
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-3')),
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-9')),
    ),
  );
  $form['left-column']['search']['text'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Search'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search Case studies')),
    '#prefix' => '<div id="search">',
  );
  $form['left-column']['search']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#suffix' => '</div>',
  );
  if (!empty($text)) {
    $form['content']['search_phrase'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="results-for">' . t('Results for !text', array('!text' => '<span class="searched-text"> ' . check_plain($text) . '</span>')) . '</div>',
    );
  }
  $form['#token'] = FALSE;
  $form['content']['sort_fieldset'] = array(
    '#type' => 'fieldset',
  );
  $form['content']['sort_fieldset']['sort'] = array(
    '#type' => 'select',
    '#title' => t('Order'),
    '#default_value' => $sort,
    '#prefix' => '<div class="sort-container col-xs-3">',
    '#suffix' => '</div>',
    '#options' => array(
      'date' => t('Latest first'),
      'alphabetically' => t('Alphabetically'),
    ),
  );
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'osha_publication') . '/js/form.js',
  );

  $per_page = 5;
  $facets_def = call_user_func($facet_callback);

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

  $facets = array();
  if (!empty($response['search_api_facets'])) {
    $facets = $response['search_api_facets'];
    _osha_publication_facet_value_clear($facets);
  }

  $query_params = drupal_get_query_parameters();

  if (!empty($query_params)) {
    // Clear filter link
    // it's really just a link to current url without params.
    $form['left-column']['link'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="clear_filters">' . l(t('Clear filters'), current_path()) . '</div>',
    );
  }

  foreach ($facets_def as $field_name => $facet_def) {
    if (!empty($facets[$field_name])) {
      $values_list = call_user_func($facet_def['options_callback'], $facet_def['options_callback_args']);
      $options = array();
      foreach ($facets[$field_name] as $facet_value) {
        if (!empty($values_list[$facet_value['filter']])) {
          if ($facet_value['filter'] == CASE_STUDY_TID) {
            continue;
          }
          // . ' ' . strtr('(@no)', array('@no' => $facet_value['count']));
          $options[$facet_value['filter']] = $values_list[$facet_value['filter']];
          $form['left-column'][$field_name] = array(
            '#type' => 'checkboxes',
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, array()),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array('search-facet-field')),
          );
        }
        elseif ($facet_value['filter'] == '!') {
          $options[$facet_value['filter']] = t('No specific group');
          $form['left-column'][$field_name] = array(
            '#type' => 'checkboxes',
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, array()),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array('search-facet-field')),
          );
        }
      }
      if (!empty($form['left-column'][$field_name]['#default_value'])) {
        foreach ($form['left-column'][$field_name]['#default_value'] as $val) {
          if (!empty($options[$val])) {
            $filter_label = '<span class="glyphicon glyphicon-remove"></span>' . $options[$val];
            $query = _osha_publication_strip_param_value($query_params, $field_name, $val) ?: ['text' => ''];
            $form['left-column']['search']['filters'][] = array(
              '#type' => 'markup',
              '#markup' => l($filter_label, $action, array('query' => $query, 'html' => TRUE)),
            );
          }
        }
      }
    }
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

/**
 * Check if 'priority area' filter selected.
 */
function _osha_publication_generate_all_facet_link($key = 'field_priority_area') {
  $url = drupal_parse_url(request_uri());
  if (isset($url['query']) && isset($url['query'][$key])) {
    unset($url['query'][$key]);
  }
  $link = l(t('All'), '/' . arg(0) . '/' . arg(1), array(
    'attributes' => array(
      'class' => 'facetapi-checkbox facetapi-inactive facetapi-makeCheckbox-processed facetapi-disableClick-processed',
    ),
    'query' => $url['query'],
  ));
  return $link;
}

/**
 * Check if 'priority area' filter selected.
 */
function _osha_publication_is_selected_facet() {
  $url = drupal_parse_url(request_uri());
  if (isset($url['query']) && isset($url['query']['field_priority_area'])) {
    return TRUE;
  }
  return FALSE;
}

function _osha_publication_menu_case_studies_get_facets_def() {
  return array(
    'language' => array(
      'label' => t('Language'),
      'field' => 'language',
      'limit' => 50,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_language_list_options',
      'options_callback_args' => array(TRUE, TRUE),
    ),
    'field_priority_area' => array(
      'label' => t('Topics'),
      'field' => 'field_priority_area',
      'limit' => 150,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => TRUE,
      'options_callback' => '_osha_publication_taxonomy_filter_options_list',
      'options_callback_args' => array('priority_area'),
    ),
  );
}

function _osha_publication_menu_publications_get_facets_def() {
  return array(
    'field_publication_type' => array(
      'label' => t('Publications type'),
      'field' => 'field_publication_type',
      'limit' => 50,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_taxonomy_filter_options_list',
      'options_callback_args' => array('publication_types'),
    ),
    'language' => array(
      'label' => t('Language'),
      'field' => 'language',
      'limit' => 50,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_osha_publication_language_list_options',
      'options_callback_args' => array(TRUE, TRUE),
    ),
    'field_priority_area' => array(
      'label' => t('Topics'),
      'field' => 'field_priority_area',
      'limit' => 150,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => TRUE,
      'options_callback' => '_osha_publication_taxonomy_filter_options_list',
      'options_callback_args' => array('priority_area'),
    ),
  );
}

function _osha_publication_get_query() {
  $server = search_api_server_load('solr_server');
  $index = search_api_index_load('default_multilingual_node_index');
  $query = new SearchApiQuery($index);
  // Avoid PHP notice.
  $query->fields(array());
  $solr = new SearchApiSolrService($server);
  return array($solr, $query);
}

function _osha_publication_language_list_options($prefix = TRUE, $native = TRUE) {
  // Used by hwc_practical_tool_get_facets_def and _oira_promotional_material_search_form_get_facets.
  // For tools and promotional materials we don't exclude Catalan.
  $disabled = osha_disabled_language_list();
  unset($disabled['ca']);
  $languages = osha_language_list_options($native);//, TRUE, $disabled
  if ($prefix) {
    foreach ($languages as $lang_code => $value) {
      $languages[$lang_code] = strtoupper($lang_code) . ' - ' . $value;
    }
  }
  return $languages;
}

function _osha_publication_taxonomy_filter_options_list($vocabulary, $default = array()) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary);
  if (!empty($vocabulary)) {
    $terms = taxonomy_term_load_multiple(array(), array('vid' => $vocabulary->vid));
    foreach ($terms as $key => $term) {
      $default[$term->tid] = $term->name;
    }
  }
  return $default;
}

function _osha_publication_facet_value_clear(&$facets) {
  if (!empty($facets)) {
    foreach ($facets as &$facet_field) {
      foreach ($facet_field as &$facet_value) {
        // The filters come wrapped in ".
        $facet_value['filter'] = trim($facet_value['filter'], '"');
      }
    }
  }
}

function _osha_publication_strip_param_value($params, $name, $value = NULL) {
  if (!empty($params[$name])) {
    if (!is_array($params[$name])) {
      unset($params[$name]);
    }
    else {
      $flipped = array_flip($params[$name]);
      if (array_key_exists($value, $flipped)) {
        unset($params[$name][$flipped[$value]]);
        if (empty($params[$name])) {
          unset($params[$name]);
        }
      }
    }
  }
  return $params;
}


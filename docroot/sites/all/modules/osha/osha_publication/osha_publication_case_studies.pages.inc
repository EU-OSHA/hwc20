<?php
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
function osha_publication_form_osha_publication_menu_case_studies_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}


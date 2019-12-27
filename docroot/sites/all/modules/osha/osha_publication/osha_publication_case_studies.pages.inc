<?php

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

function osha_publication_menu_case_studies_form($form, $form_state) {
  $variables['form_state'] = $form_state;
  return osha_publication_menu_case_studies_faceted_form($variables);
}

/* Case studies faceted form.
 * @param $variables
 *
 * @return array
 */
function osha_publication_menu_case_studies_faceted_form($variables) {
  global $current_page, $language;
  $form_state = $variables['form_state'];
  $action = 'tools-and-publications/case-studies';

  drupal_set_title(t('Publications'));
  $text = hwc_req_param($form_state, 'text');
  $sort = hwc_req_param($form_state, 'sort', 'date');

  $form = array(
    '#prefix' => '<div class="content-fluid grey-background"><div class="container">',
    '#suffix' => '</div></div>',
    '#action' => '/' . $language->language . '/' . $action,
    '#method' => 'GET',
    'left-column' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('sidebars_first')),
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('two_column')),
      '#id' => 'content',
    ),
  );
  $content_filters = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('content-filters')),
  );

  $form['left-column']['field_msd_priority_area'] = $content_filters;
  $form['left-column']['language'] = $content_filters;

  $form['#token'] = FALSE;

  if (!empty($text)) {
    $form['content']['search_phrase'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="results-for">' . t('Results for !text',
          array('!text' => '<span class="searched-text"> ' . check_plain($text) . '</span>')) . '</div>',
    );
  }
  $form['content']['exposed-widgets'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('views-exposed-widgets clearfix')),
  );

  $form['content']['exposed-widgets']['search']['text'] = array(
    '#type' => 'textfield',
    '#size' => 30,
    '#title' => t('Search'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search Case studies'), 'class' => ['search-new-design']),
    '#prefix' => '<div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget views-widget-filter-search_api_views_fulltext"><div class="views-widget">',
    '#suffix' => '</div></div>',
  );

  $form['content']['exposed-widgets']['sort'] = array(
    '#type' => 'select',
    '#title' => t('Order'),
    '#default_value' => $sort,
    '#attributes' => array('class' => ['new-select-style']),
    '#prefix' => '<div class="views-exposed-widget views-widget-sort-by">',
    '#suffix' => '</div>',
    '#options' => array(
      'date' => t('Latest first'),
      'alphabetically' => t('Alphabetically'),
    ),
  );
  $form['content']['exposed-widgets']['language'] = [];

  $query_params = drupal_get_query_parameters();
  if (!empty($query_params)) {
    $form['content']['link'] = [
      '#type' => 'markup',
      '#markup' => '<div class="clear_filters">' . l(t('Clear filters'), current_path()) . '</div>',
    ];
  }
  $facets_def = _osha_publication_menu_case_studies_get_facets_def();

  $response = osha_publication_menu_case_studies_search($form_state, $sort);
  $form['content']['results-native'] = osha_publication_menu_case_studies_native_results($form_state, $response, $sort, $current_page);

  $facets = array();
  if (!empty($response['search_api_facets'])) {
    $facets = $response['search_api_facets'];
    _osha_publication_facet_value_clear($facets);
  }

  foreach ($facets_def as $field_name => $facet_def) {
    if (!empty($facets[$field_name])) {
      $values_list = call_user_func($facet_def['options_callback'], $facet_def['options_callback_args']);
      $options = array();

      $default = array();
      if ($field_name == 'language') {
        $type = 'select';
        $class = 'new-select-style';
        $default = array($language->language);
      }
      else {
        $type = 'checkboxes';
        $class = '';
      }

      foreach ($facets[$field_name] as $facet_value) {
        if (!empty($values_list[$facet_value['filter']])) {
          if ($facet_value['filter'] == CASE_STUDY_TID) {
            continue;
          }
          $options[$facet_value['filter']] = $values_list[$facet_value['filter']];
          $form['left-column'][$field_name][$field_name] = array(
            '#type' => $type,
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, $default),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array($class)),
          );
        }
        elseif ($facet_value['filter'] == '!') {

          $options[$facet_value['filter']] = t('No specific group');
          $form['left-column'][$field_name][$field_name] = array(
            '#type' => $type,
            '#options' => $options,
            '#default_value' => hwc_req_param($form_state, $field_name, $default),
            '#title' => $facet_def['label'],
            '#attributes' => array('class' => array($class)),
          );
        }
        asort($form['left-column'][$field_name][$field_name]['#options']);
      }
    }
  }
  $form['content']['exposed-widgets']['language'] = $form['left-column']['language']['language'];
  $form['content']['exposed-widgets']['language']['#prefix'] = '<div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget views-widget-filter-search_api_language">';
  $form['content']['exposed-widgets']['language']['#suffix'] = '</div>';

  $form['content']['exposed-widgets']['language']['#chosen'] = TRUE;
  $form['content']['exposed-widgets']['language']['#multiple'] = TRUE;
  unset($form['left-column']['language']);

  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
  }
  if (empty($form['content']['results-native']['#nids'])) {
    $form['content']['results-native']['#markup'] =
      '<h3 class="no-results">' .
      t('Sorry, we couldn\'t find any results.') .
      '</h3><p class="no-results">' .
      t('You can try using some different keywords or filters to try to get better results.') .
      '</p>';
    $form['#attributes']['class'][] = 'no-results';
  }
  return $form;
}

function osha_publication_menu_case_studies_search($form_state, $sort) {
  $facets_def = _osha_publication_menu_case_studies_get_facets_def();
  $text = hwc_req_param($form_state, 'text');
  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  list($server, $query) = _osha_publication_get_query();

  $query->condition('status', 1);
  $query->condition('type', 'publication');
//  $query->condition('field_file:file', 0, '>');
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
    $selected_values = hwc_req_param($form_state, $field_name, []);
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

function osha_publication_menu_case_studies_native_results($form_state, $results, $sort, $current_page) {
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

  $languages = hwc_req_param($form_state, 'languages', array($language->language));

  $nids = array_unique($restrict);

  $per_page = 5;
  $current_page = pager_default_initialize(count($nids), $per_page);
  $start = $current_page * $per_page;
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
  $total = "";
  if ($nids) {
    $total = ' <span>(' . count($nids) . ')</span>';
  }
  $pager_total = '';
  if ((count($nids)) > $per_page) {
    $pager_total = '<div class="pager-total"><span>' . ($start + 1) . ' - ' . ($start + count($nodes)) . '</span></div>';
  }
  $pager = theme('pager', [
    'quantity' => 9,
    'parameters' => $pager_params,
  ]);
  if ($nodes) {
    $keys = array_keys($nodes);
    $data = [
      end($keys) => 'last',
      reset($keys) => 'first',
    ];
    osha_publications_classes($data);
  }

  $ret = array(
    '#nids' => $nids,
    '#shown' => count($nodes),
    '#prefix' => '<h2>' . t('Case studies available') . $total . '</h2>',
    'results-native' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
    '#suffix' => '</div><div class="content-fluid grey-background"><div class="content-pagination container">' . $pager . $pager_total . '</div></div><div>',
  );
  return $ret;
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

    'field_msd_priority_area' => array(
      'label' => t('Priority Areas'),
      'field' => 'field_msd_priority_area',
      'limit' => 150,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => TRUE,
      'options_callback' => '_osha_publication_msd_priority_area_options_list',
      'options_callback_args' => array(),
    ),
  );
}

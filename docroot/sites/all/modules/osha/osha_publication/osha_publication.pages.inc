<?php

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
function osha_publication_form_osha_publication_menu_publications_form_alter(&$form, $form_state) {
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

/* Publications faceted form.
 * @param $variables
 *
 * @return array
 */
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

  $form['left-column']['field_publication_type'] = $content_filters;
  $form['left-column']['language'] = $content_filters;
  $form['left-column']['main_tags'] = $content_filters;

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
    '#title' => t('Search in resources'),
    '#maxlength' => 200,
    '#default_value' => $text,
    '#title_display' => 'invisible',
    '#attributes' => array('placeholder' => t('Search in resources'), 'class' => ['search-new-design']),
    '#prefix' => '<div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget views-widget-filter-search_api_views_fulltext"><div class="views-widget">',
    '#suffix' => '</div></div>',
  );

  $form['content']['exposed-widgets']['sort'] = array(
    '#type' => 'select',
    '#title' => t('Sort by'),
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

  $facets_def = call_user_func($facet_callback);

  $response = call_user_func($search_callback, $form_state, $sort);

  $form['content']['results-native'] = osha_publication_menu_publications_native_results($form_state, $response, $sort, $current_page);

  $facets = array();
  if (!empty($response['search_api_facets'])) {
    $facets = $response['search_api_facets'];
    _osha_publication_facet_value_clear($facets);
  }

  $query_params = drupal_get_query_parameters();
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
          if ($facet_value['filter'] == CAMPAIGN_MATERIALS_TID) {
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
      }
    }
  }
  $form['content']['exposed-widgets']['language'] = $form['left-column']['language']['language'];
  $form['content']['exposed-widgets']['language']['#prefix'] = '<div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget views-widget-filter-search_api_language">';
  $form['content']['exposed-widgets']['language']['#suffix'] = '</div>';

  $form['content']['exposed-widgets']['language']['#chosen'] = TRUE;
  $form['content']['exposed-widgets']['language']['#multiple'] = TRUE;
  unset($form['left-column']['language']);

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
      '</h3><p class="no-results">' .
      t('You can try using some different keywords or filters to try to get better results.') .
      '</p>';
    $form['#attributes']['class'][] = 'no-results';
  }
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
  $query->condition('field_publication_type', CASE_STUDY_TID, "<>");
  $query->condition('field_publication_type', CAMPAIGN_MATERIALS_TID, "<>");
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

    if ($field_name == 'main_tags') {
      $tags_map = osha_publication_get_main_tags_map(FALSE);
      $publication_tags_ids = [];
      foreach ($selected_values as $val) {
        $publication_tags_ids[] = $val;
        foreach ($tags_map as $tid => $main_tid) {
          if ($val == $main_tid) {
            $publication_tags_ids[] = $tid;
            $term = taxonomy_term_load($tid);
          }
        }
      }
      $selected_values = $publication_tags_ids;
    }

    if ($field_name == 'field_publication_type') {
      $types_map = osha_publication_get_main_publication_types_map(FALSE);
      $publication_type_ids = array();
      if (!empty($selected_values)) {
        foreach ($selected_values as $val) {
          if ($val) {
            $publication_type_ids[] = $val;
            foreach ($types_map as $tid => $main_tid) {
              if ($val == $main_tid) {
                $publication_type_ids[] = $tid;
              }
            }
          }
        }
      }
      $selected_values = $publication_type_ids;
    }
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

function osha_publication_menu_publications_native_results($form_state, $results, $sort, $current_page) {
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
    $q = db_select('field_data_title_field', 'b');
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

  $q = db_select('field_data_field_publication_date', 'a');
  $q->innerJoin('field_data_title_field', 'b', 'a.entity_id = b.entity_id AND a.revision_id = b.revision_id');
  $q->condition('b.language', $languages, 'IN');
  $q->fields('a', array('entity_id'));
  $q->condition('a.entity_id', $nids, 'IN');
  if ($sort == 'alphabetically') {
    $q->orderBy('title_field_value', 'ASC');
  }
  else {
    // Order publications by publication_date.
    $q->orderBy('field_publication_date_value', 'DESC');
  }
  $nids = $q->execute()->fetchCol();
  $nids = array_unique($nids);

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
  if (count($nodes) > $per_page) {
  $pager_total = '<div class="pager-total"><span>' . ($start + 1) . ' - ' . ($start + count($nodes)) . '</span></div>';
  }
  $pager = theme('pager', [
    'quantity' => 9,
    'parameters' => $pager_params,
  ]);
  if ($nodes) {
    $data = [end(array_keys($nodes)) => 'last', reset(array_keys($nodes)) => 'first'];
    osha_publications_classes($data);
  }
  $ret = array(
    '#nids' => $nids,
    '#shown' => count($nodes),
    '#prefix' => '<h2>' . t('Publications available') . $total . '</h2>',
    'results-native' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
    '#suffix' => '</div><div class="content-fluid grey-background"><div class="content-pagination container">' . $pager . $pager_total . '</div></div><div>',
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
    $q->innerJoin('field_data_field_tags', 'fs', 'fs.entity_id = a.nid AND fs.revision_id = a.vid');
    $q->condition('fs.field_tags_tid', $relevant_for, 'IN');
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
  $pager = theme('pager', array(
    'quantity' => 9,
    'parameters' => $pager_params,
    'element' => 1,
  ));
  $ret = array(
    '#prefix' => '<h4>' . t('Other relevant publications in English') . '</h4>',
    '#shown' => count($nodes),
    'results-related' => node_view_multiple($nodes, 'pub_teaser', 0, $language->language),
    '#suffix' => $pager,
  );
  return $ret;
}

/**
 * Check if 'priority area' filter selected.
 */
function _osha_publication_generate_all_facet_link($key = 'main_tags') {
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
  if (isset($url['query']) && isset($url['query']['main_tags'])) {
    return TRUE;
  }
  return FALSE;
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
      'options_callback' => '_osha_publication_type_filter_options_list',
      'options_callback_args' => array(''),
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

    'main_tags' => array(
      'label' => t('Topics'),
      'field' => 'main_tags',
      'limit' => 150,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => TRUE,
      'options_callback' => '_osha_publication_topic_filter_options_list',
      'options_callback_args' => array(FALSE),
    ),
  );
}

function _osha_publication_get_query() {
  $server = search_api_server_load('solr_server');
  $index = search_api_index_load(SOLR_SEARCH_INDEX);
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
  $languages = osha_language_list_options($native);
  if ($prefix) {
    foreach ($languages as $lang_code => $value) {
      $languages[$lang_code] = strtoupper($lang_code) . ' - ' . $value;
    }
  }
  return $languages;
}

function _osha_publication_topic_filter_options_list() {
  return _osha_publication_tags_options_list(TRUE);
}

function _osha_publication_type_filter_options_list() {
  return _publication_type_options_list(TRUE);
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

/**
 * Get options for publication type filter.
 */
function _publication_type_options_list($map_only = FALSE) {
  $map = osha_publication_get_main_publication_types_map();
  $return = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('publication_types');
  if (!empty($vocabulary)) {
    $terms = taxonomy_get_tree($vocabulary->vid);
    foreach ($terms as $key => $term) {
      if ($map_only) {
        if (!empty($map[$term->tid])) {
          $term = taxonomy_term_load($map[$term->tid]);
          if (!$term->field_main_category) {
            continue;
          }
          if (!$term->field_main_category[LANGUAGE_NONE][0]['value']) {
            continue;
          }
          $return[$term->tid] = $term->name;
        }
        else {
          $term = taxonomy_term_load($term->tid);
          if (!$term->field_main_category) {
            continue;
          }
          if (!$term->field_main_category[LANGUAGE_NONE][0]['value']) {
            continue;
          }
          $return[$term->tid] = $term->name;
        }
      }
      else {
        $return[$term->tid] = $term->name;
      }
    }
  }
  return $return;
}

/**
 * Get options for tags filter.
 */
function _osha_publication_tags_options_list($map_only = FALSE) {

  $return = array();
  $q = db_select('field_data_field_tags', 't')
    ->distinct();
  $q->fields('t', array('field_tags_tid'));
  $q->condition('entity_type', 'node');
  $q->condition('bundle', 'publication');
  $q->innerJoin('taxonomy_term_data', 'td', 'td.tid = t.field_tags_tid');
  $q->orderBy('td.name', 'ASC');
  $tids = $q->execute()->fetchCol();
  if ($map_only) {
    $map = osha_publication_get_main_tags_map();
    $old_tids = $tids;
    $tids = [];
    foreach ($old_tids as $tid) {
      $term_id = $tid;
      if (!empty($map[$term_id])) {
        $term_id = $map[$term_id];
      }
      $term = taxonomy_term_load($term_id);
      if (!$term->field_main_topic) {
        continue;
      }
      if (!$term->field_main_topic[LANGUAGE_NONE][0]['value']) {
        continue;
      }
      $tids[] = $term_id;
    }
  }
  $terms = taxonomy_term_load_multiple($tids);
  if (!empty($terms)) {
    foreach ($terms as $key => $term) {
//      if (!empty($term->field_tags_code[LANGUAGE_NONE][0]['value'])) {
//        $code = $term->field_tags_code[LANGUAGE_NONE][0]['value'];
//        $code = str_replace('/', '__', $code);
//        $return[$code] = $term->name;
//      }
//      else {
        $return[$term->tid] = $term->name;
//      }
    }
  }
  return $return;
}

/**
 * Get tag tid by tag code.
 */
function _osha_publication_get_tag_by_code($code) {
  $code = str_replace('__', '/', $code);
  $tid = FALSE;
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
    ->fieldCondition('field_tags_code', 'value', $code, '=')
    ->range(0, 1);
  $result = $query->execute();

  if (isset($result['taxonomy_term'])) {
    $tid = current(array_keys($result['taxonomy_term']));
  }
  return $tid;
}

<?php
define('PRACTICAL_TOOL_PER_PAGE', 14);

/**
 * Implements hook_form_FORM_ID_alter().
 */
function hwc_practical_tool_form_hwc_practical_tool_menu_tools_form_alter(&$form, $form_state) {
  // Unset the form_id and build_id in order not to have nasty urls.
  unset($form['form_id']);
  unset($form['form_build_id']);
}

function hwc_practical_tool_menu_tools_form($form, $form_state) {
  global $current_page;
  drupal_set_title(t('Practical tools'));
  $action = 'tools-and-publications/practical-tools';

  $text = hwc_req_param($form_state, 'text');
  $sort = hwc_req_param($form_state, 'sort', 'date');
  $form = array(
    '#action' => $action,
    '#method' => 'GET',
    '#token' => FALSE,
    'top' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col col-md-12')),
    ),
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
    '#attributes' => array('placeholder' => t('Search Practical tools')),
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
      '#markup' => '<div class="results-for">' . t('Results for !text', array('!text' => '<span class="searched-text"> ' . check_plain($text) .'</span>')) . '</div>',
    );
  }
  $form['content']['sort_fieldset'] = array(
    /* Needed so that the page passes Web Accessibility test */
    '#type' => 'fieldset',
  );
  $form['content']['sort_fieldset']['sort'] = array(
    '#type' => 'select',
    '#title' => t('Order'),
    '#default_value' => $sort,
    '#prefix' => '<div class="sort-container col-xs-3">',
    '#suffix' => '</div>',
    '#options' => array('date' => t('Date'), 'alphabetically' => t('Alphabetically')),
  );
  $form['content']['results-native'] = array(
    '#nids' => '',
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'hwc_practical_tool') . '/js/form.js',
  );

  $response = hwc_practical_tool_menu_tools_search($form_state);

  $facets = array();
  if (!empty($response['search_api_facets'])) {
    $facets = $response['search_api_facets'];
    _hwc_practical_tool_facet_value_clear($facets);
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

  $facets_def = _hwc_practical_tool_get_facets_def();
  foreach ($facets_def as $field_name => $facet_def) {
    if (!empty($facets[$field_name])) {
      $values_list = call_user_func($facet_def['options_callback'], $facet_def['options_callback_args']);
      $options = array();
      foreach ($facets[$field_name] as $facet_value) {
        if (!empty($values_list[$facet_value['filter']])) {
          $options[$facet_value['filter']] = $values_list[$facet_value['filter']];
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
            $query = _hwc_practical_tool_strip_param_value($query_params, $field_name, $val) ?: ['text' => ''];
            $form['left-column']['search']['filters'][] = array(
              '#type' => 'markup',
              '#markup' => l($filter_label, $action, array('query' => $query, 'html' => TRUE)),
            );
          }
        }
      }
    }
  }

  $nids = array();
  if (!empty($response['results'])) {
    foreach ($response['results'] as $result) {
      list($lng, $nid) = explode('_', $result['id'], 2);
      $nids[] = $nid;
    }
    $nids = array_unique($nids);
  }

  $shown = 0;
  if ($nids) {
    if ($sort == 'alphabetically') {
      _hwc_practical_tool_sort_nodes($nids);
    }
    $form['content']['results-native'] = hwc_practical_tool_menu_tools_search_native($form_state, $nids);
    $shown = $form['content']['results-native']['#shown'];
  }
  $form['content']['results-related'] = hwc_practical_tool_menu_tools_search_related($form_state, $nids);

  if (!empty($form_state['#results-native'])) {
    $form['content']['results-native'] = $form_state['#results-native'];
    $form['content']['results-related'] = $form_state['#results-related'];
  }
  if (empty($form['content']['results-native']['#nids'])) {
    $form['content']['results-native']['#markup'] = '<p class="no-results">' . t('No results found to match your search.') . '</p>';
  }

  $start = $current_page * PRACTICAL_TOOL_PER_PAGE;
  $form['content']['sort_fieldset']['search_summary'] = array(
    '#prefix' => '<span class="count-container pull-right">',
    '#suffix' => '</span>',
    '#type' => 'markup',
    '#markup' => t('Showing @start - @limit from @total', array('@start' => $start + 1, '@limit' => $start + $shown, '@total' => $response['result count'])),
  );

  return $form;
}

function hwc_practical_tool_menu_tools_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = FALSE;
}

function hwc_practical_tool_menu_tools_search($form_state) {
  $text = hwc_req_param($form_state, 'text');
  $facets_def = _hwc_practical_tool_get_facets_def();

  /** @var SearchApiQuery $query */
  /** @var SearchApiSolrService $server */
  list($server, $query) = _hwc_practical_tool_menu_tools_get_query();
  $query->condition('status', 1);
  $query->condition('type', 'practical_tool');
  $query->condition('language', 'und', "<>");
  $query->keys($text);
  $query->fields(array('title_field', 'body:value'));
  $query->setOption('search_api_facets', $facets_def);
  foreach ($facets_def as $field_name => $facet_def) {
    $selected_values = hwc_req_param($form_state, $field_name, array());
    if (!empty($selected_values) && is_array($selected_values)) {
      $filter = $query->createFilter($facet_def['operator'], ['facet:' . $field_name]);
      foreach ($selected_values as $value) {
        $filter->condition($field_name, $value);
        $query->filter($filter);
      }
    }
  }

  return $server->search($query);
}

function hwc_practical_tool_menu_tools_search_native($form_state, $nids) {
  global $language, $current_page;

  $languages = hwc_req_param($form_state, 'language', array());
  $text = hwc_req_param($form_state, 'text');
  $sort = hwc_req_param($form_state, 'sort');

  $current_page = pager_default_initialize(count($nids), PRACTICAL_TOOL_PER_PAGE);
  $page = array_chunk($nids, PRACTICAL_TOOL_PER_PAGE, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  $pager_params = array('language' => $languages, 'sort' => $sort);
  if (!$languages) {
    $languages = array($language->language);
  }
  foreach ($nodes as $node) {
    $node->filter_languages = $languages;
  }
  if (!empty($text)) {
    $pager_params['text'] = $text;
  }
  $language_names = array();
  $languages_objects = language_list();
  foreach($languages as $code) {
    $language_names[] = $languages_objects[$code]->native;
  }
  $ret = array(
    '#nids' => $nids,
    '#shown' => count($nodes),
    '#prefix' => '<h2 class="h4-title">' . t('Tools and guidance in ') . implode(', ', $language_names) . '</h2>',
    'results-native' => node_view_multiple($nodes, 'teaser', 0, $language->language),
    '#suffix' => theme('pager', array(
      'tags' => array('<', '<', '', '>', '>'),
      'quantity' => 9,
      'parameters' => $pager_params,
    ))
  );
  return $ret;
}

function hwc_practical_tool_menu_tools_search_related($form_state, $native_nids) {
  global $language;
  $languages = hwc_req_param($form_state, 'language', array($language->language));

  $ret = array();
  if($form_state['input']) {
    if (($form_state['input']['language']['en'] !== NULL)) {
      return $ret;
    }
  }
  else {
    if (in_array('en', $languages)) {
      return $ret;
    }
  }

  $text = hwc_req_param($form_state, 'text');
  $is_search = !empty($text);
  $relevant_for = hwc_req_param($form_state, 'field_priority_area', array());
  // Select all publications having field_file available in filtered languages.

  $q = db_select('node', 'a')->distinct();
  $q->innerJoin('field_data_title_field', 'b', 'a.nid = b.entity_id');
  $q->fields('a', array('nid'));
  $q->condition('a.type', 'practical_tool');
  $q->condition('a.status', 1);
  if ($relevant_for) {
    $q->innerJoin('field_data_field_priority_area', 'c');
    $q->condition('c.field_priority_area_tid', $relevant_for, 'IN');
  }
  if (!empty($native_nids)) {
    $q->condition('a.nid', $native_nids, 'NOT IN');
  }
  $q->orderBy('b.title_field_value');
  $pnids = $q->execute()->fetchCol();

  $nids = array();
  foreach ($pnids as $pnid) {
    if (!empty($relevant_for)) {
      // Check if the node is relevant for all selected 'relevant for' checkboxes.
      $q2 = db_select('field_data_field_priority_area', 'b');
      $q2->fields('b', array('entity_id'));
      $q2->innerJoin('node', 'a', 'a.nid = b.entity_id');
      $q2->condition('b.entity_id', $pnid);
      $q2->condition('b.entity_type', 'node');
      $q2->condition('b.field_priority_area_tid', $relevant_for, 'IN');
      $c2 = $q2->countQuery()->execute()->fetchField();
    }
    else {
      // No 'relevant for' checkbox is selected, so let the node pass this check.
      $c2 = 1;
    }

    if ($c2 >= count($relevant_for)) {
      $nids[] = $pnid;
    }
  }

  if (!empty($native_nids)) { // Remove the nodes displayed above (native)
    $nids = array_filter($nids, function($nid) use ($native_nids) {
      return !in_array($nid, $native_nids);
    });
  }
  if (empty($nids)) {
    return array();
  }

  $current_page = pager_default_initialize(count($nids), PRACTICAL_TOOL_PER_PAGE, 1);
  $page = array_chunk($nids, PRACTICAL_TOOL_PER_PAGE, TRUE);
  $nodes = node_load_multiple($page[$current_page]);
  if (empty($nodes)) {
    return array();
  }
  $languages = hwc_req_param($form_state, 'language', array($language->language));
  foreach ($nodes as $node) {
    $node->filter_languages = $languages;
  }
  $languages = hwc_req_param($form_state, 'language', array($language->language));
  $pager_params = array('language' => $languages);
  if ($is_search) {
    $pager_params['text'] = $text;
  }
  $ret = array(
    '#prefix' => '<h2 class="h4-title">' . t('Other relevant tools in English') . '</h2>',
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

/*
The data included for each tool will be:
  Title (with link to the detail view)
  Extract of the description.
  Country | Language
  Provider



+  Type (EU tools, MS tools, visualisation materials)
       - Type of item
+  Topic / Priority Area
+  Country
+  Language

+  ?Sector / Industry - Sector / Industry covered - field_sector_industry_covered
+  Work tasks - "Tasks covered"                  - field_tasks_covered
+  Health effects - 'Hazard - health effects'    - field_hazard_health_effects
+  Worker groups - 'Worker groups covered'       - field_worker_groups_type
+  Target group - 'Target group'                 - field_target_group

*/

function _hwc_practical_tool_get_facets_def() {
  return array(
    'language' => array(
      'label' => t('Language'),
      'field' => 'language',
      'limit' => 50,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_hwc_practical_tool_language_list_options',
      'options_callback_args' => array(TRUE, TRUE),
    ),
    'field_priority_area' => array(
      'label' => t('Topics'),
      'field' => 'field_priority_area',
      'limit' => 150,
      'operator' => 'or',
      'min_count' => 1,
      'missing' => 0,
      'options_callback' => '_hwc_practical_tool_taxonomy_filter_options_list',
      'options_callback_args' => array('priority_area'),
    ),

  'field_sector_industry_covered' => array(
    'label' => t('Sector / industry'),
    'field' => 'field_sector_industry_covered',
    'limit' => 150,
    'operator' => 'or',
    'min_count' => 1,
    'missing' => 0,
    'options_callback' => '_hwc_practical_tool_taxonomy_filter_options_list',
    'options_callback_args' => array('nace_codes'),//+++
  ),

'field_target_group' => array(
  'label' => t('Target group'),
  'field' => 'field_target_group',
  'limit' => 150,
  'operator' => 'or',
  'min_count' => 1,
  'missing' => 0,
  'options_callback' => '_hwc_practical_tool_taxonomy_filter_options_list',
  'options_callback_args' => array('target_group'),//+++
),

'field_tasks_covered' => array(
  'label' => t('Work tasks'), // "Tasks covered"
  'field' => 'field_tasks_covered',
  'limit' => 150,
  'operator' => 'or',
  'min_count' => 1,
  'missing' => 0,
  'options_callback' => '_hwc_practical_tool_taxonomy_filter_options_list',
  'options_callback_args' => array('hazmap_categories'),//+++
),

'field_worker_groups_type' => array(
  'label' => t('Worker groups'),
  'field' => 'field_worker_groups_type',
  'limit' => 150,
  'operator' => 'or',
  'min_count' => 1,
  'missing' => 0,
  'options_callback' => '_hwc_practical_tool_taxonomy_filter_options_list',
  'options_callback_args' => array('worker_groups'),//+++
),

'field_hazard_health_effects' => array(
  'label' => t('Health effects'),
  'field' => 'field_hazard_health_effects',
  'limit' => 150,
  'operator' => 'or',
  'min_count' => 1,
  'missing' => 0,
  'options_callback' => '_hwc_practical_tool_taxonomy_filter_options_list',
  'options_callback_args' => array('hazard_health_effects'),//+++
),
    /*
field_hazard_health_effects

        'options_callback' => '_hwc_practical_tool_taxonomy_filter_options_list',
        'options_callback_args' => array('publication_types'),*/
/*
    "field_item_type" : { "type" : "string" },
    "field_aditional_resources:type" : { "type" : "list\\u003Cstring\\u003E" },

    "field_aditional_resources:field_hazard_health_effects" : {"type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E", "entity_type" : "taxonomy_term"},
    "field_aditional_resources:field_worker_groups_type" : {"type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E", "entity_type" : "taxonomy_term"},

"field_material_purpose_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
    "field_prevention_measure_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },

+    "field_sector_industry_covered" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
+    "field_target_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
+    "field_tasks_covered" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
+    "field_worker_groups_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
*/
  );
}

function _hwc_practical_tool_menu_tools_get_query() {
  $server = search_api_server_load('solr_server');
  $index = search_api_index_load(HWC_SOLR_SEARCH_INDEX);
  $query = new SearchApiQuery($index);
  $query->fields(array()); // Avoid PHP notice
  $solr = new SearchApiSolrService($server);
  return array($solr, $query);
}

function _hwc_practical_tool_sort_nodes(&$nids) {
  global $language;

  $q = db_select('node', 'a');
  $q->innerJoin('field_data_title_field', 'b', 'a.nid = b.entity_id');
  $q->fields('a', array('nid'))
    ->fields('b', array('title_field_value', 'language'))
    ->condition('a.nid', $nids, 'IN')
    ->condition('b.language', array('en', $language->language), 'IN')
    ->orderBy('b.title_field_value');
  $res = $q->execute()->fetchAll();
  $added = array();
  $nids = array();
  foreach ($res as $item) {
    $nid = $item->nid;
    if (!isset($added[$nid])) {
      $nids[] = $nid;
      $added[$nid] = count($nids) - 1;
      continue;
    }
    if ($item->language == 'en') {
      // Node is already added in current language.
      continue;
    }
    unset($nids[$added[$nid]]);
    $nids[] = $nid;
  }
}

function _hwc_practical_tool_facet_value_clear(&$facets) {
  if (!empty($facets)) {
    foreach ($facets as &$facet_field) {
      foreach ($facet_field as &$facet_value) {
        // The filters come wrapped in ".
        $facet_value['filter'] = trim($facet_value['filter'], '"');
      }
    }
  }
}

function _hwc_practical_tool_taxonomy_filter_options_list($vocabulary, $default = array()) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary);
  if (!empty($vocabulary)) {
    $terms = taxonomy_term_load_multiple(array(), array('vid' => $vocabulary->vid));
    foreach($terms as $key => $term) {
      $default[$term->tid] = $term->name;
    }
  }
  return $default;
}

function _hwc_practical_tool_strip_param_value($params, $name, $value = NULL) {
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

function _hwc_practical_tool_language_list_options($prefix = TRUE, $native = TRUE) {
  // used by hwc_practical_tool_get_facets_def and _oira_promotional_material_search_form_get_facets
  // for tools and promotional materials we don't exclude Catalan
  $disabled = osha_disabled_language_list();
  unset($disabled['ca']);
  $languages = osha_language_list_options($native, TRUE, $disabled);
  if ($prefix) {
    foreach ($languages as $lang_code => $value) {
      $languages[$lang_code] = strtoupper($lang_code) . ' - ' . $value;
    }
  }
  return $languages;
}

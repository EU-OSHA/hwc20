<?php
/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_social_dashboard_column_plugin_style(&$vars) {
  $view = $vars['view'];
  $vars['current_display'] = $view->current_display;
  $vars['items'] = array();
  foreach ($vars['rows'] as $item) {
    $vars['items'][]['content'][0]['content'] = $item;
  }
  foreach($view->display_order as $source => $rows) {
    foreach($rows as $k => $v) {
      $view->display_order[$source][$k] = $vars['items'][$v];
    }
  }
  $vars['items'] = $view->display_order;
}

/**
 * Implementation of template preprocess for the view fields.
 */
function template_preprocess_social_dashboard_column_plugin_rows(&$vars) {
  $view = &$vars['view'];
  $view->display_order = [];
  foreach($view->result as $idx => $row) {
    $view->display_order[$row->dashboard_item_source][] = $idx;
  }
  foreach ($vars['options'] as $id => $field) {
    switch ($id) {
      case 'title':
        if (isset($view->field[$field])) {
          $vars[$id] = $view->style_plugin->get_field($view->row_index, $field);
        }
        break;

      case 'content':
        $vars[$id] = array();
        foreach (array_filter($field) as $content_field) {
          if (isset($view->field[$content_field])) {
            $vars[$id][$content_field] = $view->style_plugin->get_field($view->row_index, $content_field);
          }
        }
        break;
    }
  }

}

function social_dashboard_views_split_rows($vars) {

  return $items;
}

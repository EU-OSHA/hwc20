<?php

/**
 * Implementation of hook_views_plugins().
 */
function hwc_views_plugins() {
  $path = drupal_get_path('module', 'hwc');

  return array(
    'style' => array(
      'hwc_quicktabs' => array(
        'title' => t('HWC Quicktabs'),
        'help' => t('Display view in Quicktabs.'),
        'handler' => 'hwc_quicktabs_style_plugin',
        'path' => "$path/includes",
        'theme' => 'quicktabs_view',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}

/**
 * Implements hook_views_pre_render().
 */
function hwc_views_pre_render(view &$view) {
  if ($view->name == 'documents') {
    drupal_add_css(drupal_get_path('module', 'hwc') . '/css/hwc.css');
  }
  // Add the alphabetical anchor javascript for views.
  // It requires class hwc-alpha-pager-view on the view
  // And hwc-alpha-pager-view-title-field on the field used as title.
  // see hwc_alpha_pager.js
  $class = $view->display_handler->get_option('css_class');
  if (!empty($class) && strpos($class, 'hwc-alpha-pager-view') >= 0) {
    $path = drupal_get_path('module', 'hwc');
    drupal_add_js($path . '/js/hwc_alpha_pager.js');
  }

  // Add JS to create a select list from tabs
  drupal_add_js(drupal_get_path('module', 'hwc') . '/js/hwc_tabs_to_select_list.js');
}

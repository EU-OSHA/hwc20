<?php
/**
 * Render footer menu as nav-pills.
 */
function bootstrap_menu_tree__menu_footer_menu(&$variables) {
  return '<ul class="menu nav nav-pills">' . $variables['tree'] . '</ul>';
}

function hwc_frontend_html_head_alter(&$head_elements) {
  global $language;
  if (
    arg(0) == 'node' &&
    is_numeric(arg(1)) &&
    isset($head_elements['metatag_canonical']['#value'])
  ) {
    $n = menu_get_object('node');
    if ($n && isset($n->field_migration_path_alias) && $n->field_migration_path_alias) {
      $head_elements['metatag_canonical']['#value'] = variable_get('hwc_migration_root_url') .
        '/' . $language->language .
        '/' . $n->field_migration_path_alias[LANGUAGE_NONE][0]['value'];
    }
  }
}

/**
 * Implements theme_menu_link__menu_block().
 */
function hwc_frontend_menu_link__menu_block($variables) {
  $element = &$variables['element'];
  $delta = $element['#bid']['delta'];
  // Render or not the Menu Image.
  // Get the variable provided by osha_menu module.
  $render_img = variable_get('menu_block_' . $delta . '_' . HWC_MENU_RENDER_IMG_VAR_NAME, 0);
  if (!$render_img) {
    return theme_menu_link($variables);
  }
  $output_link = l($element['#title'], $element['#href'], $element['#localized_options']);
  $output_image = "";
  if (!empty($element['#localized_options']['content']['image'])
    && $image_url = file_create_url($element['#localized_options']['content']['image'])) {
    $image = '<img src="' . $image_url . '"/>';
    $output_image = l($image, $element['#href'], array('html' => TRUE));
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>
    <div class="introduction-title">' . $output_link . '</div>
    <div class="introduction-image">' . $output_image . '</div>
    </li>';
}
/**
 * Overrides theme_menu_link().
 */
function hwc_frontend_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;
      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
      $element['#localized_options']['attributes']['role'] = 'button';
      $element['#localized_options']['attributes']['aria-haspopup'] = 'true';
      $element['#localized_options']['attributes']['aria-expanded'] = 'false';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements hook_preprocess_region().
 */
function hwc_frontend_preprocess_region(&$variables, $hook) {
  if (($variables['region'] == "content") && (arg(2) == 'search-toolkit-examples')) {
    $variables['classes_array'][] = 'col-md-9';
  }
}

/**
 * Implements hook_preprocess_html().
 */
function hwc_frontend_preprocess_html(&$vars) {
  $n = menu_get_object('node');
  if ($n) {
    switch ($n->type) {
      case "tk_section":
      case "tk_article":
      case "tk_tool":
      case "tk_example":
      case "tk_topic":
        $about_nid = variable_get('hwc_toolkit_about_nid', 6746);
        if ($n->nid == $about_nid) {
          $vars['classes_array'][] = 'tk-about';
        }
        $vars['classes_array'][] = 'toolkit-page';
        break;
    }
  }
  elseif ((arg(2) == 'search-toolkit-examples') || (arg(3) == 'search-toolkit-examples')) {
    $vars['classes_array'][] = 'toolkit-page';
  }
  elseif ($term = menu_get_object('taxonomy_term', 2)) {
    if ($term->vocabulary_machine_name == 'tools_and_examples') {
      $vars['classes_array'][] = 'toolkit-page';
    }
  }

  if (!empty($vars['is_front'])) {
    $vars['head_title'] = t('Healthy Workplaces MANAGE DANGEROUS SUBSTANCES 2018-19');
  }
  if (arg(0) . arg(2) == 'nodeedit') {
    if ($n->type == 'news' || $n->type == 'events') {
      $vars['classes_array'][] = 'pz-page';
    }
  }
  if (
    (arg(0) . arg(1) . arg(2)) == 'nodeaddnews' ||
    (arg(0) . arg(1) . arg(2)) == 'nodeaddevents'
  ) {
    $vars['classes_array'][] = 'pz-page';
  }

  if ((arg(0) == 'priority-areas') || (arg(1) == 'priority-areas')) {
    $vars['classes_array'][] = 'page-topics';
  }
  if (arg(0) == 'available-flags') {
    $vars['classes_array'][] = 'page-events';
  }
  if (arg(0) == 'good-practice-exchange-platform') {
    $vars['classes_array'][] = 'page-partners-documents';
    $vars['classes_array'][] = 'page-documents';
  }

  $arg1 = arg(1);
  $views_map = hwc_get_views_class_map();
  if (isset($views_map[$arg1])) {
    $vars['classes_array'][] = $views_map[$arg1];
  }
}

function hwc_get_views_class_map() {
  $views_map = [
    'priority-areas' => 'page-priority-areas',
    'glossary-list' => 'page-glossary-list',
    'tools_and_publications' => 'page-tools-and-publications',
    'get-your-certificate' => 'page-get-your-certificate',
    'national-focal-points' => 'page-national-focal-points',
    'official-campaign-partners' => 'page-official-campaign-partners',
    'good-practice-exchange' => 'page-good-practice-exchange',
    'campaign-media-partners' => 'page-campaign-media-partners',
    'enterprise-europe-network' => 'page-enterprise-europe-network',
    'press-room' => 'page-press-room',
    'news' => 'page-news',
    'events' => 'page-events',
    'past-events' => 'page-past-events',
    'photo-gallery' => 'page-photo-gallery',
    'social-media-centre' => 'page-social-media-centre',
    'publications' => 'page-publications',
    'practical-tools' => 'page-practical-tools page-search',
    'campaign-materials' => 'page-campaign-materials',
    'case-studies' => 'page-case-studies',
  ];
  return $views_map;
}

function hwc_frontend_preprocess_page(&$vars) {

  if (arg(0) == 'good-practice-exchange-platform') {
    $breadcrumb = [];
    $breadcrumb[] = l(t('Home'), '<front>');
    $breadcrumb[] = drupal_get_title();
    drupal_set_breadcrumb($breadcrumb);
  }



  $vars['back_to_pz'] = hwc_partner_back_to_private_zone();
  $vars['page']['content']['#post_render'] = ['hwc_content_post_render'];
  // Change Events page title.
  if (!empty($vars['theme_hook_suggestions']['1']) && in_array($vars['theme_hook_suggestions']['1'],
      array('page__media_centre__events', 'page__media_centre__past_events'))) {
    $title = '<span id="block-osha-events-events-links">';
    $title .= l(t('Upcoming events'), 'media-centre/events') . ' / ' . l(t('Past events'), 'media-centre/past-events');
    $title .= '</span>';
    drupal_set_title($title, PASS_THROUGH);
  }
  if (drupal_is_front_page()) {
    unset($vars['page']['content']['system_main']['default_message']);
    drupal_set_title('');
  }
  if ((arg(0) == 'practical-tools') || (arg(1) == 'practical-tools')) {
    $vars['classes_array'][] = 'page-search';
  }

  $vars['show_title'] = TRUE;
  // Add back to links (e.g. Back to news).
  if (isset($vars['node'])) {
    $node = $vars['node'];
    $tag_vars = array(
      'element' => array(
        '#tag' => 'h1',
        '#attributes' => array(
          'class' => array('page-header'),
        ),
      ),
    );
    switch ($node->type) {
      case "tk_section":
      case 'tk_article':
      case "tk_tool":
      case "tk_example":
      case "tk_topic":
        $vars['show_title'] = FALSE;
        $vars['page']['content']['#post_render'][] = 'hwc_content_post_render_add_classes';
        break;

      case 'document':
        $link_href = 'good-practice-exchange-platform';
        $link_title = t('Back to the Good practice exchange platform');
        break;

      case 'publication':
        if ($node->field_publication_type[LANGUAGE_NONE][0]['tid'] == 521 /* Case Studies */) {
          $link_title = t('Back to case studies list');
          $link_href = 'case-studies';
          $tag_vars['element']['#value'] = t('Case studies');
          $vars['page']['above_title']['title-alternative'] = array(
            '#type' => 'item',
            '#markup' => theme('html_tag', $tag_vars),
          );
          break;
        }
        $link_title = t('Back to publications list');
        $link_href = 'publications';
        $tag_vars['element']['#value'] = t('Publications');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'press_release':
        $link_title = t('Back to press releases list');
        $link_href = 'media-centre/press-room';
        $tag_vars['element']['#value'] = t('Press releases');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'news':
        $link_title = t('Back to news');
        $link_href = 'media-centre/news';
        $tag_vars['element']['#value'] = t('News');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'infographic':
        $link_title = t('Back to infographics list');
        $link_href = 'infographics';
        $tag_vars['element']['#value'] = t('Infographics');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'campaign_materials':
        $link_title = t('Back to campaign materials list');
        $link_href = 'campaign-materials';
        $tag_vars['element']['#value'] = t('Campaign materials');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'practical_tool':
        $link_title = t('Back to practical tools list');
        $link_href = 'tools-and-publications/practical-tools';
        if (isset($_REQUEST['destination'])) {
          $destination = drupal_get_destination();
          $vars['page']['below_title']['back-to-link'] = array(
            '#type' => 'item',
            '#markup' => '<a class="back-to-link pull-right" href="' . strip_tags($destination['destination']) . '">' . $link_title . '</a>',
          );
          unset($link_title);
        }
        $tag_vars['element']['#value'] = t('Practical tools and guidance');
        $vars['page']['below_title']['practical-tool-page-title'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        krsort($vars['page']['below_title']);
        break;

      case 'events':
        $date = new DateTime($node->field_start_date['und'][0]['value']);
        $now = new DateTime('today');

        $breadcrumb = array();
        $breadcrumb[] = l(t('Home'), '<front>');
        $breadcrumb[] = t('Media centre');

        if ($date < $now) {
          $breadcrumb[] = l(t('Past events'), 'media-centre/past-events');

          $link_title = t('Back to past events list');
          $link_href = 'media-centre/past-events';
          $tag_vars['element']['#value'] = t('Past events');
          $vars['page']['above_title']['events-page-title'] = array(
            '#type' => 'item',
            '#markup' => theme('html_tag', $tag_vars),
          );
        }
        else {
          $breadcrumb[] = l(t('Upcoming events'), 'media-centre/events');

          $link_title = t('Back to events list');
          $link_href = 'media-centre/events';
          $tag_vars['element']['#value'] = t('Upcoming events');
          $vars['page']['above_title']['practical-tool-page-title'] = array(
            '#type' => 'item',
            '#markup' => theme('html_tag', $tag_vars),
          );
        }
        $breadcrumb[] = $node->title;
        drupal_set_breadcrumb($breadcrumb);

        break;

      case 'flickr_gallery':

        if (!@$vars['page']['content']['system_main']['nodes'][$vars['node']->nid]['field_cover_flickr']) {
          $primary = osha_flickr_album_primary();
          $formatter = 'h';
          $markup = theme('osha_flickr_photo', array(
            'format' => NULL,
            'attribs' => NULL,
            'size' => $formatter,
            'photo' => flickr_photos_getinfo($primary),
            'settings' => [],
            'wrapper_class' => !empty($element['#settings']['image_class']) ? $element['#settings']['image_class'] : '',
          ));
          $cover_flickr = [
            '#theme' => 'field',
            '#weight' => 2,
            '#field_name' => 'field_cover_flickr',
            '#formatter' => 'album_cover',
            '#field_type' => 'flickrfield',
            '#label_display' => 'hidden',
            '#object' => $vars['node'],
            '#items' => [
              [
                'id' => $primary,
              ],
            ],
            ['#markup' => $markup],
          ];
          $vars['page']['content']['system_main']['nodes'][$vars['node']->nid]['field_cover_flickr'] = $cover_flickr;
        }

        drupal_set_title(t('Photo gallery'));
        $link_title = t('Back to gallery');
        $link_href = 'media-centre/photo-gallery';
        $vars['page']['below_title']['back-to-link'] = array(
          '#type' => 'item',
          '#markup' => l($link_title, $link_href, array('attributes' => array('class' => array('back-to-link pull-right')))),
        );
        unset($link_title);
        unset($vars['page']['above_title']);
        break;

      case 'hwc_gallery':
        $link_title = t('Back to gallery');
        $link_href = 'media-centre/photo-gallery';
        $tag_vars['element']['#value'] = t('Photo gallery');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;
    }
    if (isset($link_title)) {
      $vars['page']['above_title']['back-to-link'] = array(
        '#type' => 'item',
        '#markup' => l($link_title, $link_href, array('attributes' => array('class' => array('back-to-link pull-right')))),
      );
    }
  }

  if ($node = menu_get_object()) {
    if ($node->type == 'publication') {
      ctools_include('plugins');
      ctools_include('context');
      if ($node->field_publication_type[LANGUAGE_NONE][0]['tid'] == 521 /* Case Studies */) {
        $pb = path_breadcrumbs_load_by_name('case_studies_detail_page');
      }
      else {
        $pb = path_breadcrumbs_load_by_name('publications_detail_page');
      }
      $breadcrumbs = _path_breadcrumbs_build_breadcrumbs($pb);
      drupal_set_breadcrumb($breadcrumbs);
    }
    if ($node->type == 'practical_tool') {
      ctools_include('plugins');
      ctools_include('context');
      $pb = path_breadcrumbs_load_by_name('practical_tools_details_page');
      $breadcrumbs = _path_breadcrumbs_build_breadcrumbs($pb);
      drupal_set_breadcrumb($breadcrumbs);
    }
    if ($node->type == 'campaign_materials') {
      ctools_include('plugins');
      ctools_include('context');
      $pb = path_breadcrumbs_load_by_name('campaign_materials_details_page');
      $breadcrumbs = _path_breadcrumbs_build_breadcrumbs($pb);
      drupal_set_breadcrumb($breadcrumbs);
    }

    if (
      ($node->type == 'tk_article') ||
      ($node->type == 'tk_topic') ||
      ($node->type == 'tk_tool') ||
      ($node->type == 'tk_example')
    ) {
      $breadcrumb = hwc_toolkit_menu_breadcrumbs();
      drupal_set_breadcrumb($breadcrumb);
    }
  }

  // Add back link (e.g. 'Back to homepage') for Partners pages.
  $partner = hwc_partner_get_account_partner();
  if (is_object($partner)) {

    switch (current_path()) {
      case 'node/add/events':
      case 'node/add/news':
      case 'private':
        $link_title = t('Back to homepage');
        $link_href = 'node/' . $partner->nid;
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => drupal_get_title(),
          '#prefix' => '<strong class="title-alt">',
          '#suffix' => '</strong>',
        );
        drupal_set_title('');
        break;
    }
    if (isset($link_title)) {
      $vars['page']['above_title']['back-to-link'] = array(
        '#type' => 'item',
        '#markup' => l($link_title, $link_href, array('attributes' => array('class' => array('back-to-link pull-right')))),
      );
    }

    if (arg(0) == 'good-practice-exchange-platform') {
      $link_href = url('node/' . $partner->nid);
      $link_title = t('Back to Private Zone');
      $vars['page']['below_title']['back-to-link'] = array(
        '#type' => 'item',
        '#markup' => '<a class="back-to-link pull-right" href="' . $link_href . '">' . $link_title . '</a>',
      );
    }
  }
  // Add class container to user pages.
  $user_page = isset($vars['page']['content']['system_main']['#bundle']) && $vars['page']['content']['system_main']['#bundle'] == 'user';
  $user_login = isset($vars['page']['content']['system_main']['#form_id']) && $vars['page']['content']['system_main']['#form_id'] == 'user_login';
  if ($user_page && !empty($vars['page']['content']['system_main']['#block'])) {
    $vars['page']['content']['system_main']['#block']->css_class = 'container';
  }
  elseif ($user_login) {
    $vars['page']['content']['system_main']['#attributes']['class'][] = 'container';
  }
}

/**
 * Theme flexible layout of panels.
 * Copied the panels function and removed the css files.
 */
function hwc_frontend_panels_flexible($vars) {
  $css_id = $vars['css_id'];
  $content = $vars['content'];
  $settings = $vars['settings'];
  $display = $vars['display'];
  $layout = $vars['layout'];
  $handler = $vars['renderer'];
  panels_flexible_convert_settings($settings, $layout);
  $renderer = panels_flexible_create_renderer(FALSE, $css_id, $content, $settings, $display, $layout, $handler);
  $output = "<div class=\"panel-flexible " . $renderer->base['canvas'] . " clearfix\" $renderer->id_str>\n";
  $output .= "<div class=\"panel-flexible-inside " . $renderer->base['canvas'] . "-inside\">\n";
  $output .= panels_flexible_render_items($renderer, $settings['items']['canvas']['children'], $renderer->base['canvas']);
  // Wrap the whole thing up nice and snug.
  $output .= "</div>\n</div>\n";
  return $output;
}

function hwc_frontend_field($variables) {
  $output = '';
  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    if (in_array($variables['element']['#field_name'], ['field_download_pdf', 'field_external_link'])) {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . '</div>';
    }
    else {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
    }
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

function hwc_frontend_preprocess_field(&$variables) {
  // Add theme suggestion for field based on field name and view mode.
  if (!empty($variables['element']['#view_mode'])) {
    $variables['theme_hook_suggestions'][] = 'field__' . $variables['element']['#field_name'] . '__' . $variables['element']['#view_mode'];
  }
  // Convert new lines to BR for textareas.
  if ($variables['element']['#field_type'] == 'text_long') {
    $field_name = $variables['element']['#field_name'];
    foreach ($variables['items'] as $key => &$item) {
      foreach ($variables['element']['#object']->{$field_name} as $lang => $value) {
        if (
          ($variables['element']['#object']->{$field_name}[$lang][$key]['format'] == NULL)
          &&
          ($variables['element']['#object']->language == $lang)
        ) {
          $item['#markup'] = nl2br($item['#markup']);
        }
      }
    }
  }
}

function hwc_frontend_preprocess_node(&$vars) {
  // Remove napo film image.
  if ($vars['view_mode'] == 'full' && $vars['nid'] == 160) {
    unset($vars['content']['field_image']);
    $vars['field_image'] = [];
  }
  $search_str = '<div class="col-sm-12 col-md-8 col-md-offset-2">';
  if ((isset($vars['body'][0]['safe_value'])) && (strpos($vars['body'][0]['safe_value'], $search_str))) {
    $search_str = '<div class="row text-center recomended-resources-for-you">' . "\n" . $search_str;
    $vars['content']['body'][0]['#markup'] = str_replace($search_str, $search_str . '<h2 class="recomended-for-you element-invisible">&nbsp;</h2>', $vars['content']['body'][0]['#markup']);
  }
  if ($vars['view_mode'] == 'teaser' && $vars['type'] == 'audio_visual') {
    $vars['classes_array'][] = 'node-practical-tool';
  }
  if ($vars['view_mode'] == 'full' && $vars['type'] == 'events') {
    $vars['classes_array'][] = 'container';
    if (isset($vars['field_start_date'])) {
      if (!empty($vars['field_start_date'][0]['value2'])
        && $end_date = $vars['field_start_date'][0]['value2']) {
        $date_diff = strtotime($end_date) - strtotime('now');
        if ($date_diff < 0) {
          $vars['classes_array'][] = 'page-past-event';
        }
        else {
          $vars['classes_array'][] = 'page-upcoming-event';
        }
      }
    }
  }
  if (isset($vars['content']['links']['node']['#links']['node-readmore'])) {
    $vars['content']['links']['node']['#links']['node-readmore']['title'] = t('See more');
  }
  $view_mode = $vars['view_mode'];

  // After latest bootstrap update, the templates suggestions are pref over ds layouts.
  if (empty($vars['rendered_by_ds'])) {
    $vars['theme_hook_suggestions'][] = 'node__' . $view_mode;
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__' . $view_mode;
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__' . $view_mode;

    if (context_isset('context', 'segmentation_page')) {
      $vars['theme_hook_suggestions'][] = 'node__article_segment';
    }
  }

  //Add template to external infographic code. node--external-infographic.tpl.php - MDR-2432
  $n = menu_get_object('node');
  if ($n) {
    switch ($n->type) {
      case "article":
        $external_infographic = variable_get('hwc_external_infographic_nid', 7150);
        if ($n->nid == $external_infographic) {
          $vars['theme_hook_suggestions'][] = 'node__external_infographic';
        }
    }
  }

  // Hide share widget.
  $exclude_nid = array('129');
  if (in_array($vars['node']->nid, $exclude_nid)) {
    unset($vars['content']['share_widget']);
  }
  hwc_frontend_top_anchor($vars);

}

function hwc_frontend_file_upload_help($variables) {
  return theme_file_upload_help($variables);
}

function hwc_frontend_preprocess_image_style(&$variables) {
  $variables['attributes']['class'][] = 'img-responsive';
  if (empty($variables['alt'])) {
    $variables['alt'] = drupal_basename($variables['path']);
  }
}
/**
 * Implements theme_on_the_web_image().
 *
 * @param $variables
 *   An associative array with generated variables.
 *
 * @return
 *   HTML for a social media icon.
 */

/**
+ * Implements theme_pager().
+ */
function hwc_frontend_pager($variables) {
  // Overwrite pager links.
  $variables['tags'][0] = '«';
  $variables['tags'][1] = '‹';
  $variables['tags'][3] = '›';
  $variables['tags'][4] = '»';
  return theme_pager($variables);
}

/**
 * Theme function
 *
 * @param $service
 *    Icon for appropriate service.
 * @param $link
 *    URL where link should point.
 * @param $title
 *    Title attribute for the link tag.
 *
 * @return
 *    Linked icon with wrapper markup.
 */
function hwc_frontend_on_the_web_item($variables) {
  $service = $variables['service'];
  $link = $variables['link'];
  $title = $variables['title'];

  // Build the img tag.
  $image = theme('on_the_web_image', array('service' => $service, 'title' => $title));

  $title = ucfirst($variables['service']);
  if ($title == 'Linkedin') {
    $title = 'LinkedIn';
  }
  // Determine attributes for the link.
  $attributes = ['title' => $title];
  if (variable_get('on_the_web_target', TRUE) == TRUE) {
    $attributes['target'] = '_blank';
  }

  // Link the image and wrap it in a span.
  $linked_image = l($image, $link, array('attributes' => $attributes, 'html' => TRUE));

  return $linked_image;
}

/**
 * Theme function
 *
 * @param $service
 *    Icon for appropriate service.
 * @param $title
 *    Title attribute for the link tag.
 *
 * @return
 *    Icon image of appropriate size.
 */
function hwc_frontend_on_the_web_image($variables) {
  $service = $variables['service'];
  $title = ucfirst($variables['service']);
  if ($title == 'Linkedin') {
    $title = 'LinkedIn';
  }
  $alt = $variables['title'];
  $size = variable_get('on_the_web_size', 'sm');
  $variables = array(
    'alt'   => $alt,
    'path'  => drupal_get_path('theme', 'hwc_frontend') . '/images/social_icons/' . $size . '/' . $service . '.png',
    'title' => $title,
  );
  return theme('image', $variables);
}

function hwc_frontend_checkboxes($variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  $before_children = '';
  if ($variables['element']['#id'] == 'edit-field-priority-area') {
    $checked = _osha_publication_is_selected_facet() ? '' : 'checked';
    $link = _osha_publication_generate_all_facet_link();
    $before_children = '
<ul class="facetapi-facetapi-checkbox-links facetapi-facet-field-priority-area facetapi-processed no-margin-bottom">
  <li class="leaf first">
    <input type="checkbox" class="facetapi-checkbox" id="facetapi-link--all--checkbox" ' . $checked . '>' . $link . '
  </li>
</ul>';

  }
  return '<div' . drupal_attributes($attributes) . '>' . $before_children . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
}

/**
 * Colorbox theme function to add support for image field caption.
 *
 * @see theme_colorbox_image_formatter
 */
function hwc_frontend_colorbox_image_formatter($variables) {
  $item = $variables['item'];
  $entity_type = $variables['entity_type'];
  $entity = $variables['entity'];
  $field = $variables['field'];
  $settings = $variables['display_settings'];
  $image = array(
    'path' => $item['uri'],
    'alt' => isset($item['alt']) ? $item['alt'] : '',
    'title' => isset($item['title']) ? $item['title'] : '',
    'style_name' => $settings['colorbox_node_style'],
  );
  if ($variables['delta'] == 0 && !empty($settings['colorbox_node_style_first'])) {
    $image['style_name'] = $settings['colorbox_node_style_first'];
  }
  if (isset($item['width']) && isset($item['height'])) {
    $image['width'] = $item['width'];
    $image['height'] = $item['height'];
  }
  if (isset($item['attributes'])) {
    $image['attributes'] = $item['attributes'];
  }
  // Allow image attributes to be overridden.
  if (isset($variables['item']['override']['attributes'])) {
    foreach (array('width', 'height', 'alt', 'title') as $key) {
      if (isset($variables['item']['override']['attributes'][$key])) {
        $image[$key] = $variables['item']['override']['attributes'][$key];
        unset($variables['item']['override']['attributes'][$key]);
      }
    }
    if (isset($image['attributes'])) {
      $image['attributes'] = $variables['item']['override']['attributes'] + $image['attributes'];
    }
    else {
      $image['attributes'] = $variables['item']['override']['attributes'];
    }
  }
  $entity_title = entity_label($entity_type, $entity);
  switch ($settings['colorbox_caption']) {
    case 'auto':
      // If the title is empty use alt or the entity title in that order.
      if (!empty($image['title'])) {
        $caption = $image['title'];
      }
      elseif (!empty($image['alt'])) {
        $caption = $image['alt'];
      }
      elseif (!empty($entity_title)) {
        $caption = $entity_title;
      }
      else {
        $caption = '';
      }
      break;
    case 'title':
      $caption = $image['title'];
      break;
    case 'alt':
      $caption = $image['alt'];
      break;
    case 'node_title':
      $caption = $entity_title;
      break;
    case 'custom':
      $caption = token_replace($settings['colorbox_caption_custom'], array(
        $entity_type => $entity,
        'file' => (object) $item
      ), array('clear' => TRUE));
      break;
    default:
      $caption = '';
  }
  // If our custom checkbox is used, overwrite caption.
  if (!empty($settings['use_image_caption_field'])) {
    if (!empty($item['image_field_caption']['value'])) {
      $caption = $item['image_field_caption']['value'];
    }
  }
  // Shorten the caption for the example styles or when caption shortening is active.
  $colorbox_style = variable_get('colorbox_style', 'default');
  $trim_length = variable_get('colorbox_caption_trim_length', 75);
  if (((strpos($colorbox_style, 'colorbox/example') !== FALSE) || variable_get('colorbox_caption_trim', 0)) && (drupal_strlen($caption) > $trim_length)) {
    $caption = drupal_substr($caption, 0, $trim_length - 5) . '...';
  }
  // Build the gallery id.
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
  $entity_id = !empty($id) ? $entity_type . '-' . $id : 'entity-id';
  switch ($settings['colorbox_gallery']) {
    case 'post':
      $gallery_id = 'gallery-' . $entity_id;
      break;
    case 'page':
      $gallery_id = 'gallery-all';
      break;
    case 'field_post':
      $gallery_id = 'gallery-' . $entity_id . '-' . $field['field_name'];
      break;
    case 'field_page':
      $gallery_id = 'gallery-' . $field['field_name'];
      break;
    case 'custom':
      $gallery_id = $settings['colorbox_gallery_custom'];
      break;
    default:
      $gallery_id = '';
  }
  if ($style_name = $settings['colorbox_image_style']) {
    $path = image_style_url($style_name, $image['path']);
  }
  else {
    $path = file_create_url($image['path']);
  }
  return theme('colorbox_imagefield', array(
    'image' => $image,
    'path' => $path,
    'title' => $caption,
    'gid' => $gallery_id,
    'entity' => $entity,
    'colorbox_style' => $style_name,
  ));
}
/**
 * @see theme_colorbox_imagefield().
 * @see colorbox_handler_field_colorbox.
 */
function hwc_frontend_colorbox_imagefield($variables) {
  // Load the necessary js file for Colorbox activation.
  if (_colorbox_active() && !variable_get('colorbox_inline', 0)) {
    drupal_add_js(drupal_get_path('module', 'colorbox') . '/js/colorbox_inline.js');
  }
  if ($variables['image']['style_name'] == 'hide') {
    $image = '';
    $class[] = 'js-hide';
  }
  elseif (!empty($variables['image']['style_name'])) {
    $image = theme('image_style', $variables['image']);
  }
  else {
    $image = theme('image', $variables['image']);
  }
  $image_vars = array(
    'style_name' => $variables['colorbox_style'],
    'path' => $variables['image']['path'],
    'alt' => $variables['entity']->title,
  );
  $popup = theme('image_style', $image_vars);
  $caption = $variables['title'] . hwc_news_share_widget($variables['entity'], array('type' => 'article', 'label' => t('Share this gallery')));

  $width = 'auto';
  $height = 'auto';
  $gallery_id = $variables['gid'];
  $link_options = drupal_parse_url($variables['image']['path']);
  $link_options = array_merge($link_options, array(
    'html' => TRUE,
    'fragment' => 'colorbox-inline-' . md5($variables['image']['path']),
    'query' => array(
      'width' => $width,
      'height' => $height,
      'title' => $caption,
      'inline' => 'true'
    ),
    'attributes' => array(
      'class' => array('colorbox-inline'),
      'rel' => $gallery_id
    )
  ));
  // Remove any parameters that aren't set.
  $link_options['query'] = array_filter($link_options['query']);
  $link_tag = l($image, $variables['path'], $link_options);
  return $link_tag . '<div style="display: none;"><div id="colorbox-inline-' . md5($variables['image']['path']) . '">' . $popup . '</div></div>';
}

/**
 * Implements theme_date_display_combination().
 */
function hwc_frontend_date_display_combination(&$variables) {
  $date_theme = '';
  if (!empty($variables['dates']['value']['osha_date_theme'])) {
    $date_theme = $variables['dates']['value']['osha_date_theme'];
  }
  switch ($date_theme) {
    case 'with_time':
      if (!empty($variables['dates']['value2'])) {
        $start_date = $variables['dates']['value']['formatted_iso'];
        $end_date = $variables['dates']['value2']['formatted_iso'];
        // If same day event, show the time also.
        if (date('Y-m-d', strtotime($start_date)) == date('Y-m-d', strtotime($end_date))) {
          $variables['display']['settings']['format_type'] = 'short_date_eu';
          $variables['dates'] = date_formatter_process('date_default', $variables['entity_type'], $variables['entity'], $variables['field'], $variables['instance'], $variables['langcode'], $variables['item'], $variables['display']);
        }
      }
      return theme_date_display_combination($variables);
      break;
    default:
      return theme_date_display_combination($variables);
  }
}


/**
 * @see theme_flickr_photoset.
 */
function hwc_frontend_flickr_photoset($variables) {
  $photoset = $variables['photoset'];
  $owner = $variables['owner'];
  $size = $variables['size'];
  $media = isset($variables['media']) ? $variables['media'] : 'photos';
  $attribs = $variables['attribs'];
  $min_title = $variables['min_title'];
  $min_metadata = $variables['min_metadata'];
  $settings = $variables['settings'];
  $wrapper_class = $settings['image_class'];
  $variables['wrapper_class'] = $settings['image_class'];
  $output = '';
  if (module_exists('flickr_sets')) {
    $output = "<div class='flickr-photoset'>\n";
    $per_page = $settings['images_shown'];
    $photos = flickr_photosets_getphotos($photoset['id'], array(
      'per_page' => $per_page,
      'media' => $media,
    ));
    if ($photos['photoset']['total']) {
      foreach ((array) $photos['photoset']['photo'] as $photo) {
        // Insert owner into $photo because theme_flickr_photo needs it.
        $photo['owner'] = $owner;
        $output .= theme('flickr_photo', array(
          'photo' => $photo,
          'size' => $size,
          'format' => NULL,
          'attribs' => $attribs,
          'min_title' => $variables['min_title'],
          'min_metadata' => $variables['min_metadata'],
          'wrapper_class' => $wrapper_class,
        ));
      }
      if ($photos['photoset']['total'] > count($photos['photoset']['photo'])) {
        $output .= l(t('View all'), flickr_photoset_page_url($owner, $photoset['id']), array('attributes' => array('target' => '_blank')));
      }
    }
    else {
      $output .= t('No media in this set.');
    }
  }
  else {
    $img = flickr_img($photoset, $size, $attribs);
    $output = theme('pager');
    $photo_url = flickr_photoset_page_url($owner, $photoset['id']);
    $output .= "<div class='flickr-photoset" . $wrapper_class . "'>";
    $title = is_array($photoset['title']) ? $photoset['title']['_content'] : $photoset['title'];
    return l($img, $photo_url, array(
      'attributes' => array(
        'title' => $title),
      'absolute' => TRUE,
      'html' => TRUE,
    ));
  }
  $output .= '</div>';
  return $output;
}
/**
 * Anchor to top of the page
 */
function hwc_frontend_top_anchor(&$vars) {
  $options = array(
    'attributes' => array(
      'class' => 'top_anchor',
    ),
    'external' => TRUE,
    'fragment' => 'top',
    'html' => TRUE,
  );
  $vars['top_anchor'] = l('<img alt="Anchor to top" src="'.file_create_url(path_to_theme().'/images/anchor-top.png').'" />', '', $options);
}

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

  $path = current_path();
  $hide_pages = str_replace("\r", '', variable_get('hwc_hide_meta_description_pages', ''));
  $hide_pages = explode("\n", $hide_pages);
  if (in_array($path, $hide_pages)) {
    unset($head_elements['metatag_description_0']);
  }
}

/**
 * Implements theme_menu_link__menu_block().
 */
function hwc_frontend_menu_link__menu_block($variables) {
  $element = &$variables['element'];
  if (!empty($element['#localized_options']['attributes']['class']) && $class = $element['#localized_options']['attributes']['class']) {
    if (($class[0] == 'previous-campaigns') && ($element['#bid']['delta'] == 5)) {
      $element['#href'] = '<nolink>';
    }
  }

  $delta = $element['#bid']['delta'];
  // Render or not the Menu Image.
  // Get the variable provided by osha_menu module.
  $render_img = variable_get('menu_block_' . $delta . '_' . HWC_MENU_RENDER_IMG_VAR_NAME, 0);
  if (!$render_img) {
    return theme_menu_link($variables);
  }
  $description = '';
  if (!empty($element['#localized_options']['attributes']['title'])) {
    $description = $element['#localized_options']['attributes']['title'];
  }
  $text = '';
  if (!empty($element['#localized_options']['content']['image'])) {
    $image_url = file_create_url($element['#localized_options']['content']['image']);
    $attributes = [];
    if (!empty($element['#localized_options']['copyright']['image_alt'])) {
      $attributes['alt'] = strip_tags($element['#localized_options']['copyright']['image_alt']);
      $attributes['title'] = $attributes['alt'];
    }
    $text = '<span class="content-img"><img ' . drupal_attributes($attributes) . ' src="' . $image_url . '"/></span>';
  }
  if (!empty($element['#localized_options']['copyright']['author']) || !empty($element['#localized_options']['copyright']['copyright'])) {
    $text .= '<blockquote class="image-field-caption">';
    if (!empty($element['#localized_options']['copyright']['author'])) {
      $text .= check_markup($element['#localized_options']['copyright']['author'], 'full_html');
    }
    if (!empty($element['#localized_options']['copyright']['author']) && !empty($element['#localized_options']['copyright']['copyright'])) {
      $text .= '<span>&nbsp;/&nbsp;</span>';
    }
    if (!empty($element['#localized_options']['copyright']['copyright'])) {
      $text .= '<span class="blockquote-copyright">' . $element['#localized_options']['copyright']['copyright'] . '</span>';
    }
    $text .= '</blockquote>';
  }
  $text .= '<h2>' . $element['#title'] . '</h2><p>' . $description . '</p>';
  $output_link = l($text, $element['#href'], array('html' => TRUE));
  $element['#attributes']['class'][] = 'content-box-sub';
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output_link . '</li>';
}

/**
 * Overrides theme_menu_link().
 */
function hwc_frontend_menu_link(array $variables) {
  $element = $variables['element'];

  if (arg(0) == 'entity-collection') {
    $urls = [
      'node/129',
      'node/113',
    ];
    if (in_array($element['#href'], $urls)) {
      $element['#attributes']['class'] = [
        'expanded',
        'active-trail',
        'active',
      ];
    }
  }

  if (arg(0) == 'node') {
    $map = [
      "" => 'node/112',
      "186" => 'campaign-partners/campaign-media-partners',
      "187" => 'campaign-partners/national-focal-points',
      "185" => 'campaign-partners/official-campaign-partners',
      "1804" => 'campaign-partners/enterprise-europe-network',
    ];
    if (in_array($element['#href'], $map) && $node = menu_get_object()) {
      $type = @$node->field_partner_type[LANGUAGE_NONE][0]['tid'];
      if ($element['#href'] == 'node/112' && $type) {
        $element['#attributes']['class'] = [
          'expanded',
          'active-trail',
          'active',
        ];
      }
      if ($type && $map[$type] == $element['#href']) {
        $element['#attributes']['class'] = [
          'expanded',
          'active-trail',
          'active',
        ];
      }
    }
  }

  if (arg(0) == 'node') {
    $urls = [
      'tools-and-publications/publications',
      'tools-and-publications/case-studies',
      'tools-and-publications/campaign-materials',
    ];
    if (in_array($element['#href'], $urls) && $node = menu_get_object()) {
      $type = @$node->field_publication_type[LANGUAGE_NONE][0]['tid'];
      if ($type == CAMPAIGN_MATERIALS_TID || $type == CASE_STUDY_TID) {
        if ('tools-and-publications/publications' == $element['#href']) {
          $element['#attributes']['class'] = [];
        }
        if ($type == CASE_STUDY_TID && $element['#href'] == 'tools-and-publications/case-studies') {
          $element['#attributes']['class'] = [
            'expanded',
            'active-trail',
            'active',
          ];
        }
        if ($type == CAMPAIGN_MATERIALS_TID && $element['#href'] == 'tools-and-publications/campaign-materials') {
          $element['#attributes']['class'] = [
            'expanded',
            'active-trail',
            'active',
          ];
        }
      }
    }
  }

  if (arg(1) == 'campaign-materials') {
    $exclude = variable_get('campaign_materials_exclude', [11667, 1120]);
    $include = variable_get('campaign_materials_include', [1372, 2495]);
    if (in_array($element['#original_link']['mlid'], $exclude)) {
      $element['#attributes']['class'] = [];
    }
    if (in_array($element['#original_link']['mlid'], $include)) {
      $element['#attributes']['class'] = [
        'expanded',
        'active-trail',
        'active',
      ];
    }
  }
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
  if (variable_get('add_tracking_code', FALSE)) {
    $script = [
      '#tag' => 'script',
      '#attributes' => [
        'type' => 'text/javascript',
        'src' => '//script.crazyegg.com/pages/scripts/0083/4460.js',
        'async' => 'async',
      ],
      '#value' => '',
    ];
    drupal_add_html_head($script, 'crazyegg-script');

    $value = '(function(h,o,t,j,a,r){
  h.hj=h.hj||function() {(h.hj.q=h.hj.q||[]).push(arguments)};
  h._hjSettings={hjid:1550027,hjsv:6};
  a=o.getElementsByTagName(\'head\')[0];
  r=o.createElement(\'script\');
  r.async=1;
  r.src=t+h._hjSettings.hjid+j+h._hjSettings.hjsv;
  a.appendChild(r);
})(window,document,\'https://static.hotjar.com/c/hotjar-\',\'.js?sv=\');';

    if (variable_get('splash_mode', FALSE)) {
      $value .= '
  (function(h,o,t,j,a,r){
  h.hj=h.hj||function() {(h.hj.q=h.hj.q||[]).push(arguments)};
  h._hjSettings={hjid:1642038,hjsv:6};
  a=o.getElementsByTagName(\'head\')[0];
  r=o.createElement(\'script\');
  r.async=1;
  r.src=t+h._hjSettings.hjid+j+h._hjSettings.hjsv;
  a.appendChild(r);
})(window,document,\'https://static.hotjar.com/c/hotjar-\',\'.js?sv=\');';
    }
    $script = [
      '#tag' => 'script',
      '#attributes' => ['type' => 'text/javascript'],
      '#value' => $value,
    ];
    drupal_add_html_head($script, 'hotjar-script');
  }

  if (arg(1) == 'case-studies') {
    $vars['classes_array'][] = 'page-tools-and-publications-publications';
    $vars['classes_array'][] = 'page-publications';
  }

  if (variable_get('splash_mode', FALSE) || arg(0) == 'splash-page') {
    $vars['classes_array'][] = 'rel1';
  }
  if (variable_get('staging_mode', '')) {
    $vars['classes_array'][] = variable_get('staging_mode', '');
  }

  if (isset($_SESSION['masquerading'])) {
    $vars['classes_array'][] = 'act-as-partner';
  }

  $vars['menu_title'] = '';
  $active_trail = menu_get_active_trail();
  if (count($active_trail) > 2) {
    $vars['menu_title'] = $active_trail[count($active_trail) - 1]['title'];
  }
  $n = menu_get_object('node');
  if ($n) {
    switch ($n->type) {
      case "partner":
        $tid = $n->field_partner_type[LANGUAGE_NONE][0]['tid'];
        $map = [
          185 => 'ocp',
          186 => 'mp',
          1804 => 'een',
          187 => 'fop',
        ];
        $vars['classes_array'][] = $map[$tid];
        break;

      case "article":
        if ($n->nid == 3298) {
          $vars['classes_array'][] = 'good-practice-exchange';
        }
        if ($n->nid == 179) {
          $vars['classes_array'][] = 'press-room';
        }
        if ($n->nid == 108) {
          $vars['classes_array'][] = 'video-page';
        }
        if ($n->nid == 129) {
          $vars['classes_array'][] = 'newsletter';
        }
        if ($n->nid == 164) {
          $vars['classes_array'][] = 'european-week';
        }
        break;

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

  if (drupal_is_front_page() || arg(0) == 'splash-page' || arg(0) == 'regular-page') {
    if (variable_get('splash_mode', FALSE) || arg(0) == 'splash-page') {
      $vars['classes_array'][] = 'splash-page';
    }
    else {
      $vars['classes_array'][] = 'front-page';
    }
  }
  if (!empty($vars['is_front'])) {
    $vars['head_title'] = t('Healthy Workplaces Lighten the Load 2020-22');
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

function hwc_frontend_css_alter(&$css) {
  if (drupal_is_front_page() && variable_get('splash_mode', FALSE)) {
    unset($css['sites/all/themes/hwc_frontend/css/hwc20.css']);
  }
  if (variable_get('splash_mode', FALSE) && arg(0) == 'splash-page') {
    unset($css['sites/all/themes/hwc_frontend/css/hwc20.css']);
  }
}

/**
 * Override block template.
 */
function hwc_frontend_preprocess_block(&$vars) {
  $block = $vars['block'];
  if ($block->delta == '-exp-documents-gpep') {
    $vars['theme_hook_suggestions'][] = 'block__gpep';
  }
  if ($block->delta == 'hwc_homepage_topics') {
    $vars['theme_hook_suggestions'][] = 'block__priority_area';
  }
  if ($block->delta == 'hwc_practical_tool_less') {
    $vars['theme_hook_suggestions'][] = 'block__show_less';
  }
  if ($block->delta == 'hwc_practical_tool_more') {
    $vars['theme_hook_suggestions'][] = 'block__show_more';
  }
  if ($block->delta == 'partners-block_1') {
    $vars['theme_hook_suggestions'][] = 'block__partners';
  }

  if (($block->delta == 'savwFG7EXPDT1TOCbW1g7W55ENxEJnMY')) {
    $vars['theme_hook_suggestions'][] = 'block__empty';
  }
  if (($block->delta == 'gpexamples-block')) {
    $vars['theme_hook_suggestions'][] = 'block__gpexamples';
  }
  if (($block->delta == 'news-press_room') || ($block->delta == 'frontpage_events-press_room')) {
    $vars['theme_hook_suggestions'][] = 'block__press_room';
  }
}

function _hwc_frontend_allow_title($active_trail) {
  $path = current_path();
  $exclude_banner_titles = str_replace("\r", '', variable_get('hwc_exclude_banner_titles', ''));
  $exclude_banner_titles = explode("\n", $exclude_banner_titles);
  $previous_campaigns_mlid = variable_get('hwc_previous_campaigns_mlid', '35515');
  if (
    count($active_trail) > 2 &&
    ($active_trail[1]['mlid'] == 1123 || $active_trail[1]['mlid'] == $previous_campaigns_mlid) &&
    !in_array($path, $exclude_banner_titles)
  ) {
    return TRUE;
  }
  return FALSE;
}

function hwc_frontend_get_newsletter_name($nid) {
  $entities = entity_load_multiple_by_name('entity_collection', $names = FALSE, array('bundle' => 'newsletter_content_collection'));
  foreach ($entities as $entity) {
    $tree = $entity->getTree();
    if ($tree->getChild('node:' . $nid)) {
      return $entity;
    }
  }
  return FALSE;
}

function hwc_frontend_preprocess_page(&$vars) {
  $vars['head_text'] = t('Healthy Workplaces Lighten the Load 2020-22');
  $vars['banner_title'] = '';
  $n = menu_get_object('node');
  if ($n) {
    $active_trail = menu_get_active_trail();
    if (_hwc_frontend_allow_title($active_trail)) {
      $vars['title'] = $active_trail[count($active_trail) - 2]['title'];
    }
    switch ($n->type) {
      case "partner":
        $tid = $n->field_partner_type[LANGUAGE_NONE][0]['tid'];
        $term = taxonomy_term_load($tid);
        $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
        $vars['partner_type'] = $wrapper->name->value();
        $vars['theme_hook_suggestions'][] = 'page__node__partner';
        break;

      case "gpa":
        $vars['theme_hook_suggestions'][] = 'page__gpa';
        break;

      case "article":
        if ($n->nid == 3298) {
        }
        elseif ($n->nid == 179) {
          $vars['theme_hook_suggestions'][] = 'page__press__room';
        }
        elseif ($n->nid == 164) {
          $vars['theme_hook_suggestions'][] = 'page__european__week';
//          $vars['title_suffix'] = '<div id="european_week_date">' . variable_get('european_week_date', '12<sup>th</sup>-14<sup>th</sup> of October 2020') . '</div>';
        }
        else {
          $vars['theme_hook_suggestions'][] = 'page__node__article';
        }
        break;

      case "priority_area":
        $vars['theme_hook_suggestions'][] = 'page__node__priority_area';
        break;

      case "campaign_16":
        $vars['theme_hook_suggestions'][] = 'page__node__campaign_16';
        break;

      case "campaign_18":
        $vars['theme_hook_suggestions'][] = 'page__node__campaign_18';
        break;

      case "publication":
        $vars['theme_hook_suggestions'][] = 'page__node__publication';
        break;

      case "practical_tool":
        $vars['theme_hook_suggestions'][] = 'page__node__practical_tool';
        break;
    }
  }

  if (arg(0) == 'good-practice-exchange-platform') {
    $breadcrumb = [];
    $breadcrumb[] = l(t('Home'), '<front>');
    $breadcrumb[] = drupal_get_title();
    drupal_set_breadcrumb($breadcrumb);
  }
  if (drupal_is_front_page() || arg(0) == 'splash-page' || arg(0) == 'regular-page') {
    if (variable_get('splash_mode', FALSE) || arg(0) == 'splash-page') {
      $vars['theme_hook_suggestions'][] = 'page__splash';
    }
    else {
      $vars['theme_hook_suggestions'][] = 'page__front';
    }
  }
  if (arg(0) . arg(1) == 'about-topicglossary-list') {
    $vars['theme_hook_suggestions'][] = 'page__glossary__list';
  }
  if (arg(0) . arg(1) . arg(2) == 'tools-and-publicationspublications') {
    $vars['theme_hook_suggestions'][] = 'page__publications';
  }
  if (arg(0) . arg(1) == 'tools-and-publicationspractical-tools') {
    $vars['theme_hook_suggestions'][] = 'page__practical__tools';
  }
  $vars['back_to_pz'] = '';
  //hwc_partner_back_to_private_zone();
  $vars['page']['content']['#post_render'] = ['hwc_content_post_render'];
  if (drupal_is_front_page()) {
    unset($vars['page']['content']['system_main']['default_message']);
    drupal_set_title('');
  }
  if ((arg(0) == 'practical-tools') || (arg(1) == 'practical-tools')) {
    $vars['classes_array'][] = 'page-search';
  }

  $tag_vars = array(
    'element' => array(
      '#tag' => 'h1',
      '#attributes' => array(
        'class' => array('page-header'),
      ),
    ),
  );
  $vars['show_title'] = TRUE;
  // Add back to links (e.g. Back to news).

  if ((arg(0) == 'node') && (arg(2) == 'news')) {
    $tag_vars['element']['#value'] = t('News');
    $vars['page']['above_title']['title-alternative'] = array(
      '#type' => 'item',
      '#markup' => theme('html_tag', $tag_vars),
    );
  }
  if ((arg(0) == 'node') && (arg(2) == 'events')) {
    $tag_vars['element']['#value'] = t('Events');
    $vars['page']['above_title']['title-alternative'] = array(
      '#type' => 'item',
      '#markup' => theme('html_tag', $tag_vars),
    );
  }

  if (isset($vars['node'])) {
    $node = $vars['node'];
    switch ($node->type) {
      case "tk_section":
      case 'tk_article':
      case "tk_tool":
      case "tk_example":
      case "tk_topic":
        $vars['page']['content']['#post_render'][] = 'hwc_content_post_render_add_classes';
        $vars['theme_hook_suggestions'][] = 'page__campaign__toolkit';
        break;

      case 'document':
        if (arg(2) == 'edit') {
          $tag_vars['element']['#value'] = t('Upload information');
        }
        else {
          $tag_vars['element']['#value'] = t('Document');
        }
        $vars['page']['above_title']['title-document'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'publication':
        if ($node->field_publication_type[LANGUAGE_NONE][0]['tid'] == CASE_STUDY_TID) {
          $tag_vars['element']['#value'] = t('Case studies');
          $vars['page']['above_title']['title-alternative'] = array(
            '#type' => 'item',
            '#markup' => theme('html_tag', $tag_vars),
          );
          break;
        }
        if ($node->field_publication_type[LANGUAGE_NONE][0]['tid'] == CAMPAIGN_MATERIALS_TID) {
          $tag_vars['element']['#value'] = t('Campaign materials');
          $vars['page']['above_title']['title-alternative'] = array(
            '#type' => 'item',
            '#markup' => theme('html_tag', $tag_vars),
          );
          break;
        }

        $tag_vars['element']['#value'] = t('Publications');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'youtube':
        $breadcrumb[] = l(t('Home'), '<front>');
        $breadcrumb[] = l(t('Media centre'), 'media-centre');
        $breadcrumb[] = l(t('Newsletter'), 'media-centre/newsletter');
        if ($newsletter = hwc_frontend_get_newsletter_name($node->nid)) {
          $breadcrumb[] = l($newsletter->title, 'entity-collection/' . $newsletter->name);
        }
        $breadcrumb[] = $node->title;
        drupal_set_breadcrumb($breadcrumb);
        drupal_set_title(t('Audiovisual'));
        break;

      case 'spotlight':

        $breadcrumb = array();
        $breadcrumb[] = l(t('Home'), '<front>');
        $breadcrumb[] = l(t('Media centre'), 'media-centre');
        $breadcrumb[] = l(t('Newsletter'), 'media-centre/newsletter');
        if ($newsletter = hwc_frontend_get_newsletter_name($node->nid)) {
          $breadcrumb[] = l($newsletter->title, 'entity-collection/' . $newsletter->name);
        }
        $breadcrumb[] = $node->title;
        drupal_set_breadcrumb($breadcrumb);
        drupal_set_title(t('In the spotlight'));
        break;

      case 'press_release':
        $breadcrumb = array();
        $breadcrumb[] = l(t('Home'), '<front>');
        $breadcrumb[] = l(t('Media centre'), 'media-centre');
        $breadcrumb[] = l(t('Press room'), 'media-centre/press-room');
        $breadcrumb[] = l(t('Press room news'), 'media-centre/press-room/press-room-news');
        $breadcrumb[] = $node->title;
        drupal_set_breadcrumb($breadcrumb);
        $tag_vars['element']['#value'] = t('Press releases');
        $vars['page']['above_title']['press-room-page-title'] = array(
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
        $tag_vars['element']['#value'] = t(variable_get('campaign_resources_title', 'Campaign Resources'));
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'practical_tool':
        $tag_vars['element']['#value'] = t('Practical tools and guidance');
        $vars['page']['above_title']['title-alternative'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'pa_highlights':
        $breadcrumb[] = l(t('Home'), '<front>');
        $breadcrumb[] = l(t('About the topic'), 'about-topic');
        $breadcrumb[] = l(t('Priority areas'), 'about-topic/priority-areas');
        $pa = hwc_priority_areas_pa_highlights_pa_title($node->nid);
        if ($pa) {
          $breadcrumb[] = l($pa->title, 'node/' . $pa->nid);
          $breadcrumb[] = $node->title;
          drupal_set_breadcrumb($breadcrumb);
          $tag_vars['element']['#value'] = $pa->title;
        }
        else {
          $tag_vars['element']['#value'] = t(variable_get('pa_highlights_title', 'News'));
        }
        $vars['page']['above_title']['news-page-title'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'news':
        $tag_vars['element']['#value'] = t('News');
        $vars['page']['above_title']['news-page-title'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
        break;

      case 'events':
        $breadcrumb = array();
        $breadcrumb[] = l(t('Home'), '<front>');
        $breadcrumb[] = l(t('Media centre'), 'media-centre');
        $breadcrumb[] = l(t('Events'), 'media-centre/events');
        $tag_vars['element']['#value'] = t('Events');
        $vars['page']['above_title']['events-page-title'] = array(
          '#type' => 'item',
          '#markup' => theme('html_tag', $tag_vars),
        );
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
      if ($node->field_publication_type[LANGUAGE_NONE][0]['tid'] == CASE_STUDY_TID) {
        $pb = path_breadcrumbs_load_by_name('case_studies_detail_page');
      }
      else if ($node->field_publication_type[LANGUAGE_NONE][0]['tid'] == CAMPAIGN_MATERIALS_TID) {
        $pb = path_breadcrumbs_load_by_name('campaign_materials_details_page');
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

  if (arg(2) == 'search-toolkit-examples') {
    $vars['theme_hook_suggestions'][] = 'page__search_toolkit_examples';
    $tag_vars['element']['#value'] = t('Campaign toolkit');
    $vars['page']['above_title']['title-alternative'] = array(
      '#type' => 'item',
      '#markup' => theme('html_tag', $tag_vars),
    );
  }

  if (arg(0) == 'entity-collection') {
    $breadcrumb = [];
    $breadcrumb[] = l(t('Home'), '<front>');
    $breadcrumb[] = l(t('Media centre'), 'media-centre');
    $breadcrumb[] = l(t('Healthy Workplaces Newsletter'), 'node/129');
    $breadcrumb[] = drupal_get_title();
    drupal_set_breadcrumb($breadcrumb);
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
  $map = osha_publications_classes();
  $vars['row_class'] = '';
  if (@$map[$vars['nid']]) {
    $vars['row_class'] = $map[$vars['nid']];
  }
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

  $vars['hide_title'] = FALSE;
  $active_trail = menu_get_active_trail();
  if (!_hwc_frontend_allow_title($active_trail)) {
    $vars['hide_title'] = TRUE;
  }

  $n = menu_get_object('node');
  if ($n) {
    switch ($n->type) {
      case "article":
        if ($n->field_article_type[LANGUAGE_NONE][0]['tid'] == HWC_INTRODUCTION_ARTICLE) {
          $vars['classes_array'][] = 'introductory-page';
        }
        $external_infographic = variable_get('hwc_external_infographic_nid', 7150);
        if ($n->nid == $external_infographic) {
          // Add template to external infographic code.
          // node--external-infographic.tpl.php - MDR-2432.
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

function hwc_frontend_pagerer_standard($variables) {
  return osha_pagerer_theme_handler('pagerer_standard', $variables);
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

function hwc_frontend_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . ($text) . '</a>';
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

function hwc_frontend_implode_comma_and_join($names) {
  $last = array_pop($names);
  if ($names) {
    return implode(', ', $names) . ' ' . t('and') . ' ' . $last;
  }
  return $last;
}

function hwc_frontend_checkboxes($variables) {
  if ($variables['element']['#name'] == 'main_tags') {
    $map = osha_publication_get_main_tags_map();
    foreach ($variables['element']['#options'] as $tid => $title) {
      $sub_tids = [];
      foreach ($map as $sub_tid => $main_tid) {
        if ($tid == $main_tid) {
          $sub_tids[$sub_tid] = $sub_tid;
        }
      }
      if (count($sub_tids) >= 1) {
        foreach ($sub_tids as $sub_tid) {
          $term = taxonomy_term_load($sub_tid);
          $sub_tids[$sub_tid] = $term->name;
        }
        $search = 'for="edit-main-tags-' . $tid . '"';
        $attr = drupal_attributes(['title' => $title . ' ' . t('include') . ' ' . hwc_frontend_implode_comma_and_join($sub_tids)]);
        $variables['element']['#children'] = str_replace($search, $search . ' ' . $attr, $variables['element']['#children']);
      }
    }
  }

  if ($variables['element']['#name'] == 'field_publication_type') {
    $map = osha_publication_get_main_publication_types_map();
    foreach ($variables['element']['#options'] as $tid => $title) {
      $sub_tids = [];
      foreach ($map as $sub_tid => $main_tid) {
        if ($tid == $main_tid) {
          $sub_tids[$sub_tid] = $sub_tid;
        }
      }
      if (count($sub_tids) >= 1) {
        foreach ($sub_tids as $sub_tid) {
          $term = taxonomy_term_load($sub_tid);
          $sub_tids[$sub_tid] = $term->name;
        }
        $search = 'for="edit-field-publication-type-' . $tid . '"';
        $attr = drupal_attributes(['title' => $title . ' ' . t('include') . ' ' . hwc_frontend_implode_comma_and_join($sub_tids)]);
        $variables['element']['#children'] = str_replace($search, $search . ' ' . $attr, $variables['element']['#children']);;
      }
    }
  }

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



// Create a theme function that can be overridden by other theme developers.
function hwc_frontend_text_resize_block() {
  // Add js, css, and library
  $content = array(
    '#attached' => array(
      'js' => array(
        array(
          'data' => "var text_resize_scope = " . drupal_json_encode(variable_get('text_resize_scope', 'main')) . ";
          var text_resize_minimum = " . drupal_json_encode(variable_get('text_resize_minimum', '12')) . ";
          var text_resize_maximum = " . drupal_json_encode(variable_get('text_resize_maximum', '25')) . ";
          var text_resize_line_height_allow = " . drupal_json_encode(variable_get('text_resize_line_height_allow', FALSE)) . ";
          var text_resize_line_height_min = " . drupal_json_encode(variable_get('text_resize_line_height_min', 16)) . ";
          var text_resize_line_height_max = " . drupal_json_encode(variable_get('text_resize_line_height_max', 36)) . ";",
          'type' => 'inline',
        ),
        array(
          'data' => drupal_get_path('module', 'text_resize') . '/text_resize.js',
          'type' => 'file',
        )
      ),
      'css' => array(
        drupal_get_path('module', 'text_resize') . '/text_resize.css',
      ),
      'library' => array(
        array('system', 'jquery.cookie')
      ),
    ),
  );
  if (variable_get('text_resize_reset_button', FALSE) == TRUE) {
    $content['#markup'] = t('<a href="javascript:;" class="changer" title="Smaller text" id="text_resize_decrease"><sup>-</sup>A</a> <a href="javascript:;" class="changer" id="text_resize_reset">A</a> <a href="javascript:;" class="changer" title="Bigger text" id="text_resize_increase"><sup>+</sup>A</a><div id="text_resize_clear"></div>');
  }
  else {
    $content['#markup'] = t('<a href="javascript:;" class="changer" title="Smaller text" id="text_resize_decrease"><sup>-</sup>A</a> <a href="javascript:;" class="changer" title="Bigger text" id="text_resize_increase"><sup>+</sup>A</a><div id="text_resize_clear"></div>');
  }

  return render($content);
}
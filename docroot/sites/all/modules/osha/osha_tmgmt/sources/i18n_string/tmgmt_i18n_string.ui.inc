<?php

/**
 * Class OSHATMGMTI18nStringDefaultSourceUIController overrides in order to remove from screen the menu links already
 * present inside the translation cart.
 */
class OSHATMGMTI18nStringDefaultSourceUIController extends TMGMTI18nStringDefaultSourceUIController {

  /**
   * {@inheritdoc}
   */
  public function overviewForm($form, &$form_state, $type) {
    $form += $this->overviewSearchFormPart($form, $form_state, $type);

    $form['items'] = array(
      '#type' => 'tableselect',
      '#header' => $this->overviewFormHeader($type),
      '#empty' => t('No strings matching given criteria have been found.')
    );

    $search_data = $this->getSearchFormSubmittedParams();

    $i18n_strings = osha_tmgmt_i18n_string_get_strings($type, $search_data['label'], $search_data['target_language'], $search_data['target_status']);

    foreach ($this->getTranslationData($i18n_strings, $form_state['item_type']) as $id => $data) {
      $form['items']['#options'][$id] = $this->overviewRow($type, $data);
    }

    $form['pager'] = array('#markup' => theme('pager', array('tags' => NULL)));
    $form['search_wrapper']['search']['target_language']['#options'] = osha_language_list_options();

    return $form;
  }

  /**
   * Builds a table row for overview form.
   *
   * @param string $type
   *   i18n type.
   * @param array $data
   *   Data needed to build the list row.
   *
   * @return array
   */
  public function overviewRow($type, $data) {
    // Set the default item key, assume it's the first.
    $item_title = reset($data['object']);

    $type_label = i18n_object_info($type, 'title');

    $row = array(
      'id' => $data['id'],
      'title' => $item_title->get_string() ? t('@title (@id)', array('@title' => $item_title->get_string(), '@id' => $data['id'])) : $data['id'],
      'type' => empty($type_label) ? t('Unknown') : $type_label,
    );

    foreach (language_list() as $langcode => $language) {
      $langcode = str_replace('-', '', $langcode);
      $row['langcode-' . $langcode] = theme('osha_tmgmt_ui_translation_language_status_single', array(
        'translation_status' => $data['translation_statuses'][$langcode],
        'job_item' => isset($data['current_job_items'][$langcode]) ? $data['current_job_items'][$langcode] : NULL,
      ));
    }

    return $row;
  }

  /**
   * Helper function to create translation data list for the sources page list.
   *
   * @param array $i18n_strings
   *   Result of the search query returned by tmgmt_i18n_string_get_strings().
   * @param string $type
   *   I18n object type.
   *
   * @return array
   *   Structured array with translation data.
   */
  protected function getTranslationData($i18n_strings, $type) {
    $objects = array();
    $source_language = variable_get_value('i18n_string_source_language');

    foreach ($i18n_strings as $i18n_string) {
      $wrapper = tmgmt_i18n_string_get_wrapper($type, $i18n_string);

      if ($wrapper instanceof i18n_string_object_wrapper) {
        $id = $i18n_string->job_item_id;

        // Get existing translations and current job items for the entity
        // to determine translation statuses
        $current_job_items = osha_tmgmt_job_item_load_latest('i18n_string', $wrapper->get_type(), $id, $source_language);

        $objects[$id] = array(
          'id' => $id,
          'object' => $wrapper->get_strings(array('empty' => TRUE)),
          'wrapper' => $wrapper,
        );
        // Load entity translation specific data.
        foreach (language_list() as $langcode => $language) {
          $langcode = str_replace('-', '', $langcode);

          $translation_status = 'current';

          if ($langcode == $source_language) {
            $translation_status = 'original';
          }
          elseif ($i18n_string->{'lang_' . $langcode} === NULL) {
            $translation_status = 'missing';
          }

          $objects[$id]['current_job_items'][$langcode] = isset($current_job_items[$langcode]) ? $current_job_items[$langcode] : NULL;
          $objects[$id]['translation_statuses'][$langcode] = $translation_status;
        }
      }
    }

    return $objects;
  }
}

/**
 * Gets i18n strings for given type and label. We override this to intersect with cart items.
 *
 * @param string $type
 *   i18n object type.
 * @param string $search_label
 *   Label to search for.
 * @param string $target_language
 *   Target language.
 * @param string $target_status
 *   Target status.
 *
 * @return array
 *   List of i18n strings data.
 */
function osha_tmgmt_i18n_string_get_strings($type, $search_label = NULL, $target_language = NULL, $target_status = 'untranslated_or_outdated') {
  $info = i18n_object_info($type);

  $languages = drupal_map_assoc(array_keys(language_list()));
  $select = db_select('i18n_string', 'i18n_s');

  $select->condition('i18n_s.textgroup', $info['string translation']['textgroup']);

  if (!empty($target_language) && in_array($target_language, $languages)) {
    if ($target_status == 'untranslated_or_outdated') {
      $or = db_or();
      $or->isNull("lt_$target_language.language");
      $or->condition("lt_$target_language.i18n_status", I18N_STRING_STATUS_UPDATE);
      $select->condition($or);
    }
    elseif ($target_status == 'outdated') {
      $select->condition("lt_$target_language.i18n_status", I18N_STRING_STATUS_UPDATE);
    }
    elseif ($target_status == 'untranslated') {
      $select->isNull("lt_$target_language.language");
    }
  }

  if (isset($info['string translation']['type'])) {
    $select->condition('i18n_s.type', $info['string translation']['type']);
  }
  elseif ($type == 'field' || $type == 'field_instance') {
    // Fields and field instances share the same textgroup. Use list of bundles
    // to include/exclude field_instances.
    $bundles = array();
    foreach (entity_get_info() as $entity_info) {
      $bundles = array_merge($bundles, array_keys($entity_info['bundles']));
    }
    $select->condition('i18n_s.objectid', $bundles, $type == 'field_instance' ? 'IN' : 'NOT IN');
  }

  $select->join('locales_source', 'ls', 'ls.lid = i18n_s.lid');
  $select->addField('ls', 'source');
  if (!empty($search_label)) {
    $select->where('LOWER(CAST(ls.source AS CHAR)) LIKE :search',
      array(':search' => "%" . db_like(strtolower($search_label)) . "%"));
  }

  foreach ($languages as $langcode) {
    $langcode = str_replace('-', '', $langcode);
    $select->leftJoin('locales_target', "lt_$langcode", "i18n_s.lid = %alias.lid AND %alias.language = '$langcode'");
    $select->addField("lt_$langcode", 'language', "lang_$langcode");
  }
  $select->fields("i18n_s", array('lid', 'textgroup', 'context', 'type', 'objectid'));

  $select->addExpression("concat(i18n_s.textgroup, ':', i18n_s.type, ':', i18n_s.objectid)", 'job_item_id');

  // Intersect with the cart and remove items already added to the cart
  $cart = tmgmt_ui_cart_get();
  $job_items = $cart->getJobItemsFromCart();
  $cart_ids = array();
  foreach ($job_items as $job_item) {
    if ($job_item->item_type == 'menu_link') {
      $cart_ids[] = "'" . $job_item->item_id . "'";
    }
  }
  if (!empty($cart_ids)) {
    $select->where(sprintf("concat(i18n_s.textgroup, ':', i18n_s.type, ':', i18n_s.objectid) NOT IN (%s)", implode(',', $cart_ids)));
  }
  $select->orderBy('i18n_s.context');

  $select->groupBy('type');
  $select->groupBy('objectid');

  $select = $select->extend('PagerDefault')->limit(variable_get('tmgmt_source_list_limit', 20));

  return $select->execute()->fetchAll();
}

/**
 * Gets translation language status.
 *
 * @param array $variables
 *   - 'translation_status': A flag that determines the status. Possible values:
 *     original, missing, outofdate.
 *   - 'job_item': Current job item entity associated with translation.
 *
 * @return string
 *   Icon or a link icon that explains the translation status and possibly
 *   links to an active translation job.
 */
function theme_osha_tmgmt_ui_translation_language_status_single($variables) {
  switch ($variables['translation_status']) {
    case 'original':
      $label = t('Source language');
      $icon_color = 'tmgmt-ui-icon-white';
      break;

    case 'missing':
      $label = t('Not translated');
      $icon_color = 'tmgmt-ui-icon-grey';
      break;

    case 'outofdate':
      $label = t('Translation Outdated');
      $icon_color = 'tmgmt-ui-icon-orange';
      break;

    default:
      $label = t('Translation up to date');
      $icon_color = 'tmgmt-ui-icon-green';
  }

  // Add classes to show the correct html icon.
  $classes = array();
  $classes[] = 'tmgmt-ui-icon';
  // Icon size 10px square.
  $classes[] = 'tmgmt-ui-icon-10';
  $classes[] = $icon_color;

  // Add necessary css file.
  drupal_add_css(drupal_get_path('module', 'tmgmt_ui') . '/css/tmgmt_ui.admin.css');

  $status = '';
  if (empty($variables['job_item'])) {
    $status = sprintf('<div class="%s" title="%s"><span></span></div>', implode(' ', $classes), $label);
  }

  // If we have an active job item, wrap it in a link.
  if (!empty($variables['job_item'])) {
    $job_item_wrapper = entity_metadata_wrapper('tmgmt_job_item', $variables['job_item']);
    $label = t('Active job item: @state', array('@state' => $job_item_wrapper->state->label()));
    $uri = $variables['job_item']->uri();
    /** @var TMGMTJob $job */
    $job = $variables['job_item']->getJob();
    $job_wrapper = entity_metadata_wrapper('tmgmt_job', $job);

    switch ($variables['job_item']->state) {
      case TMGMT_JOB_ITEM_STATE_ACTIVE:
        if ($job->isUnprocessed()) {
          $uri = $job->uri();
          $label = t('Active job item: @state', array('@state' => $job_wrapper->state->label()));
        }
        $icon_color = 'tmgmt-ui-icon-blue';
        break;

      case TMGMT_JOB_ITEM_STATE_REVIEW:
        $icon_color = 'tmgmt-ui-icon-yellow';
        break;
    }

    // Add classes to show the correct html icon.
    $classes = array();
    $classes[] = 'tmgmt-ui-icon';
    // Icon size 10px square.
    $classes[] = 'tmgmt-ui-icon-10';
    $classes[] = $icon_color;

    $job_status = sprintf('<div class="%s" title="%s"><span></span></div>', implode(' ', $classes), $label);

    $status .= l($job_status, $uri['path'], array(
      'query' => array('destination' => current_path()),
      'html' => TRUE,
      'attributes' => array('title' => $label),
    ));
  }
  return $status;
}
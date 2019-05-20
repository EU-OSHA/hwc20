<?php

/**
 * @file
 * Provides the i18n string source controller.
 */

/**
 * Translation plugin controller for i18n strings (menu items).
 */
class OSHATMGMTI18nStringSourcePluginController extends TMGMTI18nStringSourcePluginController {

  /**
   * {@inheritdoc}
   */
  public function saveTranslation(TMGMTJobItem $job_item) {
    $data = array_filter(tmgmt_flatten_data($job_item->getData()), '_tmgmt_filter_data');
    $updated = FALSE;
    foreach ($data as $i18n_string => $item) {
      if (!empty($item['#translation']['#text'])) {
        $updated = TRUE;
        i18n_string_translation_update($i18n_string, $item['#translation']['#text'], $job_item->target_language);
      }
    }
    // We just saved the translation, set the state of the job item to 'finished'.
    if ($updated) {
      $job_item->accepted();
    }
  }
}

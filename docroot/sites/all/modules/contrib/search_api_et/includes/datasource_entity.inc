<?php

/**
 * @file
 * Contains the SearchApiEtDatasourceController class.
 */

/**
 * Provides multilingual versions of all entity types.
 */
class SearchApiEtDatasourceController extends SearchApiEntityDataSourceController {

  /**
   * Overrides SearchApiEntityDataSourceController::$table.
   *
   * Needed because we have a string ID, instead of a numerical one.
   *
   * @var string
   */
  protected $table = 'search_api_et_item';

  /**
   * {@inheritdoc}
   */
  public function getIdFieldInfo() {
    return array(
      'key' => 'search_api_et_id',
      'type' => 'string',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function loadItems(array $ids) {
    $item_languages = array();
    foreach ($ids as $id) {
      list($langcode, $entity_id) = explode('_', $id, 2);
      $item_languages[$entity_id][] = $langcode;
    }
    $entities = entity_load($this->entityType, array_keys($item_languages));

    // If some items could not be loaded, remove them from tracking.
    if (count($entities) != count($item_languages)) {
      $unknown = array_keys(array_diff_key($item_languages, $entities));
      if ($unknown) {
        $deleted = array();
        foreach ($unknown as $entity_id) {
          foreach ($item_languages[$entity_id] as $langcode) {
            $deleted[] = "{$langcode}_{$entity_id}";
          }
        }
        search_api_track_item_delete($this->type, $deleted);
      }
    }

    // Now arrange them according to our IDs again, with language.
    $items = array();
    foreach ($item_languages as $entity_id => $langs) {
      if (!empty($entities[$entity_id])) {
        foreach ($langs as $lang) {
          $id = "{$lang}_{$entity_id}";
          $entity = clone $entities[$entity_id];
          $entity->search_api_et_id = $id;
          $entity->language = $lang;
          $items[$id] = $entity;
        }
      }
    }

    return $items;
  }

  /**
   * {@inheritdoc}
   */
  public function getMetadataWrapper($item = NULL, array $info = array()) {
    // Since this is usually called with a "property info alter" callback
    // already in place (and only one value is allowed), we have to call
    // the existing callback from within our own callback to make it work.
    $property_info_alter = isset($info['property info alter']) ? $info['property info alter'] : NULL;
    $callback = new SearchApiEtPropertyInfoAlter($property_info_alter);
    $info['property info alter'] = array($callback, 'propertyInfoAlter');

    // If the item isn't the object and a multilingual id is provided
    // extract the entity id to load and wrap the entity.
    if (!is_object($item) && is_scalar($item) && strpos($item, '_') !== FALSE) {
      list($item_language, $item) = explode('_', $item);
    }

    $wrapper = entity_metadata_wrapper($this->entityType, $item, $info);
    if (!empty($item->search_api_language)) {
      $wrapper = $wrapper->language($item->search_api_language);
    }
    return $wrapper;
  }

  /**
   * {@inheritdoc}
   */
  public function getItemId($item) {
    return isset($item->search_api_et_id) ? $item->search_api_et_id : NULL;
  }

  /**
   * Overrides SearchApiEntityDataSourceController::startTracking().
   *
   * Reverts the behavior to always use getAllItemIds(), instead of taking a
   * shortcut via "base table".
   *
   * This method will also be called when the multilingual configuration of an
   * index changes, to take care of new and/or out-dated IDs.
   */
  public function startTracking(array $indexes) {
    if (!$this->table) {
      return;
    }

    // We first clear the tracking table for all indexes, so we can just insert
    // all items again without any key conflicts.
    // @TODO: Update the tracking table instead of removing and re-adding items.
    // Clearing the tracking table first is standard Search API behavior, it
    // would be nicer though to update its content instead, by adding missing
    // item IDs and removing those that shouldn't be there anymore.
    $this->stopTracking($indexes);

    $operations = array();

    // Find out number of all entities to be processed.
    foreach ($indexes as $index) {
      $entity_type = $index->getEntityType();

      $query = new EntityFieldQuery();
      $entities = $query->entityCondition('entity_type', $entity_type)
        ->execute();
      if (empty($entities[$entity_type])) {
        continue;
      }

      $steps = ceil(count($entities[$entity_type]) / $index->options['cron_limit']);

      for ($step = 0; $step < $steps; $step++) {
        $operations[] = array('search_api_et_batch_queue_entities', array($index, array_keys($entities[$entity_type]), $step));
      }
    }

    // This might be called both from web interface as well as from drush.
    $t = drupal_is_cli() ? 'dt' : 't';

    $batch = array(
      'title' => $t('Adding items to the index queue'),
      'operations' => $operations,
      'finished' => 'search_api_et_batch_queue_entities_finished',
      'progress_message' => $t('Completed about @percentage% of the queueing operation.'),
      'file' => drupal_get_path('module', 'search_api_et') . '/search_api_et.batch.inc',
    );
    batch_set($batch);

    if (drupal_is_cli()) {
      // Calling drush_backend_batch_process() to start batch execution directly
      // from here doesn't work for some unknown reason, so we need to call it
      // from a shutdown function instead.
      drupal_register_shutdown_function('search_api_et_shutdown_batch_process');
    }
    else {
      batch_process();
    }
  }

  /**
   * Retrieves all item IDs for a given index.
   *
   * Is used instead of SearchApiAbstractDataSourceController::getAllItemIds(),
   * since available items depend on the index configuration.
   *
   * @param SearchApiIndex $index
   *   The index for which item IDs should be retrieved.
   *
   * @return array
   *   An array with all item IDs for a given index, with keys and values both
   *   being the IDs.
   */
  public function getAllIndexItemIds(SearchApiIndex $index) {
    $entities = entity_load($this->entityType);
    $ids = array();

    foreach ($entities as $id => $entity) {
      foreach (search_api_et_item_languages($entity, $this->entityType, $index) as $lang) {
        $lang_id = "{$lang}_{$id}";
        $ids[$lang_id] = $lang_id;
      }
    }

    return $ids;
  }

}

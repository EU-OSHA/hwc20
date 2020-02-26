<?php

/**
 * Class NCWMSDMigration migrates practical tool
 *
 * Set hwc_migration_dangerous_substances_url variable for explicit source URL.
 */

class NCWMSDMigration extends AbstractNCWNodeMigration {

  public $new_providers = array();

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWMSDSource', 'practical_tool');
    $this->description = 'Import DS from NCW';
  }

  function getTermReferenceFieldsMap() {
    return [
      'field_msd_priority_area' => 'msd_priority_area',
      'field_sector_industry_covered' => 'nace_codes',
      'field_hazards' => 'hazards',
      'field_health_effects' => 'health_effects',
      'field_worker_groups_covered' => 'worker_groups_covered',
      'field_prevention_measures' => 'prevention_measures_msd',
      'field_purpose_of_the_material' => 'purpose_of_material',
      'field_target_audience' => 'target_audience',
      'field_msd_resource_type' => 'resource_type',
      'field_material_country' => 'country',
    ];
  }

  /**
   * {@inheritdoc}
   */
  function addFieldMappings() {
    parent::addFieldMappings();
    $unmigrated_destinations = [];
    foreach ($this->getTermReferenceFieldsMap() as $taxonomy => $vocabulary) {
      $this->addFieldMapping($taxonomy . ':source_type')->defaultValue('tid');
      $this->addFieldMapping($taxonomy . ':create_term')->defaultValue(FALSE);
      $this->addFieldMapping($taxonomy, $taxonomy);
      $unmigrated_destinations[] = $taxonomy . ':ignore_case';
    }

    $this->addUnmigratedDestinations($unmigrated_destinations);
    $this->ignoreMetatagMigration();
  }

  /**
   * {@inheritdoc}
   */
  protected function getManuallyMigratedFields() {
    $map = array_keys($this->getTermReferenceFieldsMap());
    $map[] = 'field_msd_provider';
    $map[] = 'field_modified_date';
    return $map;
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, stdClass $row) {
    parent::prepare($entity, $row);
    $this->new_providers = [];

    // Language_field fix.
    if ($entity->field_available_in_languages) {
      $entity->field_available_in_languages['und'] = $entity->field_available_in_languages['und'][0]['value'];
    }
    if ($entity->field_original_desc_language) {
      $entity->field_original_desc_language['und'] = $entity->field_original_desc_language['und'][0]['value'];
    }
    $entity->field_modified_date = [];
    $entity->field_modified_date[LANGUAGE_NONE][0]['value'] = $row->changed;

    $entity_ids = [];
    if (!empty($entity->nid)) {
      $result = db_query("SELECT field_msd_provider_value from field_data_field_msd_provider where entity_id=" . $entity->nid);
      foreach ($result as $value) {
        $objects = entity_load('field_collection_item', [$value->field_msd_provider_value]);
        if ($objects) {
          $entity_ids[] = $value->field_msd_provider_value;
        }
      }
    }
    $msd_providers = [];
    foreach ($row->field_msd_provider as $idx => $provider) {
      if (@$entity_ids[$idx]) {
        $objects = entity_load('field_collection_item', [$entity_ids[$idx]]);
        $field_collection = $objects[$entity_ids[$idx]];
      }
      else {
        $field_collection = entity_create('field_collection_item', array('field_name' => 'field_msd_provider'));
        if (!empty($entity->nid)) {
          $hostEntity = node_load($entity->nid);
          $field_collection->setHostEntity('node', $hostEntity, LANGUAGE_NONE, FALSE);
        }
      }
      $field_collection->field_msd_provider_name = $provider['field_msd_provider_name'];
      $field_collection->field_msd_provider_name_o = $provider['field_msd_provider_name_o'];
      if (empty($entity->nid)) {
        $this->new_providers[] = $field_collection;
      }
      else {
        $field_collection->save(TRUE);
        $msd_providers[] = ['value' => $field_collection->item_id, 'revision_id' => $field_collection->revision_id];
      }
    }

    $entity->field_msd_provider = [];
    if ($msd_providers) {
      $entity->field_msd_provider = ['und' => $msd_providers];
    }
  }

  /**
   * Implements Migration::complete() to configure translations.
   */
  public function complete($entity, stdClass $row) {
    parent::complete($entity, $row);
    if ($this->new_providers) {
      foreach ($this->new_providers as $field_collection) {
        $field_collection->setHostEntity('node', $entity, LANGUAGE_NONE, FALSE);
        $field_collection->save(TRUE);
        $entity->field_msd_provider['und'][] = ['value' => $field_collection->item_id, 'revision_id' => $field_collection->revision_id];
      }
      node_save($entity);
    }
  }

  /**
   * {@inheritdoc}
   */
  function prepareRow($row) {
    $row->field_msd_resource_type_other = $row->field_resource_type_other;
    $row->field_material_country = $row->field_material_country;
    $row->field_msd_resource_type = $row->field_resource_type;
    parent::prepareRow($row);
    if ($row->path) {
      $row->field_migration_path_alias = $row->path;
    }
    else {
      $row->field_migration_path_alias = 'node/' . $row->nid;
    }
    // Disable NCW alias.
    $row->path = NULL;
    foreach ($this->getTermReferenceFieldsMap() as $taxonomy => $vocabulary) {
      if ($row->{$taxonomy}) {
        $orig_taxonomies = $row->{$taxonomy};
        $row->{$taxonomy} = osha_migration_normalize_migrated_term_reference($row->{$taxonomy}, 'tax_' . $vocabulary);
        if (!$row->{$taxonomy}) {
          foreach ($orig_taxonomies as $orig_taxonomy) {
            watchdog('ncw_migration', "[BUG]Cannot find taxonomy '" . serialize($orig_taxonomy) . "', for $vocabulary", array(), WATCHDOG_ERROR);
          }
        }
      }
    }
  }

  /**
   * Remove nodes that are not in the source anymore.
   */
  protected function removeNeedsUpdateItems() {
    $map = $this->getMap();
    $source = $this->getSource();
    $removed = $map->getRowsNeedingUpdate(10000);
    $source_ids = $source->getSourceIds();
    if (!empty($removed) && $source_ids) {
      if (strpos($this->arguments['machine_name'], 'tax_') === 0) {
        // TODO ?! Removing terms that don't exists anymore
        // Similar as for nodes below.
      }
      else {
        // Check if the needs review nodes are indeed missing in source.
        foreach ($removed as $to_remove) {
          if (isset($source_ids[$to_remove->sourceid1])) {
            continue;
          }
          $url = $source->itemURL($to_remove->sourceid1);
          $curl = curl_init();
          curl_setopt($curl, CURLOPT_URL, $url);
          curl_setopt($curl, CURLOPT_NOBODY, TRUE);
          curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, 5);
          curl_setopt($curl, CURLOPT_FOLLOWLOCATION, TRUE);
          $result = curl_exec($curl);
          $info = curl_getinfo($curl);
          curl_close($curl);
          // Remove only if 404.
          if (!empty($info['http_code']) && $info['http_code'] == 404) {
            node_delete($to_remove->destid1);
            $this->getMap()->delete(array($to_remove->sourceid1));
            watchdog('ncw_migration', 'Deleting NODE that are not in the source anymore (@migration): !nids.',
              array('!nids' => $to_remove->destid1, '@migration' => $this->arguments['machine_name']), WATCHDOG_INFO);
          }
          else {
            $nid = $to_remove->destid1;
            if ($node = node_load($nid)) {
              if ($node->status == 1) {
                $node->status = 0;
                node_save($node);
                $this->currentMigration()->displayMessage(
                  strtr('Unpublishing @type @title - not found in source anymore.', array('@type' => $node->type, '@title' => $node->title)),
                  'warning'
                );
              }
            }
            else {
              $this->currentMigration()->displayMessage(
                strtr('Node @nid not found! Deleted from migrate map.', array('@nid' => $nid)),
                'warning'
              );
              $this->getMap()->delete(array($to_remove->sourceid1));
            }
          }
        }
      }
    }
  }

}

class NCWDangerousSubstancesMigration extends NCWMSDMigration {

}

class NCWMSDSource extends AbstractNCWNodeSource {

  /**
   * @var array
   */
  protected $source_ids;

  /**
   * {@inheritdoc}
   */
  public function __construct($options) {
    parent::__construct($options);
    $this->source_ids = [];
    $this->endpoint_url .= '?' . rand(100, 200);
  }

  /**
   * {@inheritdoc}
   */
  public function getNextRow() {
    if (empty($this->rows)) {
      $this->readData();
    }
    $item = NULL;
    if (count($this->rows)) {
      $node_url = current($this->rows);
      if ($rowd = $this->fileGetContents($node_url)) {
        if ($row_ob = json_decode($rowd, TRUE)) {
          unset($rowd);
          $item = new stdClass();
          foreach ($row_ob as $k => $v) {
            $item->$k = $v;
          }
          unset($row_ob);
        }
      }
      else {
        $msg = format_string('Failed to read data from !url', array('!url' => $node_url));
        watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
      }
      next($this->rows);
    }
    return $item;
  }

  /**
   * Source node ids.
   */
  public function getSourceIds() {
    return $this->source_ids;
  }

  /**
   * Get modified dates.
   */
  public function getMSDModifiedDates() {
    $q = db_select('migrate_map_msd', 'mm');
    $q->fields('mm', ['sourceid1']);
    $q->fields('md', ['field_modified_date_value']);
    $q->leftJoin('field_data_field_modified_date', 'md', 'md.entity_id = mm.destid1');
    return $q->execute()->fetchAllKeyed(0, 1);
  }

  /**
   * Read data from source.
   */
  public function readData() {
    $msg = format_string('Updating from !url', array('!url' => $this->endpoint_url));
    watchdog('ncw_migration', $msg, [], WATCHDOG_INFO);
    ncw_migration_debug('!klass: Starting reading items from !url', array('!klass' => get_class($this), '!url' => $this->endpoint_url));
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      ncw_migration_debug('!klass:      * Processing !count items', array('!klass' => get_class($this), '!count' => count($data->items)));
      $dates = $this->getMSDModifiedDates();
      $check_date = variable_get('ncw_migration_ds_check_date', TRUE);
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        $this->source_ids[$id] = $id;
        if (in_array($id, $this->skip_ids)) {
          continue;
        }
        if ($check_date && isset($dates[$id]) && ($dates[$id] == $ob->changed)) {
          continue;
        }
        $node_url = $this->itemURL($id);
        ncw_migration_debug('!klass:      * Reading item: !url', array('!klass' => get_class($this), '!url' => $node_url));
        $this->rows[$id] = $node_url;
      }
    }
    else {
      $msg = format_string('Failed to read data from !url', array('!url' => $this->endpoint_url));
      watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
      throw new MigrateException($msg, Migration::MESSAGE_ERROR);
    }
    ncw_migration_debug('!klass: Done reading items', array('!klass' => get_class($this)));
    reset($this->rows);
  }

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'field_msd_priority_area' => '',
      'field_sector_industry_covered' => '',
      'field_hazards' => '',
      'field_health_effects' => '',
      'field_worker_groups_covered' => '',
      'field_prevention_measures' => '',
      'field_purpose_of_the_material' => '',
      'field_target_audience' => '',
      'field_msd_resource_type' => '',
      'field_material_country' => '',
    );

    $text = [
      'field_msd_provider' => '',
      'field_original_desc_language' => '',
      'field_original_desc_lang_other' => '',
      'field_available_in_languages' => '',
      'field_external_url' => '',
      'field_publication_year' => '',
      'field_nominated_by_fop' => '',
      'field_type_of_item' => '',
      'field_title_original' => '',
      'field_country_other' => '',
      'field_languages_other' => '',
      'field_hazards_other' => '',
      'field_hazard_health_other' => '',
      'field_worker_groups_other' => '',
      'field_prevention_measures_other' => '',
      'field_material_purpose_other' => '',
      'body' => '',
      'field_body_original' => '',
      'field_target_group_other' => '',
      'field_msd_resource_type_other' => '',
      'field_msd_video_length' => '',
      'field_for_pictogram_guide' => '',
      'field_comments' => '',
    ];

    $fields += $text;
    return $fields;
  }

}

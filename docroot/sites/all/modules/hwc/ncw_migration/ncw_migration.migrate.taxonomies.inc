<?php
class NCWTaxonomyThesaurusMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'thesaurus');
    $this->description = 'Import taxonomy "thesaurus" from NCW';
  }
}

class NCWTaxonomyActivityMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'activity');
    $this->description = 'Import taxonomy "activity" from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();
    $this->addSimpleMappings(array('parent', 'field_activity_code', 'field_activity_level'));
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $map = $this->getMap();
    if ($destid1 = $map->lookupDestinationID(array($row->tid))) {
      if ($destid1) {
        $row->parent = array_keys(taxonomy_get_parents($destid1['destid1']));
      }
    }
  }

}

class NCWTaxonomyHazardsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'hazards');
    $this->description = 'Import taxonomy "hazards" from NCW';
  }
}

class NCWTaxonomyHealthEffectsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'health_effects');
    $this->description = 'Import taxonomy "health_effects" from NCW';
  }
}

class NCWTaxonomyMSDPrioritySreaMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'msd_priority_area');
    $this->description = 'Import taxonomy "msd_priority_area" from NCW';
  }
}

class NCWTaxonomyPreventionMeasuresMSDMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'prevention_measures_msd');
    $this->description = 'Import taxonomy "prevention_measures_msd" from NCW';
  }
}


class NCWTaxonomyMSDGlossaryMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'msd_glossary');
    $this->description = 'Import taxonomy "msd_glossary" from NCW';
  }
}

class NCWTaxonomyPurposeOfMaterialMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'purpose_of_material');
    $this->description = 'Import taxonomy "purpose_of_material" from NCW';
  }
}

class NCWTaxonomyResourceTypeMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'resource_type');
    $this->description = 'Import taxonomy "resource_type" from NCW';
  }
}

class NCWTaxonomyTargetAudienceMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'target_audience');
    $this->description = 'Import taxonomy "target_audience" from NCW';
  }
}

class NCWTaxonomyWorkerGroupsCoveredMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'worker_groups_covered');
    $this->description = 'Import taxonomy "worker_groups_covered" from NCW';
  }
}

class NCWTaxonomyCountryMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'CountryNCWTaxonomyTermSource', 'country');
    $this->description = 'Import taxonomy "country" from NCW';
  }
}

class NCWTaxonomyCountryStatusMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'country_status');
    $this->description = 'Import taxonomy "country_status" from NCW';
  }
}

class NCWTaxonomyFOPLinkSectionsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'fop_link_sections');
    $this->description = 'Import taxonomy "fop_link_sections" from NCW';
  }
}

class NCWTaxonomyNewsletterSectionsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'newsletter_sections');
    $this->description = 'Import taxonomy "newsletter_sections" from NCW';
  }

}

class NCWTaxonomyPublicationTypeMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'PublicationTypeNCWTaxonomyTermSource', 'publication_types');
    $this->description = 'Import taxonomy "publication_types" from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();
    $this->addSimpleMappings(array('parent'));
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $map = $this->getMap();
    if ($destid1 = $map->lookupDestinationID(array($row->tid))) {
      if ($destid1) {
        $row->parent = array_keys(taxonomy_get_parents($destid1['destid1']));
      }
    }
  }

}

class NCWTaxonomySegmentationMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SegmentationNCWTaxonomyTermSource', 'segment');
    $this->description = 'Import taxonomy "relevant_for" from NCW';
  }
}

class NCWTaxonomyTagsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'TagsNCWTaxonomyTermSource', 'tags');
    $this->description = 'Import taxonomy "tags" from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();
    $this->addSimpleMappings(array('parent'));
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    $map = $this->getMap();
    if ($destid1 = $map->lookupDestinationID(array($row->tid))) {
      if ($destid1) {
        $row->parent = array_keys(taxonomy_get_parents($destid1['destid1']));
      }
    }
  }

}

class NCWTaxonomyPriorityAreaMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'SimpleNCWTaxonomyTermSource', 'priority_area');
    $this->description = 'Import taxonomy "priority_area" from NCW';
  }
}

class NCWTaxonomyProviderTypeMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'ProviderTypeNCWTaxonomyTermSource', 'provider_type');
    $this->description = 'Import taxonomy "provider_type" from NCW';
  }
}

class NCWTaxonomyNaceCodesMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'NaceCodesNCWTaxonomyTermSource', 'nace_codes');
    $this->description = 'Import taxonomy "nace_codes" from NCW';
    $this->destination = new NaceCodeMigrateDestinationTerm('nace_codes', array('language' => 'en', 'allow_duplicate_terms' => true));
  }
}

class NaceCodeMigrateDestinationTerm extends MigrateDestinationTerm {
  /**
   * Import a single term.
   *
   * @param $term
   *  Term object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *  Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *  Array of key fields (tid only in this case) of the term that was saved if
   *  successful. FALSE on failure.
   */
  public function import(stdClass $term, stdClass $row) {
    $migration = Migration::currentMigration();
    // Updating previously-migrated content?
    if (isset($row->migrate_map_destid1)) {
      if (isset($term->tid)) {
        if ($term->tid != $row->migrate_map_destid1) {
          throw new MigrateException(t("Incoming tid !tid and map destination nid !destid1 don't match",
            array('!tid' => $term->tid, '!destid1' => $row->migrate_map_destid1)));
        }
      }
      else {
        $term->tid = $row->migrate_map_destid1;
      }
    }

    // Default to bundle if no vocabulary machine name provided
    if (!isset($term->vocabulary_machine_name)) {
      $term->vocabulary_machine_name = $this->bundle;
    }

    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      if (!isset($term->tid)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but no destination tid provided'));
      }
      $rawterm = $term;
      $this->prepare($term, $row);
      $old_term = taxonomy_term_load($term->tid);
      if (empty($old_term)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but term !tid does not exist',
          array('!tid' => $term->tid)));
      }
      foreach ($rawterm as $field => $value) {
        $old_term->$field = $term->$field;
      }
      $term = $old_term;
    }
    else {
      // vid is required
      if (empty($term->vid)) {
        static $vocab_map = array();
        if (!isset($vocab_map[$term->vocabulary_machine_name])) {
          // The keys of the returned array are vids
          $vocabs = taxonomy_vocabulary_load_multiple(array(),
            array('machine_name' => $term->vocabulary_machine_name));
          $vids = array_keys($vocabs);
          if (isset($vids[0])) {
            $vocab_map[$term->vocabulary_machine_name] = $vids[0];
          }
          else {
            $migration->saveMessage(t('No vocabulary found with machine_name !name',
              array('!name' => $term->vocabulary_machine_name)));
            return FALSE;
          }
        }
        $term->vid = $vocab_map[$term->vocabulary_machine_name];
      }

      if (!isset($term->format)) {
        $term->format = $this->textFormat;
      }
      if (!isset($term->language)) {
        $term->language = $this->language;
      }

      $this->prepare($term, $row);

      if (empty($term->name)) {
        throw new MigrateException(t('Taxonomy term name is required.'));
      }
      $existing_term = $this->findMatchingTerm($term);
      if ($existing_term) {
        foreach ($existing_term as $field => $value) {
          if (!isset($term->$field)) {
            $term->$field = $existing_term->$field;
          }
        }
      }
    }

    // Trying to update an existing term.
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      $existing_term = taxonomy_term_load($term->tid);
      if ($existing_term) {
        // Incoming data overrides existing data, so only copy non-existent fields
        foreach ($existing_term as $field => $value) {
          if (!isset($term->$field)) {
            $term->$field = $existing_term->$field;
          }
        }
      }
    }

    if (isset($term->tid)) {
      $updating = TRUE;
    }
    else {
      $updating = FALSE;
    }

    // Validate field data prior to saving.
    MigrateDestinationEntity::fieldAttachValidate('taxonomy_term', $term);

    migrate_instrument_start('taxonomy_term_save');
    $status = taxonomy_term_save($term);
    migrate_instrument_stop('taxonomy_term_save');
    $this->complete($term, $row);
    if (isset($term->tid)) {
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      $return = array($term->tid);
    }
    else {
      $return = FALSE;
    }
    return $return;
  }

  /**
   * Attempt to find a term that has the same name, vocabulary, and parents.
   *
   * @param object $term
   *   A taxonomy term object with at least the name and vid properties defined.
   *
   * @return object
   *   A matching taxonomy term object if found, otherwise FALSE.
   */
  public function findMatchingTerm($term) {
    $nace_code = $term->field_nace_code['und'][0]['value'];
    // See if the term, with the same parentage, already exists - if so,
    // load it

    $candidates = taxonomy_term_load_multiple(array(),
      array('name' => trim($term->name), 'vid' => $term->vid));

    foreach ($candidates as $candidate) {
      if ($candidate->field_nace_code['und'][0]['value'] === $nace_code) {
        return $candidate;
      }
    }
    return FALSE;
  }

}

class NCWTaxonomyHazmapCategoriesMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'HazmapCategoriesNCWTaxonomyTermSource', 'hazmap_categories');
    $this->description = 'Import taxonomy "hazmap_categories" from NCW';
  }
}

class NCWTaxonomyBiologicalHazardMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'BiologicalHazardNCWTaxonomyTermSource', 'biological_hazard');
    $this->description = 'Import taxonomy "biological_hazard" from NCW';
  }
}

class NCWTaxonomyHazardPhysicalStateMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'HazardPhysicalStateNCWTaxonomyTermSource', 'hazard_physical_state');
    $this->description = 'Import taxonomy "hazard_physical_state" from NCW';
  }
}

class NCWTaxonomyHazardHealthEffectsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'HazardHealthEffectsNCWTaxonomyTermSource', 'hazard_health_effects');
    $this->description = 'Import taxonomy "hazard_health_effects" from NCW';
  }
}

class NCWTaxonomyExposureRouteMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'ExposureRouteNCWTaxonomyTermSource', 'exposure_route');
    $this->description = 'Import taxonomy "exposure_route" from NCW';
  }
}

class NCWTaxonomyWorkerGroupsMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'WorkerGroupsNCWTaxonomyTermSource', 'worker_groups');
    $this->description = 'Import taxonomy "worker_groups" from NCW';
  }
}

class NCWTaxonomyPreventionMeasuresMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'PreventionMeasuresNCWTaxonomyTermSource', 'prevention_measures');
    $this->description = 'Import taxonomy "prevention_measures" from NCW';
  }
}

class NCWTaxonomyMaterialPurposeMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'MaterialPurposeNCWTaxonomyTermSource', 'material_purpose');
    $this->description = 'Import taxonomy "material_purpose" from NCW';
  }
}

class NCWTaxonomyTargetGroupMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'TargetGroupNCWTaxonomyTermSource', 'target_group');
    $this->description = 'Import taxonomy "target_group" from NCW';
  }
}

class NCWTaxonomyEvaluationMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'EvaluationNCWTaxonomyTermSource', 'evaluation');
    $this->description = 'Import taxonomy "evaluation" from NCW';
  }
}

class NCWTaxonomyMaterialObjectiveMigration extends AbstractNCWTaxonomyTermMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'MaterialObjectiveNCWTaxonomyTermSource', 'material_objective');
    $this->description = 'Import taxonomy "material_objective" from NCW';
  }
}

class SimpleNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array();
  }
}

class TagsNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array(
      'field_tags_code' => 'field_tags_code',
    );
  }
}

class SegmentationNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array();
  }
}

class PublicationTypeNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array(
      'field_publication_type_code' => 'field_publication_type_code',
    );
  }
}

class CountryNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {

  public function contentFields() {
    return array(
      'field_iso2' => 'field_iso2',
      'field_flag' => 'field_flag',
      'field_country_status' => 'field_country_status',
    );
  }
}

class ProviderTypeNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_provider_type_code' => 'field_provider_type_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class NaceCodesNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_nace_code' => 'field_nace_code',
      'field_nace_changes' => 'field_nace_changes',
      'field_nace_includes' => 'field_nace_includes',
      'field_nace_excludes' => 'field_nace_excludes',
      'field_nace_includes_also' => 'field_nace_includes_also',
    );
  }
}

class HazmapCategoriesNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_hazmap_categories_code' => 'field_hazmap_categories_code',
    );
  }
}

class BiologicalHazardNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_biological_hazard_code' => 'field_biological_hazard_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class HazardPhysicalStateNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_hazard_health_effects_code' => 'field_hazard_health_effects_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class HazardHealthEffectsNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_hazard_physical_state_code' => 'field_hazard_physical_state_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class ExposureRouteNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_exposure_route_code' => 'field_exposure_route_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class WorkerGroupsNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_worker_groups_code' => 'field_worker_groups_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class PreventionMeasuresNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_prevention_measures_code' => 'field_prevention_measures_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
      'field_prevention_level' => 'field_prevention_level',
    );
  }
}

class MaterialPurposeNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_material_purpose_code' => 'field_material_purpose_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class TargetGroupNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_target_group_code' => 'field_target_group_code',
      'field_thesaurus_id' => 'field_thesaurus_id',
    );
  }
}

class EvaluationNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_evaluation_code' => 'field_evaluation_code',
    );
  }
}

class MaterialObjectiveNCWTaxonomyTermSource extends AbstractNCWTaxonomyTermSource {
  public function contentFields() {
    return array(
      'field_material_objective_code' => 'field_material_objective_code',
    );
  }
}

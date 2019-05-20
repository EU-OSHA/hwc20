<?php

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

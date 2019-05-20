<?php

/**
 * Class NCWPressContactMigration migrates press contacts.
 *
 * Set hwc_migration_press_contacts_url variable for explicit source URL.
 */
class NCWPressContactMigration extends AbstractNCWNodeMigration {
  public static $nodequeue = array();

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWPressContactSource', 'press_contact');
    $this->description = 'Import press contacts from NCW';
  }

  /**
   * {@inheritdoc}
   */
  protected function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_contact_type')->defaultValue('Press Contact');
    $this->addFieldMapping('field_contact_type:create_term')->defaultValue(TRUE);

    $this->addUnmigratedDestinations(array(
      'field_city:language',
      'field_contact_type:source_type',
      'field_contact_type:ignore_case',
      'field_country:source_type',
      'field_country:ignore_case',
      'field_personal_title:language',
      'field_press_contact_organization:language',
      'field_press_contact_phone:language',
      'field_website:language',
      'field_wg_category:source_type',
      'field_wg_category:ignore_case',
      'field_wg_role_1:source_type',
      'field_wg_role_1:ignore_case',
      'field_wg_role_2:source_type',
      'field_wg_role_2:ignore_case',
      'field_zip_code:language',
    ));
    $this->ignoreMetatagMigration();
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
    $row->field_migration_path_alias = $row->path;
    // Disable NCW alias.
    $row->path = NULL;
  }

  /**
   * Implements Migration::complete() to configure translations.
   */
  public function complete($entity, stdClass $row) {
    parent::complete($entity, $row);
    if (!empty($row->nodequeue_order)) {
      self::$nodequeue[$entity->nid] = $row->nodequeue_order;
    }
  }

  /**
   * Executes after import.
   */
  public function postImport() {
    parent::postImport();
    // Add contacts to nodequeue.
    $nodequeue = nodequeue_load(3);
    asort(self::$nodequeue);
    $subq = nodequeue_load_subqueue(3);
    foreach (self::$nodequeue as $nid => $order) {
      // Remove the node and add it again in the correct order.
      nodequeue_subqueue_remove_node(3, $nid);
      nodequeue_subqueue_add($nodequeue, $subq, $nid);
    }
  }

  function getManuallyMigratedFieldS() {
    return array('field_contact_type');
  }
}


class NCWPressContactSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_contact_type',
      'field_press_contact_job_title',
      'field_press_contact_job_title_language',
      'field_personal_title',
      'field_press_contact_organization',
      'field_press_contact_location',
      'field_press_contact_location_language',
      'field_press_contact_location_format',
      'field_city',
      'field_country',
      'field_zip_code',
      'field_press_contact_email',
      'field_press_contact_phone',
      'field_wg_role_1',
      'field_wg_role_2',
      'field_wg_category',
      'field_website',
      'field_website_title',
      'field_website_attributes',
      'field_migration_path_alias',
    );
    return array_combine($fields, $fields);
  }
}

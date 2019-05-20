<?php
/**
 * @file
 * campaign_materials.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function campaign_materials_taxonomy_default_vocabularies() {
  return array(
    'campaign_material_types' => array(
      'name' => 'Campaign Material Types',
      'machine_name' => 'campaign_material_types',
      'description' => 'Campaign Material Types',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}

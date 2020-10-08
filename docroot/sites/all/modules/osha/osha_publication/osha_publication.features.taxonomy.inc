<?php
/**
 * @file
 * osha_publication.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function osha_publication_taxonomy_default_vocabularies() {
  return array(
    'publication_types' => array(
      'name' => 'Publication Types',
      'machine_name' => 'publication_types',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'base_i18n_mode' => 1,
      'base_language' => 'und',
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
    'thesaurus' => array(
      'name' => 'Thesaurus',
      'machine_name' => 'thesaurus',
      'description' => 'This taxonomy will be used to classify content by EU-OSHA’s controlled vocabulary',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'base_i18n_mode' => 1,
      'base_language' => 'und',
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

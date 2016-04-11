<?php
/**
 * @file
 * cordis_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cordis_feature_taxonomy_default_vocabularies() {
  return array(
    'subprogramme_areas' => (object) array(
      'name' => 'Subprogramme areas',
      'machine_name' => 'subprogramme_areas',
      'description' => 'Cordis Subprogramme Area',
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

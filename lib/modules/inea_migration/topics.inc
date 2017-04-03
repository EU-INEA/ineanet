<?php

/**
 * @file
 * Handler to migrate topics from INEA website.
 */

/**
 * Topic migration class.
 */
class IneaMigration_TopicsMigration extends IneaBasicMigration {

  /**
   * Setup the field mappings between the source and destination.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    ini_set('auto_detect_line_endings', TRUE);
    $http_options = array();
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
      ),
    ), MigrateDestinationTerm::getKeySchema());

    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/inea/modules/content/topics.csv', array(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm('tags');

    $this->addFieldMapping('vocabulary_machine_name', 'catalog');
    $this->addFieldMapping('name', 'name');
  }

  /**
   * Prepare row to transform the data.
   */
  public function prepareRow(stdClass $row) {
    if ($row->catalog == 'Energy countries') {
      if ($row->name == 'Multi-country actions_E') {
        $name = 'Multi-country projects';
      }
      else {
        $name = drupal_substr($row->name, 0, -2);
      }
      $terms = taxonomy_get_term_by_name($name);
      if (!empty($terms)) {
        $term = reset($terms);
        $this->map->saveIDMapping($row, (array) $term->tid, MigrateMap::STATUS_IGNORED, MigrateMap::ROLLBACK_PRESERVE);
        return FALSE;
      }
      else {
        $row->name = $name;
        $row->catalog = 'countries';
      }
    }
    $vocab_machine_name = str_replace(' ', '_', drupal_strtolower($row->catalog));
    $vocab_machine_name = preg_replace('/[^A-Za-z0-9\_]/', '', $vocab_machine_name);
    if (!taxonomy_vocabulary_machine_name_load($vocab_machine_name)) {
      if (!field_info_field('field_content_migration_info')) {
        $old_id_field = array(
          'field_name' => 'field_content_migration_info',
          'type' => 'text',
          'module' => 'text',
          'active' => '1',
          'cardinality' => '1',
        );
        field_create_field($old_id_field);
      }
      if (!field_info_field('field_term_image')) {
        $term_image_field = array(
          'field_name' => 'field_term_image',
          'type' => 'image',
          'module' => 'image',
          'active' => '1',
          'cardinality' => '1',
        );
        field_create_field($term_image_field);
      }
      $vocab = (object) array(
        'name' => $row->catalog,
        'machine_name' => $vocab_machine_name,
      );
      taxonomy_vocabulary_save($vocab);

      $old_id_field_instance = array(
        'label' => t('Old ID'),
        'field_name' => 'field_content_migration_info',
        'widget' => array(
          'type' => 'text_textfield',
        ),
        'entity_type' => 'taxonomy_term',
        'bundle' => $vocab_machine_name,
      );
      field_create_instance($old_id_field_instance);
      $term_image_field_instance = array(
        'label' => t('Image'),
        'field_name' => 'field_term_image',
        'widget' => array(
          'type' => 'image',
        ),
        'entity_type' => 'taxonomy_term',
        'bundle' => $vocab_machine_name,
      );
      field_create_instance($term_image_field_instance);
    }
    $row->catalog = $vocab_machine_name;
  }

  /**
   * Prepare entity to be saved.
   */
  public function prepare($entity, stdClass $row) {
    $entity->field_content_migration_info = array(
      LANGUAGE_NONE => array(
        array(
          'value' => $row->id,
        ),
      ),
    );
  }

}

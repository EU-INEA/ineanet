<?php

/**
 * @file
 * Handler to migrate topics from INEA website.
 */

/**
 * Images migration class.
 */
class ImagesMigration extends IneaBasicMigration {

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
    ), MigrateDestinationNode::getKeySchema());

    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/inea/modules/content/images.csv', array(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

    $this->addFieldMapping('destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://');
    $this->addFieldMapping('destination_file', 'source');
    $this->addFieldMapping('value', 'source');
    $this->addFieldMapping('type')
      ->defaultValue('image');
    $this->addFieldMapping('source_dir')
      ->defaultValue(drupal_realpath(variable_get('file_default_scheme', 'public') . '://'));
    $this->addFieldMapping('file_replace')
      ->defaultValue(-1);
    $this->addFieldMapping('preserve_files')
      ->defaultValue(TRUE);
  }

}

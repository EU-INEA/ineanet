<?php

/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, you don't need to implement your hook in the .module file.
 */

/**
 * Implements hook_migrate_api().
 */
function inea_migration_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'INEA' => array(
        'title' => t('INEA Imports'),
      ),
    ),
    'migrations' => array(
      'Topics' => array(
        'class_name' => 'TopicsMigration',
        'groups' => 'INEA',
      ),
      'Images' => array(
        'class_name' => 'ImagesMigration',
        'groups' => 'INEA',
      ),
      'Projects' => array(
        'class_name' => 'ProjectsMigration',
        'groups' => 'INEA',
      ),
      'ISuccesses' => array(
        'class_name' => 'ImplementationSuccessesMigration',
        'groups' => 'INEA',
      ),
      'News' => array(
        'class_name' => 'NewsMigration',
        'groups' => 'INEA',
      ),
      'Events' => array(
        'class_name' => 'EventsMigration',
        'groups' => 'INEA',
      ),
    ),
  );
  return $api;
}

/**
 * Abstract class as a base for all our migration classes.
 */
abstract class IneaBasicMigration extends Migration {
  /**
   * Constructor function.
   */
  public function __construct($arguments) {
    // Always call the parent constructor first for basic setup.
    parent::__construct($arguments);
    // Avoid known line ending issue: "Invalid data value".
    ini_set('auto_detect_line_endings', TRUE);
  }
}

<?php

/**
 * @file
 *   A H2020 Project migration.
 */



/*
 * You must implement hook_migrate_api(), setting the API level to 2, for
 * your migration classes to be recognized by the Migrate module.
 */
function migrate_h2020_import_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'h2020' => array(
        'title' => t('h2020_project_import'),
      ),
    ),
      'migrations' => array(
          'h2020projects' => array(
              'class_name' => 'h2020importProjectMigration',
              'group_name' => 'h2020',
          )
      )
  );
  return $api;
}


/**
 * A migration that is reused for each source CSV file.
 */
class ProjectH2020 extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import H2020 Projects from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'start_date' => array('type' => 'varchar',
                           'length' => 8,
                           'not null' => TRUE,
                           'description' => 'Start date',
                          ),
          'corda' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Corda import',
                          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceCSV($arguments['source_file'], $this->csvcolumns(), array(), $this->fields());

    $this->destination = new MigrateDestinationNode('h2020_project_import');

    $this->addFieldMapping('title', 'title')
         ->description('See prepareRow().');
    $this->addFieldMapping('field_start_date', 'start_date');
    $this->addFieldMapping('field_park', 'park_id');
    $this->addFieldMapping('field_visiting_team', 'visiting_team');
    $this->addFieldMapping('field_home_team', 'home_team');
    $this->addFieldMapping('field_home_game_number', 'home_game_number');
    $this->addFieldMapping('field_home_score', 'home_score');
    $this->addFieldMapping('field_visiting_score', 'visiting_score');
    $this->addFieldMapping('field_outs', 'outs');
    $this->addFieldMapping('field_attendance', 'attendance');
    $this->addFieldMapping('field_duration', 'duration')
         ->defaultValue(NULL);
    $this->addFieldMapping('field_home_pitcher', 'home_pitcher');
    $this->addFieldMapping('field_visiting_pitcher', 'visiting_pitcher');
    $this->addFieldMapping('field_home_batters', 'home_batters')
         ->separator(',')
         ->description('See prepareRow().');
    $this->addFieldMapping('field_visiting_batters', 'visiting_batters')
         ->separator(',')
         ->description('See prepareRow().');
    for ($i=1; $i <= 9; $i++ ) {
      $this->addFieldMapping(NULL, "visiting_batter_$i")
           ->description('Not needed since we use the multi-value field: visiting_batters.');
      $this->addFieldMapping(NULL, "home_batter_$i")
           ->description('Not needed since we use the multi-value field: home_batters.');
    }
  }
}
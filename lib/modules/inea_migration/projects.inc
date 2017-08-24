<?php

/**
 * @file
 * Handler to migrate topics from INEA website.
 */

/**
 * Event migration class.
 */
class ProjectsMigration extends IneaBasicMigration {

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

    $this->dependencies[] = 'Topics';
    $this->dependencies[] = 'Images';

    $options = array(
      'header_rows' => 1,
      'embedded_newlines' => 1,
      'escape' => ' ',
    );
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/inea/modules/content/projects.csv', array(), $options);

    $this->destination = new MigrateDestinationNode('project', array('text_format' => 'full_html'));

    $this->addFieldMapping('uid')
      ->defaultValue(1);
    $this->addFieldMapping('language')
      ->defaultValue('en');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_content_migration_info', 'id');
    $this->addFieldMapping('field_project_summary', 'summary');
    $this->addFieldMapping('field_project_description', 'body');
    $this->addFieldMapping('field_project_map', 'image')
      ->sourceMigration('Images');
    $this->addFieldMapping('field_project_map:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_project_map:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_project_other_info', 'other_info');
    $this->addFieldMapping('field_project_tags', 'topics')
      ->separator(',')
      ->sourceMigration('Topics');
  }

  /**
   * Prepare row to transform the data.
   */
  public function prepareRow(stdClass $row) {
    $contents = explode("---", $row->contents);
    $row->title = trim(strip_tags($contents[0]));
    $row->summary = strip_tags($contents[1]);
    if (count($contents) > 7) {
      $row->body = $contents[3] . $contents[5];
    }
    else {
      $row->body = $contents[3];
    }
    $row->body = str_replace(' "', '"', $row->body);
    $row->other_info = str_replace(' "', '"', $contents[4]);
  }

  /**
   * Prepare entity to be saved.
   */
  public function prepare($entity, stdClass $row) {
    $programme_map = array(
      '112470000000536' => 'TEN-T Projects',
      '112470114528950' => 'CEF-Energy',
    );
    $programme = $programme_map[$row->project_type];

    $term = reset(taxonomy_get_term_by_name($programme));
    if (!empty($term)) {
      $tid = array('tid' => $term->tid);
      $entity->field_tag_programme[LANGUAGE_NONE][] = $tid;
    }

    if (!empty($entity->field_project_tags)) {
      if (!is_array($entity->field_project_tags)) {
        $entity->field_project_tags = array($entity->field_project_tags);
      }
      foreach ($entity->field_project_tags as $tid) {
        $term = taxonomy_term_load($tid);
        $vocabulary = taxonomy_vocabulary_load($term->vid);
        switch ($vocabulary->machine_name) {
          case 'country':
            $entity->field_tag_country[LANGUAGE_NONE][] = array('tid' => $tid);
            break;

          case 'transport_mode':
            $entity->field_tag_transport_mode[LANGUAGE_NONE][] = array('tid' => $tid);
            break;

          case 'priority_project':
            $entity->field_tag_priority_projects[LANGUAGE_NONE][] = array('tid' => $tid);
            break;

          case 'energy_10_pci':
            $entity->field_tag_energy_10_pci[LANGUAGE_NONE][] = array('tid' => $tid);
            break;

          case 'energy_type':
            $entity->field_tag_energy_type[LANGUAGE_NONE][] = array('tid' => $tid);
            break;

          case 'type':
            $entity->field_tag_type_of_project[LANGUAGE_NONE][] = array('tid' => $tid);
            break;
        }
      }
      unset($entity->field_project_tags);
    }
  }

}

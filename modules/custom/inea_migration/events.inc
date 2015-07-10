<?php

/**
 * @file
 * Handler to migrate events from INEA website.
 */

/**
 * Event migration class.
 */
class EventsMigration extends IneaBasicMigration {
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

    $options = array(
      'header_rows' => 1,
      'embedded_newlines' => 1,
      'escape' => ' ',
    );
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/inea/modules/content/events.csv', array(), $options);

    $this->destination = new MigrateDestinationNode('inea_events', array('text_format' => 'full_html'));

    $this->addFieldMapping('uid')
      ->defaultValue(1);
    $this->addFieldMapping('language')
      ->defaultValue('en');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('field_content_migration_info', 'id');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'description');
    $this->addFieldMapping('field_content_tags', 'topics')
      ->separator(',')
      ->sourceMigration('Topics');
  }

  /**
   * Prepare row to transform the data.
   */
  public function prepareRow(stdClass $row) {
    if (strrpos($row->title, 'Registration', -strlen($haystack)) !== FALSE ||
      strrpos($row->title, 'Thank', -strlen($haystack)) !== FALSE) {
      return FALSE;
    }
    $content = explode("---", $row->content);
    $row->body = $row->other_info = str_replace(' "', '"', $content[0]);
  }

  /**
   * Prepare entity to be saved.
   */
  public function prepare($entity, stdClass $row) {

    if (!empty($row->gallery)) {
      $files = file_scan_directory(variable_get('file_default_scheme', 'public') . '://images' . $row->gallery, '/.*\.(jpg|png|gif)$/', array('recurse' => FALSE));
      $fids = array();
      foreach ($files as $file) {
        $fid = _inea_migration_create_file($file, $entity->uid);
        if ($fid) {
          $fids[] = array('fid' => $fid);
        }
      }
      $entity->field_inea_event_picture_ga['und'] = $fids;
    }
    $parent_nid = _inea_migration_load_node_by_old_id('112470000000120');
    $mlids = _inea_migration_get_mlid('node/' . $parent_nid);
  }

}

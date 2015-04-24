<?php

/**
 * @file
 * Handler to migrate topics from INEA website
 */

class ImplementationSuccessesMigration extends IneaBasicMigration {
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

    $this->dependencies[] = 'Images';

    $options = array(
      'header_rows' => 1,
      'embedded_newlines' => 1,
      'escape' => ' ',
    );
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/' . drupal_get_path('module', 'inea_migration') . '/sources/successes.csv', array(), $options);

    $this->destination = new MigrateDestinationNode('implementation_success', array('text_format' => 'full_html'));

    $this->addFieldMapping('uid')
      ->defaultValue(1);
    $this->addFieldMapping('language')
      ->defaultValue('en');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_content_migration_info', 'id');
    $this->addFieldMapping('field_is_summary', 'summary');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('field_is_map', 'image')
      ->sourceMigration('Images');
    $this->addFieldMapping('field_is_map:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_is_other_info', 'other_info');
  }

  /**
   * Prepare row to transform the data.
   */
  public function prepareRow(stdClass $row) {
    if ($row->image == '\N') {
      return FALSE;
    }
    $contents = explode("---", $row->contents);

    $row->summary = $contents[2];
    $row->body = $contents[4];
    $row->other_info = $contents[6];
  }

  /**
   * Prepare entity to be saved.
   */
  public function prepare($entity, stdClass $row) {
    if (!empty($row->gallery)) {
      $files = file_scan_directory(variable_get('file_default_scheme', 'public') . '://' . $row->gallery, '/.*\.(jpg|png|gif)$/', array('recurse' => FALSE));
      $fids = array();
      foreach ($files as $file) {
        $fids[] = array('fid' => _inea_migration_create_file($file, $entity->uid));
      }
      $entity->field_is_picture_gallery['und'] = $fids;
    }
    $parent_nid = _inea_migration_load_node_by_old_id('112470000394799');
    if ($parent_nid) {
      $menu = array();
      $menu['enabled'] = TRUE;
      $menu['link_title'] = $entity->title;
      $menu['menu_name'] = 'main-menu';
      $menu['plid'] = _inea_migration_get_node_mlid($parent_nid, 'main-menu');
      $entity->menu = $menu;
    }
  }
}

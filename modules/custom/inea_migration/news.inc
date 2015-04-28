<?php

/**
 * @file
 * Handler to migrate topics from INEA website
 */

class NewsMigration extends IneaBasicMigration {

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
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/inea/modules/content/news.csv', array(), $options);

    $this->destination = new MigrateDestinationNode('news', array('text_format' => 'full_html'));

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
    $contents = explode("---", $row->contents);
    $row->body = $contents[0];
  }

  /**
   * Prepare entity to be saved.
   */
  public function prepare($entity, stdClass $row) {
    $news_type_map = array(
      "/images/news/news_cef.png" => "CEF",
      "/images/news/news_h2020.png" => "Horizon 2020",
      "/images/news/news_marco_polo.png" => "Marco Polo",
      "/images/news/news_tent.png" => "TEN-T Projects",
      "/images/news/news_general.png" => "General",
    );
    if (!empty($row->image)) {
      $news_type = $news_type_map[$row->image];

    }
    if (empty($news_type)) {
      $news_type = 'General';
    }
    $term = reset(taxonomy_get_term_by_name($news_type));
    $tid = array('tid' => $term->tid);
    $entity->field_news_type['und'][] = $tid;
    if (!empty($row->gallery)) {
      $files = file_scan_directory(variable_get('file_default_scheme', 'public') . '://' . $row->gallery, '/.*\.(jpg|png|gif)$/', array('recurse' => FALSE));
      $fids = array();
      foreach ($files as $file) {
        $fids[] = array('fid' => _inea_migration_create_file($file, $entity->uid));
      }
      $entity->field_news_picture_gallery['und'] = $fids;
    }
  }
}

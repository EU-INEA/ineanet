<?php
/**
 * @file
 * h2020_project_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function h2020_project_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'h2020_projects';
  $feeds_importer->config = array(
    'name' => 'H2020 Projects',
    'description' => 'Import H2020 projects from Lucas\' spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
        'encoding' => 'UTF-8',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Project Number',
            'target' => 'title',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Project Number',
            'target' => 'field_inea_h2020_project_referen',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Project Title',
            'target' => 'field_inea_h2020_project_descrip',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Project Call Id',
            'target' => 'field_inea_h2020_call_for_propos',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Project Topic Code',
            'target' => 'field_inea_h2020_topic',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Project Acronym',
            'target' => 'field_inea_h2020_acronym',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Project Start Date',
            'target' => 'field_inea_h2020_duration:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Project End Date',
            'target' => 'field_inea_h2020_duration:end',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Project Total Costs',
            'target' => 'field_inea_h2020_total_costs',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Project Requested EC Contribution',
            'target' => 'field_inea_h2020_eu_contribution',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Project TOA',
            'target' => 'field_inea_h2020_funding_scheme',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Coordinator',
            'target' => 'field_inea_h2020_coordinator',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Short Description',
            'target' => 'field_inea_h2020_short_summary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Cordis Link',
            'target' => 'field_inea_h2020_cordis_url:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'h2020_project',
        'insert_new' => '1',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['h2020_projects'] = $feeds_importer;

  return $export;
}

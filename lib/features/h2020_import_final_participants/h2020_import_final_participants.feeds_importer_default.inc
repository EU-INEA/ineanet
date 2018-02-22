<?php

/**
 * @file
 * h2020_import_final_participants.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function h2020_import_final_participants_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'h2020_import_final_participants';
  $feeds_importer->config = array(
    'name' => 'H2020 Import Final Participants',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'delete_uploaded_file' => FALSE,
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
        'author' => '48',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Project Acronym',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Participant Short Name',
            'target' => 'field_inea_participant',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Participant LE Country Code',
            'target' => 'field_inea_participant_country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Participant Requested EC Contribution',
            'target' => 'field_inea_participant_requested',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'h2020_project',
        'insert_new' => '0',
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
  $export['h2020_import_final_participants'] = $feeds_importer;

  return $export;
}

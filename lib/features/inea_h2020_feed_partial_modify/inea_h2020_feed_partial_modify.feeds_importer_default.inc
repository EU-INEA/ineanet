<?php

/**
 * @file
 * inea_h2020_feed_partial_modify.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function inea_h2020_feed_partial_modify_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'h2020_fix_currency_fields';
  $feeds_importer->config = array(
    'name' => 'H2020 fix currency fields',
    'description' => 'Get rid of coding strangeness around euro sign',
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
            'source' => 'Project Acronym',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Project Total Costs',
            'target' => 'field_inea_h2020_total_costs',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Project Requested EC Contribution',
            'target' => 'field_inea_h2020_eu_contribution',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'h2020_project',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['h2020_fix_currency_fields'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'h2020_taxterm_and_description_field';
  $feeds_importer->config = array(
    'name' => 'H2020 Taxterm and description field',
    'description' => 'Just import 2 fields from Elina\'s spreadsheets.',
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
            'source' => 'Project Acronym',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Project Summary',
            'target' => 'field_inea_h2020_short_summary',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Tax Term',
            'target' => 'field_inea_h2020_area_term',
            'term_search' => '0',
            'autocreate' => 1,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'h2020_project',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['h2020_taxterm_and_description_field'] = $feeds_importer;

  return $export;
}

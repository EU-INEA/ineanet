<?php
/**
 * @file
 * inea_cef_project_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function inea_cef_project_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'inea_cef_project_importer';
  $feeds_importer->config = array(
    'name' => 'INEA CEF Project Importer',
    'description' => 'Import CEF projects into website',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
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
            'source' => 'CEF Action Code',
            'target' => 'field_cef_action_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'CEF Action Title',
            'target' => 'field_cef_action_title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'CEF Action Description',
            'target' => 'field_cef_action_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'CEF Action Sector',
            'target' => 'field_cef_action_sector',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'CEF Energy Sector',
            'target' => 'field_inea_cef_energy_sector',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'CEF Transport Mode',
            'target' => 'field_inea_cef_transport_mode',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'CEF Smart Grid',
            'target' => 'field_inea_cef_smart_grid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'CEF PCI',
            'target' => 'field_inea_cef_pci',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'CEF corridor',
            'target' => 'field_corridor',
            'term_search' => '0',
            'autocreate' => 0,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Member State',
            'target' => 'field_tag_country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'CEF Start Date',
            'target' => 'field_inea_cef_start_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'CEF End Date',
            'target' => 'field_inea_cef_start_date:end',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'CEF Project Cost',
            'target' => 'field_inea_cef_project_cost',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'CEF EU Contribution',
            'target' => 'field_inea_cef_eu_contribution',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'CEF Support percentage',
            'target' => 'field_inea_cef_support_percent',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'CEF Coordinator',
            'target' => 'field_inea_cef_coordinator',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'CEF Beneficiary',
            'target' => 'field_inea_cef_beneficiary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'CEF Action Status',
            'target' => 'field_inea_cef_action_status',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'cef_project',
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
  $export['inea_cef_project_importer'] = $feeds_importer;

  return $export;
}

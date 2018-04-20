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
        'allowed_extensions' => 'txt csv tsv xml opml xlsx ods',
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
        'delete_uploaded_file' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
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
            'source' => 'ACTION_TITLE',
            'target' => 'title',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'ACTION_CODE',
            'target' => 'field_cef_action_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'ACTION_DESCR',
            'target' => 'field_project_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'ACTION_SECTOR',
            'target' => 'field_inea_cef_action_sector2',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'PROGRAMME_TEXT',
            'target' => 'field_inea_programme_text',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'CALL_YEAR',
            'target' => 'field_cef_call_year',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'ACTION_STATUS',
            'target' => 'field_inea_cef_project_status',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'ENERGY_SECTOR',
            'target' => 'field_cef_energy_sector',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'PCI',
            'target' => 'field_cef_pci',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'ENER_CORRIDOR',
            'target' => 'field_inea_cef_ener_corridor',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'TRANS_CORRIDOR',
            'target' => 'field_inea_cef_trans_corridor',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'TRANSPORT_MODE',
            'target' => 'field_inea_cef_transport_mode',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'HORIZONTAL_PRIORITY',
            'target' => 'field_inea_cef_horizontal_priori',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'MS',
            'target' => 'field_inea_cef_member_state',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'DSI',
            'target' => 'field_inea_cef_dsi',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          15 => array(
            'source' => 'START_DATE',
            'target' => 'field_inea_cef_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'END_DATE',
            'target' => 'field_inea_cef_date:end',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'COST',
            'target' => 'field_cef_project_cost',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'EU_CONTRIB',
            'target' => 'field_inea_cef_eu_contrib',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'SUPPORT_PERC',
            'target' => 'field_inea_cef_eu_percent',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'COORDINATOR',
            'target' => 'field_cef_coordinator',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'BENEFICIARIES',
            'target' => 'field_inea_cef_participants',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'ENERBENEFICIARIES',
            'target' => 'field_inea_ener_beneficiaries',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'BENE_CTRY',
            'target' => 'field_cef_participant_country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'OK_TO_PUBLISH',
            'target' => 'field_inea_cef_publish',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'IMAGE',
            'target' => 'field_project_map:uri',
            'file_exists' => '1',
            'language' => 'und',
          ),
          26 => array(
            'source' => 'IMAGE',
            'target' => 'field_inea_cef_map:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'EXEC_SUM',
            'target' => 'field_cef_executive_summary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'ADDITIONAL_INFO',
            'target' => 'field_cef_additional_info',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'inea_cef_project',
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
  $export['inea_cef_project_importer'] = $feeds_importer;

  return $export;
}

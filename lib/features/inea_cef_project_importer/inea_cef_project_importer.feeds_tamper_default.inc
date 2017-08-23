<?php
/**
 * @file
 * inea_cef_project_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function inea_cef_project_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-action_sector-sprintf';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'ACTION_SECTOR';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '%s',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Format string';
  $export['inea_cef_project_importer-action_sector-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-beneficiaries-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'BENEFICIARIES';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-beneficiaries-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-end_date-strtotime';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'END_DATE';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['inea_cef_project_importer-end_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-ms-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'MS';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-ms-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-pci-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'PCI';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-pci-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-start_date-strtotime';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'START_DATE';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['inea_cef_project_importer-start_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-trans_corridor-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'TRANS_CORRIDOR';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-trans_corridor-explode'] = $feeds_tamper;

  return $export;
}

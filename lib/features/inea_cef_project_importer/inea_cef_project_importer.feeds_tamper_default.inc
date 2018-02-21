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
  $feeds_tamper->id = 'inea_cef_project_importer-action_title-required';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'ACTION_TITLE';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['inea_cef_project_importer-action_title-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-bene_ctry-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'BENE_CTRY';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-bene_ctry-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-beneficiaries-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'BENEFICIARIES';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-beneficiaries-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-coordinator-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'COORDINATOR';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-coordinator-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-cost-array_filter';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'COST';
  $feeds_tamper->plugin_id = 'array_filter';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Filter empty items';
  $export['inea_cef_project_importer-cost-array_filter'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-cost-number_format';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'COST';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Format a number';
  $export['inea_cef_project_importer-cost-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-cost-rewrite';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'COST';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '€[cost]',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Rewrite';
  $export['inea_cef_project_importer-cost-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-cost-sprintf';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'COST';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '%s',
  );
  $feeds_tamper->weight = 6;
  $feeds_tamper->description = 'Format string';
  $export['inea_cef_project_importer-cost-sprintf'] = $feeds_tamper;

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
  $feeds_tamper->id = 'inea_cef_project_importer-enerbeneficiaries-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'ENERBENEFICIARIES';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['inea_cef_project_importer-enerbeneficiaries-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-eu_contrib-number_format';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'EU_CONTRIB';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Format a number';
  $export['inea_cef_project_importer-eu_contrib-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-eu_contrib-rewrite';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'EU_CONTRIB';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '€[eu_contrib]',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Rewrite with €';
  $export['inea_cef_project_importer-eu_contrib-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-eu_contrib-sprintf';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'EU_CONTRIB';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '%s',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format string';
  $export['inea_cef_project_importer-eu_contrib-sprintf'] = $feeds_tamper;

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
  $feeds_tamper->id = 'inea_cef_project_importer-ms-rewrite';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'MS';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[ms],',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite';
  $export['inea_cef_project_importer-ms-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-pci-explode';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'PCI';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
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

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'inea_cef_project_importer-trans_corridor-str_pad';
  $feeds_tamper->importer = 'inea_cef_project_importer';
  $feeds_tamper->source = 'TRANS_CORRIDOR';
  $feeds_tamper->plugin_id = 'str_pad';
  $feeds_tamper->settings = array(
    'pad_length' => 60,
    'pad_string' => '',
    'pad_type' => '1',
    'real_pad_string' => ' ',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Pad a string';
  $export['inea_cef_project_importer-trans_corridor-str_pad'] = $feeds_tamper;

  return $export;
}

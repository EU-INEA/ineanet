<?php

/**
 * @file
 * inea_h2020_project_import_final.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function inea_h2020_project_import_final_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-coordinator-array_filter';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Coordinator';
  $feeds_tamper->plugin_id = 'array_filter';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Filter empty items';
  $export['h2020_import_final-coordinator-array_filter'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-participant_le_country_code-explode';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Participant LE Country Code';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['h2020_import_final-participant_le_country_code-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-participant_requested_ec_contribution-explode';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Participant Requested EC Contribution';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['h2020_import_final-participant_requested_ec_contribution-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-participant_requested_ec_contribution-number_format';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Participant Requested EC Contribution';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format a number';
  $export['h2020_import_final-participant_requested_ec_contribution-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-participant_requested_ec_contribution-sprintf';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Participant Requested EC Contribution';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '€%s',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Format string';
  $export['h2020_import_final-participant_requested_ec_contribution-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-participant_short_name-explode';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Participant Short Name';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['h2020_import_final-participant_short_name-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-project_end_date-strtotime2';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Project End date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['h2020_import_final-project_end_date-strtotime2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-project_requested_ec_contribution-number_format';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Project Requested EC Contribution';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format a number';
  $export['h2020_import_final-project_requested_ec_contribution-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-project_requested_ec_contribution-sprintf';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Project Requested EC Contribution';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '€%s',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Format string';
  $export['h2020_import_final-project_requested_ec_contribution-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-project_start_date-strtotime';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Project Start Date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['h2020_import_final-project_start_date-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-project_total_costs-number_format';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Project Total Costs';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format a number';
  $export['h2020_import_final-project_total_costs-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-project_total_costs-sprintf';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Project Total Costs';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '€%s',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Format string';
  $export['h2020_import_final-project_total_costs-sprintf'] = $feeds_tamper;

  return $export;
}

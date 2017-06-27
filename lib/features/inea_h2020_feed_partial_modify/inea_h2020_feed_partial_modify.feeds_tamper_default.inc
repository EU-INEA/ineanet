<?php

/**
 * @file
 * inea_h2020_feed_partial_modify.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function inea_h2020_feed_partial_modify_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_fix_currency_fields-project_requested_ec_contribution-number_format';
  $feeds_tamper->importer = 'h2020_fix_currency_fields';
  $feeds_tamper->source = 'Project Requested EC Contribution';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format a number';
  $export['h2020_fix_currency_fields-project_requested_ec_contribution-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_fix_currency_fields-project_requested_ec_contribution-sprintf';
  $feeds_tamper->importer = 'h2020_fix_currency_fields';
  $feeds_tamper->source = 'Project Requested EC Contribution';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '€%s',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Format string';
  $export['h2020_fix_currency_fields-project_requested_ec_contribution-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_fix_currency_fields-project_total_costs-number_format';
  $feeds_tamper->importer = 'h2020_fix_currency_fields';
  $feeds_tamper->source = 'Project Total Costs';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format a number';
  $export['h2020_fix_currency_fields-project_total_costs-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_fix_currency_fields-project_total_costs-sprintf';
  $feeds_tamper->importer = 'h2020_fix_currency_fields';
  $feeds_tamper->source = 'Project Total Costs';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '€%s',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Format string';
  $export['h2020_fix_currency_fields-project_total_costs-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_taxterm_and_description_field-project_summary-truncate_text';
  $feeds_tamper->importer = 'h2020_taxterm_and_description_field';
  $feeds_tamper->source = 'Project Summary';
  $feeds_tamper->plugin_id = 'truncate_text';
  $feeds_tamper->settings = array(
    'num_char' => '255',
    'ellipses' => 1,
    'wordsafe' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Truncate';
  $export['h2020_taxterm_and_description_field-project_summary-truncate_text'] = $feeds_tamper;

  return $export;
}

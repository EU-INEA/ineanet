<?php
/**
 * @file
 * h2020_import_final_participants.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function h2020_import_final_participants_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final_participants-participant_le_country_code-explode';
  $feeds_tamper->importer = 'h2020_import_final_participants';
  $feeds_tamper->source = 'Participant LE Country Code';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['h2020_import_final_participants-participant_le_country_code-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final_participants-participant_requested_ec_contribution-explode';
  $feeds_tamper->importer = 'h2020_import_final_participants';
  $feeds_tamper->source = 'Participant Requested EC Contribution';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['h2020_import_final_participants-participant_requested_ec_contribution-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final_participants-participant_requested_ec_contribution-number_format';
  $feeds_tamper->importer = 'h2020_import_final_participants';
  $feeds_tamper->source = 'Participant Requested EC Contribution';
  $feeds_tamper->plugin_id = 'number_format';
  $feeds_tamper->settings = array(
    'decimals' => 0,
    'dec_point' => '.',
    'thousands_sep' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format a number';
  $export['h2020_import_final_participants-participant_requested_ec_contribution-number_format'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final_participants-participant_requested_ec_contribution-sprintf';
  $feeds_tamper->importer = 'h2020_import_final_participants';
  $feeds_tamper->source = 'Participant Requested EC Contribution';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '%s',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Format string';
  $export['h2020_import_final_participants-participant_requested_ec_contribution-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final_participants-participant_short_name-explode';
  $feeds_tamper->importer = 'h2020_import_final_participants';
  $feeds_tamper->source = 'Participant Short Name';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['h2020_import_final_participants-participant_short_name-explode'] = $feeds_tamper;

  return $export;
}

<?php
/**
 * @file
 * h2020_import_final.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function h2020_import_final_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'h2020_import_final-coordinator-array_filter';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Coordinator';
  $feeds_tamper->plugin_id = 'array_filter';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Filter empty items';
  $export['h2020_import_final-coordinator-array_filter'] = $feeds_tamper;

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
  $feeds_tamper->id = 'h2020_import_final-project_start_date-strtotime';
  $feeds_tamper->importer = 'h2020_import_final';
  $feeds_tamper->source = 'Project Start Date';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['h2020_import_final-project_start_date-strtotime'] = $feeds_tamper;

  return $export;
}

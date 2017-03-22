<?php
/**
 * @file
 * h2020_import_final_participants.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function h2020_import_final_participants_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

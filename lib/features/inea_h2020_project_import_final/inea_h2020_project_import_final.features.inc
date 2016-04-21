<?php
/**
 * @file
 * inea_h2020_project_import_final.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function inea_h2020_project_import_final_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function inea_h2020_project_import_final_node_info() {
  $items = array(
    'h2020_project' => array(
      'name' => t('H2020 Project'),
      'base' => 'node_content',
      'description' => t('H2020 Project content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

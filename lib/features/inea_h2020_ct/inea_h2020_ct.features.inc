<?php
/**
 * @file
 * inea_h2020_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function inea_h2020_ct_ctools_plugin_api($module = NULL, $api = NULL) {
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
function inea_h2020_ct_node_info() {
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
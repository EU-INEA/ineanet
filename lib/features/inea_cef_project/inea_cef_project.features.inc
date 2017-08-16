<?php
/**
 * @file
 * inea_cef_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function inea_cef_project_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function inea_cef_project_node_info() {
  $items = array(
    'inea_cef_project' => array(
      'name' => t('INEA CEF Project'),
      'base' => 'node_content',
      'description' => t('CEF Project Content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

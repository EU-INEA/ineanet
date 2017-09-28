<?php
/**
 * @file
 * inea_cef_project_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function inea_cef_project_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function inea_cef_project_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function inea_cef_project_content_type_node_info() {
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

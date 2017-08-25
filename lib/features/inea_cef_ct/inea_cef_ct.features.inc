<?php
/**
 * @file
 * inea_cef_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function inea_cef_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function inea_cef_ct_node_info() {
  $items = array(
    'cef_project' => array(
      'name' => t('CEF Project'),
      'base' => 'node_content',
      'description' => t('A CEF project or Action - applicable to Sectors ENER/TRAN/SYNERGY.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

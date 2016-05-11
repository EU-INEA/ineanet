<?php
/**
 * @file
 * cordis_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cordis_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cordis_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cordis_feature_node_info() {
  $items = array(
    'cordis_importer' => array(
      'name' => t('Cordis Importer'),
      'base' => 'node_content',
      'description' => t('Stores information about each Cordis feed URL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'programmes_and_projects' => array(
      'name' => t('CORDIS Project Selection'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('CORDIS Project'),
      'base' => 'node_content',
      'description' => t('Project from CORDIS'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

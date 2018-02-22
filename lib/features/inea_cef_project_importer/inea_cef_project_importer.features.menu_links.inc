<?php

/**
 * @file
 * inea_cef_project_importer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function inea_cef_project_importer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_:admin/structure/taxonomy/%.
  $menu_links['management_:admin/structure/taxonomy/%'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy/%',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => '',
    'options' => array(
      'identifier' => 'management_:admin/structure/taxonomy/%',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'management_taxonomy:admin/structure/taxonomy',
  );

  return $menu_links;
}

<?php
/**
 * @file
 * inea_cef_project_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function inea_cef_project_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cef_tags|node|inea_cef_project|form';
  $field_group->group_name = 'group_cef_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'inea_cef_project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cef_terms';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '13',
    'children' => array(
      0 => 'field_cef_energy_sector',
      1 => 'field_cef_pci',
      2 => 'field_inea_cef_action_sector2',
      3 => 'field_inea_cef_dsi',
      4 => 'field_inea_cef_ener_corridor',
      5 => 'field_inea_cef_member_state',
      6 => 'field_inea_cef_project_status',
      7 => 'field_inea_cef_trans_corridor',
      8 => 'field_tag_transport_mode',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cef_tags|node|inea_cef_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cef_terms|node|inea_cef_project|form';
  $field_group->group_name = 'group_cef_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'inea_cef_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CEF Project fields',
    'weight' => '6',
    'children' => array(
      0 => 'group_cef_tags',
      1 => 'group_proj_top_1',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cef_terms|node|inea_cef_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_proj_top_1|node|inea_cef_project|form';
  $field_group->group_name = 'group_proj_top_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'inea_cef_project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cef_terms';
  $field_group->data = array(
    'label' => 'Diverse fields',
    'weight' => '12',
    'children' => array(
      0 => 'field_cef_3rd_cntry',
      1 => 'field_cef_coordinator',
      2 => 'field_cef_project_cost',
      3 => 'field_inea_cef_date',
      4 => 'field_inea_cef_eu_contrib',
      5 => 'field_inea_cef_eu_percent',
      6 => 'field_inea_cef_participants',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_proj_top_1|node|inea_cef_project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('CEF Project fields');
  t('Diverse fields');
  t('Tags');

  return $field_groups;
}
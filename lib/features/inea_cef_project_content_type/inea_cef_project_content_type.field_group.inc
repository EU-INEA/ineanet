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
      0 => 'field_inea_cef_action_sector2',
      1 => 'field_tag_transport_mode',
      2 => 'field_inea_cef_trans_corridor',
      3 => 'field_inea_cef_member_state',
      4 => 'field_inea_cef_project_status',
      5 => 'field_inea_cef_ener_corridor',
      6 => 'field_inea_cef_dsi',
      7 => 'field_cef_energy_sector',
      8 => 'field_cef_pci',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-cef-tags field-group-htabs',
        'id' => '',
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
    'weight' => '5',
    'children' => array(
      0 => 'group_proj_top_1',
      1 => 'group_cef_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'CEF Project fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cef-terms field-group-fieldset',
        'description' => 'All the tags associated with this Action/Project',
      ),
      'formatter' => 'collapsible',
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
      0 => 'field_inea_cef_date',
      1 => 'field_cef_project_cost',
      2 => 'field_inea_cef_eu_contrib',
      3 => 'field_inea_cef_eu_percent',
      4 => 'field_cef_coordinator',
      5 => 'field_inea_cef_participants',
      6 => 'field_cef_3rd_cntry',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Diverse fields',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-proj-top-1 field-group-htabs',
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

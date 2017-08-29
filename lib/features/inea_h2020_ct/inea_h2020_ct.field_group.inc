<?php
/**
 * @file
 * inea_h2020_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function inea_h2020_ct_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inea_h2020_abstract|node|h2020_project|form';
  $field_group->group_name = 'group_inea_h2020_abstract';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_inea_h2020_import';
  $field_group->data = array(
    'label' => 'Text Fields',
    'weight' => '23',
    'children' => array(
      0 => 'field_inea_h2020_abstract',
      1 => 'field_inea_h2020_short_summary',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Text Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-inea-h2020-abstract field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_inea_h2020_abstract|node|h2020_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inea_h2020_financials|node|h2020_project|form';
  $field_group->group_name = 'group_inea_h2020_financials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_inea_h2020_import';
  $field_group->data = array(
    'label' => 'Financials',
    'weight' => '22',
    'children' => array(
      0 => 'field_inea_h2020_eu_contribution',
      1 => 'field_inea_h2020_funding_scheme',
      2 => 'field_inea_h2020_total_costs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Financials',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-inea-h2020-financials field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_inea_h2020_financials|node|h2020_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inea_h2020_import|node|h2020_project|form';
  $field_group->group_name = 'group_inea_h2020_import';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Automatically Imported fields',
    'weight' => '8',
    'children' => array(
      0 => 'group_inea_h2020_tags',
      1 => 'group_inea_h2020_part_info',
      2 => 'group_inea_h2020_financials',
      3 => 'group_inea_h2020_abstract',
      4 => 'group_inea_h2020_other',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Automatically Imported fields',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_inea_h2020_import|node|h2020_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inea_h2020_other|node|h2020_project|form';
  $field_group->group_name = 'group_inea_h2020_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_inea_h2020_import';
  $field_group->data = array(
    'label' => 'Other Imported fields',
    'weight' => '24',
    'children' => array(
      0 => 'field_inea_h2020_acronym',
      1 => 'field_inea_h2020_call_for_propos',
      2 => 'field_inea_h2020_coordinator',
      3 => 'field_inea_h2020_cordis_url',
      4 => 'field_inea_h2020_duration',
      5 => 'field_inea_h2020_topic',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Other Imported fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-inea-h2020-other field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_inea_h2020_other|node|h2020_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inea_h2020_part_info|node|h2020_project|form';
  $field_group->group_name = 'group_inea_h2020_part_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_inea_h2020_import';
  $field_group->data = array(
    'label' => 'Participants Info',
    'weight' => '21',
    'children' => array(
      0 => 'field_inea_participant',
      1 => 'field_inea_participant_country',
      2 => 'field_inea_participant_requested',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Participants Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-inea-h2020-part-info field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_inea_h2020_part_info|node|h2020_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inea_h2020_tags|node|h2020_project|form';
  $field_group->group_name = 'group_inea_h2020_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_inea_h2020_import';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '25',
    'children' => array(
      0 => 'field_inea_h2020_project_field',
      1 => 'field_inea_h2020_programme',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inea-h2020-tags field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_inea_h2020_tags|node|h2020_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants_display|node|h2020_project|default';
  $field_group->group_name = 'group_participants_display';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Participants',
    'weight' => '15',
    'children' => array(
      0 => 'field_inea_participant',
      1 => 'field_inea_participant_country',
      2 => 'field_inea_participant_requested',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Participants',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-participants-display field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_participants_display|node|h2020_project|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Automatically Imported fields');
  t('Financials');
  t('Other Imported fields');
  t('Participants');
  t('Participants Info');
  t('Tags');
  t('Text Fields');

  return $field_groups;
}

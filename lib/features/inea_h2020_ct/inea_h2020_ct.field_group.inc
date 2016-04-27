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
  $field_group->identifier = 'group_participants|node|h2020_project|form';
  $field_group->group_name = 'group_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'h2020_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Participants',
    'weight' => '27',
    'children' => array(
      0 => 'field_inea_participant_country',
      1 => 'field_inea_participant_requested',
      2 => 'field_inea_participant',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Participants',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_participants|node|h2020_project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Participants');

  return $field_groups;
}

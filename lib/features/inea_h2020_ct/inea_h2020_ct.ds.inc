<?php
/**
 * @file
 * inea_h2020_ct.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function inea_h2020_ct_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|h2020_project|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'h2020_project';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_inea_h2020_acronym',
        1 => 'field_inea_h2020_project_descrip',
        2 => 'field_inea_h2020_short_summary',
        3 => 'field_inea_h2020_project_referen',
        4 => 'field_inea_h2020_call_for_propos',
        5 => 'field_inea_h2020_topic',
        6 => 'field_inea_h2020_duration',
        7 => 'field_inea_h2020_total_costs',
        8 => 'field_inea_h2020_eu_contribution',
        9 => 'field_inea_h2020_abstract',
      ),
      'right' => array(
        10 => 'field_inea_h2020_image',
        11 => 'field_inea_h2020_funding_scheme',
        12 => 'field_inea_h2020_coordinator',
        13 => 'field_inea_h2020_url',
        14 => 'field_inea_h2020_cordis_url',
        15 => 'field_inea_participant',
        16 => 'field_inea_participant_country',
        17 => 'field_inea_participant_requested',
      ),
    ),
    'fields' => array(
      'field_inea_h2020_acronym' => 'left',
      'field_inea_h2020_project_descrip' => 'left',
      'field_inea_h2020_short_summary' => 'left',
      'field_inea_h2020_project_referen' => 'left',
      'field_inea_h2020_call_for_propos' => 'left',
      'field_inea_h2020_topic' => 'left',
      'field_inea_h2020_duration' => 'left',
      'field_inea_h2020_total_costs' => 'left',
      'field_inea_h2020_eu_contribution' => 'left',
      'field_inea_h2020_abstract' => 'left',
      'field_inea_h2020_image' => 'right',
      'field_inea_h2020_funding_scheme' => 'right',
      'field_inea_h2020_coordinator' => 'right',
      'field_inea_h2020_url' => 'right',
      'field_inea_h2020_cordis_url' => 'right',
      'field_inea_participant' => 'right',
      'field_inea_participant_country' => 'right',
      'field_inea_participant_requested' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|h2020_project|default'] = $ds_layout;

  return $export;
}

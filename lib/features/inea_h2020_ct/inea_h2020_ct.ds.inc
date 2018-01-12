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
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_inea_h2020_project_descrip',
      ),
      'left' => array(
        1 => 'field_inea_h2020_abstract',
      ),
      'right' => array(
        2 => 'field_inea_h2020_image',
        3 => 'field_inea_h2020_project_referen',
        4 => 'field_inea_h2020_topic',
        5 => 'field_inea_h2020_call_for_propos',
        6 => 'field_inea_h2020_duration',
        7 => 'field_inea_h2020_funding_scheme',
        8 => 'field_inea_h2020_total_costs',
        9 => 'field_inea_h2020_eu_contribution',
        10 => 'field_inea_h2020_coordinator',
        11 => 'field_inea_h2020_url',
        12 => 'field_inea_h2020_cordis_url',
      ),
      'footer' => array(
        13 => 'group_participants_display',
        14 => 'field_inea_participant',
        15 => 'field_inea_participant_country',
        16 => 'field_inea_participant_requested',
      ),
    ),
    'fields' => array(
      'field_inea_h2020_project_descrip' => 'header',
      'field_inea_h2020_abstract' => 'left',
      'field_inea_h2020_image' => 'right',
      'field_inea_h2020_project_referen' => 'right',
      'field_inea_h2020_topic' => 'right',
      'field_inea_h2020_call_for_propos' => 'right',
      'field_inea_h2020_duration' => 'right',
      'field_inea_h2020_funding_scheme' => 'right',
      'field_inea_h2020_total_costs' => 'right',
      'field_inea_h2020_eu_contribution' => 'right',
      'field_inea_h2020_coordinator' => 'right',
      'field_inea_h2020_url' => 'right',
      'field_inea_h2020_cordis_url' => 'right',
      'group_participants_display' => 'footer',
      'field_inea_participant' => 'footer',
      'field_inea_participant_country' => 'footer',
      'field_inea_participant_requested' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|h2020_project|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|h2020_project|print';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'h2020_project';
  $ds_layout->view_mode = 'print';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_inea_h2020_image',
        1 => 'field_inea_h2020_programme',
        2 => 'field_inea_h2020_topic',
        3 => 'field_inea_h2020_call_for_propos',
        4 => 'field_inea_h2020_duration',
        5 => 'field_inea_h2020_funding_scheme',
        6 => 'field_inea_h2020_total_costs',
        7 => 'field_inea_h2020_eu_contribution',
        8 => 'field_inea_h2020_coordinator',
        9 => 'field_inea_h2020_url',
        10 => 'field_inea_h2020_cordis_url',
      ),
      'header' => array(
        11 => 'field_inea_h2020_acronym',
        12 => 'field_inea_h2020_project_descrip',
        13 => 'field_inea_h2020_project_referen',
      ),
      'right' => array(
        14 => 'field_inea_h2020_abstract',
      ),
      'footer' => array(
        15 => 'field_inea_participant',
        16 => 'field_inea_participant_country',
        17 => 'field_inea_participant_requested',
      ),
    ),
    'fields' => array(
      'field_inea_h2020_image' => 'left',
      'field_inea_h2020_programme' => 'left',
      'field_inea_h2020_topic' => 'left',
      'field_inea_h2020_call_for_propos' => 'left',
      'field_inea_h2020_duration' => 'left',
      'field_inea_h2020_funding_scheme' => 'left',
      'field_inea_h2020_total_costs' => 'left',
      'field_inea_h2020_eu_contribution' => 'left',
      'field_inea_h2020_coordinator' => 'left',
      'field_inea_h2020_url' => 'left',
      'field_inea_h2020_cordis_url' => 'left',
      'field_inea_h2020_acronym' => 'header',
      'field_inea_h2020_project_descrip' => 'header',
      'field_inea_h2020_project_referen' => 'header',
      'field_inea_h2020_abstract' => 'right',
      'field_inea_participant' => 'footer',
      'field_inea_participant_country' => 'footer',
      'field_inea_participant_requested' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|h2020_project|print'] = $ds_layout;

  return $export;
}

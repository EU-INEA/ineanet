<?php

/**
 * @file
 * inea_cef_project_content_type.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function inea_cef_project_content_type_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|inea_cef_project|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'inea_cef_project';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '24',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'changed_date' => array(
      'weight' => '20',
      'label' => 'above',
      'format' => 'ds_post_date_month_year',
    ),
  );
  $export['node|inea_cef_project|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|inea_cef_project|print';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'inea_cef_project';
  $ds_fieldsetting->view_mode = 'print';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'changed_date' => array(
      'weight' => '16',
      'label' => 'above',
      'format' => 'ds_post_date_month_year',
    ),
  );
  $export['node|inea_cef_project|print'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function inea_cef_project_content_type_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|inea_cef_project|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'inea_cef_project';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_cef_action_title',
      ),
      'left' => array(
        1 => 'field_inea_programme_text',
        2 => 'field_cef_call_year',
        3 => 'field_inea_cef_member_state',
        4 => 'field_inea_cef_date',
        5 => 'field_inea_cef_eu_contrib',
        6 => 'field_cef_project_cost',
        7 => 'field_inea_cef_eu_percent',
        8 => 'field_cef_coordinator',
        9 => 'field_inea_cef_project_status',
        10 => 'field_cef_3rd_cntry',
        11 => 'field_inea_cef_ener_corridor',
        12 => 'field_inea_cef_dsi',
        13 => 'field_cef_energy_sector',
        14 => 'field_cef_pci',
        15 => 'field_inea_cef_trans_corridor',
        16 => 'field_inea_cef_transport_mode',
        17 => 'field_cef_executive_summary',
        18 => 'field_cef_additional_info',
        19 => 'changed_date',
      ),
      'right' => array(
        20 => 'field_cef_action_code',
        21 => 'field_inea_cef_map',
        22 => 'field_project_description',
      ),
      'footer' => array(
        23 => 'comments',
      ),
    ),
    'fields' => array(
      'field_cef_action_title' => 'header',
      'field_inea_programme_text' => 'left',
      'field_cef_call_year' => 'left',
      'field_inea_cef_member_state' => 'left',
      'field_inea_cef_date' => 'left',
      'field_inea_cef_eu_contrib' => 'left',
      'field_cef_project_cost' => 'left',
      'field_inea_cef_eu_percent' => 'left',
      'field_cef_coordinator' => 'left',
      'field_inea_cef_project_status' => 'left',
      'field_cef_3rd_cntry' => 'left',
      'field_inea_cef_ener_corridor' => 'left',
      'field_inea_cef_dsi' => 'left',
      'field_cef_energy_sector' => 'left',
      'field_cef_pci' => 'left',
      'field_inea_cef_trans_corridor' => 'left',
      'field_inea_cef_transport_mode' => 'left',
      'field_cef_executive_summary' => 'left',
      'field_cef_additional_info' => 'left',
      'changed_date' => 'left',
      'field_cef_action_code' => 'right',
      'field_inea_cef_map' => 'right',
      'field_project_description' => 'right',
      'comments' => 'footer',
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
  $export['node|inea_cef_project|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|inea_cef_project|print';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'inea_cef_project';
  $ds_layout->view_mode = 'print';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_inea_programme_text',
        1 => 'field_inea_cef_trans_corridor',
        2 => 'field_inea_cef_transport_mode',
        3 => 'field_cef_call_year',
        4 => 'field_inea_cef_member_state',
        5 => 'field_inea_cef_date',
        6 => 'field_inea_cef_eu_contrib',
        7 => 'field_cef_project_cost',
        8 => 'field_inea_cef_eu_percent',
        9 => 'field_cef_coordinator',
        10 => 'field_inea_cef_project_status',
        11 => 'field_cef_3rd_cntry',
        12 => 'field_inea_cef_ener_corridor',
        13 => 'field_inea_cef_dsi',
        14 => 'field_cef_energy_sector',
        15 => 'field_cef_pci',
        16 => 'changed_date',
      ),
      'right' => array(
        17 => 'title',
        18 => 'field_cef_action_code',
        19 => 'field_inea_cef_map',
        20 => 'field_project_description',
      ),
      'footer' => array(
        21 => 'field_inea_cef_participants',
        22 => 'field_cef_participant_country',
      ),
    ),
    'fields' => array(
      'field_inea_programme_text' => 'left',
      'field_inea_cef_trans_corridor' => 'left',
      'field_inea_cef_transport_mode' => 'left',
      'field_cef_call_year' => 'left',
      'field_inea_cef_member_state' => 'left',
      'field_inea_cef_date' => 'left',
      'field_inea_cef_eu_contrib' => 'left',
      'field_cef_project_cost' => 'left',
      'field_inea_cef_eu_percent' => 'left',
      'field_cef_coordinator' => 'left',
      'field_inea_cef_project_status' => 'left',
      'field_cef_3rd_cntry' => 'left',
      'field_inea_cef_ener_corridor' => 'left',
      'field_inea_cef_dsi' => 'left',
      'field_cef_energy_sector' => 'left',
      'field_cef_pci' => 'left',
      'changed_date' => 'left',
      'title' => 'right',
      'field_cef_action_code' => 'right',
      'field_inea_cef_map' => 'right',
      'field_project_description' => 'right',
      'field_inea_cef_participants' => 'footer',
      'field_cef_participant_country' => 'footer',
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
  $export['node|inea_cef_project|print'] = $ds_layout;

  return $export;
}

<?php
/**
 * @file
 * h2020_ct.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function h2020_ct_ds_layout_settings_info() {
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
        0 => 'field_h2020_project_reference',
        1 => 'field_h2020_call_for_proposals',
        2 => 'field_h2020_topic',
        3 => 'field_h2020_acronym',
        4 => 'field_h2020_project_description',
        5 => 'field_h2020_date_from',
        6 => 'field_h2020_total_costs',
        7 => 'field_h2020_eu_contribution',
        8 => 'field_h2020_short_summary',
      ),
      'right' => array(
        9 => 'field_h2020_image',
        10 => 'field_h2020_funding_scheme',
        11 => 'field_h2020_coordinator',
        12 => 'field_h2020_url',
        13 => 'field_h2020_cordis_url',
        14 => 'field_h2020_participants',
        15 => 'field_h2020_partner_countries',
        16 => 'field_h2020_abstract',
      ),
    ),
    'fields' => array(
      'field_h2020_project_reference' => 'left',
      'field_h2020_call_for_proposals' => 'left',
      'field_h2020_topic' => 'left',
      'field_h2020_acronym' => 'left',
      'field_h2020_project_description' => 'left',
      'field_h2020_date_from' => 'left',
      'field_h2020_total_costs' => 'left',
      'field_h2020_eu_contribution' => 'left',
      'field_h2020_short_summary' => 'left',
      'field_h2020_image' => 'right',
      'field_h2020_funding_scheme' => 'right',
      'field_h2020_coordinator' => 'right',
      'field_h2020_url' => 'right',
      'field_h2020_cordis_url' => 'right',
      'field_h2020_participants' => 'right',
      'field_h2020_partner_countries' => 'right',
      'field_h2020_abstract' => 'right',
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

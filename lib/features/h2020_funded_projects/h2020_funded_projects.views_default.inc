<?php

/**
 * @file
 * h2020_funded_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function h2020_funded_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'h2020_projects_by_field_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'H2020 Projects by field content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'H2020 Projects by field content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_inea_h2020_short_summary' => 'field_inea_h2020_short_summary',
    'field_inea_h2020_project_descrip' => 'field_inea_h2020_project_descrip',
    'field_inea_h2020_project_referen' => 'field_inea_h2020_project_referen',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inea_h2020_short_summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inea_h2020_project_descrip' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_inea_h2020_project_referen' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: h2020 short summary */
  $handler->display->display_options['fields']['field_inea_h2020_short_summary']['id'] = 'field_inea_h2020_short_summary';
  $handler->display->display_options['fields']['field_inea_h2020_short_summary']['table'] = 'field_data_field_inea_h2020_short_summary';
  $handler->display->display_options['fields']['field_inea_h2020_short_summary']['field'] = 'field_inea_h2020_short_summary';
  /* Field: Content: inea h2020 project description */
  $handler->display->display_options['fields']['field_inea_h2020_project_descrip']['id'] = 'field_inea_h2020_project_descrip';
  $handler->display->display_options['fields']['field_inea_h2020_project_descrip']['table'] = 'field_data_field_inea_h2020_project_descrip';
  $handler->display->display_options['fields']['field_inea_h2020_project_descrip']['field'] = 'field_inea_h2020_project_descrip';
  /* Field: Content: Project reference */
  $handler->display->display_options['fields']['field_inea_h2020_project_referen']['id'] = 'field_inea_h2020_project_referen';
  $handler->display->display_options['fields']['field_inea_h2020_project_referen']['table'] = 'field_data_field_inea_h2020_project_referen';
  $handler->display->display_options['fields']['field_inea_h2020_project_referen']['field'] = 'field_inea_h2020_project_referen';
  /* Sort criterion: Content: inea h2020 programme (field_inea_h2020_programme) */
  $handler->display->display_options['sorts']['field_inea_h2020_programme_tid']['id'] = 'field_inea_h2020_programme_tid';
  $handler->display->display_options['sorts']['field_inea_h2020_programme_tid']['table'] = 'field_data_field_inea_h2020_programme';
  $handler->display->display_options['sorts']['field_inea_h2020_programme_tid']['field'] = 'field_inea_h2020_programme_tid';
  /* Sort criterion: Content: inea H2020 area term (field_inea_h2020_area_term) */
  $handler->display->display_options['sorts']['field_inea_h2020_area_term_tid']['id'] = 'field_inea_h2020_area_term_tid';
  $handler->display->display_options['sorts']['field_inea_h2020_area_term_tid']['table'] = 'field_data_field_inea_h2020_area_term';
  $handler->display->display_options['sorts']['field_inea_h2020_area_term_tid']['field'] = 'field_inea_h2020_area_term_tid';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['arguments']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid_1']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid_1']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid_1']['validate_options']['vocabularies'] = array(
    'programmes' => 'programmes',
  );
  $handler->display->display_options['arguments']['tid_1']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid_1']['validate_options']['transform'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = '%1:%2';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'h2020_field' => 'h2020_field',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'h2020_project' => 'h2020_project',
  );

  /* Display: H2020 Projects by one field */
  $handler = $view->new_display('page', 'H2020 Projects by one field', 'h2020_proj_by_1_field');
  $handler->display->display_options['path'] = 'horizon-2020/%/projects-by-field/%';
  $export['h2020_projects_by_field_content'] = $view;

  $view = new view();
  $view->name = 'tax_terms_h2020_field';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Tax terms H2020 Field';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'H2020 Field terms';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '55';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_inea_h2020_programme',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content using inea H2020 area term */
  $handler->display->display_options['relationships']['reverse_field_inea_h2020_area_term_node']['id'] = 'reverse_field_inea_h2020_area_term_node';
  $handler->display->display_options['relationships']['reverse_field_inea_h2020_area_term_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_inea_h2020_area_term_node']['field'] = 'reverse_field_inea_h2020_area_term_node';
  $handler->display->display_options['relationships']['reverse_field_inea_h2020_area_term_node']['required'] = TRUE;
  /* Relationship: Taxonomy term: Content using inea h2020 programme */
  $handler->display->display_options['relationships']['reverse_field_inea_h2020_programme_node']['id'] = 'reverse_field_inea_h2020_programme_node';
  $handler->display->display_options['relationships']['reverse_field_inea_h2020_programme_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_inea_h2020_programme_node']['field'] = 'reverse_field_inea_h2020_programme_node';
  /* Field: Content: inea h2020 programme */
  $handler->display->display_options['fields']['field_inea_h2020_programme']['id'] = 'field_inea_h2020_programme';
  $handler->display->display_options['fields']['field_inea_h2020_programme']['table'] = 'field_data_field_inea_h2020_programme';
  $handler->display->display_options['fields']['field_inea_h2020_programme']['field'] = 'field_inea_h2020_programme';
  $handler->display->display_options['fields']['field_inea_h2020_programme']['relationship'] = 'reverse_field_inea_h2020_area_term_node';
  $handler->display->display_options['fields']['field_inea_h2020_programme']['label'] = '';
  $handler->display->display_options['fields']['field_inea_h2020_programme']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_inea_h2020_programme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_inea_h2020_programme']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_inea_h2020_programme']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'horizon-2020/[field_inea_h2020_programme]/projects-by-field/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'h2020_field' => 'h2020_field',
    'programmes' => 'programmes',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: H2020 Projects  */
  $handler = $view->new_display('page', 'H2020 Projects ', 'page');
  $handler->display->display_options['path'] = 'horizon-2020/projects/funded-projectsx';
  $export['tax_terms_h2020_field'] = $view;

  return $export;
}

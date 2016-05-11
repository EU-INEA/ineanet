<?php
/**
 * @file
 * cordis_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cordis_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'subprogramme_area_projects';
  $view->description = 'Projects of the certain subprogramme area';
  $view->tag = 'cordis';
  $view->base_table = 'node';
  $view->human_name = 'Subprogramme area projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Factsheets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'cordis-project-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: RCN code */
  $handler->display->display_options['fields']['field_proj_rcn']['id'] = 'field_proj_rcn';
  $handler->display->display_options['fields']['field_proj_rcn']['table'] = 'field_data_field_proj_rcn';
  $handler->display->display_options['fields']['field_proj_rcn']['field'] = 'field_proj_rcn';
  $handler->display->display_options['fields']['field_proj_rcn']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'http://cordis.europa.eu/projects/rcn/[field_proj_rcn]_en.html';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Project acronym */
  $handler->display->display_options['fields']['field__proj_acronym']['id'] = 'field__proj_acronym';
  $handler->display->display_options['fields']['field__proj_acronym']['table'] = 'field_data_field__proj_acronym';
  $handler->display->display_options['fields']['field__proj_acronym']['field'] = 'field__proj_acronym';
  $handler->display->display_options['fields']['field__proj_acronym']['label'] = '';
  $handler->display->display_options['fields']['field__proj_acronym']['element_label_colon'] = FALSE;
  /* Field: Content: Project Logo */
  $handler->display->display_options['fields']['field_proj_logo']['id'] = 'field_proj_logo';
  $handler->display->display_options['fields']['field_proj_logo']['table'] = 'field_data_field_proj_logo';
  $handler->display->display_options['fields']['field_proj_logo']['field'] = 'field_proj_logo';
  $handler->display->display_options['fields']['field_proj_logo']['label'] = '';
  $handler->display->display_options['fields']['field_proj_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_proj_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_proj_summary_1']['id'] = 'field_proj_summary_1';
  $handler->display->display_options['fields']['field_proj_summary_1']['table'] = 'field_data_field_proj_summary';
  $handler->display->display_options['fields']['field_proj_summary_1']['field'] = 'field_proj_summary';
  $handler->display->display_options['fields']['field_proj_summary_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_proj_summary_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_proj_summary_1']['alter']['text'] = '[field_proj_summary_1]..';
  $handler->display->display_options['fields']['field_proj_summary_1']['type'] = 'trimmed_cleansed';
  $handler->display->display_options['fields']['field_proj_summary_1']['settings'] = array(
    'trim_length' => '500',
  );
  /* Field: Content: Project review */
  $handler->display->display_options['fields']['field_project_review']['id'] = 'field_project_review';
  $handler->display->display_options['fields']['field_project_review']['table'] = 'field_data_field_project_review';
  $handler->display->display_options['fields']['field_project_review']['field'] = 'field_project_review';
  $handler->display->display_options['fields']['field_project_review']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_review']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_project_review']['alter']['text'] = '[field_project_review]..';
  $handler->display->display_options['fields']['field_project_review']['empty'] = '[field_proj_summary_1]';
  $handler->display->display_options['fields']['field_project_review']['type'] = 'trimmed_cleansed';
  $handler->display->display_options['fields']['field_project_review']['settings'] = array(
    'trim_length' => '500',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_proj_summary']['id'] = 'field_proj_summary';
  $handler->display->display_options['fields']['field_proj_summary']['table'] = 'field_data_field_proj_summary';
  $handler->display->display_options['fields']['field_proj_summary']['field'] = 'field_proj_summary';
  $handler->display->display_options['fields']['field_proj_summary']['label'] = '';
  $handler->display->display_options['fields']['field_proj_summary']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_proj_summary']['alter']['text'] = '[field_project_review]';
  $handler->display->display_options['fields']['field_proj_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_proj_summary']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'More...';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'http://cordis.europa.eu/projects/rcn/[field_proj_rcn]_en.html';
  $handler->display->display_options['fields']['nothing']['alter']['prefix'] = '<div class="more-link">';
  $handler->display->display_options['fields']['nothing']['alter']['suffix'] = '</div>';
  $handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
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
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['subprogramme_area_projects'] = array(
    t('Master'),
    t('Factsheets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('RCN code'),
    t('Summary'),
    t('[field_proj_summary_1]..'),
    t('Project review'),
    t('[field_project_review]..'),
    t('[field_proj_summary_1]'),
    t('[field_project_review]'),
    t('More...'),
    t('<div class="more-link">'),
    t('</div>'),
    t('Block'),
  );
  $export['subprogramme_area_projects'] = $view;

  return $export;
}

<?php
/**
 * @file
 * cordis_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cordis_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cordis_projects';
  $context->description = 'Projects from cordis';
  $context->tag = 'cordis';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'programmes_and_projects' => 'programmes_and_projects',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-9d65cca93b9b2985d6d0d639f5b3a61d' => array(
          'module' => 'views',
          'delta' => '9d65cca93b9b2985d6d0d639f5b3a61d',
          'region' => 'content_tab4',
          'weight' => '-10',
        ),
      ),
    ),
    'digital_agenda_general_tabs' => array(
      'content' => array(
        'id' => 'Article',
        'title' => 'Article',
      ),
      'content_tab1' => array(
        'id' => 'Latest',
        'title' => 'Latest',
      ),
      'content_tab2' => array(
        'id' => 'Blogs',
        'title' => 'Blogs',
      ),
      'content_tab3' => array(
        'id' => 'Blogs',
        'title' => 'Blogs',
      ),
      'content_tab4' => array(
        'id' => 'EU Investments',
        'title' => 'EU Investments',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Projects from cordis');
  t('cordis');
  $export['cordis_projects'] = $context;

  return $export;
}

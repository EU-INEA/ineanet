<?php
/**
 * @file
 * inea_cef_project_content_type.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function inea_cef_project_content_type_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cef_project_pdf_class';
  $context->description = 'A context to assign CSS classes to CEF Projects based on TAG PROGRAMME';
  $context->tag = 'cef class';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        37 => 37,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'cef-energy',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context to assign CSS classes to CEF Projects based on TAG PROGRAMME');
  t('cef class');
  $export['cef_project_pdf_class'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cef_project_pdf_class_synergy';
  $context->description = 'A context to assign CSS classes to CEF Projects based on TAG PROGRAMME';
  $context->tag = 'cef class';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        862 => 862,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'cef-synergy',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context to assign CSS classes to CEF Projects based on TAG PROGRAMME');
  t('cef class');
  $export['cef_project_pdf_class_synergy'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cef_project_pdf_class_telecom';
  $context->description = 'A context to assign CSS classes to CEF Projects based on TAG PROGRAMME';
  $context->tag = 'cef class';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        39 => 39,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'cef-telecom',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context to assign CSS classes to CEF Projects based on TAG PROGRAMME');
  t('cef class');
  $export['cef_project_pdf_class_telecom'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cef_project_pdf_class_transport';
  $context->description = 'A context to assign CSS classes to CEF Projects based on TAG PROGRAMME';
  $context->tag = 'cef class';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        38 => 38,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'cef-transport-tm',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context to assign CSS classes to CEF Projects based on TAG PROGRAMME');
  t('cef class');
  $export['cef_project_pdf_class_transport'] = $context;

  return $export;
}

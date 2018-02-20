<?php

/**
 * @file
 * inea_h2020_ct.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function inea_h2020_ct_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'h2020_project_energy_pdf_class';
  $context->description = 'A context to assign CSS classes to H2020 Energy Projects based on TAG PROGRAMME';
  $context->tag = 'theme';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        434 => 434,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'h2020-energy',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context to assign CSS classes to H2020 Energy Projects based on TAG PROGRAMME');
  t('theme');
  $export['h2020_project_energy_pdf_class'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'h2020_project_pdf_class';
  $context->description = 'A context to assign CSS classes to H2020 Transport Projects based on TAG PROGRAMME';
  $context->tag = 'theme';
  $context->conditions = array(
    'node_taxonomy' => array(
      'values' => array(
        433 => 433,
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'h2020-transport',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context to assign CSS classes to H2020 Transport Projects based on TAG PROGRAMME');
  t('theme');
  $export['h2020_project_pdf_class'] = $context;

  return $export;
}

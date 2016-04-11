<?php
/**
 * @file
 * cordis_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function cordis_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'cordis';
  $feeds_importer->config = array(
    'name' => 'Cordis',
    'description' => 'Import Cordis Projects',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'project/title',
          'xpathparser:1' => 'project/title/text()',
          'xpathparser:2' => 'project/reference/text()',
          'xpathparser:3' => 'project/teaser/text()',
          'xpathparser:4' => 'project/relations/associations/programme[@type=\'relatedProgramme\']/code/text()',
          'xpathparser:5' => 'project/acronym/text()',
          'xpathparser:6' => 'project/rcn/text()',
          'xpathparser:7' => 'project/contentUpdateDate/text()',
          'xpathparser:12' => 'project/reference/text()',
          'xpathparser:14' => 'project/objective/text()',
          'xpathparser:16' => 'project/startDate/text()',
          'xpathparser:17' => 'project/endDate/text()',
          'xpathparser:18' => '',
          'xpathparser:19' => '',
          'xpathparser:20' => 'project/relations/associations/programme[@type=\'relatedSubProgramme\']/code/text()',
          'xpathparser:21' => 'project/relations/associations/organization/address/country/text()',
          'xpathparser:22' => 'project/relations/associations/webItem[@type=\'relatedPpmProjectLogo\']/uri/text()',
          'xpathparser:23' => 'project/details/ppmJDescription/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:12' => 0,
          'xpathparser:14' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
        ),
        'context' => '//response/hits/hit',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:12' => 0,
            'xpathparser:14' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_short_title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_shared_teaser',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_proj_programme_acronym',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field__proj_acronym',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_proj_rcn',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_proj_update_date:start',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_proj_reference',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_proj_summary',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_proj_start_date:start',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_proj_end_date:start',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_proj_long',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_proj_lat',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_subprogramme_area',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          15 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_shared_country',
            'term_search' => '1',
            'autocreate' => 1,
          ),
          16 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_proj_logo',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:23',
            'target' => 'field_project_review',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'authorize' => 0,
        'skip_hash_check' => 1,
        'bundle' => 'project',
      ),
    ),
    'content_type' => 'cordis_importer',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 0,
    'process_in_background' => 0,
  );
  $export['cordis'] = $feeds_importer;

  return $export;
}

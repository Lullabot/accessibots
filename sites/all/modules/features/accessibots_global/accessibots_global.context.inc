<?php
/**
 * @file
 * accessibots_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function accessibots_global_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Homepage Settings';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-the-accessibots' => array(
          'module' => 'bean',
          'delta' => 'the-accessibots',
          'region' => 'home_page_intro',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage Settings');
  $export['homepage'] = $context;

  return $export;
}

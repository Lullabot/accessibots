<?php
/**
 * @file
 * accessibots_global.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function accessibots_global_filter_default_formats() {
  $formats = array();

  // Exported format: HTML.
  $formats['html'] = array(
    'format' => 'html',
    'name' => 'HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(
          'local_paths' => 'https://live-accessibots.pantheon.io/
http://live-accessibots.pantheon.io/
http://www.accessibots.com/
http://www.accessibots.io/
http://accessibots.com/
http://accessibots.io/
/',
          'protocol_style' => 'path',
        ),
      ),
    ),
  );

  return $formats;
}

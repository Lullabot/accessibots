<?php
/**
 * @file
 * accessibots_simple_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function accessibots_simple_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function accessibots_simple_page_node_info() {
  $items = array(
    'simple_page' => array(
      'name' => t('Simple Page'),
      'base' => 'node_content',
      'description' => t('Basic content pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

<?php
/**
 * @file
 * abots_global.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function abots_global_ctools_plugin_api($module = NULL, $api = NULL) {
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
function abots_global_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News Post'),
      'base' => 'node_content',
      'description' => t('Create a new news post that can be promoted to the home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'simple_page' => array(
      'name' => t('Simple Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

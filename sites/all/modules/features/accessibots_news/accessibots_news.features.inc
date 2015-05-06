<?php
/**
 * @file
 * accessibots_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function accessibots_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function accessibots_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News Post'),
      'base' => 'node_content',
      'description' => t('Create a new news post that can be promoted to the home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

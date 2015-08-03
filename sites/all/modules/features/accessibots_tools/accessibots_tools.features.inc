<?php
/**
 * @file
 * accessibots_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function accessibots_tools_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function accessibots_tools_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function accessibots_tools_image_default_styles() {
  $styles = array();

  // Exported image style: icon.
  $styles['icon'] = array(
    'label' => 'Icon (20x20)',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 20,
          'height' => 20,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: small_square__190x190_.
  $styles['small_square__190x190_'] = array(
    'label' => 'Small Square (190x190)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 190,
          'height' => 190,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function accessibots_tools_node_info() {
  $items = array(
    'tool' => array(
      'name' => t('Tool'),
      'base' => 'node_content',
      'description' => t('Create a new accessibility testing tool.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

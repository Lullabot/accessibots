<?php
/**
 * @file
 * accessibots_simple_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function accessibots_simple_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__simple_page';
  $strongarm->value = array(
    'view_modes' => array(
      'home_page_announcement' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__simple_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_simple_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_simple_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_simple_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_simple_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_simple_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_simple_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_simple_page';
  $strongarm->value = '0';
  $export['node_preview_simple_page'] = $strongarm;

  return $export;
}

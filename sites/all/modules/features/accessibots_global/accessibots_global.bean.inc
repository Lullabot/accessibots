<?php
/**
 * @file
 * accessibots_global.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function accessibots_global_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'text_snippet';
  $bean_type->label = 'Text Snippet';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['text_snippet'] = $bean_type;

  return $export;
}

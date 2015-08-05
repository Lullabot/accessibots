<?php
/**
 * @file
 * accessibots_global.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function accessibots_global_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-text_snippet-field_content_body'
  $field_instances['bean-text_snippet-field_content_body'] = array(
    'bundle' => 'text_snippet',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_content_body',
    'label' => 'Content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');

  return $field_instances;
}

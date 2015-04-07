<?php

define('KC_MODULE_DISABLED', dt('disabled'));

/**
 * Implements hook_drush_command().
 *
 * @return mixed
 */
function compare_schemas_drush_command() {
  $items['compare-schema'] = array(
    'description' => 'Compare the modules enabled and their versions between two sites.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'site-1' => 'A site alias.',
      'site-2' => 'Another site alias.',
    ),
    'required-arguments' => TRUE,
    'options' => array(
      'status' => 'Filter by module status. (enabled or disabled)',
      'diff' => 'Only return modules where the schema differs between sites.',
    ),
    'examples' => array(
      'drush compare-schema @site.dev @site.stage' => 'Show the differences between the modules enabled and their versions.',
    ),
    'aliases' => array('compsch'),
    'outputformat' => array(
      'default' => 'table',
      'pipe-format' => 'list',
      'field-labels' => array('name' => 'Module', 'a1' => 'Alias 1', 'a2' => 'Alias 2'),
      'output-data-type' => 'format-table',
    ),
  );

  return $items;
}

/**
 * Command callback validate.
 */
function drush_compare_schemas_validate($alias1, $alias2) {
  $args = array('@alias1' => $alias1, '@alias2' => $alias2);

  // Ensure the aliases exist.
  if (!_drush_sitealias_load_alias($alias1)) {
    drush_set_error('INVALID_ALIAS', dt('@alias1 is not a valid alias.', $args));
  }
  if (!_drush_sitealias_load_alias($alias2)) {
    drush_set_error('INVALID_ALIAS', dt('@alias2 is not a valid alias.', $args));
  }
}

/**
 * Command callback.
 */
function drush_compare_schemas($alias1, $alias2) {
  $schema1 = $schema2 = array();
  $args    = array('query' => "SELECT CONCAT(name, ',', status, ',', schema_version) FROM system WHERE type = 'module'");
  $ops     = array('extra' => '--skip-column-names');
  $backend = array('integrate' => FALSE);
  $rows    = array();

  // Load a config file if available
  if ($config = drush_get_option('config-file')) {
    $ops['config'] = $config;
  }

  // --status option
  $status = strtolower(drush_get_option('status'));
  if ($status == 'enabled') {
    $args['query'] .= "AND status = 1";
  }
  elseif ($status == 'disabled') {
    $args['query'] .= "AND status = 0";
  }

  // --diff option
  $diff_only = drush_get_option('diff');

  // Get the schema for alias1
  $res = drush_invoke_process($alias1, 'sql-query', $args, $ops, $backend);
  $schema1 = _compare_schemas_output_to_array($res['output']);

  // Get the schema for alias2
  $res = drush_invoke_process($alias2, 'sql-query', $args, $ops, $backend);
  $schema2 = _compare_schemas_output_to_array($res['output']);

  // Add items from the first schema, comparing against the second schema.
  foreach ($schema1 as $module => $data) {
    if (!$diff_only || _kc_compare_schema_module_differs($module, $schema1, $schema2)) {
      $rows[$module] = array(
        'name' => $module,
        'a1' => $data['status'] == 1 ? $data['version'] : KC_MODULE_DISABLED,
        'a2' => isset($schema2[$module]) ? ($schema2[$module]['status'] == 1 ? $schema2[$module]['version'] : KC_MODULE_DISABLED) : 'NA',
      );
    }

    // Remove matching items from schema2
    unset($schema2[$module]);
  }

  // If there are any items in schema2 not listed in schema1, add them.
  if (!empty($schema2)) {
    foreach ($schema2 as $module => $data) {
      $rows[$module] = array(
        'name' => $module,
        'a1' => 'NA',
        'a2' => $data['status'] == 1 ? $data['version'] : KC_MODULE_DISABLED,
      );
    }
  }

  // Sort results alphabetically
  asort($rows);

  // @todo: Figure out how to alter the ouputformatter to do this
  // Add some headers
  $headers['border'] = array(
    'name' => '------',
    'a1'   => str_pad('', strlen($alias1), '-'),
    'a2'   => str_pad('', strlen($alias2), '-'),
  );
  $headers['aliases'] = array(
    'name' => '',
    'a1' => $alias1,
    'a2' => $alias2,
  );
  $headers['border2'] = $headers['border'];
  $headers['border2']['name'] = '';

  $rows = $headers + $rows;

  return $rows;
}

/**
 * Helper function to process the result.
 *
 * @param string $results
 *   The results from the sql query in $res['output'].
 *
 * @return array
 */
function _compare_schemas_output_to_array($results) {
  $ret = array();

  foreach (explode(PHP_EOL, $results) as $row) {
    $row = trim($row);
    if (empty($row)) {
      continue;
    }
    list($module, $status, $version) = explode(',', $row);
    $ret[$module] = array('status' => $status, 'version' => $version);
  }

  return $ret;
}

/**
 * Helper function to compare a module's status and schema version between sites.
 */
function _compare_schema_module_differs($module, $schema1, $schema2) {
  return !($schema1[$module]['status'] === $schema2[$module]['status'] && $schema1[$module]['version'] === $schema2[$module]['version']);
}

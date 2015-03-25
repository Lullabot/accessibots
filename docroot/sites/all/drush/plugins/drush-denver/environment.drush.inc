<?php
/**
 * @file
 */

/**
 * Implementation of hook_drush_command().
 */
function environment_drush_command() {
  $items['environment'] = array(
    'description' => 'Enable settings for a specific environment.',
    'arguments' => array(
      'environment-name' => 'Predefined environment names created in your env.drushrc.php files.  Combine multiple environment definitions using the plus(+) sign.',
    ),
    'examples' => array(
      'drush env dev' => 'Run the dev environment settings.',
      'drush env dev+chris' => 'Run the dev settings then run chris\'s settings.',
    ),
    'aliases' => array('env'),
  );

  $items['environment-list'] = array(
    'description' => 'Show all available environments.',
    'examples' => array(
      'drush env-list' => 'Display all available environments and their location.',
    ),
    'aliases' => array('env-list'),
    'outputformat' => array(
      'default' => 'key-value-list',
      'pipe-format' => 'json',
    ),
  );

  $items['environment-info'] = array(
    'description' => 'Get info about a specific environment definition.',
    'arguments' => array(
      'name' => 'The name of an environment definition.',
    ),
    'examples' => array(
      'drush env-info' => 'Alias for environment-list.',
      'drush env-info dev' => 'Show the details of the \'dev\' environment definition.',
    ),
    'aliases' => array('env-info', 'envin'),
  );

  $items['environment-dir'] = array(
    'description' => 'Show and optionally make the directory where env definitions should be placed for this site.',
    'options' => array(
      'make' => 'Create a definition file if it does not already exist.',
    ),
    'examples' => array(
      'drush env-dir' => 'Print the directory path.',
      'drush env-dir --make' => 'Create a starter env.drushrc.php in the proper directory.',
      'drush env-dir --make=dev' => 'Create a starter dev.env.drushrc.php in the proper directory.',
    ),
    'aliases' => array('env-dir', 'envdir'),
  );

  return $items;
}

/**
 * Drush command callback function.
 */
function drush_environment($env = NULL) {
  $environments = array();

  // Load all available environments for the site.
  _drush_environment_load_env_site($environments);

  // Make sure we found at least one env.
  if (empty($environments)) {
    return drush_set_error('DRUSH_DRUPAL_ERROR_MESSAGE', dt('Unable to find any environment definitions.'));
  }

  // The user needs to tell us which one they want to employ.
  if (!$env) {
    return drush_set_error('DRUSH_DRUPAL_ERROR_MESSAGE', dt('You need to specify at lease one environment definition to employ.'));
  }

  // Separate any combined envs.
  $envs = explode('+', $env);

  // Make sure the ones they specified exists.  Bail out if any don't exist.
  foreach ($envs as $_env) {
    if (!isset($environments[$_env])) {
      return drush_set_error('DRUSH_DRUPAL_ERROR_MESSAGE', dt('Unable to locate the environment definition for \'@env.\'', array('@env' => $_env)));
    }
  }

  // Merge multiple definitions
  $exec = array();
  if (count($envs) == 1) {
    $exec = $environments[$envs[0]];
  }
  else {
    foreach ($envs as $_env) {
      $exec = array_merge_recursive_distinct($exec, $environments[$_env]);
    }
  }

  // @todo: Add options to run only certain settings
  // @see: https://github.com/KeyboardCowboy/denver/issues/5

  // Execute the env settings.
  foreach ($exec as $type => $options) {
    $function = "_drush_environment_{$type}_management";
    if (function_exists($function)) {
      $function($options);
    }
  }
}

/**
 * Command callback.
 */
function drush_environment_list() {
  $environments = array();
  _drush_environment_load_env_site($environments);

  $data = array();
  foreach ($environments as $name => $env) {
    $data['env'][$name] = $env['filename'];
  }

  return $data;
}

/**
 * Command callback.
 */
function drush_environment_info($env = NULL) {
  $environments = array();
  _drush_environment_load_env_site($environments);

  // Print the details of a given env definition if specified.
  // @todo: Is there a formatter than can do this?
  if ($env && isset($environments[$env])) {
    foreach ($environments[$env]['modules'] as &$status) {
      $status = $status == 0 ? dt('disable') : dt('enable');
    }

    drush_print(dt('Modules:'));
    drush_print_format(array($environments[$env]['modules']), 'key-value-list');

    drush_print(dt('Variables:'));
    drush_print_format(array($environments[$env]['vars']), 'key-value-list');

    drush_print(dt('Permissions:'));
    foreach ($environments[$env]['perms'] as $role => $perms) {
      foreach ($environments[$env]['perms'][$role] as &$grant) {
        $grant = $grant == 0 ? dt('revoke') : dt('grant');
      }

      drush_print($role);
      drush_print_format(array($environments[$env]['perms'][$role]), 'key-value-list');
    }
  }
  else {
    if (empty($env)) {
      drush_log(dt('Provide an environment definition to view.'));
    }
    else {
      drush_log(dt('Unable to locate \'!name\' environment definition. Try another:', array('!name' => $env)), 'warning', TRUE);
    }

    // @todo: Do I need to get arguments for the current command to pass into
    // the invoked command?
    drush_invoke('environment-list');
  }
}

/**
 * Command callback.
 */
function drush_environment_dir() {
  $site_path = _drush_environment_site_dir();

  // Optionally create the directory
  if ($name = drush_get_option('make')) {
    // Create the directory if it doesn't already exist.
    drush_mkdir($site_path);

    // Create new env definition file name.
    $filename = ($name == 1 ? 'env.drushrc.php' : "{$name}.env.drushrc.php");
    $filepath = "{$site_path}/{$filename}";

    // Get the file path relative to the user's current dir.
    $localpath = '.' . substr($filepath, strpos($filepath, drush_cwd()) + strlen(drush_cwd()));

    // Create the file, checking for existence first.
    if (file_exists($filepath)) {
      drush_log(dt('The file @name already exists.', array('@name' => $localpath)), 'warning');
    }
    else {
      $root = dirname(__FILE__);
      $content = ($name == 1 ? file_get_contents("{$root}/templates/group.inc") : file_get_contents("{$root}/templates/single.inc"));
      if (file_put_contents($filepath, $content)) {
        drush_log(dt('The file @name has been created for you!', array('@name' => $localpath)), 'success');
      }
      else {
        drush_log(dt('Unable to create the file @name for you. Sorry!', array('@name' => $localpath)), 'error');
      }
    }
  }
  else {
    drush_print(dt('Add your env definition files here: @path', array('@path' => $site_path)));
  }
}

/**
 * Helper function to load all the available site environments.
 */
function _drush_environment_load_env_site(&$environments) {
  $config_paths = array(_drush_environment_site_dir());

  // Find directories to scan for environment config files.
  foreach (array('custom', 'drupal', 'home.drush', 'system') as $context) {
    if ($files = _drush_config_file($context, 'env')) {
      if (is_array($files)) {
        foreach ($files as $file) {
          $config_paths[] = dirname($file);
        }
      }
      else {
        $config_paths[] = dirname($files);
      }
    }
  }

  // Scan for environment files
  foreach ($config_paths as $path) {
    foreach (drush_scan_directory($path, '/env\.drushrc\.php$/') as $file) {
      _drush_environment_load_env_file($environments, $file);
    }
  }
}

/**
 * Get the path to the site dir.
 */
function _drush_environment_site_dir() {
  $site_path = '';

  // Check for aliases
  $site_name = drush_sitealias_bootstrapped_site_name();
  $alias = drush_sitealias_get_record("@{$site_name}");

  if (floatval(DRUSH_VERSION) > 6.2) {
    $site_path = drush_sitealias_local_site_path($alias);
  }
  else {
    $supposed_path = drush_sitealias_local_site_path($alias);
    $hostname = drush_sitealias_uri_to_site_dir($alias['uri']);

    $site_root = drush_get_context('DRUSH_SELECTED_DRUPAL_ROOT');
    if (file_exists($site_root . '/sites/sites.php')) {
      $sites = array();

      include($site_root . '/sites/sites.php');

      // If we found a match in sites.php and the supposed path is sites/default
      // then replace 'default' with the matching directory.
      if (isset($sites[$hostname]) && substr($supposed_path, -8) == '/default') {
        $site_path = str_replace('/default', "/{$sites[$hostname]}", $supposed_path);
      }
      else {
        $site_path = $supposed_path;
      }
    }
    else {
      $site_path = $supposed_path;
    }
  }

  // If the site dir is 'default', switch to 'all'
  if (substr($site_path, -8) == '/default') {
    $site_path = str_replace('/default', '/all', $site_path);
  }

  return $site_path . '/drush';
}

/**
 * Drush command helper to load environments from files.
 */
function _drush_environment_load_env_file(&$environments, $file) {
  // Look for a group file
  if (stripos($file->name, 'env') === 0) {
    foreach (_drush_environment_extract_env($file->filename) as $name => $env) {

      // Parse filename to shorten to web relative
      $filename = substr($file->filename, strpos($file->filename, DRUPAL_ROOT) + strlen(DRUPAL_ROOT) + 1);

      $env['filename'] = $filename;
      $environments[$name] = $env;
    }
  }
  // Load a single definition
  else {
    list($name, ,) = explode('.', $file->name);
    $environments[$name] = _drush_environment_extract_env($file->filename);
    $environments[$name]['filename'] = $file->filename;
  }
}

/**
 * Drush command helper to extract environemnt definitions from a file.
 */
function _drush_environment_extract_env($filename) {
  include($filename);
  return $env;
}

/**
 * Drush command helper function used to enable/disable modules.
 */
function _drush_environment_modules_management($modules = array()) {
  // Lets build a list of modules to enable and a separate list of modules to disable.
  $enable = $disable = array();
  foreach ($modules as $module_name => $status) {
    if ($status == 1 && !module_exists($module_name)) {
      $enable[] = $module_name;
    }
    elseif ($status == 0 && module_exists($module_name)) {
      $disable[] = $module_name;
    }
  }
  if (!empty($enable)) {
    drush_invoke('pm-enable', implode(',', $enable));
  }

  if (!empty($disable)) {
    drush_invoke('pm-disable', implode(',', $disable));
  }
}

/**
 * Drush command helper function used to set variables.
 */
function _drush_environment_vars_management($settings = array()) {
  foreach ($settings as $variable => $value) {
    variable_set($variable, $value);
    if (is_scalar($value)) {
      drush_print(dt('The "!var" variable has been set to !val.', array(
        '!var' => $variable,
        '!val' => $value
      )));
    }
    else {
      drush_print(dt('The "!var" has been set.', array('!var' => $variable)));
    }
  }
}

/**
 * Drush command helper function used to set permissions.
 */
function _drush_environment_perms_management($settings = array()) {
  $roles = array_flip(user_roles());
  foreach ($settings as $role => $perm_settings) {
    // Get the role id based on the role name.
    if (isset($roles[$role])) {
      $rid = $roles[$role];
    }
    else {
      return drush_set_error('DRUSH_DRUPAL_ERROR_MESSAGE', dt('That does not exist: !role', array('!role' => $role)));
    }

    // Group the grants and revokes
    $perms = array('grant' => array(), 'revoke' => array());
    foreach ($perm_settings as $perm => $grant) {
      if ($grant) {
        $perms['grant'][] = $perm;
      }
      else {
        $perms['revoke'][] = $perm;
      }
    }

    if (!empty($perms['grant'])) {
      user_role_grant_permissions($rid, $perms['grant']);
      drush_print(dt("Granted to '!role': !permissions", array(
        '!role' => $role,
        '!permissions' => implode(', ', $perms['grant'])
      )));
    }

    if (!empty($perms['revoke'])) {
      user_role_revoke_permissions($rid, $perms['revoke']);
      drush_print(dt("Revoked from '!role': !permissions", array(
        '!role' => $role,
        '!permissions' => implode(', ', $perms['revoke'])
      )));
    }
  }
}

/**
 * Format output into a simple list.
 */
function _env_format_simple_list($data) {

}

/**
 * Helper function to recursively merge arrays.
 */
function array_merge_recursive_distinct(array &$array1, array &$array2) {
  $merged = $array1;

  foreach ($array2 as $key => &$value) {
    if (is_array($value) && isset($merged[$key]) && is_array($merged [$key])) {
      $merged[$key] = array_merge_recursive_distinct($merged[$key], $value);
    }
    else {
      $merged[$key] = $value;
    }
  }

  return $merged;
}

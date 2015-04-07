<?php
/**
 * @file
 * Disables, uninstalls and reinstalls a module.
 */
/**
 * Command callback.
 */
function drush_sync_tools_sync_to_local($source) {
  // Sync the DB
  $commands[] = array(
    'command' => 'sql-sync',
    'arguments' => array('source' => $source, 'target' => '@self'),
    'options' => array(
      'yes' => TRUE,
      'create-db' => TRUE,
      'notify' => TRUE,
      'sanitize' => TRUE,
      'sanitize-email' => 'no',
    ),
  );

  // Run the standard reset
  $commands[] = array(
    'command' => 'reset',
  );

  // Apply the local settings
  // Requires: drush-denver
  $commands[] = array(
    'command' => 'env',
    'arguments' => array('local'),
    'options' => array('yes' => TRUE),
  );

  // Clear all caches.
  $commands[] = array(
    'command' => 'cache-clear',
    'arguments' => array('all'),
  );

  // Pass the drushrc file through to drush_invoke_process
  $default_options = array();
  if ($config = drush_get_option('config-file')) {
    $default_options['config'] = $config;
  }

  // Pull the latest changes from the git branch
  if (!drush_get_option('skip-git')) {
    drush_shell_exec('git pull');
    foreach (drush_shell_exec_output() as $msg) {
      drush_print($msg);
    }
  }

  foreach ($commands as $command) {
    $command += array('alias' => '@self', 'arguments' => array(), 'options' => array());
    $command['options'] += $default_options;

    drush_invoke_process($command['alias'], $command['command'], $command['arguments'], $command['options']);
    if (drush_get_error() != DRUSH_SUCCESS) {
      return drush_set_error('LOCAL_SYNC_FAILED', dt('Sync failed on drush @command.', array('@command' => $command['command'])));
    }
  }

  // Success!
  drush_log(dt('Local sync completed.'), 'success');
}

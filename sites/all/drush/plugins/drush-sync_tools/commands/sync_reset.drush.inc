<?php
/**
 * @file
 * Disables, uninstalls and reinstalls a module.
 */
/**
 * Command callback.
 */
function drush_sync_tools_reset() {
  $commands[] = array(
    'command' => 'rr',
    'options' => array('yes' => TRUE),
  );
  $commands[] = array(
    'command' => 'updatedb',
    'options' => array('yes' => TRUE),
  );
  $commands[] = array(
    'command' => 'cache-clear',
    'arguments' => array('drush'),
  );
  $commands[] = array(
    'command' => 'features-revert-all',
    'options' => array('yes' => TRUE),
  );
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

  // Run the commands
  foreach ($commands as $command) {
    $command += array('alias' => '@self', 'arguments' => array(), 'options' => array());
    $command['options'] += $default_options;

    drush_invoke_process($command['alias'], $command['command'], $command['arguments'], $command['options']);
    if (drush_get_error() != DRUSH_SUCCESS) {
      return drush_set_error('FLUSH_FAILED', dt('Reset failed on drush @command.', array('@command' => $command['command'])));
    }
  }

  // Success!
  drush_log(dt('Reset completed.'), 'success');
}

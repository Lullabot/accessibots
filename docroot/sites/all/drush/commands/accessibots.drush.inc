<?php

function accessibots_drush_command() {
  $items['build'] = array(
    'description' => 'Rebuild a local instance with a fresh DB and codebase.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
      'sync' => 'Sync the prod database in the build.',
    ),
  );

  return $items;
}

/**
 * One stop shop to prep your local instance.
 */
function drush_accessibots_build() {
  // Update the git repo
  drush_shell_exec('git pull');
  foreach (drush_shell_exec_output() as $msg) {
    drush_print($msg);
  }

  // Update composer
  drush_shell_exec('cd ..; php ./composer.phar update');
  foreach (drush_shell_exec_output() as $msg) {
    drush_print($msg);
  }

  if (drush_get_option('sync')) {
    // Run the full sync script
    drush_invoke_process('@self', 'sync-to-local', array('source' => '@ab.prod'),  array('skip-git' => TRUE));
  }
  else {
    // Run the reset script
    drush_invoke_process('@self', 'reset', array(), array('skip-git' => TRUE));
  }

  // Build CSS
  drush_shell_exec('drush sass-compile');
  foreach (drush_shell_exec_output() as $msg) {
    drush_print($msg);
  }
}

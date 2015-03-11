<?php

/**
 * Include settings files common to all environments.
 */
foreach (glob(__DIR__ . '/settings/common/*.inc') as $file) {
  include_once $file;
}

/**
 * Include settings files for command line PHP (drush).
 */
if (PHP_SAPI == 'cli') {
  foreach (glob(__DIR__ . "/settings/drush/*.inc") as $file) {
    include_once $file;
  }
}

/**
 * Include files that contain the database settings and other environment
 * specific settings. We store the database settings in an external file so they
 * can be different per environment and because they should never exist in a
 * file that exists in a git/svn repository for extra security.
 */
if (file_exists('../settings.local.php')) {
  require '../settings.local.php';
}

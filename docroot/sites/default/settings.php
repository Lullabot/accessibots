<?php
$settings = array();

/**
 * Include settings files common to all environments.
 */
$settings['common'] = __DIR__ . '/settings/common.inc';

/**
 * Include settings files for command line PHP (drush).
 */
if (PHP_SAPI == 'cli') {
  $settings['drush'] = __DIR__ . "/settings/drush.inc";
}

/**
 * Include settings files specific to this environment.
 */
if (!empty($_ENV['SITE_ENVIRONMENT'])) {
  $settings[$_ENV['SITE_ENVIRONMENT']] = __DIR__ . "/settings/{$_ENV['SITE_ENVIRONMENT']}.inc";
}

/**
 * Include files that contain the database settings and other environment
 * specific settings. We store the database settings in an external file so they
 * can be different per environment and because they should never exist in a
 * file that exists in a git/svn repository for extra security.
 */
$settings['local'] = "../settings.local.php";

foreach ($settings as $file) {
  if (file_exists($file)) {
    require $file;
  }
}

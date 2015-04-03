<?php
/**
 * Aliases for Accessibots
 */

print_r($_SERVER);

// Parent aliases
if ($_SERVER['HOSTNAME'] != 'vhost.162unlimited.com') {
  $aliases['_remote'] = array(
    'remote-host' => '204.62.14.91',
    'remote-user' => 'accessibot',
    'path-aliases' => array(
      '%dump-dir' => '/var/www/db',
    ),
  );
}

// Stage
$aliases['stage'] = array(
  'parent' => '@ab._remote',
  'root' => '/var/www/htdocs/accessibots/stage/docroot',
  'uri' => 'stage.accessibots.io',
);

// Prod
$aliases['prod'] = array(
  'parent' => '@ab._remote',
  'root' => '/var/www/htdocs/accessibots/prod/docroot',
  'uri' => 'accessibots.io',
);

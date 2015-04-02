<?php

/**
 * @file
 * Configuration file for Drupal's multi-site directory aliasing feature.
 */

//$sites['accessibots.io'] = 'accessibots';

$local_sites = __DIR__ . '/sites.local.php';
if (file_exists($local_sites)) {
  include($local_sites);
}

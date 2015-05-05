<?php
/**
 * @file
 * Example environment definition file.
 */

/**
 * In a group file (env.drushrc.php)
 */
$env['example'] = array(
  // The list of modules to enabled (1) or disable (0).
  'modules' => array(
    'devel'       => 1,
    'securepages' => 0,
  ),

  // The list of variables to configure.
  'vars' => array(
    'preprocess_css' => 0,
    'preprocess_js'  => 0,
  ),

  // The list of roles to grant (1) and revoke (0) on a per role basis.
  'perms' => array(
    'Administrator' => array (
      'administer features' => 1,
      'administer permissions' => 1,
    ),
    'anonymous user' => array (
      'administer features' => 0,
      'administer permissions' => 0,
    )
  ),
);

/**
 * In a single definition file (example.env.drushrc.php).
 */
$env = array(
  // The list of modules to enabled (1) or disable (0).
  'modules' => array(
    'devel'       => 1,
    'securepages' => 0,
  ),

  // The list of variables to configure.
  'vars' => array(
    'preprocess_css' => 0,
    'preprocess_js'  => 0,
  ),

  // The list of roles to grant (1) and revoke (0) on a per role basis.
  'perms' => array(
    'Administrator' => array (
      'administer features' => 1,
      'administer permissions' => 1,
    ),
    'anonymous user' => array (
      'administer features' => 0,
      'administer permissions' => 0,
    )
  ),
);

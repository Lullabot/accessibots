<?php
/**
 * Generic local env settings.
 */
$env = array(
  'modules' => array(
    'coffee' => 1,
  ),
  'vars'    => array(
    'syslog_format' => '[!type] !message',
  ),
  'perms'   => array(
    'anonymous user' => array(),
    'authenticated user' => array(),
  ),
);

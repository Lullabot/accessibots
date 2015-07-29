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
    'stage_file_proxy_hotlink' => 1,
  ),
  'perms'   => array(
    'anonymous user' => array(),
    'authenticated user' => array(),
  ),
);

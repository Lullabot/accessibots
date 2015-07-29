<?php
/**
 * Generic local env settings.
 */
$env = array(
  'modules' => array(
    'devel' => 1,
    'field_ui' => 1,
    'views_ui' => 1,
    'update' => 1,
    'fpa' => 1,
    'admin_devel' => 1,
    'stage_file_proxy' => 1,
  ),
  'vars'    => array(
    'cache' => 0,
    'block_cache' => 0,
    'preprocess_js' => 0,
    'preprocess_css' => 0,
    'stage_file_proxy_origin' => 'http://live-accessibots.pantheon.io',
    'stage_file_proxy_origin_dir' => 'sites/default/files',
    'stage_file_proxy_use_imagecache_root' => 1,
  ),
  'perms'   => array(
    'anonymous user' => array(
      'access devel information' => 1,
    ),
    'authenticated user' => array(),
  ),
);

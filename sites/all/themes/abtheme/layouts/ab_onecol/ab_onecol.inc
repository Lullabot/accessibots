<?php
// Plugin definition
$plugin = array(
  'title'    => t('Accessibots OneCol'),
  'description' => t('Simple, one column layout.'),
  'category' => t('Accessibots'),
  'icon'     => 'abots_onecol.png',
  'theme'    => 'ab_onecol',
  'css'      => 'css/abots_onecol.css',
  'admin css' => 'css/abots_onecol_admin.css',
  'regions'  => array(
    'header' => t('Header'),
    'main'   => t('Main'),
  ),
);

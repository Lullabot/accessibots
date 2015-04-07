<?php

// Set memory limit to unlimited in drush.
ini_set('memory_limit', '-1');
// Ensure display errors is on in drush.
ini_set('display_errors', '1');
// Report running errors and notices.
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);

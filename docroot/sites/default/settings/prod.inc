<?php
// Performance settings
$conf['preprocess_css'] = 1;
$conf['preprocess_js'] = 1;

// Ensure errors are never displayed on prod/stage environment.
ini_set('display_errors', 'Off');
$conf['error_level'] = 0;

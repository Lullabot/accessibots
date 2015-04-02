<?php
// Patchfile Settings.
$options['patch-file'] = '../patches.make';

// Add our commands directory.
$options['include'][] = __DIR__ . '/drush/commands';

// Add our aliases.
$options['alias-path'][] = __DIR__ . '/drush/aliases';

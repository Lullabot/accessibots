<?php
// Patchfile Settings.
$options['patch-file'] = '../patches.make';

// Add our plugins directory.
$options['include'][] = __DIR__ . '/plugins';

// Add our commands directory.
$options['include'][] = __DIR__ . '/commands';

// Add our aliases.
$options['alias-path'][] = __DIR__ . '/aliases';

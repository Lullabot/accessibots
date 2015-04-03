<?php
$root = str_replace('/drush', '', dirname(__FILE__));

// Patchfile Settings.
$options['patch-file'] = '../patches.make';

// Add our plugins directory.
$options['include'][] = __DIR__ . '/plugins';

// Add our commands directory.
$options['include'][] = __DIR__ . '/commands';

// Add our aliases.
$options['alias-path'][] = __DIR__ . '/aliases';

// Custom shell aliases
$options['shell-aliases']['sass-compile'] = '!cd ' . $root . '/themes/abtheme && bundle install && sass -f --update --style=compressed _scss:css';
$options['shell-aliases']['sass-watch'] = '!cd ' . $root . '/themes/abtheme && bundle install && sass --watch _scss:css';

<?php
$root = str_replace('/drush', '', dirname(__FILE__));

// Patchfile Settings.
$options['patch-file'] = 'sites/all/patches.make';

// DO NOT UPDATE CORE WITH DRUSH!  USE PANTHEON!
$options['no-core'] = TRUE;

// Add our plugins directory.
$options['include'][] = __DIR__ . '/plugins';

// Add our commands directory.
$options['include'][] = __DIR__ . '/commands';

// Add our aliases.
$options['alias-path'][] = __DIR__ . '/aliases';

// Custom shell aliases for sass compiling
$options['shell-aliases']['sass-compile'] = '!cd ' . $root . '/themes/abtheme && bundle install && sass -fr sass-globbing --update --style=expanded --debug-info _scss:css';
$options['shell-aliases']['sass-watch'] = '!cd ' . $root . '/themes/abtheme && bundle install && sass -rsass-globbing --watch _scss:css';

/*
 * Customize this associative array with your own tables. This is the list of
 * tables whose *data* is skipped by the 'sql-dump' and 'sql-sync' commands when
 * a structure-tables-key is provided. You may add new tables to the existing
 * array or add a new element.
 */
$options['structure-tables'] = array(
  'common' => array(
    'batch',
    'cache',
    'cache_*',
    'ctools_*_cache',
    'flood',
    'history',
    'honeypot_user',
    'mollom',
    'search_*',
    'sessions',
    'watchdog',
    'webform_submissions',
    'webform_submitted_data',
  ),
);

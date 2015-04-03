#!/usr/bin/env bash
set -ex

ROOT="/var/www/htdocs/accessibots/prod"
WEBROOT="/var/www/htdocs/accessibots/prod/docroot"

cd $ROOT

# Update composer
if [ -d vendor ]; then
  php ./composer.phar update
else
  php ./composer.phar install
fi

cd $WEBROOT

# Put site in maintenance mode
drush vset --exact maintenance_mode 1

# Run updates, reverts and flushes
drush cc drush
drush reset --skip-git

# Compile CSS
drush sass-compile

# Take site out of maintenance mode
drush vset --exact maintenance_mode 0

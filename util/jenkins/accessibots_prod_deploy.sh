#!/usr/bin/env bash
set -ex

REPO="git@github.com:Lullabot/accessibots.git"
ROOT="/var/www/htdocs/accessibots/prod"
WEBROOT="/var/www/htdocs/accessibots/prod/docroot"
WORKSPACE="/home/jenkins/jobs/Accessibots Prod Deploy/workspace/"

# Put site in maintenance mode

cd $ROOT

# Update composer
if [ -d vendor ]; then
  php ./composer.phar update
else
  php ./composer.phar install
fi

cd $WEBROOT

# Run updates, reverts and flushes
drush cc drush
drush reset --skip-git

# Compile CSS

# Take site out of maintenance mode

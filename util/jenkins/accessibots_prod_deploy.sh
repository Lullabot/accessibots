#!/usr/bin/env bash
set -ex

REPO="git@github.com:Lullabot/accessibots.git"
ROOT="/var/www/htdocs/accessibots/prod"

cd $ROOT

if [ -d "vendor" ]; then
  php ./composer.phar update
else
  php ./composer.phar install
fi

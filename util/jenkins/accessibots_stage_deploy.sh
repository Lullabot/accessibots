#!/usr/bin/env bash
set -ex

REPO="git@github.com:Lullabot/accessibots.git"
ROOT="/var/www/htdocs/accessibots/stage"

cd $ROOT

php ./composer.phar update

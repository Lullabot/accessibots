#!/usr/bin/env bash
set -ex

REPO="git@github.com:Lullabot/accessibots.git"
ROOT="/var/www/htdocs/accessibots/prod"
WORKSPACE="/home/jenkins/jobs/Accessibots Prod Deploy/workspace/"

cd $ROOT

# Run updates, reverts and flushes
drush reset

# Compile CSS

#!/usr/bin/env bash
#
# Wrapper around the HUB utility to simplify creating PRs.
# Symlink this into a directory in your $PATH for easier access.

HUB_LOC=`which hub`

# Ensure HUB is installed
if [ -z $HUB_LOC ]; then
  echo "Could not find HUB. Please install the HUB utility to use this command. https://hub.github.com"
  exit 1
fi

# Ensure the title is set and formatted properly.
if [ -z "$1" ]; then
  echo 'Usage: pullRequest "Add a Pull Request Title Here"'
  exit 1
fi

# Get the branch name
NAME=$(git branch | grep '*' | sed 's/* //')

# Grab the ticket string out of the branch name.
TICKET=$(echo $NAME | grep -o '\-[0-9]*\-')

# Strip off the hyphens to get the issue number.
TICKET="${TICKET:1:${#TICKET}-2}"

# Construct the message with the ticket name at the beginning.
MSG="[#$TICKET] $1"

# Create the PR
URL=$(hub pull-request -b master -m "$MSG" -i "$TICKET")
echo "Pull Request $MSG created at $URL"

# Open it in the browser
open $URL

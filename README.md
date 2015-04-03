# Accessibots.io
## Getting Started
1. Clone the repo
1. Add settings.local.php parallel to the docroot and add your DB settings.
1. Move within the docroot and run `drush build --sync`

## SASS
CSS files are not stored in the repo.  Use these commands to compile your
styles.

- `drush sass-compile`
- `drush sass-watch`

## Making Changes
Anything pushed to the master branch will be deployed.  Make sure it works
properly on your local before doing this.

Production will run all the necessary commands to update the DB, deploy the
code and compile the styles.

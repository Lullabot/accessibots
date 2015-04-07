# Drupal Environment Personalizer
This is a fork of the sandbox project at https://drupal.org/sandbox/bleen18/1696714
which is based on the code by Eric Duran at http://drupal.org/sandbox/ericduran/1154642

The Drupal ENVironemnt personalizER allows you to define blanket settings to apply to
your site in one command, such as enabling and disabling modules and setting
variables.

## Installation
Extract this repository into any of Drush's searchable paths for plugins:

1. A `.drush` folder in your HOME folder.

2. Anywhere in a folder tree below an active module on your site.

3. `/usr/share/drush/commands` (configurable)

4. In an arbitrary folder specified with the `--include` option.

5. Drupal's `/drush` or `/sites/all/drush` folders.


*See `drush topic docs-commands` for more details*

## Configuration

These can be defined in two different files and only apply to the site directory
in which they are defined.

1. `sites/[default|example.com]/drush/env.drushrc.php`

2. `sites/[default|example.com]/drush/[dev.]env.drushrc.php`


Like aliases, in the first file you can define multiple aliases keyed on the
definition name such as 'dev,' 'stage' or 'chris.' In the second example you can
define each environment in a separate file and prefix the filename with the
definition name.

The definitions are formatted as such:

    $env['dev'] = array(
      // The list of modules to enabled (1) or disable (0).
      'modules' => array(
        'devel'       => 1,
        'securepages' => 0,
      ),

      // The list of variables to configure.
      'vars' => array(
        'preprocess_css' => 0,
        'preprocess_js'  => 0,
      ),

      // The list of roles to grant (1) and revoke (0) on a per role basis.
      'perms' => array(
        'Administrator' => array (
          'administer features' => 1,
          'administer permissions' => 1,
        ),
        'anonymous user' => array (
          'administer features' => 0,
          'administer permissions' => 0,
        )
      ),
    );

OR if using a named file like dev.env.drushrc.php, simply remove the name key
from the $env array.

    $env = array(
      'modules' => array(),
      'vars'    => array(),
      'perms'   => array(),
    );


## How to Use It

You must be inside a Drupal site directory or use an alias for these commands to
work (multisite alias support is coming soon).

1. Create a starter file

    `drush env-dir --make`

1. See which environments are available.

    `drush env-list`

2. Inspect the contents of an environment definition.

    `drush env-list [env-name]`

    Ex. `drush env-list dev`

3. Run the environment settings for a single definition.

    `drush env [env-name]`

    Ex. `drush env dev`

4. Combine multiple environments.  The settings for the latter overriding the former.

    `drush env [env-name1]+[env-name2]`

    Ex. `drush env dev+chris`

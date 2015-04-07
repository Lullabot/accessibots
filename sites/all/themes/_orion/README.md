# Orion Rapid Prototyping Library
Version 3.x

https://github.com/KeyboardCowboy/orion

Orion is my own library of [SASS](http://sass-lang.com/) components and [Jade](http://jade-lang.com/) base layouts I've compiled
over time in order to facilitate rapid prototyping for responsive and
cross-browser compatible websites.

## Libraries
Orion ships with various 3rd party libraries:

### Included
Some libraries are included in Orion and are loaded automatically.
- [Bourbon](http://bourbon.io) for CSS3 and multi-vendor support (required for Orion to work)
- [Zen Grids](http://zengrids.com) for responsive grid layouts
- [Typeplate, v1.1.2](http://typeplate.com) for typography
- [Normalize, v2.1.3](http://necolas.github.io/normalize.css) for cross browser consistency

### Experimental
- [Foundation](http://foundation.zurb.com/docs/sass.html) components are being wrapped for easier implementation and to prevent unnecessary styles from being injected into the stylesheets.


## How to Use Orion
1. Drop Orion into your project.

        - mySassProject
          - orion
          - _vars.scss
          - _mixins.scss
          - styles.scss

2. Import the orion partial into your SCSS file.

  `@import 'orion/orion';`

3. Add any custom variables and mixins, especially any variables that typeplate may use if you are including that.

        @import 'vars';
        @import 'mixins';

4. (Optional) Import starter styles

        @import 'orion/normalize';
        @import 'orion/typeplate';

5. Add your own styles.

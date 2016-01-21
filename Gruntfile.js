module.exports = function(grunt) {

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    sass: {
      options: {
        style: 'compressed'
      },
      dist: {
        options: {
          style: 'compressed'
        },
        files: {
          'css/main.css': '_scss/main.scss'
        }
      }
    },
    sass_globbing: {
      dist: {
        files: {
          '_scss/styles/_components.scss': '_scss/styles/components/**/*.scss',
          '_scss/styles/_nodes.scss': '_scss/styles/nodes/**/*.scss',
          '_scss/styles/_pages.scss': '_scss/styles/pages/**/*.scss'
        }
      },
      options: {
        useSingleQuotes: true
      }
    },
    watch: {
      css: {
        files: ['_scss/**/*.scss'],
        tasks: ['sass_globbing', 'sass', 'autoprefixer', 'px_to_rem', 'csslint', 'cssmin'],
        options: {
          livereload: true,
          spawn: false
        }
      },
      js: {
        files: ['js/raw/*.js'],
        tasks: ['uglify'],
        options: {
          mangle: false
        }
      }
    },
    autoprefixer: {
      options: {
        browsers: ['last 3 versions', 'ie 9', 'iOS > 6', 'Safari > 6']
      },
      single_file: {
        src: 'css/main.css',
        dest: 'css/main.css'
      }
    },
    px_to_rem: {
      files: {
        'css/main.css': ['css/main.css']
      }
    },
    csslint: {
      options: {
        csslintrc: '.csslintrc',
        src: ['css/main.css']
      }
    },
    cssmin: {
      target: {
        files: [{
          expand: true,
          cwd: 'css',
          src: ['*.css', '!*.min.css'],
          dest: 'css',
          ext: '.min.css'
        }]
      }
    },
    uglify: {
      options: {
        mangle: false
      },
      my_target: {
        files: {
          'js/accessibots.min.js': ['js/raw/jquery.sticky.js', 'js/raw/global.js']
        }
      }
    }
  });

  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-sass-globbing');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-wiredep');
  grunt.loadNpmTasks('grunt-autoprefixer');
  grunt.loadNpmTasks('grunt-px-to-rem');
  grunt.loadNpmTasks('grunt-contrib-csslint');
  grunt.loadNpmTasks('grunt-contrib-cssmin');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-shell');
  grunt.loadNpmTasks('grunt-contrib-uglify');

  grunt.registerTask('default', [
    'sass_globbing',
    'sass',
    'autoprefixer',
    'px_to_rem',
    'csslint',
    'cssmin',
    'uglify'
  ]);
};

module.exports = function(grunt) {

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    sass: {
      options: {
        //sourceMap: true
      },
      dist: {
        files: {
          'css/abtheme.css': '_scss/abtheme.scss',
          'css/wysiwyg.css': '_scss/wysiwyg.scss'
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
        tasks: ['sass_globbing', 'sass', 'autoprefixer', 'px_to_rem'],
        options: {
          livereload: true,
          spawn: false
        }
      }
    },
    clean: {
      css: [
        'css/abtheme.css',
        'css/abtheme.min.css'
      ]
    },
    autoprefixer: {
      options: {
        browsers: ['last 3 versions', 'ie 9', 'iOS > 6', 'Safari > 6']
      },
      single_file: {
        src: 'css/abtheme.css',
        dest: 'css/abtheme.css'
      }
    },
    px_to_rem: {
      files: {
        'css/style.css': ['css/abtheme.css']
      }
    },
    csslint: {
      options: {
        csslintrc: '.csslintrc',
        src: ['css/abtheme.css']
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
    }
  });

  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-sass-globbing');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-wiredep');
  grunt.loadNpmTasks('grunt-autoprefixer');
  grunt.loadNpmTasks('grunt-px-to-rem');
  grunt.loadNpmTasks('grunt-contrib-csslint');
  grunt.loadNpmTasks('grunt-contrib-cssmin');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-shell');

  grunt.registerTask('default', [
    'clean:css',
    'sass_globbing',
    'sass',
    'autoprefixer',
    'px_to_rem',
    'csslint',
    'cssmin'
  ]);
};

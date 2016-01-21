(function($) {
  var Accessibots = {
    /**
     * Initialize.
     */
    init: function() {
      // Make the header sticky
      //this.stickyNav();

      this.menuSetup();

      // Convert SVG Images
      this.convertSVG();
    },

    menuSetup: function() {
      var $nav = $('.js-nav-toggle');

      $nav.once().click(function() {
        $('#main-nav').toggleClass('active');
        if ($('.js-nav-toggle span').text().trim() === 'Open menu') {
          $('.js-nav-toggle span').text('Close menu');
        }
        else {
          $('.js-nav-toggle span').text('Open menu');
        }
      });

      $('#main-nav').find('ul > li:last-child a').blur(function() {
        $nav.focus();
      });
    },

    /**
     * Fix the main nav to the top of the screen.
     */
    stickyNav: function() {
      $("#main-nav").sticky();
    },

    /*
     * Replace all SVG images with inline SVG
     */
    convertSVG: function() {

      $("img[src$='svg']").each(function () {
        var $img = $(this);
        var imgID = $img.attr('id');
        var imgClass = $img.attr('class');
        var imgURL = $img.attr('src');

        $.get(imgURL, function (data) {
          // Get the SVG tag, ignore the rest
          var $svg = $(data).find('svg');

          // Add replaced image's ID to the new SVG
          if (typeof imgID !== 'undefined') {
            $svg = $svg.attr('id', imgID);
          }
          // Add replaced image's classes to the new SVG
          if (typeof imgClass !== 'undefined') {
            $svg = $svg.attr('class', imgClass + ' replaced-svg');
          }

          // Remove any invalid XML tags as per http://validator.w3.org
          $svg = $svg.removeAttr('xmlns:a');

          // Replace image with new SVG
          $img.replaceWith($svg);

        }, 'xml');
      });
    }
  };

  $(document).ready(function() {
    Accessibots.init();
  });
})(jQuery);

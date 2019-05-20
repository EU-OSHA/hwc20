/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_facets = {
        attach: function(context, settings) {
            jQuery( "#napo_films .left, #napo_films .right" ).click(function() {
                jQuery("#napo_films video").trigger('pause');
            });
        }
    }

})(jQuery);

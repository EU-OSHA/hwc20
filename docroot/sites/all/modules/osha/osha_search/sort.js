/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_sort = {
        attach: function(context, settings) {
            jQuery('#edit-sort-by').change(function(){
                jQuery('#views-exposed-form-search-site #edit-sort-by--2').val(jQuery(this).val());
                jQuery('#views-exposed-form-search-site').submit();
            });
            if (jQuery('#osha-search-sort-form').length) {
              document.getElementById('osha-search-sort-form').onsubmit = function() {
                return false;
              };
            }
        }
    }
})(jQuery);

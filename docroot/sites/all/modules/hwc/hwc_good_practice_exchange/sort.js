/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_sort = {
        attach: function(context, settings) {
            jQuery('#edit-sort-by').change(function(){
                jQuery('#views-exposed-form-documents-gpep #edit-sort-by--2, #views-exposed-form-documents-page-1 #edit-sort-by--2, #views-exposed-form-documents-page-2 #edit-sort-by--2').val(jQuery(this).val());
                jQuery('#views-exposed-form-documents-gpep, #views-exposed-form-documents-page-1, #views-exposed-form-documents-page-2').submit();
            });
            jQuery('#edit-sort-order').change(function(){
                jQuery('#views-exposed-form-documents-gpep #edit-sort-order--2, #views-exposed-form-documents-page-1 #edit-sort-order--2, #views-exposed-form-documents-page-2 #edit-sort-order--2').val(jQuery(this).val());
                jQuery('#views-exposed-form-documents-gpep, #views-exposed-form-documents-page-1, #views-exposed-form-documents-page-2').submit();
            });
            if (jQuery('#hwc-good-practice-exchange-sort-form').length) {
                document.getElementById('hwc-good-practice-exchange-sort-form').onsubmit = function() {
                return false;
              };
            }
        }
    }
})(jQuery);

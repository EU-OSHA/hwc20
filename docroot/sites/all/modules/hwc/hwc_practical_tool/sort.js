/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_sort = {
        attach: function(context, settings) {
            jQuery('.page-practical-tools .region-sidebar-first .block-facetapi a').click(function () {
                    jQuery('.view-content .loader').remove();
                    jQuery('.view-content').prepend('<div class="loader"><img id="tmgmt-4" src="/sites/all/themes/hwc_frontend/images/hwc_clock.png" alt=""><p id="tmgmt-5">' + Drupal.settings.loader_text + '</p></div>');
                }
            );

            jQuery('#practical-tool-more-link').click(function() {
                jQuery('#more-filters-block').slideDown();
                jQuery(this).hide();
                return false;
            });
            jQuery('#practical-tool-less-link').click(function() {
                jQuery('#practical-tool-more-link').show();
                jQuery('#more-filters-block').slideUp();
                return false;
            });

            jQuery('#edit-sort-by').change(function(){
                jQuery('#views-exposed-form-practical-tools-page #edit-sort-by--2').val(jQuery(this).val());
                jQuery('#views-exposed-form-practical-tools-page').submit();
            });
            jQuery('#edit-sort-order').change(function(){
                jQuery('#views-exposed-form-practical-tools-page #edit-sort-order--2').val(jQuery(this).val());
                jQuery('#views-exposed-form-practical-tools-page').submit();
            });
            if (jQuery('#hwc-practical-tool-sort-form').length) {
              document.getElementById('hwc-practical-tool-sort-form').onsubmit = function() {
                return false;
              };
            }
        }
    }
})(jQuery);

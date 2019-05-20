/**
 * Created by dragos on 11/19/14.
 *
 * Inspired from facetapi.js
 */

(function ($) {

    Drupal.behaviors.search_facets = {
        attach: function(context, settings) {
            if (Drupal.settings.facet_items != 'undefined') {
                for (var i in Drupal.settings.facet_items) {
                    for (var j = 0; j < Drupal.settings.facet_items[i].length; j++) {
                        jQuery('#remove_filter').append(Drupal.settings.facet_items[i][j]);
                    }
                }
            }
            jQuery('.page-search .region-sidebar-first').once('publication_toggle_facets', function() {
                jQuery('.block-facetapi .facetapi-facetapi-checkbox-links').hide();
                jQuery('.block-facetapi .facetapi-facetapi-checkbox-links').has('input:checked').show();
                jQuery('.block-facetapi .facetapi-facetapi-checkbox-links').siblings('h2').on('click', function() {
                    var $checkboxes = jQuery(this).parent().find('.facetapi-facetapi-checkbox-links');
                    if ($checkboxes.is(':visible')) {
                        $checkboxes.slideUp();
                        jQuery(this).removeClass('area-shown');
                    }
                    else {
                        jQuery(this).addClass('area-shown');
                        $checkboxes.slideDown();
                    }
                });
            });
        }
    }

    Drupal.behaviors.dropdownfacetapi = {
        attach: function(context, settings) {
            if (settings.facetapi) {
                for (var index in settings.facetapi.facets) {
                    if (null != settings.facetapi.facets[index].makeDropdown) {
                        if(Drupal.facetapi){
                            Drupal.facetapi.makeOptions(settings.facetapi.facets[index].id);
                        }
                    }
                }
            }
        }
    };

    /**
     * Copy all the facet links into select.
     * Ensures the facet is disabled if a link is clicked.
     */
    if(Drupal.facetapi){
        Drupal.facetapi.makeOptions = function(facet_id) {
            var $facet = $('#' + facet_id),
                $links = $('a.facetapi-dropdown', $facet);

            var $container = $facet.hide().closest('.block-facetapi .item-list');

            var $active = $('a.facetapi-dropdown.facetapi-active', $facet);

            // If active exists don't attach the select widget.
            if ($active.length == 0) {
                var $select = $('<select id="select_' + facet_id + '">' +
                    '<option>' + Drupal.settings.osha_search.any_option + '</option>' +
                    '</select>');
                $select.appendTo($container);
                // Find all checkbox facet links and add them an option.
                $links.once('facetapi-makeOption').each(
                    function() {
                        Drupal.facetapi.makeOption($select, this);
                    }
                );
                $select.change(function () {
                    window.location.href = $(this).find(':checked').data('href');
                });
                $container.find('.facetapi-limit-link').remove();
            }
            else {
                $active.once('facetapi-makeDropdownRL').each(function(){
                    $container.append($(this).parent().html());
                });
            }

            $links.once('facetapi-disableClick').click(function (e) {
                Drupal.facetapi.disableFacet($facet);
            });

        };
    }

    /**
     * Move click links in select options
     */
    if(Drupal.facetapi){
        Drupal.facetapi.makeOption = function($select, elem) {
            var $link = $(elem),
                active = $link.hasClass('facetapi-active');

            // Get the option text.
            var $link_clone = $link.clone();
            $link_clone.find('.element-invisible').remove();
            var href = $link.attr('href');
            // Attach the option.
            var $option = $('<option data-href="'+ href +'">' + $link_clone.html() + '</option>');
            $select.append($option);
        }
    }

})(jQuery);

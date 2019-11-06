(function($){
    Drupal.behaviors.osha_back_button = {
        attach: function(context, settings) {
            $(".back-to-link").once('osha_back_button', function(){
                var $this = $(this);
                var url = window.location.origin + $this.attr('href');
                // if user is coming from the listing, make history back
                // to keep the potential query parameters.
                if (document.referrer.indexOf(url) === 0) {
                    $this.on('click', function(e){
                        e.preventDefault();
                        history.go(-1);
                    });
                }
            });
        }
    }
})(jQuery);


jQuery(document).ready(function($){
    if ($(".previous-next .previous")[0]){
        $(".previous-next").addClass('two-arrows');
    }
});

jQuery(document).ready(function($){
    if(/(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|ipad|iris|kindle|Android|Silk|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(navigator.userAgent) 
        || /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(navigator.userAgent.substr(0,4))) { 
        $("#block-hwc-hwc-print-friendly").addClass('hide');
        $("#block-text-resize-0").addClass('hide');
        $('#block-on-the-web-0').addClass('isMobile');
    }
});



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
            jQuery('.page-search .region-sidebar-first, .page-documents .region-sidebar-first').once('publication_toggle_facets', function() {
                jQuery('.block-facetapi .facetapi-facetapi-checkbox-links').hide();
                if (!jQuery('.page-practical-tools').length) {
                    if (jQuery(window).width() > 992) {
                        jQuery('.block-facetapi .facetapi-facetapi-checkbox-links.facetapi-facet-field-priority-area').show();
                        jQuery('.block-facetapi .facetapi-facetapi-checkbox-links').has('input:checked').show();
                    }
                }
                else {
                    if (jQuery(window).width() > 992) {
                        jQuery('.block-facetapi .facetapi-facetapi-checkbox-links.facetapi-facet-field-priority-area').show();
                        jQuery('.block-facetapi .facetapi-facetapi-checkbox-links').has('input:checked').show();
                        // jQuery('.block-facetapi .facetapi-facetapi-checkbox-links.facetapi-facet-field-item-type').show();
                    }
                }

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

(function($){
    Drupal.behaviors.hwc_alpha_pager = {
        attach: function (context, settings) {
            $('.hwc-alpha-pager-view').once('hwc_alpha_pager', function() {
                var quicktab_page = $('.hwc-alpha-pager-view .quicktabs-tabpage');
                if (quicktab_page.length > 0) {
                    quicktab_page.each(function(idx, container) {
                        hwc_alpha_pager_parse_container(container, idx, '.quicktabs-views-group');
                    });
                }
                else {
                    $('.hwc-alpha-pager-view').each(function(idx, container) {
                        hwc_alpha_pager_parse_container(container, idx, '.views-row');
                    });
                }

                $('body').on('click', '.hwc-char-link', function(e) {
                    e.preventDefault();
                    $('html, body').animate({
                        scrollTop: $($(this).attr('href')).offset().top - 60
                    }, 400);
                })
            });
        }
    };

    function hwc_alpha_pager_parse_container(container, idx, group_wrapper) {
        var chars = [];
        var char = '';
        var aa_type = $(container).hasClass('aa');
        var titles = $(container).find('.hwc-alpha-pager-view-title-field .field-content');
        titles.each(function(index, elem) {
            var first_char = $(elem).text()[0].toLowerCase();
            if (aa_type) {
                if ($(elem).data('iso')) {
                    first_char = $(elem).data('iso').toLowerCase();
                }
                else {
                    first_char = first_char + $(elem).text()[1].toLowerCase();
                }
            }
            if (first_char !== char) {
                char = first_char;
                chars.push(char);
                $(elem).closest(group_wrapper).before(hwc_alpha_pager_format_char(idx, char));
            }
            if (index > 0 && index == titles.length) {
                $(elem).closest(group_wrapper).before(hwc_alpha_pager_format_char(idx, char));
            }
        });

        if (aa_type) {
            if ($('.view-header', container).length) {
                $('.view-header', container).after(hwc_alpha_pager_format_alphabet(chars, idx, aa_type));
            }
            else {
                $(container).prepend(hwc_alpha_pager_format_alphabet(chars, idx, aa_type));
            }
        }
        else {
            $(container).prepend(hwc_alpha_pager_format_alphabet(chars, idx, aa_type));
        }
    }

    function hwc_alpha_pager_format_char(idx, char) {
        return '<div id="hwc-char-' + idx + '-' + char + '" class="char-anchor">' + char + '</div>';
    }

    function hwc_alpha_pager_format_alphabet(chars, prefix, aa_type) {
        var alphabet = "abcdefghijklmnopqrstuvwxyz".split("");
        var output = '<div class="hwc-alphabet-container">';
        $.each(alphabet, function(idx, char) {
            if (aa_type) {
                $.each(alphabet, function(idx2, char2) {
                    if ($.inArray(char+''+char2, chars) !== -1) {
                        output += '<a class="hwc-char-link" href="#hwc-char-' + prefix + '-' + char+''+char2 + '">' + char+''+char2 + '</span>';
                    }
                });
            }
            else {
                if ($.inArray(char, chars) != -1) {
                    output += '<a class="hwc-char-link" href="#hwc-char-' + prefix + '-' + char + '">' + char + '</span>';
                }
                else {
                    //HCW-950: Only the letters with content must be shown.
                    //output += '<a class="hwc-char-link disabled" href="javascript:void(0);">' + char + '</span>';
                }
            }
        });
        output += '</div>';
        return output;
    }

})(jQuery);
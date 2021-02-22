(function($){
    Drupal.behaviors.hwc_alpha_pager = {
        attach: function (context, settings) {
            $('.hwc-alpha-pager-view').once('hwc_alpha_pager', function () {
                var quicktab_page = $('.hwc-alpha-pager-view .quicktabs-tabpage');
                if (quicktab_page.length > 0) {
                    quicktab_page.each(function (idx, container) {
                        hwc_alpha_pager_parse_container(container, idx, '.quicktabs-views-group');
                    });
                }
                else {
                    $('.hwc-alpha-pager-view').each(function (idx, container) {
                        hwc_alpha_pager_parse_container(container, idx, '.views-row');
                    });
                }

                $('body').on('click', '.hwc-char-link', function (e) {
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
        var one_letter = false;
        if ($('.page-campaign-partners-official-campaign-partners').length) {
            one_letter = true;
        }

        var titles = $(container).find('.hwc-alpha-pager-view-title-field .field-content');
        titles.each(function (index, elem) {
            var first_char = $(elem).text()[0].toLowerCase();
            if (!one_letter) {
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

        if (!one_letter) {
            if ($('.view-header', container).length) {
                $('.view-header', container).after(hwc_alpha_pager_format_alphabet(chars, idx, one_letter));
            }
            else {
                $(container).prepend(hwc_alpha_pager_format_alphabet(chars, idx, one_letter));
            }
        }
        else {
            $(container).prepend(hwc_alpha_pager_format_alphabet(chars, idx, one_letter));
        }
    }

    function hwc_alpha_pager_format_char(idx, char) {
        return '<div id="hwc-char-' + idx + '-' + char + '" class="char-anchor">' + char + '</div>';
    }

    function hwc_alpha_pager_format_alphabet(chars, prefix, one_letter) {
        var alphabet = "abcdefghijklmnopqrstuvwxyz".split("");
        var output = '<div class="hwc-alphabet-container">';
        $.each(alphabet, function (idx, char) {
            if (!one_letter) {
                $.each(alphabet, function (idx2, char2) {
                    if ($.inArray(char + '' + char2, chars) !== -1) {
                        output += '<a class="hwc-char-link a1" href="#hwc-char-' + prefix + '-' + char + '' + char2 + '">' + char + '' + char2 + '</a> ';
                    }
                });
            }
            else {
                if ($.inArray(char, chars) != -1) {
                    output += '<a class="hwc-char-link b1" href="#hwc-char-' + prefix + '-' + char + '"> ' + char + '</a> ';
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
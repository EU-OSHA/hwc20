(function($){
    Drupal.behaviors.publication_form_submit = {
        attach: function(context, settings) {
            jQuery('#osha-publication-menu-case-studies-form .field-files a, #osha-publication-menu-publications-form .field-files a').attr('target','_blank');
            var $form = $('#osha-publication-menu-case-studies-form, #osha-publication-menu-publications-form');
            $form.find('input[type=checkbox]').click(function(){
                var $container = $(this).closest('.form-checkboxes');
                if ($(this).val() != 0) {
                    $container.find('[value=0]').prop('checked', false);
                }
                else {
                    $container.find('[type=checkbox]').not(this).prop('checked', false);
                }
                if ($container.find(':checked').length == 0) {
                    $container.find('[value=0]').prop('checked', true);
                }
                $form.submit();
            });
            $form.find('select').change(function() {
                $form.submit();
            });
            $form.find('input[type=text]').focusout(function() {
                $form.submit();
            });

        }
    }

    Drupal.behaviors.publication_toggle_facets = {
        attach: function(context, settings) {

            $('#osha-publication-menu-case-studies-form, #osha-publication-menu-publications-form').once('publication_toggle_facets', function(){
                $('.form-checkboxes.search-facet-field').hide();
                $('#edit-field-priority-area').show();
                $('#edit-field-publication-type').show();
                $('.form-checkboxes.search-facet-field').has('input:checked').show();
                if ($('#edit-language input:checked').length < 2) {
                    $('#edit-language').hide();
                    $('.form-item-language label').removeClass('active');
                }
                $('.form-checkboxes.search-facet-field').siblings('label').on('click', function() {
                    var $checkboxes = $(this).parent().find('.form-checkboxes.search-facet-field');
                    if ($checkboxes.is(':visible')) {
                        $checkboxes.slideUp();
                        $(this).removeClass('area-shown');
                    }
                    else {
                        $(this).addClass('area-shown');
                        $checkboxes.slideDown();
                    }
                });
            });
        }
    }
})(jQuery);

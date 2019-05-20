(function($){
    Drupal.behaviors.practical_tool = {
        attach: function(context, settings) {
            var $form = $('#hwc-practical-tool-menu-tools-form');
            $form.find('input[name=sort]').click(function(){
                $form.submit();
            });
            $form.find('select').change(function() {
                $form.submit();
            });
            $form.find('input[type=text]').focusout(function() {
                $form.submit();
            });
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
        }
    }

    Drupal.behaviors.publication_toggle_facets = {
        attach: function(context, settings) {

            $('#hwc-practical-tool-menu-tools-form').once('publication_toggle_facets', function(){
                $('.form-checkboxes.search-facet-field').hide();
                $('.form-checkboxes.search-facet-field').has('input:checked').show();
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

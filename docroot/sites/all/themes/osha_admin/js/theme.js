(function ($) {
    Drupal.behaviors.oshaAdminTheme = {
        attach: function (context, settings) {
            // Handler for Select all link in views exposed multiselect filter.
            // Add a link on filter element in form_alter in order for this to work.
            $('.osha-select-all-link').live('click', function() {
                $(this).parent().find('select[multiple=multiple] option').each(
                    function(index, elem) {
                        $(elem).attr('selected', 'selected');
                });
            });
        }
    };
})(jQuery);
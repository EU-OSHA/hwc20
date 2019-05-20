(function($){
    Drupal.behaviors.osha_gallery_reorder = {
        attach: function (context, settings) {
            $("#osha_gallery_files_sort_container").once('osha_gallery_reorder', function(){
                var container = $(this);
                container.sortable();
                container.disableSelection();
                $('.osha-gallery-make-first-button').on('click', function() {
                    $(this).closest('.osha-gallery-reorder-field').prependTo(container);
                    container.sortable("refresh");
                });
            });
        }
    };
})(jQuery);

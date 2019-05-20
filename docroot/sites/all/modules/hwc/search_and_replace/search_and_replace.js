(function($){
Drupal.behaviors.search_and_replace = {
    attach: function(context, settings) {
        $('#search-and-replace-form', context).once('search_and_replace').submit();
    }
}
})(jQuery);

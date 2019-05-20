(function ($) {
    console.log('sss');
    Drupal.behaviors.osh_image_gallery = {
        attach: function (context, settings) {
            $('body').once('osh_image_gallery', function(){
                $('body').on('click', '.media-item', function() {
                    window.location = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'file/' + $(this).attr('data-fid') + '/view';
                });
            });
        }
    };
}(jQuery));
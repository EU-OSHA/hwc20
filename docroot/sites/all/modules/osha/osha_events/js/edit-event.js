(function($){
    Drupal.behaviors.osha_event_edit_website = {
        attach: function (context, settings) {
            jQuery('#field-website-of-event-values .form-text').attr('readonly', 'true');
            jQuery('#field-website-of-event-values .form-item-field-website-of-event-und-0 .form-text').removeAttr('readonly');
        }
    }
})(jQuery);

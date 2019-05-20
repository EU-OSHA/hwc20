jQuery(document).ready(function()
{
    osha_events_hide_date_filters(1);
    jQuery('.view-id-events').show();
});

function osha_events_hide_date_filters(initial_load){
    jQuery('.events-filter-by-date ul').each(function(i) {
        if(!initial_load) { // onclick phase
            jQuery(this).hide();
        } else if(!jQuery(this).find('a.current_month').length && !jQuery(this).parent().find('a.current_year').length) { // init phase
            jQuery(this).hide();
        }
    });
}

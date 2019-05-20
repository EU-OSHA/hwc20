jQuery(document).ready(function() {

    //select all languages in the cart form
    jQuery('#edit-select-all-lng').change(function(){
        select_values('#edit-select-all-lng', '#edit-target-language', 'all');
    });

    // unchecked checkbox if select single options
    jQuery('#edit-target-language').change(function(){
        var selected_option = jQuery('#edit-target-language option:selected').length;
        var all_options = jQuery('#edit-target-language option').length;

        if (all_options - selected_option === 0) {
            jQuery('#edit-select-all-lng').attr("checked",true);
        } else {
            jQuery('#edit-select-all-lng').attr("checked",false);
        }
    });
});

/**
 * select and deselect multiple elements (or all) is a multi select drop down
 */
function select_values(source, target, values){
    jQuery('select'+target+' > option').attr('selected', '');

    if(jQuery(source).is(":checked")) {
        if(values == 'all') {
            jQuery('select'+target+' > option').attr('selected', 'selected');
        } else {
            jQuery.each(values, function(i, val){
                jQuery(''+target+' option[value="'+val+'"]').attr('selected', 'selected');
            });
        }
    }
}
jQuery(document).ready(function() {
  jQuery("#block-system-main .view-id-admin_events table tr").each(function() {
    var color = jQuery.trim(jQuery(".views-field-field-color",this).text());
    switch (color) {
        case 'Green':
            jQuery(this).children("td").css("color", "green");
            break;

        case 'Blue':
            jQuery(this).children("td").css("color", "blue");
            break;

        case 'Red':
            jQuery(this).children("td").css("color", "red");
            break;

        case 'Yellow':
            jQuery(this).children("td").css("color", "yellow");
            break;

        case 'Grey':
            jQuery(this).children("td").css("color", "grey");
            break;

        case 'Black':
            jQuery(this).children("td").css("color", "black");
            break;
        }
    });
});

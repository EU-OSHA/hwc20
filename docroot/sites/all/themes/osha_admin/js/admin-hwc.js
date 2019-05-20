jQuery(document).ready(function($) {
  // MDR-2215 - HWC: "Path: p" line and explanation in the summary and the body of news and events
	
  	//Add News-events
	if ( $( ".field-type-text-with-summary" ).length ) {
		$("#body-add-more-wrapper > div > div.description").appendTo("#edit-body-und-0-format");
	}
	if ( $( "#edit-field-summary" ).length ) {
		$("#field-summary-add-more-wrapper > div > div.description").appendTo("#edit-field-summary-und-0-format");
	}

	//Edit News
	if ( $( "#field-summary-add-more-wrapper" ).length ) {
		$("#field-summary-add-more-wrapper > div > div.description").appendTo("#edit-field-summary-en-0-format");
	}

	if ( $( "#edit-field-summary" ).length ) {
		$("#body-add-more-wrapper > div > div.description").appendTo("#edit-body-en-0-format");
	}

	//Edit Event
	if ( $( "#body-add-more-wrapper" ).length ) {
		$("#body-add-more-wrapper > div > div.description").appendTo("#edit-body-en-0-format");
	}
	
	
});
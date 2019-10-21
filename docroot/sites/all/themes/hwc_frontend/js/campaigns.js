function ipad_fix_iframe_width() {
	if (jQuery(window).width() > jQuery(window).height()) {
        jQuery('.fb-post').addClass('ipad_fix_width');
	} else {
        jQuery('.fb-post').removeClass('ipad_fix_width');
	}
    setTimeout(ipad_fix_iframe_width, 5000);
}

window.onorientationchange = function() {
    ipad_fix_iframe_width();
}

jQuery(document).ready(function() {

	jQuery(".start-here .col-inner").click(function() {
		window.location = jQuery(this).find("a").attr("href");
		return false;
	});

	if ((jQuery('.fb-post').length) && (jQuery(window).width()<=1024)) {
		setTimeout(ipad_fix_iframe_width, 5000);
	}

	//menu toolkit
	jQuery("#block-hwc-toolkit-toolkit-left-menu .key-menu-container >.menu >.menu__item.expanded >span").click(function(){
		if(jQuery(this).siblings("ul").is(":visible")){
			jQuery(this).removeClass("up-arrow");
			jQuery(this).addClass("closed-down-arrow");
			jQuery('#block-hwc-toolkit-toolkit-left-menu').removeClass("opened");
			jQuery(this).siblings("ul").slideUp();
		}
		else {
			jQuery(this).addClass("up-arrow");
			jQuery(this).removeClass("closed-down-arrow");
			jQuery('#block-hwc-toolkit-toolkit-left-menu').addClass("opened");
			jQuery(this).siblings("ul").slideDown();
		}

	});

	//menu toolkit tablet & mobile
	jQuery("#block-hwc-toolkit-toolkit-left-menu .key-menu-container >.menu-index").click(function(){
		if(jQuery(this).siblings(".menu").is(":visible")){
			jQuery(this).removeClass("up-arrow");
			jQuery(this).addClass("closed-down-arrow");
			jQuery('#block-hwc-toolkit-toolkit-left-menu').removeClass("opened");
			jQuery(this).siblings(".menu").slideUp();
		}
		else {
			jQuery(this).addClass("up-arrow");
			jQuery(this).removeClass("closed-down-arrow");
			jQuery('#block-hwc-toolkit-toolkit-left-menu').addClass("opened");
			jQuery(this).siblings(".menu").slideDown();
		}

	});

	//toolkit download pdf & links
	jQuery(".node-type-tk-example .node-tk-example .group-left .field-name-field-download-pdf .field-label, .node-type-tk-example .node-tk-example .group-left .field-name-field-external-link .field-label").click(function(){
		if(jQuery(this).siblings(".field-items").is(":visible")){
			jQuery(this).removeClass("up-arrow");
			jQuery(this).siblings(".field-items").slideUp();
		}
		else {
			jQuery(this).addClass("up-arrow");
			jQuery(this).siblings(".field-items").slideDown();
		}
	});

	// Prev. camp. accordion menu.
	jQuery(".left-menu.accordion-menu ul.menu > li.expanded > span").click(function(){
		if(jQuery(this).siblings("ul").is(":visible")){
			jQuery(this).removeClass("up-arrow");
			jQuery(this).addClass("closed-down-arrow");
			jQuery('.left-menu.accordion-menu').removeClass("opened");
			jQuery(this).siblings("ul").slideUp();
		}
		else {
			jQuery(this).addClass("up-arrow");
			jQuery(this).removeClass("closed-down-arrow");
			jQuery('.left-menu.accordion-menu').addClass("opened");
			jQuery(this).siblings("ul").slideDown();
		}
	});

    // Detect objectFit support
	//if('objectFit' in document.documentElement.style === false) {

	  // assign HTMLCollection with parents of images with objectFit to variable
	  var container = document.getElementsByClassName('flickr-img-wrap');

	  // Loop through HTMLCollection
	  for(var i = 0; i < container.length; i++) {

	    // Asign image source to variable
	    var imageSource = container[i].querySelector('img').src;

	    // Hide image
	    container[i].querySelector('img').style.display = 'none';

	    // Add background-size: cover
	    container[i].style.backgroundSize = 'cover';

	    // Add background-image: and put image source here
	    container[i].style.backgroundImage = 'url(' + imageSource + ')';

	    // Add background-position: center center
	    container[i].style.backgroundPosition = 'center center';
	  }
	//}


	// Hide Header on on scroll down
	var didScroll;
	var lastScrollTop = 0;
	var delta = 5;
	var navbarHeight = jQuery('header').outerHeight()-70;

	jQuery(window).scroll(function(event){
	    didScroll = true;
	});


	var isToolkitPages =  jQuery('body').attr( "class").indexOf('toolkit-page');
	if(isToolkitPages > 0){
		var toolkitPages = jQuery('header').addClass( "no-sticky");
	}


   	var toolkitPages = jQuery('header').attr( "class").indexOf('no-sticky');
   	if(toolkitPages > 0){
   		jQuery('body').addClass('tk-pages-resize');
   	   	var widthWin=jQuery(window).width();
	   	if(widthWin <= 768 ){
	   		jQuery('header').removeClass('no-sticky');
	   		jQuery('body').removeClass('tk-pages');
	   	} else {
			jQuery('body').css('padding-top','');
			jQuery('body').addClass('tk-pages');
	   	}
   	}

	jQuery(window).resize(function () {
		var widthWin=jQuery(window).width();
		if( jQuery('body').attr( "class").indexOf('tk-pages-resize') > 0 ){
		   	if(widthWin <= 768 ){
		   		jQuery('header').removeClass('no-sticky');
		   		jQuery('body').removeClass('tk-pages');
		   	} else {
		   		jQuery('header').addClass('no-sticky');
	   			jQuery('body').addClass('tk-pages');
		   	}
	   }
	});

	setInterval(function() {
	    if (didScroll) {
	    	var toolkitPages = jQuery('header').attr( "class").indexOf('no-sticky');
	    	if( toolkitPages < 0 ){
		        hasScrolled();
		        didScroll = false;
	    	}

	    }
	}, 110);

	function hasScrolled() {
		//If we are in toolit page, no sticky the main menu, and fixed toolkit menu
	    if (jQuery("body.toolkit-page")[0]){
		    // Do something if class exists

		    jQuery(window).scroll(function (event) {
			    var scroll = jQuery(window).scrollTop();
			    if (scroll == 0){
			    	jQuery('.toolkit-page .above_title').addClass('reset-sticky').removeClass('sticky-toolkit');
			    	jQuery('.toolkit-page #block-hwc-toolkit-toolkit-left-menu').addClass('reset-sticky').removeClass('sticky-toolkit');
		        	jQuery('.toolkit-page h1').addClass('reset-sticky').removeClass('sticky-toolkit');
			    }
			    if (scroll > 160){
			    	jQuery('.toolkit-page .above_title').removeClass('reset-sticky').addClass('sticky-toolkit');
			    	jQuery('.toolkit-page #block-hwc-toolkit-toolkit-left-menu').removeClass('reset-sticky').addClass('sticky-toolkit');
		        	jQuery('.toolkit-page h1').removeClass('reset-sticky').addClass('sticky-toolkit');
			    }
			});

		//If we are not in toolkit page
		} else {
		    // Do something if class does not exist
		    var st = jQuery(this).scrollTop();

		    // Make sure they scroll more than delta
		    if(Math.abs(lastScrollTop - st) <= delta)
		        return;

		    // If they scrolled down and are past the navbar, add class .nav-up.
		    // This is necessary so you never see what is "behind" the navbar.
		    if (st > lastScrollTop && st > navbarHeight){
		        // Scroll Down
		        jQuery('header').removeClass('nav-down').addClass('nav-up');
		    } else {
		        // Scroll Up
		        if(st + jQuery(window).height() < jQuery(document).height()) {
		            jQuery('header').removeClass('nav-up').addClass('nav-down');
		        }
		    }
		}
	    lastScrollTop = st;
	}

	//If the page have the external Infographic, disable sticky-menu
	if (!jQuery(".dialog-off-canvas-main-canvas")[0]){
		//fixing sticky menu
		var num = 150; //number of pixels before modifying styles
		if(jQuery("body").height()>=550){
			jQuery(window).bind('scroll', function () {
			    if (jQuery(window).scrollTop() > num) {
			    	if( toolkitPages < 0 ){
			        	jQuery("#navbar").addClass("sticky-menu");
			    	}
			    } else {
			        jQuery('#navbar').removeClass('sticky-menu');
			    }
			});
		};
	}

	//removing the sticky only for this app form page
	/*if(jQuery("body").height()>=1250){
		jQuery(window).bind('scroll', function () {
			if (jQuery(window).scrollTop() > num) {
		        jQuery('.page-node-225 #navbar').removeClass('sticky-menu');
		    }
		});
	};*/

	/*Fix the target _blank when we import the content of CORPORATE*/

	jQuery('.node-news a[href^="https://osha.europa.eu"]').attr('target','_blank');
	jQuery('.node-press-release a[href^="https://osha.europa.eu"]').attr('target','_blank');
	jQuery('.node-events a[href^="https://osha.europa.eu"]').attr('target','_blank');

	/*Fix the target _blank OCP links*/

	jQuery('.node-type-partner .pane-node-field-website a').attr('target','_blank');
	jQuery('.node-type-partner .field-name-field-website a').attr('target','_blank');
	jQuery('.node-type-partner .profile-col-right-2 .field-type-link-field a').attr('target','_blank');
	jQuery('.node-type-partner .panels-flexible-column-last .field-type-link-field a').attr('target','_blank');


	/*Fix the height of the Everis iframe*/

	jQuery('#iframe-application').load(function() {
		var alto = jQuery('#iframe-application').contents().height();
		jQuery('#iframe-application').css("height",alto + 50);
	});


	var windowWidth= jQuery(window).width();//window size

	/*
	jQuery(window).resize(function() {
	    windowWidth= jQuery(window).width();//window size, when resizing
	    if(jQuery("#napo_films").length > 0){
	    	location.reload();
	    }
	});
	*/

	/*View newsletter captcha*/

	jQuery( "#edit-email-osh" ).click(function() {
  		jQuery('#block-osha-newsletter-osha-newsletter-subscribe div.captcha').show();
	});

	/*changing capcha on click*/
	jQuery("#edit-email").click(function(){
		jQuery("#edit-submit").css({'margin-left':'auto', 'margin-right':'auto', 'display':'block'});
		jQuery(this).css("margin-right", "22px");
		jQuery(".form-item-email").css({"margin-right":"auto", "margin-left":"auto", "display":"table"});
	});

	/*adding color to "sort by" labels when is checked*/
	jQuery(".pane-hwc-practical-tool-hwc-practical-tool-listing #edit-content .form-type-radios.form-item-sort input:checked").parent('label').css({'color':'#749b00','font-weight':'bold'});

	/*show more and less newsletters*/
	jQuery(".more_newsletters").click(function(){
		jQuery("div.newsletter-item:gt(3)").slideDown();
		jQuery(".more_newsletters").hide();

		if(windowWidth <= 992){
			jQuery(".less_newsletters").show().css("display", "block");
		}else{
			jQuery(".less_newsletters").show().css("display", "inline-block");
		}
	});
	jQuery(".less_newsletters").click(function(){
		jQuery("div.newsletter-item:gt(3)").slideUp();
		jQuery(".less_newsletters").hide();
		jQuery(".more_newsletters").show();
	});

	$number_of_newsletter = jQuery( "div.newsletter-item" ).length;
	
	if($number_of_newsletter <= 4){
		jQuery(".less_newsletters").hide();
		jQuery(".more_newsletters").hide();
	}

	/*specific functions for tablet and/or mobile */
	funcionesTabletMovil();

	funcionesMovil();

	funcionesDesktop();


	//Fixing responsive menu to iPhone
	jQuery(document).ready(function() {

		//Hover for download episodes on iPad
		document.addEventListener("touchstart", function() {},false);
	});




	/*filters of list dropdown*/
	jQuery(".form-item-main-tags > label").click(function() {
				jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-field-publication-type > label").click(function() {
				jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-language > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-field-priority-area > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-relevant-for > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-languages > label").click(function() {
		jQuery(this).toggleClass("active");
	});
	jQuery(".form-item-publication-type > label").click(function() {
		jQuery(this).toggleClass("active");
	});

	/*filters of list dropdown*/
	if(jQuery(".form-item-main-tags div").is(':visible')){
		jQuery(".form-item-main-tags > label").addClass("active");
	};
	if(jQuery(".form-item-field-publication-type div").is(':visible')){
		jQuery(".form-item-field-publication-type > label").addClass("active");
	};
	if(jQuery(".form-item-language div").is(':visible')){
		jQuery(".form-item-language > label").addClass("active");
	};
	if(jQuery(".form-item-field-priority-area div").is(':visible')){
		jQuery(".form-item-field-priority-area > label").addClass("active");
	};
	if(jQuery(".form-item-relevant-for div").is(':visible')){
		jQuery(".form-item-relevant-for > label").addClass("active");
	};
	if(jQuery(".form-item-languages div").is(':visible')){
		jQuery(".form-item-languages > label").addClass("active");
	};
	if(jQuery(".form-item-publication-type div").is(':visible')){
		jQuery(".form-item-publication-type > label").addClass("active");
	};

	/*Private zone hover effect menu*/
	jQuery(".profile-edit-links-container .hwc-partner-private-link-block-title a").hover(function(){
		jQuery(".profile-edit-links-container .pane-content").css("background", "inherit");
		jQuery(this).parent().parent().css("background", "#e2e2e3");
	});
	jQuery(".profile-edit-links-container .hwc-partner-private-link-block-title a").mouseleave(function(){
		jQuery(".profile-edit-links-container .pane-content").css("background", "inherit");
		//jQuery(this).parent().parent().css("background", "#e2e2e3");
	});


	/**
	 * Clearable text inputs

	function tog(v){return v?'addClass':'removeClass';}
	jQuery(document).on('input', '.clearable', function(){
	    jQuery(this)[tog(this.value)]('x');
	}).on('mousemove', '.x', function( e ){
	    jQuery(this)[tog(this.offsetWidth-18 < e.clientX-this.getBoundingClientRect().left)]('onX');
	}).on('touchstart click', '.onX', function( ev ){
	    ev.preventDefault();
	    jQuery(this).removeClass('x onX').val('').change();
	});
	 */

	/************************** FUNCTIONS *******************************/

	function funcionesDesktop () {
		jQuery(window).resize(function() {
	    	windowWidth= jQuery(window).width();//window size, when resizing
		    if(windowWidth > 976){//<-----functions for desktop

		    	jQuery('#block-hwc-toolkit-toolkit-left-menu .key-menu-container > .menu').css("display", "block");

			}
		});

	}
	function funcionesTabletMovil () {
		if(windowWidth <= 992){//<-----functions for tablet and/or mobile



		}//<-----End: functions for tablet and/or mobile
	}

	function funcionesMovil () {
		jQuery("#block-menu-menu-header-login, #block-lang-dropdown-language").addClass("visibility");
		if(windowWidth <= 767){//<-----functions for mobile

			//Menu function, transform the menu icon in a x

			jQuery(".navbar-toggle").on("click", function () {
		    	jQuery(this).toggleClass("active");
				jQuery("#block-menu-menu-header-login, #block-lang-dropdown-language").toggleClass("visibility");
			});

			//Additional Resources Block

			jQuery(".field-name-field-aditional-resources h4.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});

			//Press Room

			jQuery(".pane-osha-press-release-osha-press-rel-become-partner h2.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});

			jQuery(".pane-press-contacts h2.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});

			jQuery(".pane-osha-press-release-osha-press-kit h2.pane-title").click(function() {
				jQuery(this).toggleClass("closeLabel");
				jQuery(this).next("div").toggle();
			});

		}
	}

	//AÑADIDO GALDER
	jQuery(".page-glossary-list .view-content .glossary_type .type-name").click(function(){
		jQuery(this).addClass("active");
	});


	// DELETE SEARCH TOOLKIT EXAMPLES EMPTY

		jQuery('.tools-and-examples-items').each(function( index ) {
			var examplesItemsContent = jQuery(this).html();
			var hasItemsContent = examplesItemsContent.trim().length;
			if(hasItemsContent == 0){
				jQuery(this).remove();
			} else {
				jQuery(this).fadeIn( "slow" );
			}
		});

		jQuery(".view-search-toolkit-examples .hide-filters a").click(function(){
			jQuery('.view-search-toolkit-examples .view-filters').fadeToggle();
			jQuery('.view-footer .result-summary').toggleClass('filetrs-hidden');

			var isHidden = jQuery('.view-search-toolkit-examples .view-filters').attr('style').indexOf('opacity: 1');
			if(isHidden < 0){
				jQuery(".view-search-toolkit-examples .hide-filters a").text('Hide filters');
			} else {
				jQuery(".view-search-toolkit-examples .hide-filters a").text('Show filters');
			}
		});



		/* Responsive Search Menu */
		if (jQuery(window).width() < 768) {
			jQuery('.region-header .input-group-btn').on('click', function() {
			    if (jQuery('#edit-search-block-form--2').css('opacity') == 0) {
			       jQuery('#edit-search-block-form--2').css('display', 'block');
			       jQuery('#edit-search-block-form--2').addClass('expand');
			       jQuery('#block-search-form').addClass('expand');
			    }
			    else {
			        jQuery('#edit-search-block-form--2').css('display', 'none');
			        jQuery('#edit-search-block-form--2').removeClass('expand');
			        jQuery('#block-search-form').removeClass('expand');
			        //jQuery("#edit-submit--2").click() TO DO
			    }
			});
		}

		//Calculate the header height and add the padding-top to the body. All resolotuions and responsive
		var calculate_height = jQuery(".campaigns-header").height();
		jQuery("body").css('padding-top', calculate_height);
		jQuery("body.splash-page").css('padding-top', calculate_height);


		jQuery(window).resize(function() {
        	var calculate_height_resize = jQuery(".campaigns-header").height();
			jQuery("body").css('padding-top', calculate_height_resize);
			jQuery("body.splash-page").css('padding-top', calculate_height_resize);
    	});

    	/* Cookies declined */
		jQuery(".decline-button").click(function() {
			jQuery('#sliding-popup').fadeOut(200);
		});


		//Add class if "result for" search appears
		if (jQuery(".results-for")[0]){
			jQuery('.sidebars_first').addClass('with-result-for');
		}
});


/* Publications filter accorddions */

jQuery(document).ready(function($) {
  $("#edit-main-tags > div > label").on("click", function() {
    if ($(this).hasClass("active")) {
      $("#edit-main-tags .form-checkboxes").slideDown(200);
    }else{
      $("#edit-main-tags .form-checkboxes").slideUp(200);
    }
  });
  $("#edit-field-publication-type > div > label").on("click", function() {
    if ($(this).hasClass("active")) {
      $("#edit-field-publication-type .form-checkboxes").slideDown(200);
    }else{
      $("#edit-field-publication-type .form-checkboxes").slideUp(200);
    }
  });
  $("#edit-field-priority-area > div > label").on("click", function() {
    if ($(this).hasClass("active")) {
      $("#edit-field-priority-area .form-checkboxes").slideDown(200);
    }else{
      $("#edit-field-priority-area .form-checkboxes").slideUp(200);
    }
  });

   if (jQuery(window).width() < 1200) {
   	$("#edit-main-tags > div > label").removeClass('active');
   	$("#edit-field-publication-type > div > label").removeClass('active');
   	$("#edit-field-priority-area > div > label").removeClass('active');

   	$("#edit-main-tags .form-checkboxes").css('display' , 'none');
   	$("#edit-field-publication-type .form-checkboxes").css('display' , 'none');
   	$("#edit-field-priority-area .form-checkboxes").css('display' , 'none');
   }

   	//Add two-column class when European Week has Events
	if (jQuery("#block-hwc-european-week-news-events .box-before.events")[0]){
		 $("#block-hwc-european-week-news-events .box-before.news").addClass('two-column');
	}

	//Add span to Subscribe Checkbox to make custom Checkbox
	if ($("#edit-subscribe-details")[0]){
		 $("#edit-subscribe-details .form-type-checkbox label").append('<span class="my-checkbox"></span>');
		 $("#edit-subscribe-details .form-type-checkbox input").appendTo("#edit-subscribe-details .form-type-checkbox");
		 $("#edit-subscribe-details .form-type-checkbox label").appendTo("#edit-subscribe-details .form-type-checkbox");
	}


	//Add class to fix the margin footer when the last block has grey colour
	if ($(".content-box-sub")[0]){
		 $("footer.footer").addClass('fix-margin');
	}

	if ($("#block-hwc-european-week-news-events")[0]){
		 $("footer.footer").addClass('fix-margin');
	}

	if ($(".page-search")[0]){
		 $("footer.footer").addClass('fix-margin');   
	}

});



/** CAROUSEL **/
jQuery(document).ready(function () {

  console.log('CAROUSEL');
  var itemsMainDiv = ('.multicarousel--block');
  var itemsDiv = ('.multicarousel--block--inner');
  var itemWidth = "";
  var multicarouselPage = 0;
  var incno = 0;

  // this function define the size of the items
  function ResCarouselSize() {
    var dataItems = ("data-items");
    var itemClass = ('.item');
    var id = 0;
    var btnParentSb = '';
    var itemsSplit = '';
    var sampwidth = jQuery(itemsMainDiv).width();
    var bodyWidth = jQuery('body').width();
    jQuery(itemsDiv).each(function () {
      id = id + 1;
      var itemNumbers = jQuery(this).find(itemClass).length;
      btnParentSb = jQuery(this).parent().attr(dataItems);
      itemsSplit = btnParentSb.split(',');


      jQuery(this).parent().attr("id", "multicarouselBlock" + id);


      if (bodyWidth >= 1200) {
        incno = itemsSplit[3];
        itemWidth = sampwidth / incno;
      }
      else if (bodyWidth >= 992) {
        incno = itemsSplit[2];
        itemWidth = sampwidth / incno;
      }
      else if (bodyWidth >= 768) {
        incno = itemsSplit[1];
        itemWidth = sampwidth / incno;
      }
      else {
        incno = itemsSplit[0];
        itemWidth = sampwidth / incno;
      }

      jQuery(this).css({ 'transform': 'translateX(0px)', 'width': itemWidth * itemNumbers });
      jQuery(this).find(itemClass).each(function () {
        jQuery(this).outerWidth(itemWidth);
      });

      jQuery(".leftLst").addClass("over");
      jQuery(".rightLst").removeClass("over");

    });
  }

  // this function used to move the items
  function ResCarousel(e, el, s) {

    var leftBtn = ('.leftLst');
    var rightBtn = ('.rightLst');
    var translateXval = '';
    var divStyle = jQuery(el + ' ' + itemsDiv).css('transform');
    var values = divStyle.match(/-?[\d\.]+/g);
    var xds = Math.abs(values[4]);
    if (e == 0) {
      translateXval = parseInt(xds) - parseInt(itemWidth * s);
      jQuery(el + ' ' + rightBtn).removeClass("over");
      multicarouselPage -= 1;

      if (translateXval <= itemWidth / 2) {
        multicarouselPage = 0;
        translateXval = 0;
        jQuery(el + ' ' + leftBtn).addClass("over");
      }
    }
    else if (e == 1) {
      var itemsCondition = jQuery(el).find(itemsDiv).width() - jQuery(el).width();
      multicarouselPage += 1;
      translateXval = parseInt(xds) + parseInt(itemWidth * s);
      jQuery(el + ' ' + leftBtn).removeClass("over");

      if (translateXval >= itemsCondition - itemWidth / 2) {
        translateXval = itemsCondition;
        jQuery(el + ' ' + rightBtn).addClass("over");
      }
    }
    jQuery(el + ' ' + itemsDiv).css('transform', 'translateX(' + -translateXval + 'px)');
    jQuery(".multicarousel-indicators li").removeClass('active')
    jQuery("#multicarousel-indicator-"+multicarouselPage).addClass('active');
  }

//It is used to get some elements from btn
  function click(ell, ee) {
    var Parent = "#" + jQuery(ee).parent().attr("id");
    var slide = jQuery(Parent).attr("data-slide");
    ResCarousel(ell, Parent, slide);
  }

  jQuery('.leftLst, .rightLst').click(function () {
    var condition = jQuery(this).hasClass("leftLst");
    if (condition)
      click(0, this);
    else
      click(1, this)
  });

  ResCarouselSize();

  var cl='class="active"';
  for (i = 0; i < Math.ceil(jQuery('.multicarousel--block--inner .item').length / incno); i++) {
    jQuery('.multicarousel-indicators').append('<li id="multicarousel-indicator-'+i+'" data-slide-to="' + i + '" '+cl+'></li>');
    cl='class=""';
  }

  jQuery(window).resize(function () {
    ResCarouselSize();
  });

  jQuery('.multicarousel-indicators li').click(function () {
    var slide_to = jQuery(this).data('slide-to');
    if (multicarouselPage != slide_to) {
      jQuery(".multicarousel-indicators li").removeClass('active')
      jQuery("#multicarousel-indicator-" + slide_to).addClass('active');
      if (slide_to > multicarouselPage) {
        var el = jQuery('.rightLst');
        for (i = 0; i <= slide_to - multicarouselPage; i++) {
          click(1, el);
        }
      }
      else {
        var el = jQuery('.leftLst');
        for (i = 0; i <= multicarouselPage - slide_to; i++) {
          click(0, el);
        }
      }
    }
  });

});

jQuery(document).ready(function(){
  if (jQuery(window).width() >= 1200) {
    jQuery(".multicarousel--block").attr("data-slide","4");
  }
});

jQuery(window).resize(function () {
  if (jQuery(window).width() >= 1200) {
    jQuery(".multicarousel--block").attr("data-slide","4");
  }
});


jQuery(document).ready(function(){
  if (jQuery(window).width() >= 992) {
    jQuery(".multicarousel--block").attr("data-slide","3");
  }
});

jQuery(window).resize(function () {
  if (jQuery(window).width() >= 992) {
    jQuery(".multicarousel--block").attr("data-slide","3");
  }
});

jQuery(document).ready(function(){
  if (jQuery(window).width() <= 991) {
    jQuery(".multicarousel--block").attr("data-slide","3");
    jQuery(".node-type-gpa .main-container ol.multicarousel-indicators").css("width", "87%");
  }
});

jQuery(window).resize(function () {
  if (jQuery(window).width() <= 991) {
    jQuery(".multicarousel--block").attr("data-slide","3");
    jQuery(".node-type-gpa .main-container ol.multicarousel-indicators").css("width", "87%");
  }
});

jQuery(document).ready(function(){
  if (jQuery(window).width() <= 767) {
    jQuery(".multicarousel--block").attr("data-slide","1");
    jQuery(".node-type-gpa .main-container ol.multicarousel-indicators").css("width", "84%");
  }
});

jQuery(window).resize(function () {
  if (jQuery(window).width() <= 767) {
    jQuery(".multicarousel--block").attr("data-slide","1");
    jQuery(".node-type-gpa .main-container ol.multicarousel-indicators").css("width", "84%");
  }
});


/* FAQ accorddions */

jQuery(document).ready(function($) {
	$('.panel-group .panel-default:nth-child(1) h4.panel-title').addClass('active');
	$('h4.panel-title').click(function() { // when a .myDiv is clicked
	    $('h4.panel-title').not(this).removeClass('active');
	    $(this).toggleClass('active');
	})
});
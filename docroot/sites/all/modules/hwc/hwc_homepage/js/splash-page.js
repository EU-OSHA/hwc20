(function($) {
  $(document).ready(function() {
    // Font size.
    $("[data-font]").click(function() {
      if (!$(this).hasClass("is_selected")) {

        $("html").removeClass("smaller larger");
        $("html").addClass($(this).data("font"));

        $("[data-font].is_selected").removeClass("is_selected");
        $(this).addClass("is_selected");

      }
    });

  });
})(jQuery);

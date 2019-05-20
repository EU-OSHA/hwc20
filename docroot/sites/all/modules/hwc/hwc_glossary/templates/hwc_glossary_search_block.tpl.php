<script>
    jQuery("a[href='/glossary']").addClass("is-active-trail active-trail active");
</script>
<div class="selectCountry">
    <div class="containerSmall">
        <div class="textGlossary"><?php echo t("Find all terms:"); ?> </div>
        <div class="searchGlossary selected"><?php echo t("Search"); ?> <div class="arrow"></div></div>
        <div class="filterGlossary"><?php echo l(t("A-Z Filter"), 'glossary') ?></div>
    </div>
</div>
<script>
jQuery(".search-result a").each(function() {
    jQuery(this).removeAttr("href");
});
</script>

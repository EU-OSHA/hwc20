<?php
/**
 * @file social-dashboard-column-plugin-style.tpl.php
 * Default simple view template to display Socail Dashboard Columns.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
$in_block = TRUE;
if ($current_display != 'block_1') {
  $in_block = FALSE;
}
?>
<div>
<?php if ($view->current_display=='facebook') { ?>
<script src="//connect.facebook.net/en_US/sdk.js#xfbml=1&amp;version=v2.5" async></script>
<script>
if (typeof(FB) !== 'undefined') {
    FB.XFBML.parse();
}
</script>
<?php } ?>
<?php if (($view->current_display=='twitter')||($view->current_display=='block_1')) { ?>
<script>
    if (typeof(twttr) !== 'undefined') {
        twttr.widgets.load();
    }
</script>
<script>window.twttr = (function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0],
            t = window.twttr || {};
        if (d.getElementById(id)) return t;
        js = d.createElement(s);
        js.id = id;
        js.src = "https://platform.twitter.com/widgets.js";
        fjs.parentNode.insertBefore(js, fjs);

        t._e = [];
        t.ready = function(f) {
            t._e.push(f);
        };

        return t;
    }(document, "script", "twitter-wjs"));</script>
<?php } ?>
<div id="social-dashboard-column-<?php print $id ?>" class="row <?php print $classes ?>">
<?php
    foreach ($items as $title => $rows) { ?>
    <div>
        <?php if (!$in_block && 0) { ?><h2><?php echo ucfirst($title) ?></h2><?php } ?>
<?php
      foreach ($rows as $row) {
          foreach ($row['content'] as $column) {
            print $column['content'];
          }
      } ?>
    </div>
<?php
    }
?>
</div>
</div>

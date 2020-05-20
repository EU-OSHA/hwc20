<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */

global $language;
include(drupal_get_path('theme', 'hwc_frontend').'/templates/header.tpl.php');
?>

<div class="main-container container-fluid">

  <?php /* print $content_column_class; */ ?>
  <?php if (!empty($page['highlighted'])): ?>
      <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
  <?php endif; ?>
    <a id="main-content"></a>
  <?php print render($title_prefix); ?>
    <div class="above_title">
      <?php print render($page['above_title']); ?>
    </div>
  <?php if ($show_title) { ?>
      <div class="page_title">
  <?php
  $external_infographic = variable_get('hwc_external_infographic_nid', 7150);
  $node_nid = NULL;
  $node_type = NULL;
  /*If is a external infographic, change the breadcrumbs*/
  $n = menu_get_object('node');
  if ($n) {
    $node_nid = $n->nid;
    $node_type = $n->type;
    switch ($node_type) {
      case "article":
        if ($node_nid == $external_infographic) { ?>
            <div class="breadcrumb breadcrumb-external-infographic contextual-links-region">
            <span class="inline odd first">
                      <?php print '<a href="/' . $language->language . '">' . t("Home") . '</a>'; ?>
                    </span>
            <span class="delimiter">»</span>
            <span class="inline even">
                      <?php print '<a href="/' . $language->language . '/tools-and-publications">' . t("Tools and Publications") . '</a>'; ?>
                    </span>
            <span class="delimiter">»</span>
            <span class="inline even">
                      <?php print '<a href="/' . $language->language . '/tools-and-publications/infographics">' . t("Infographics") . '</a>'; ?>
                    </span>
            <span class="delimiter">»</span>
            <span class="inline odd last"><?php print $n->title; ?></span>
            </div><?php
        }
        break;

      case "infographic": ?>
          <div class="breadcrumb breadcrumb-external-infographic contextual-links-region">
          <span class="inline odd first">
                  <?php print '<a href="/' . $language->language . '">' . t("Home") . '</a>' ?>
                </span>
          <span class="delimiter">»</span>
          <span class="inline even">
                  <?php print '<a href="/' . $language->language . '/tools-and-publications">' . t("Tools and Publications") . '</a>' ?>
                </span>
          <span class="delimiter">»</span>
          <span class="inline odd last">
                   <?php print t("Infographics"); ?>
                </span>
          </div><?php
        break;

    }
  }
  if (!empty($breadcrumb) && ($node_nid != $external_infographic) && ($node_type != 'infographic')) {
    print $breadcrumb;
  }
  if (!empty($back_to_pz)) {
    print $back_to_pz;
  } ?>
    <?php if (!empty($title)) { ?>
          <h1 class="page-header"><?php print $title; ?></h1>
    <?php } ?>
      </div>
    <?php
  }
  print render($title_suffix);
  print $messages;
  $content_cols = 12;
  if (!empty($page['sidebar_first'])) {
    $content_cols -= 3;
  }
  if (!empty($page['sidebar_second'])) {
    $content_cols -= 3;
  }
  ?>
    <div class="below_title">
      <?php print render($page['below_title']); ?>
    </div>
    <div class="container">
        <div class="row">
          <?php if (!empty($tabs)): ?>
            <?php print render($tabs); ?>
          <?php endif; ?>
          <?php if (!empty($page['help'])): ?>
            <?php print render($page['help']); ?>
          <?php endif; ?>
          <?php if (!empty($action_links)): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>

          <?php if (!empty($page['sidebar_first'])): ?>
              <aside class="col-md-3 col-xs-12" role="complementary">
                <?php print render($page['sidebar_first']); ?>
              </aside>  <!-- /#sidebar-first -->
          <?php endif; ?>
            <aside class="col-md-<?php print $content_cols ?> col-xs-12">
            <div id="skip-to-content" style="visibility: hidden; height: 0px"><a href="#skip-to-content" rel="nofollow" accesskey="S" style="visibility: hidden;"><?php print t('Skip to content'); ?></a></div>
          <?php print render($page['content']); ?>
            </aside>
          <?php if (!empty($page['sidebar_second'])): ?>
              <aside class="col-md-3 col-xs-12" role="complementary">
                <?php print render($page['sidebar_second']); ?>
              </aside>  <!-- /#sidebar-second -->
          <?php endif; ?>
          <?php if (!empty($page['below_content'])): ?>
            <aside class="col-md-12 col-xs-12" role="below_content">
              <?php print render($page['below_content']); ?>
            </aside>  <!-- /#below_content -->
          <?php endif; ?>
        </div>
    </div>
</div>
<footer class="footer">
    <div class="container">
      <?php print render($page['footer']); ?>
        <div class="content-second-footer">
            <div class="intro-footer">
                <p><?php print t("Safety and health at work is everyone's concern. It's good for you. It's good for business."); ?></p>
                <p><?php print t("European Agency for Safety and Health at Work | an agency of the European Union"); ?></p>
            </div>
        </div>
        <div class="on-the-web"><span><?php print t('Follow us:'); ?></span>
          <?php $my_block = module_invoke('on_the_web', 'block_view', 'on_the_web'); print render($my_block['content']); ?>
        </div>
    </div>
</footer>

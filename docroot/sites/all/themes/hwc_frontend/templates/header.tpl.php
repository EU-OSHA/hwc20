<?php

global $language;

if ($language->language=="en"){
    $idioma = "";
     $logo_osha = '/images/header/logos/EU-OSHA.png';
  }else{
    $idioma = $language->language;
    $logo = str_replace("logo.png", "/images/header/logos/" .$idioma ."_logo.jpg", $logo);
    $logo_osha = '/images/header/logos/EU-OSHA-'. $idioma . '.png';
}

$theme_dir = drupal_get_path('theme', 'hwc_frontend');
?>
<?php if (!empty($page['above_header'])): ?>
<?php endif; ?>
<header id="navbar" class="navbar navbar-default container-fluid"><?php // print $navbar_classes; ?>
  <div class="container-fluid campaigns-header">
    <div class="row">
      <div class="navbar-header">
        <div class="row">
          <div class="col-xs-12 col-sm-9">
            <a class="pull-left" accesskey="0" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
            <a href="http://osha.europa.eu" title="EU-OSHA" target="_blank">
              <?php print '<img class="pull-left" alt="'.t("EU-OSHA logo").'" src="'.base_path() . path_to_theme() .$logo_osha .'">'; ?>
            </a>
            <img class="pull-left" src="/<?php print $theme_dir . '/logo-eu.png'; ?>" alt="<?php print t('EU logo'); ?>" />
            <div class="header-text"><?php echo $head_text; ?><span><?php print t('Coming soon') ?></span></div>
          </div>
          <div class="col-xs-12 col-sm-3 xs-menu">
            <div class="header_top_bar">
              <div class="vertical-align">
                <?php print render($page['above_header']); ?>
              </div>
            </div>
            <?php print render($page['header']); ?>
      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
    <div class="navbar-collapse collapse">
      <nav>
      <?php if (!empty($primary_nav)): ?>
        <?php print render($primary_nav); ?>
      <?php endif; ?>
      </nav>
    </div>
    </div>
  </div>
</header>

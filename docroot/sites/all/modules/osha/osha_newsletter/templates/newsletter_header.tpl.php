<?php

if (empty($campaign_id)) {
  if (!empty($variables['elements']['#campaign_id'])) {
    $campaign_id = $variables['elements']['#campaign_id'];
  }
  elseif (!empty($variables['campaign_id'])) {
    $campaign_id = $variables['campaign_id'];
  }
}

$url_query = array();
if (!empty($campaign_id)) {
  $url_query = array('pk_campaign' => $campaign_id);
}

global $language;
$directory = drupal_get_path('module','osha_newsletter');
?>
<style type="text/css">
    a {text-decoration: none !important;}
</style>
<span class="preview-text" style="color: transparent; display: none !important; height: 0; max-height: 0; max-width: 0; opacity: 0; overflow: hidden; mso-hide: all; visibility: hidden; width: 0;">
  <?php
    $newsletter_ready_date = format_date(strtotime($newsletter_date), 'custom', 'F Y');
    print t("Healthy Workplaces Campaign Newsletter &ndash; ");
    print t($newsletter_ready_date);
  ?>
</span>
<table border="0" cellpadding="0" cellspacing="0" width="800" class="preheader template-container">
  <tbody>
    <tr>
      <td height="6" style="background-color: #003399;"">
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="800" style="font-family: Arial,sans-serif; table-layout: fixed;" class="header template-container">
  <tbody>
    <tr>
      <td class="hwc-logo visible-mobile" width="0" style="width: 0px; max-width: 0px;" valign="bottom">
        <?php
          print l(theme('image', array(
            'path' => $directory . '/images/healthy_workplaces.png',
            'width' => 88,
            'height' => 83,
            'alt' => 'Healthy Workplaces',
            'attributes' => array('style' => 'border: 0px; width: 88px; max-width: 88px; height: 83px; max-height: 83px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
        ?>
      </td>
      <td class="hwc-image hidden-mobile" width="230" style="width: 230px; max-width: 230px;" valign="bottom">
        <?php
          global $base_url;
          print l(theme('image', array(
            'path' => $directory . '/images/hwc_image.png',
            'width' => 219,
            'height' => 108,
            'alt' => 'Healthy Workplaces Campaign',
            'attributes' => array('style' => 'border: 0px; width: 219px; max-width: 219px; height: 108px; max-height: 108px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
        ?>
      </td>
      <td class="condensed-title hidden-mobile" width="140" style="width: 140px; max-width: 140px; font-family: Arial; font-size: 16px; font-weight: bold; color: #003399; vertical-align: middle;" valign="bottom">
        Healthy Workplaces MANAGE DANGEROUS SUBSTANCES
      </td>
      <td class="osha-logos" width="182" style="width: 182px; max-width: 182px;" valign="bottom">
        <?php
          global $base_url;
          $eu_osha_img = 180;
          print l(theme('image', array(
            'path' => $directory . '/images/logo-osha2.png',
            'width' => 180,
            'height' => 88,
            'alt' => 'European Agency for Safety and Health at Work',
            'attributes' => array('style' => 'border: 0px; width: 180px; max-width: 180px; height: 88px; max-height: 88px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
          ?>
      </td>
      <td class="eu-logo" width="77" style="width: 77px; max-width: 77px;" valign="bottom">
        <?php
          print theme('image', array(
            'path' => $directory . '/images/europeLogo.png',
            'width' => 57,
            'height' => 37.09,
            'alt' => 'EU',
            'attributes' => array('style' => 'border: 0px; width: 57px; max-width: 57px; height: 37.09px; max-height: 37.09px;')
          ));
        ?>
      </td>
      <td class="hwc-logo hidden-mobile" width="87" style="width: 87px; max-width: 87px;" valign="bottom">
        <?php
          print l(theme('image', array(
            'path' => $directory . '/images/healthy_workplaces.png',
            'width' => 88,
            'height' => 83,
            'alt' => 'Healthy Workplaces',
            'attributes' => array('style' => 'border: 0px; width: 88px; max-width: 88px; height: 83px; max-height: 83px;')
            )), $base_url.'/'.$language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query
          ));
        ?>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="800" class="template-container">
  <tbody>
    <tr>
      <?php
        global $base_url;
        $bg_path = "{$base_url}/sites/all/modules/osha/osha_newsletter/images/header-banner-bg.png";
      ?>
      <td class="header-banner-container" background="<?php print $bg_path; ?>" bgcolor="#6ca638" valign="top" style="background-image: url(<?php print $bg_path; ?>); background-repeat: no-repeat; background-size: cover; padding-top: 0; padding-bottom: 0px;">
        <!--[if gte mso 9]>
        <v:rect xmlns:v="urn:schemas-microsoft-com:vml" fill="true" stroke="false" style="width: 800px;">
          <v:fill type="frame" src="<?php print $bg_path; ?>" color="#6ca638" />
          <v:textbox style="mso-fit-shape-to-text:true" inset="0,0,0,0">
        <![endif]-->
        <div>
          <table border="0" cellpadding="0" cellspacing="0" width="800" class="header-banner">
            <tbody>
              <tr>
                <td style="width: 70%; text-align: left; font-size: 24px; font-weight: bold; color: #ffffff; font-family: Arial,sans-serif;" class="header-title responsive-column">
                  <?php print t("Healthy Workplaces Campaign Newsletter");?>
                </td>
                <td style="width: 30%; text-align: right; font-size: 24px; font-weight: normal; color: #ffffff; font-family: Arial,sans-serif;" class="header-date hidden-print responsive-column">
                  <?php print t($newsletter_ready_date); ?>
                </td>
              </tr>
            <tr class="intro"><td colspan="2">
                    <p style="font-style: italic; color: #ffffff; font-size: 12px; font-family: Arial,sans-serif;">
                      <?php 
                        if ($newsletter_intro != ''){
                          print t($newsletter_intro);
                        }
                      ?>
                    </p>
                </td></tr>
            </tbody>
          </table>
         </div>
        <!--[if gte mso 9]>
          </v:textbox>
        </v:rect>
        <![endif]-->
      </td>
    </tr>
  </tbody>
</table>

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
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="preheader template-container">
  <tbody>
    <tr>
      <td height="6" style="background-color: #003399;"">
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family: Arial,sans-serif; table-layout: fixed;" class="header template-container">
  <tbody>
    <tr>
      <td style="padding-top: 10px;padding-bottom: 10px;">
        <?php
        $img = theme('image', array(
          'path' => $directory . '/images/healthy-workplaces.png',
          'width' => 800,
          'height' => 109,
          'alt' => 'Healthy Workplaces',
          'attributes' => array('style' => 'border: 0px;'),
        ));
        print l($img, 'https://healthy-workplaces.eu/' . $language->language,
          [
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query,
          ]
        );
        ?>
      </td>
    </tr>
  </tbody>
</table>

<table border="0" cellpadding="0" cellspacing="0" width="100%" height="140" class="template-container">
  <tbody>
    <tr>
      <td class="header-banner-container" valign="top">
        <table border="0" cellpadding="0" cellspacing="0" width="100%" height="140" class="header-banner">
          <tbody>
            <tr>
              <td style="width: 70%;height:140px;text-align: center; font-size: 24px; font-weight: bold; color: #ffffff; font-family: Arial,sans-serif; vertical-align: middle;">
                 <?php
                  $directory = drupal_get_path('module', 'osha_newsletter');
                  print (theme('image', array(
                    'path' => $directory . '/images/' . 'header-banner-bg.png',
                    'width' => '840',
                    'height' => '140',
                  )));
                  ?>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>
<table border="0" cellpadding="0" cellspacing="0" width="800" class="header-banner">
  <tbody>
    <tr>
      <td style="width: 30%; text-align: left; font-size: 21px; font-weight: normal; color: #003399; font-family: Arial,sans-serif;padding-top: 20px;padding-bottom: 0;padding-left: 20px" class="header-date hidden-print responsive-column">
        <?php print t($newsletter_ready_date); ?>
      </td>
    </tr>
  </tbody>
</table>

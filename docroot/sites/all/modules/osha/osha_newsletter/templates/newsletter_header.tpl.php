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
      <td style="padding: 0;line-height: 0;padding-top: 10px;padding-bottom: 10px;">
        <?php
        print l(
          theme('image', array(
            'path' => $directory . '/images/healthy-workplaces.png',
            'width' => 800,
            'height' => 114,
            'alt' => 'Healthy Workplaces',
            'attributes' => array('style' => 'border: 0px;'),
          )
          ), $base_url . '/' . $language->language, array(
            'html' => TRUE,
            'external' => TRUE,
            'query' => $url_query,
          )
        );
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
                <td style="width: 70%; text-align: center; font-size: 24px; font-weight: bold; color: #ffffff; font-family: Arial,sans-serif;" class="header-title responsive-column">
                  <?php print t("Healthy Workplaces Campaign Newsletter");?>
                </td>
              </tr>
              <tr>
                <td style="width: 30%; text-align: center; font-size: 24px; font-weight: normal; color: #ffffff; font-family: Arial,sans-serif;" class="header-date hidden-print responsive-column">
                  <?php print t($newsletter_ready_date); ?>
                </td>
              </tr>
            <tr class="intro"><td colspan="2">
                    <p style="font-style: italic; color: #ffffff; font-size: 12px; font-family: Arial,sans-serif;">
                      <?php
                        if ($newsletter_intro != '') {
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

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
global $base_url;

$unsubscribe_text = variable_get('unsubscribe_campaign_news_text', 'To unsubscribe from the CAMPAIGN-NEWS list, click the following link:');
$unsubscribe_url = variable_get('unsubscribe_campaign_news_url', 'http://list.osha.eu/scripts/wa.exe?SUBED1=CAMPAIGN-NEWS&A=1');
$bottom_text = variable_get('hwc_mail_bottom_text', '');

?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0;background-color:#ffffff;table-layout:fixed;max-width:100%;width:100%">
  <tbody>
  <tr style="border:0;background-color:transparent">
    <td style="vertical-align:top;border:0;padding-top: 25px;">
      <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0">
        <tbody>
        <tr style="border:0;background-color:#a5bd1f;height:135px">
          <td class="to-responsive-footer1" style="width:350px;">
            <?php
            $footer_img = "{$base_url}/sites/all/modules/osha/osha_newsletter/images/newsletter-img-footer.png";

            $style = 'border: 0px;display:block;';
            print l(theme('image', array(
              'path' => $footer_img,
              'alt' => 'footer image',
              'attributes' => array('style' => $style),
            )),
              url('node/' . $node->nid, array('absolute' => TRUE)),
              array('html' => TRUE, 'external' => TRUE, 'query' => $url_query));
           ?>
          </td>
          <td class="to-responsive-footer2" style="vertical-align:middle;border:0;color:#ffffff;padding:0;width: 400px;">
            <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0; margin: 0 auto;">
              <tbody>
              <tr style="border:0;background-color:transparent">
                <td colspan="5" style="vertical-align: top;border: 0;padding: 5px 20px 15px 20px;text-align: center;font-size: 23px;color: #FFF;">
                  <?php print  t('Follow us on'); ?>
                </td>
              </tr>
              <tr style="border:0;background-color:transparent">
                <td style="vertical-align:top;border:0;padding:5px 20px 0 20px;width:40px;height:40px;text-align:center;padding-top:5px">
                  <a href="https://twitter.com/eu_osha" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://twitter.com/eu_osha&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNEjD-bso_INECdN2hSssHEjnJUtMA">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px!important;max-height:25px!important;width:31px!important;max-width:31px!important" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/twitter.jpg" width="31" height="25" alt="Twitter" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 0 20px;width:40px;height:40px;text-align:center;padding-top:5px">
                  <a href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNE8B4kEJTEXOwpWLsxNQLlY3qVc8A">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px !important;max-height:25px!important;width:25px!important;max-width:25px!important" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/facebook.jpg" width="25" height="25" alt="Facebook" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 0 20px;width:40px;height:40px;text-align:center;padding-top:5px">
                  <a href="https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNECEeZnqSz65ut3caY8dHk2QulewA">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px !important;max-height:25px!important;width:25px!important;max-width:25px!important" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/linkedin.jpg" width="25" height="25" alt="LinkedIn" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 0 20px;width:40px;height:40px;text-align:center;padding-top:5px">
                  <a href="https://www.youtube.com/user/EUOSHA" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.youtube.com/user/EUOSHA&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNF2DU3gB_j1-A3zLqUuB5pY10OCZQ">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px!important;max-height:25px!important;width:35px!important;max-width:35px!important" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/youtube.jpg" width="35" height="25" alt="Youtube" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 0 20px;width:40px;height:40px;text-align:center;padding-top:5px">
                  <a href="https://www.flickr.com/photos/euosha/albums" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.flickr.com/photos/euosha/albums&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNHzz7YT4uQIFOXGOqk5lcjUCxlaeg">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px!important;max-height:25px!important;width:31px!important;max-width:31px!important" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/flickr.jpg" width="31" height="25" alt="Flickr" class="CToWUd">
                  </a>
                </td>
                <td class="to-responsive-footer1" style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:150px">
                  &nbsp;
                </td>
              </tr>
              </tbody>
            </table>
          </td>
        </tr>
        </tbody>
      </table>
      <table style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0;padding-top:15px;width:100%;margin-left:0">
        <tbody>
        <tr style="border:0;background-color:transparent">
          <td style="vertical-align:top;border:0;padding:20px 20px 5px 20px;padding-bottom:20px;font-size:10px;font-family:verdana;color:#666666;text-align:center">
            <?php echo $bottom_text; ?>
          </td>
        </tr>
        <tr>
          <td style="vertical-align:top;border-top:2px solid #666666;padding:5px 20px 5px 20px;padding-bottom:20px;padding-top:20px;font-size:10px;font-family:verdana;color:#666666;text-align:center">
            <?php
            echo $unsubscribe_text;
            if ($unsubscribe_url) {
              ?>
                <br>
                <a href="<?php echo $unsubscribe_url; ?>"><?php echo $unsubscribe_url; ?></a>
              <?php
            }
            ?>
          </td>
        </tr>
        </tbody>
      </table>
    </td>
  </tr>
  </tbody>
</table>
<div class="gmailfix" style="white-space:nowrap; font:15px courier; line-height:0;">
  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
</div>

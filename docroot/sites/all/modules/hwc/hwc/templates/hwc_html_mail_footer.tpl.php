<?php
$unsubscribe_text = variable_get('unsubscribe_campaign_news_text', 'To unsubscribe from the CAMPAIGN-NEWS list, click the following link:');
$unsubscribe_url = variable_get('unsubscribe_campaign_news_url', 'http://list.osha.eu/scripts/wa.exe?SUBED1=CAMPAIGN-NEWS&A=1');
global $base_url;
//$directory = drupal_get_path('module', 'osha_newsletter');
//$social = array(
//  'email-twitter' => array(
//    'path' => 'https://twitter.com/eu_osha',
//    'alt' => t('Twitter'),
//    'width' => 31,
//  ),
//  'email-facebook' => array(
//    'path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
//    'alt' => t('Facebook'),
//    'width' => 25,
//  ),
//  'email-linkedin' => array(
//    'path' => 'https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
//    'alt' => t('LinkedIn'),
//    'width' => 25,
//  ),
//  'email-youtube' => array(
//    'path' => 'https://www.youtube.com/user/EUOSHA',
//    'alt' => t('Youtube'),
//    'width' => 35,
//  ),
//  'email-flickr' => array(
//    'path' => 'https://www.flickr.com/photos/euosha/albums',
//    'alt' => t('Flickr'),
//    'width' => 31,
//  ),
//);
?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0;background-color:#ffffff;table-layout:fixed;max-width:800px;width:800px">
  <tbody>
  <tr style="border:0;background-color:transparent">
    <td style="vertical-align:top;border:0;">
      <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0">
        <tbody>
        <tr style="border:0;background-color:#a6be1d;height:100px">
          <td style="vertical-align:middle;border:0;color:#ffffff;padding:0">
            <table border="0" cellpadding="0" cellspacing="0" width="100%" style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0">
              <tbody>
              <tr style="border:0;background-color:transparent">
                <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:150px">
                  &nbsp;
                </td>
                <?php

//                foreach ($social as $name => $options) {
//                  $directory = drupal_get_path('module', 'osha_newsletter');
//
//                  $width = $options['width'];
//                  print '<td style="width: 60px; text-align: center; padding-top: 5px;">' . "\n";
//                  print l(
//                      theme('image', array(
//                          'path' => $directory . '/images/' . $name . '.png',
//                          'width' => $width,
//                          'height' => 25,
//                          'alt' => $options['alt'],
//                          'attributes' => array('style' => 'border:0px;height:25px;max-height:25px;width: ' . $width . 'px;max-width:' . $width . 'px;', 'class' => 'social-logo'),
//                        )
//                      ), $options['path'], array(
//                      'attributes' => array('target' => '_blank'),
//                      'html' => TRUE,
//                      'external' => TRUE,
//                    )) . "\n";
//                  print '</td>' . "\n";
//                }

                ?>

                <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:60px;text-align:center;padding-top:5px">
                  <a href="https://twitter.com/eu_osha" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://twitter.com/eu_osha&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNEjD-bso_INECdN2hSssHEjnJUtMA">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px;max-height:25px;width:31px;max-width:31px" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/twitter.jpg" width="31" height="25" alt="Twitter" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:60px;text-align:center;padding-top:5px">
                  <a href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNE8B4kEJTEXOwpWLsxNQLlY3qVc8A">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px;max-height:25px;width:25px;max-width:25px" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/facebook.jpg" width="25" height="25" alt="Facebook" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:60px;text-align:center;padding-top:5px">
                  <a href="https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNECEeZnqSz65ut3caY8dHk2QulewA">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px;max-height:25px;width:25px;max-width:25px" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/linkedin.jpg" width="25" height="25" alt="LinkedIn" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:60px;text-align:center;padding-top:5px">
                  <a href="https://www.youtube.com/user/EUOSHA" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.youtube.com/user/EUOSHA&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNF2DU3gB_j1-A3zLqUuB5pY10OCZQ">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px;max-height:25px;width:35px;max-width:35px" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/youtube.jpg" width="35" height="25" alt="Youtube" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:60px;text-align:center;padding-top:5px">
                  <a href="https://www.flickr.com/photos/euosha/albums" style="color:#0074bd;text-decoration:none;display:inline-block;vertical-align:middle" target="_blank" data-saferedirecturl="https://www.flickr.com/photos/euosha/albums&amp;source=gmail&amp;ust=1581508467712000&amp;usg=AFQjCNHzz7YT4uQIFOXGOqk5lcjUCxlaeg">
                    <img style="display:inline;vertical-align:middle;border:0px;height:25px;max-height:25px;width:31px;max-width:31px" src="https://healthy-workplaces.eu/sites/all/themes/hwc_frontend/images/imghwccrm/flickr.jpg" width="31" height="25" alt="Flickr" class="CToWUd">
                  </a>
                </td>
                <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;width:150px">
                  &nbsp;
                </td>
              </tr>
              </tbody>
            </table>
          </td>
        </tr>
        </tbody>
      </table>
      <table style="font-family:Arial,sans-serif;font-size:14px;border:0;margin:0;border-collapse:collapse;border-spacing:0;padding-top:15px;width:700px;margin-left:50px">
        <tbody>
        <tr style="border:0;background-color:transparent">
          <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;padding-bottom:20px;font-size:10px;font-family:verdana;color:#666666;text-align:center">
            <?php echo $bottom_text; ?>
          </td>
          <td style="vertical-align:top;border:0;padding:5px 20px 5px 20px;padding-bottom:20px;font-size:10px;font-family:verdana;color:#666666;text-align:center">
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

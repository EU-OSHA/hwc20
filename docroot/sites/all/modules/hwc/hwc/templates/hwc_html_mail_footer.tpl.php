<?php
$directory = drupal_get_path('module', 'osha_newsletter');
$unsubscribe_text = variable_get('unsubscribe_campaign_news_text', 'To unsubscribe from the CMPAIGN-NEWS list, click the following link:');
$unsubscribe_url = variable_get('unsubscribe_campaign_news_url', 'http://list.osha.eu/scripts/wa.exe?SUBED1=CAMPAIGN-NEWS&A=1');
$unsubscribe_url = variable_get('unsubscribe_campaign_news_url', 'http://list.osha.eu/scripts/wa.exe?SUBED1=CAMPAIGN-NEWS&A=1');
global $base_url;
$bg_path = $base_url . '/sites/all/modules/osha/osha_newsletter/images/social-background.png';
?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="template-container newsletter-container newsletter-footer" style="max-width:800px; width:800px">
  <tbody>
  <tr>
    <td>
      <table border="0" cellpadding="0" cellspacing="0" width="100%">
        <tbody>
        <tr class="social footer-social" style="background: url(<?php echo $bg_path; ?>) no-repeat; height: 100px;">
          <td>
            <table border="0" cellpadding="0" cellspacing="0" width="100%">
              <tbody>
              <tr style="border: 0; background-color: transparent;">
                <td style="width:150px;">
                  &nbsp;
                </td>
                <?php
                $social = array(
                  'email-twitter' => array(
                    'path' => 'https://twitter.com/eu_osha',
                    'alt' => t('Twitter'),
                    'width' => 31,
                  ),
                  'email-facebook' => array(
                    'path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
                    'alt' => t('Facebook'),
                    'width' => 25,
                  ),
                  'email-linkedin' => array(
                    'path' => 'https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
                    'alt' => t('LinkedIn'),
                    'width' => 25,
                  ),
                  'email-youtube' => array(
                    'path' => 'https://www.youtube.com/user/EUOSHA',
                    'alt' => t('Youtube'),
                    'width' => 35,
                  ),
                  'email-flickr' => array(
                    'path' => 'https://www.flickr.com/photos/euosha/albums',
                    'alt' => t('Flickr'),
                    'width' => 31,
                  ),
                );
                foreach ($social as $name => $options) {
                  $directory = drupal_get_path('module', 'osha_newsletter');

                  $width = $options['width'];
                  print '<td style="width: 60px; text-align: center; padding-top: 5px;">' . "\n";
                  print l(
                      theme('image', array(
                          'path' => $directory . '/images/' . $name . '.png',
                          'width' => $width,
                          'height' => 25,
                          'alt' => $options['alt'],
                          'attributes' => array('style' => 'border:0px;height:25px;max-height:25px;width: ' . $width . 'px;max-width:' . $width . 'px;', 'class' => 'social-logo'),
                        )
                      ), $options['path'], array(
                      'attributes' => array('target' => '_blank'),
                      'html' => TRUE,
                      'external' => TRUE,
                    )) . "\n";
                  print '</td>' . "\n";
                }
                ?>
                <td style="width:150px;">
                  &nbsp;
                </td>
              </tr>
              </tbody>
            </table>
          </td>
        </tr>
        </tbody>
      </table>
      <table style="padding-top: 15px; width: 700px; margin-left: 50px;">
        <tr>
          <td style="border-bottom: 1px solid #999999;padding-bottom: 20px; font-size: 10px; font-family: verdana; color: #666666; text-align: center;">
            <?php echo $bottom_text; ?>
          </td>
        </tr>
      </table>
      <table style="padding-top: 5px; width: 700px; margin-left: 50px;">
        <tr>
          <td style="padding-bottom: 20px; font-size: 10px; font-family: verdana; color: #666666; text-align: center;">
            <?php echo $unsubscribe_text; ?>
            <br>
            <a href="<?php echo $unsubscribe_url; ?>"><?php echo $unsubscribe_url; ?></a>
          </td>
        </tr>
      </table>
    </td>
  </tr>
  </tbody>
</table>

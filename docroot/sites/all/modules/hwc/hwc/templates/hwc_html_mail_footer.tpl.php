<?php
$directory = drupal_get_path('module', 'osha_newsletter');
$unsubscribe_text = variable_list('unsubscribe_campaign_news_text', 'To unsubscribe from the CMPAIGN-NEWS list, click the following link:');
$unsubscribe_url = variable_list('unsubscribe_campaign_news_url', 'http://list.osha.eu/scripts/wa.exe?SUBED1=CAMPAIGN-NEWS&A=1');
?>
<table border="0" cellpadding="0" cellspacing="0" width="100%" class="template-container newsletter-container newsletter-footer" style="max-width:800px; width:800px">
  <tbody>
  <tr>
    <td>
      <table border="0" cellpadding="0" cellspacing="0" width="100%">
        <tbody>
        <tr class="social footer-social" style="background: url(<?php echo '/' . $directory . '/images/'; ?>social-background.png) no-repeat; background-size: cover; height: 100px;">
          <td style="width:150px;">
            &nbsp;
          </td>
          <td style="color: #FFF; text-align: end; font-size: 30px; padding-right: 10px; font-family: verdana">
            Follow us on
          </td>
          <td style="width: 60px; text-align: center; padding-top: 5px;">
            <a href="https://twitter.com/eu_osha">
              <img src="<?php echo '/' . $directory . '/images/'; ?>email-twitter.png">
            </a>
          </td>
          <td style="width: 60px; text-align: center; padding-top: 5px;">
            <a href="https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork">
              <img src="<?php echo '/' . $directory . '/images/'; ?>email-facebook.png">
            </a>
          </td>
          <td style="width: 60px; text-align: center; padding-top: 5px;">
            <a href="https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work">
              <img src="<?php echo '/' . $directory . '/images/'; ?>email-linkedin.png">
            </a>
          </td>
          <td style="width: 60px; text-align: center; padding-top: 5px;">
            <a href="https://www.youtube.com/user/EUOSHA">
              <img src="<?php echo '/' . $directory . '/images/'; ?>email-youtube.png">
            </a>
          </td>
          <td style="width: 60px; text-align: center; padding-top: 5px;">
            <a href="https://www.flickr.com/photos/euosha/albums">
              <img src="<?php echo '/' . $directory . '/images/'; ?>email-flickr.png">
            </a>
          </td>
          <td style="width:150px;">
            &nbsp;
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

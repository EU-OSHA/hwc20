<?php
/**
 * @file
 * EU-OSHA's theme implementation to display a newsletter item in Newsletter item view mode.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */

$campaign_id = '';
if (!empty($variables['elements']['#campaign_id'])) {
  $campaign_id = $variables['elements']['#campaign_id'];
}
elseif (!empty($variables['campaign_id'])) {
  $campaign_id = $variables['campaign_id'];
}

$url_query = array();
if (!empty($campaign_id)) {
  $url_query = array('pk_campaign' => $campaign_id);
}
?>
<?php if ($node->title != NULL) {?>
  <table id="node-<?php print $node->nid; ?>" class="newsletter-item <?php print drupal_clean_css_identifier($node->type); ?>">
    <tbody>
      <?php if(!empty($node->old_newsletter)): ?>
        <tr>
          <td colspan="3" class="pt15"></td>
        </tr>
      <?php endif; ?>
    <?php
    if (isset($node->field_publication_date[LANGUAGE_NONE][0]['value']) && $node->type != 'newsletter_article') {
      $date = strtotime($node->field_publication_date[LANGUAGE_NONE][0]['value']);
    }
    $link = 'node/' . $node->nid;
    if (isset($node->alt_url)) {
      $link = $node->alt_url;
    }
    if ($node->type == 'news') {
      $w = entity_metadata_wrapper('node', $node);
      if (!empty($node->field_image)) {
        $field_image = $w->field_image->value();
      }
      $field_publication_date = '';
      if (!empty($node->field_publication_date)) {
        if (isset($node->field_publication_date[0])) {
            $node->field_publication_date = [LANGUAGE_NONE => $node->field_publication_date];
        }
        $field_publication_date = $w->field_publication_date->value();
      }
      // Url healthy-workplaces-newsletter.
      if (129 == arg(1)) {
          ?>
          <tr>
              <td style="padding-left: 10px;padding-top: 10px; width: 100%; font-size: 12px; font-family: Arial, sans-serif; color: #000000;">
                  <div style="color:#59595a"><?php echo format_date($field_publication_date, 'custom', 'd/m/Y'); ?></div>
                  <div>
                    <?php
                    print l($title, url($node->url, array('absolute' => TRUE)), array(
                      'attributes' => array('style' => 'font-family: Arial, sans-serif; color: #003399; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: top; text-decoration: none;'),
                      'query' => $url_query,
                      'external' => TRUE,
                    ));
                    ?>
                  </div>
              </td>
          </tr>
          <?php
      }
        else {
          ?>
            <tr>
                <td style="width: 220px; font-size: 12px; font-family: Arial, sans-serif; color: #000000; vertical-align: middle; padding: 0; margin: 0;">
                  <table>
                    <tr>
                      <td style="border: 0;margin:0;padding: 0;">
                        <?php
                          if (isset($field_image)) {
                              print l(theme('image_style', array(
                                'style_name' => 'medium_newsletter_crop',
                                'path' => (isset($field_image) && !empty($field_image)) ? $field_image['uri'] : '',
                                'width' => 220,
                                'alt' => (isset($field_image) && !empty($field_image)) ? $field_image['alt'] : '',
                                'attributes' => array(
                                  'style' => 'vertical-align:middle;max-width: initial!important; border-radius: 15px;',
                                  'align' => 'left',
                                ),
                              )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
                                'html' => TRUE,
                                'external' => TRUE,
                                'query' => $url_query,
                                'attributes' => array('style' => ''),
                              ));
                          }
                          ?>
                       </td>
                      </tr>
                    </table>
                  </div>
                </td>
                <td style="padding-bottom: 0px; width: 80%; font-size: 12px; font-family: Arial, sans-serif; color: #000000; padding-left: 15px; ">
                    <div style="font-weight: bold; color: #59595a"><?php echo format_date($field_publication_date, 'custom', 'd/m/Y'); ?></div>
                    <div>
                      <?php
                      print l($title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
                        'attributes' => array('style' => 'font-family: Arial, sans-serif; color: #003399; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: middle; text-decoration: none;'),
                        'query' => $url_query,
                        'external' => TRUE,
                      ));
                      ?>
                    </div>
                    <table>
                      <tr>
                        <td style="padding-top: 8px;color:#000;font-size: 13px;line-height: 18px; color:#59595a">
                          <?php
                            $is_empty = FALSE;
                            $summary = render($elements['field_summary']);
                            if (!trim(strip_tags($summary))) {
                              $is_empty = TRUE;
                            }
                            else {
                                $clear = strip_tags($summary);
                                print substrwords($clear, 300);
                            }

                            if (!empty($elements['body']) && $is_empty) {
                              $text = $elements['body'][0]['#markup'];
                              $clear = strip_tags($text);
                              print substrwords($clear, 300);

                            }

                            $directory = drupal_get_path('module', 'osha_newsletter');

                          ?>
                      </td>
                    </tr>
                  </table>

                </td>
            </tr>
            <tr>
                <td style="padding-bottom: 10px; ">&nbsp;</td>
                <td style="padding-bottom: 10px;padding-left: 15px">
                    <table>
                        <tr>
                            <td style="padding-top: 0px;" width="505">
                              <?php
                              print '<div>';
                              $node_url = url('node/' . $node->nid, array('absolute' => TRUE));
                              print l(t('See more'), $node_url, array(
                                'attributes' => array('class' => ['see-more']),
                                'query' => $url_query,
                                'external' => TRUE,
                              ));
                              print '</div>';
                              ?>
                            </td>
                            <td align="right" valign="middle" style="padding-top: 0px;" width="20">
                              <?php
                              print l(theme('image', array(
                                'path' => $directory . '/images/' . 'share-icon.png',
                                'width' => '20',
                                'height' => '20',
                                'attributes' => array('style' => 'border:0px;width:20px;height:20px;'),
                              )), $node_url, array(
                                'html' => TRUE,
                                'query' => $url_query + ['action' => 'share'],
                                'external' => TRUE,
                              ));
                              ?>

                            </td>
                        </tr>
                    </table>
                </td>
            </tr>
            <tr>
              <td colspan="2" style="border-top: 1px solid #749b00;line-height: 12px;">&nbsp;</td>
            </tr>
          <?php
      }
      ?>
      <?php
    }
    if ($node->type == 'spotlight') {
      $w = entity_metadata_wrapper('node', $node);
      if (!empty($node->field_image)) {
        $field_image = $w->field_image->value();
        if (!$field_image) {
          $field_image = $node->field_image[0];
        }
      }
      $field_publication_date = '';
      if (!empty($node->field_publication_date)) {
        if (isset($node->field_publication_date[0])) {
          $node->field_publication_date = [LANGUAGE_NONE => $node->field_publication_date];
        }
        $field_publication_date = $w->field_publication_date->value();
      }
    ?>
      <tr>
        <td colspan="2" style="font-size:20px; border-bottom: 2px solid #003399; margin-bottom: 10px;">
          <table>
            <tr>
              <td style="vertical-align: top;padding: 0;border: 0;color: #003399;padding-left: 24px;font-size: 19px;height: 20px;background: url(/sites/all/themes/hwc_frontend/images/spotlight.png) no-repeat 0px 1px;">
                 <?php
                  // todo spotlight styles here.
                  echo t(variable_get('in_spotlight_text', 'In the spotlight'));
                  ?>
              </td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td>
          &nbsp;
        </td>
      </tr>
      <tr>
        <td style="min-height: 160px; width: 220px; font-size: 12px; font-family: Arial, sans-serif; color: #000000; vertical-align: middle; padding: 0; margin: 0;">
          <table style="min-height: 160px;">
            <tr>
              <td style="vertical-align: middle; margin:0;padding: 0; padding-left: 30px; color:#FFF;background: #a6be1d;border-bottom-left-radius: 15px; border-top-left-radius: 15px;padding-top: 2em;padding-bottom: 2em;">
                <?php
                if (isset($field_image)) {
                  print l(theme('image_style', array(
                    'style_name' => 'spotlight',
                    'path' => (isset($field_image) && !empty($field_image)) ? $field_image['uri'] : '',
                    'width' => 260,
                    'alt' => (isset($field_image) && !empty($field_image)) ? $field_image['alt'] : '',
                    'attributes' => array(
                      'style' => 'vertical-align:middle;max-width: initial!important;border-radius:15px',
                      'align' => 'left',
                    ),
                  )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
                    'html' => TRUE,
                    'external' => TRUE,
                    'query' => $url_query,
                    'attributes' => array('style' => ''),
                  ));
                }
                ?>
              </td>
            </tr>
          </table>
          </div>
        </td>
        <td style="padding-bottom: 0px; width: 80%; font-size: 12px; font-family: Arial, sans-serif; color: #FFF; padding-left: 15px; background: #a6be1d; vertical-align: middle; border-bottom-right-radius: 15px; border-top-right-radius: 15px; vertical-align: top; padding-top: 2em;">
          <div style="font-weight: bold; color:#59595a"><?php echo format_date($field_publication_date, 'custom', 'd/m/Y'); ?></div>
          <div style="padding-top: 1em;">
            <?php
            print l($title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
              'attributes' => array('style' => 'font-family: Arial, sans-serif; color: #FFF; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: middle; text-decoration: none;'),
              'query' => $url_query,
              'external' => TRUE,
            ));
            ?>
          </div>
          <table>
            <tr>
              <td style="padding-top: 8px;color:#FFF;font-size: 13px;line-height: 18px;">
                <?php
                $is_empty = FALSE;
                // todo city country.
                $summary = render($elements['field_summary']);
                if (!trim(strip_tags($summary))) {
                  $is_empty = TRUE;
                }
                else {
                  $clear = strip_tags($summary);
                  print substrwords($clear, 300);
                }
                $directory = drupal_get_path('module', 'osha_newsletter');
                ?>
              </td>
            </tr>
          </table>

        </td>
      </tr>
      <tr>
        <td colspan="2" style="border-top: 1px solid #749b00;line-height: 12px;">&nbsp;</td>
      </tr>
      <?php
    }
    if ($node->type == 'twitter_tweet_feed') {
?>
        <tr style="height: 100%;">
          <?php if (!in_array($node->type, ['twitter_tweet_feed'])
            && (empty($node->parent_section) || $node->parent_section != 13)) { ?>
              <td align="left" width="10" style="padding-right: 0px; vertical-align: top; padding-top: 5px; font-family: Arial, sans-serif;width:10px;">
                  <span> > </span>
              </td>
          <?php } ?>
            <td align="right" style="text-align: left; padding-top: 5px; padding-bottom: 10px; padding-left:0px;">
              <?php
                  if (!empty($node->field_tweet_author[LANGUAGE_NONE][0]['value'])
                    && !empty($node->field_tweet_contents[LANGUAGE_NONE][0]['value'])
                    && !empty($node->field_link_to_tweet[LANGUAGE_NONE][0]['value'])) {
                    printf("<p class='tweet-author'><a target='_blank' href='%s'>@%s</a></p><p class='tweet-contents'>%s</p>",
                      $node->field_link_to_tweet[LANGUAGE_NONE][0]['value'],
                      $node->field_tweet_author[LANGUAGE_NONE][0]['value'],
                      $node->field_tweet_contents[LANGUAGE_NONE][0]['value']);
                  }
                  else {
                    print l($node->title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
                      'attributes' => array('style' => 'text-decoration: none; font-family:Arial, sans-serif; font-size: 13px; font-weight: bold;'),
                      'query' => $url_query,
                      'external' => TRUE,
                    ));
                  }
              ?>
            </td>
        </tr>
      <?php
    }
    if ($node->type == 'events') {
      global $base_url;
      $date = (isset($field_start_date) && !empty($field_start_date)) ? strtotime($field_start_date[0]['value']) : '';
      $city = $node->field_city[LANGUAGE_NONE][0]['value'];
      $country_code = $node->field_country_code[LANGUAGE_NONE][0]['value'];
      $info = field_info_field('field_country_code');
      $country_codes = $info['settings']['allowed_values'];
      ?>
      <tr>
          <td class="rs2" rowspan="2" style="text-align: center;">
            <?php
            $calendar_month = date('D', $date);

            $calendar_img = 'calendar-' . date('d', $date);
            $calendar_img = !empty($node->arrow_color) ? "{$calendar_img}-{$node->arrow_color}.png" : "{$calendar_img}.png";
            $calendar_img_path = "{$base_url}/sites/all/modules/osha/osha_newsletter/images/calendars/{$calendar_img}";

            $style = 'border: 0px;display:block;';
            print l(theme('image', array(
              'path' => $calendar_img_path,
              'alt' => 'calendar',
              'attributes' => array('style' => $style),
            )),
              url('node/' . $node->nid, array('absolute' => TRUE)),
              array('html' => TRUE, 'external' => TRUE, 'query' => $url_query));
           ?>
            <span style="padding-top: 5px;display: block;font-weight: bold;"><?php echo t(strtoupper($calendar_month)); ?></span>
          </td>
          <td colspan="2" class="cs2">
            <span class="item-date"><?php
              $date = format_date($date, 'custom', 'd/m/Y');
              print l($date, url($link, array('absolute' => TRUE)), array(
                'attributes' => array('style' => 'text-decoration: none; font-family:Arial, sans-serif; font-size: 13px; font-weight: bold;'),
                'query' => $url_query,
                'external' => TRUE,
              ));
           ?></span>
            <div class="content-date-country">
                <?php if ($country_code) { ?>
                <span class="city">
                  <?php echo $country_codes[$country_code] . ', ';?><?php } ?>    
                </span>
                <span class="country">
                  <?php echo $city; ?>
                </span>
              </div>
          </td>
      </tr>
      <tr class="tr_h">
          <td class="ar"><?php
            print l($node->title, url($link, array('absolute' => TRUE)), array(
              'attributes' => array('style' => 'text-decoration: none; font-family:Arial, sans-serif; font-size: 13px; font-weight: bold;'),
              'query' => $url_query,
              'external' => TRUE,
            ));
            ?>
          </td>
      </tr>
      <?php
    }
    if(!empty($node->old_newsletter)): ?>
      <tr>
        <td colspan="3" class="pt15"></td>
      </tr>
    <?php endif; ?>
    </tbody>
  </table>
<?php }

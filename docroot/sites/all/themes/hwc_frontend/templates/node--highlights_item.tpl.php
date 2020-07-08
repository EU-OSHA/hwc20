<?php

/**
 * @file
 * EU-OSHA's theme implementation to display a newsletter item in Newsletter Highlights view mode.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
global $osha_newsletter_send_mail;

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
<table id="node-<?php print $node->nid; ?>" border="0" cellpadding="0" cellspacing="0" width="100%" class="highlight-item">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" class="item-thumbnail-and-title" width="100%">
          <thead>
            <tr>
              <th rowspan=2 width="220" class="template-column template-image">
                <table border="0" cellpadding="0" cellspacing="0" width="100%">
                  <tbody>
                    <tr>
                      <td align="left" width="width: 220px;" style="padding: 0 0 25px 0!important;">
                        <?php
                          if ($node->type == 'youtube') {
                            if (!empty($node->field_youtube[LANGUAGE_NONE][0]['video_id'])) {
                              $video_id = $node->field_youtube[LANGUAGE_NONE][0]['video_id'];
                            }
                            elseif (!empty($node->field_youtube['en'][0]['video_id'])) {
                              $video_id = $node->field_youtube['en'][0]['video_id'];
                            }
                            if (!empty($video_id)) {
                                if (!empty($osha_newsletter_send_mail)) {
                                  print l(theme('image', array(
                                    'style_name' => 'newsletter_highlight',
                                    'path' => sprintf("https://img.youtube.com/vi/%s/hqdefault.jpg", $video_id),
                                    'alt' => $title,
                                    'attributes' => array('style' => 'border-radius: 15px;'),
                                  )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
                                    'html' => TRUE,
                                    'query' => $url_query,
                                    'external' => TRUE,
                                  ));
                                }
                                else {
                                  print '<iframe id="youtube-field-player" class="youtube-field-player" width="100%" height="225" src="//www.youtube.com/embed/' . $video_id . '?wmode=opaque" frameborder="0" allowfullscreen=""></iframe>';
                                }

                            }
                          }
                          else {

                            $w = entity_metadata_wrapper('node', $node);
                            $image_style = 'medium_newsletter_crop';
                            if (!empty($node->field_image_mail)) {
                              $field_image = [$w->field_image_mail->value()];
                              $image_style = 'medium_newsletter_mail_crop';
                            }
                            print l(theme('image_style', array(
                              'style_name' => $image_style,
                              'path' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['uri'] : '',                              
                              'alt' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['alt'] : '',
                              'attributes' => array('style' => ''),
                              'attributes' => array('style' => 'border-radius: 15px;'),
                            )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
                              'html' => TRUE,
                              'query' => $url_query,
                              'external' => TRUE,                              
                            ));
                          }
                        ?>
                      </td>
                    </tr>
                  </tbody>
                </table>
              </th>
              <th valign="top" style="color: #003399; padding-bottom: 7px; padding-left: 15px; padding-right: 0px;font-family: Arial, sans-serif;" class="template-column">
                <?php
                if (isset($node->field_publication_date[LANGUAGE_NONE][0]['value'])) {
                  $date = strtotime($node->field_publication_date[LANGUAGE_NONE][0]['value']);
                }
                ?>
                <div class="item-date" style="color: #59595a;font-family: Arial, sans-serif;font-size: 12px;line-height: 12px;padding-bottom: 10px;font-weight: bold;"><?php print format_date($date, 'custom', 'd/m/Y');?></div>
                <?php
                if ($node->type == 'publication') {
                  print l($title, url('node/' . $node->nid . '/view', array('absolute' => TRUE)), array(
                    'attributes' => array('class' => ['highlight-title']),
                    'query' => $url_query,
                    'external' => TRUE,
                    'html' => TRUE,
                  ));
                } else {
                  print l($title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
                    'attributes' => array('class' => ['highlight-title']),
                    'query' => $url_query,
                    'external' => TRUE,
                    'html' => TRUE,
                  ));
                }
                ?>
              </th>
            </tr>
            <tr><th class="body-responsive" style="padding-left: 15px;">
              <table border="0" cellpadding="0" cellspacing="0" class="item-summary" width="100%">
                <tbody>
                  <tr>
                    <td colspan="2" style="width: 100%; font-size: 13px; font-family: Arial, sans-serif; color: #59595a;">
                      <?php
                      $body_text = '';
                      if (isset($field_summary) && is_array($field_summary) && !empty($field_summary)) {
                        $body_text = field_view_field('node', $node, 'field_summary', 'highlights_item');
                      }
                      elseif (isset($body) && is_array($body) && !empty($body)) {
                        $body_text = field_view_field('node', $node, 'body', 'highlights_item');
                      }
                      $body_text = render($body_text);
                      if (!empty($body_text)) {
                        if (!empty($campaign_id)) {
                          // CW-1896 Add pk_campaign to links inside the body text.
                          $doc = new DOMDocument();
                          $doc->loadHTML(mb_convert_encoding($body_text, 'HTML-ENTITIES', "UTF-8"));
                          $links = $doc->getElementsByTagName('a');
                          foreach ($links as $link) {
                            $url = $link->getAttribute('href');
                            $url_comp = parse_url($url);
                            if (preg_match('/(osha.europa.eu|napofilm.net|oshwiki.eu|oiraproject.eu|esener.eu|healthy-workplaces.eu|healthyworkplaces.eu|localhost|eu-osha.bilbomatica.es)/', $url_comp['host'])) {
                              $link->setAttribute('href', $url . ($url_comp['query'] ? '&' : '?') . 'pk_campaign=' . $campaign_id);
                            }
                          }
                          if ($links->length > 0) {
                            $body_text = $doc->saveHTML();
                          }
                        }
                        print($body_text);
                      }
                      ?>
                    </td>
                  </tr>
                  <tr>
                      <td style="font-family: Arial, sans-serif; padding-top: 10px;padding-bottom: 10px;">
                        <?php
                        if ($node->type == 'publication') {
                          $node_url = url('node/' . $node->nid . '/view', array('absolute' => TRUE));
                        }
                        else {
                          $node_url = url('node/' . $node->nid, array('absolute' => TRUE));
                        }
                        $directory = drupal_get_path('module', 'osha_newsletter');
                        print l(theme('image', array(
                          'path' => $directory . '/images/' . 'see-more-img.png',
                          'width' => '92',
                          'height' => '23',
                          'attributes' => array('style' => 'border:0px;width:92px;height:23px;'),
                        )), $node_url, array(
                          'html' => TRUE,
                          'query' => $url_query,
                          'external' => TRUE,
                        ));
                        ?>
                      </td>
                      <td class="highlight-share hidden-mobile" align="right" valign="middle" style="font-family: Arial, sans-serif; padding-top: 10px;">
                        <?php
                        $directory = drupal_get_path('module', 'osha_newsletter');
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
                </tbody>
              </table>
            </th></tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>

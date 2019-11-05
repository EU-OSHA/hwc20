<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
$i = 1;
$video_id = @$row->field_field_banner_video[0]['raw']['entity']->field_youtube['en'][0]['video_id'];
if ($video_id) {
?>
<div class="youtube-video">
  <div class="video">
    <?php echo render($row->field_field_image); ?>
    <img id="hp-btn<?php print $i; ?>" class="icon-play" alt="play" src="/sites/all/themes/hwc_frontend/images/icon-play.png">
  </div>
  <div id="hp-modal<?php print $i; ?>" class="hp-modal">
    <div class="hp-modal-content">
      <span class="hp-close close<?php print $i; ?>">&times;</span>
      <iframe class="videoIframe js-videoIframe hp-video-modal-<?php print $i; ?>" src="https://www.youtube-nocookie.com/embed/<?php print $video_id ?>"  allowfullscreen></iframe>
    </div>
  </div>
</div>
<style>
  .youtube-video {
    position: relative;
    float: left;
    margin-top: 1em;
    margin-right: 1em;
  }
  .youtube-video img {
    width: 100%;
    height: auto;
  }
  .youtube-video img.icon-play {
    width: 70px;
    position: absolute;
    top: 29%;
    left: 41%;
    cursor: pointer;
    height: auto;
  }
  .youtube-video .hp-modal {
    display: none;
    position: fixed;
    z-index: 9999999;
    padding-top: 100px;
    left: 0;
    top: 0;
    width: 100%;
    height: 100%;
    overflow: auto;
    background-color: rgb(0,0,0);
    background-color: rgba(0,0,0,0.4);
  }
  .youtube-video .hp-modal-content {
    background-color: #fefefe;
    margin: auto;
    padding: 20px;
    border: 1px solid #888;
    width: 80%;
    height: 80%;
  }
  .youtube-video .hp-close {
    color: #003399;
    float: right;
    font-size: 28px;
    font-weight: bold;
    display: block;
    margin-top: -11px;
    padding-bottom: 0.5em;
    cursor: pointer;
  }
  .youtube-video .hp-modal-content iframe {
    width: 100%;
    height: 96%;
  }

</style>
<?php
}

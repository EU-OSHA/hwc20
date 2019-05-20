<?php
/**
 * @file
 * Template file for the galleryformatter default formatter
 */
?>
<div class="galleryformatter galleryview galleryformatter-<?php print $settings['style'] ?>">
  <div class="gallery-slides" style="width: <?php print $dimensions['slides']['width']; ?>px; height: <?php print $dimensions['slides']['height']; ?>px;">
    <div class="gallery-frame">
      <ul>
      <?php foreach ($slides as $id => $data): ?>
        <li class="gallery-slide" id="<?php print $data['hash_id']; ?>">
          <?php print $data['image']; ?>
          <?php if (!empty($data['title']) || !empty($data['alt'])): ?>
            <div class="panel-overlay">
              <div class="overlay-inner">
                <?php if ($data['alt']): ?><h4><?php print $data['alt']; ?></h4><?php endif; ?>
                <?php if ($data['title']): ?><h3><?php print $data['title']; ?></h3><?php endif; ?>
              </div>
            </div>
          <?php endif; ?>
        </li>
      <?php endforeach; ?>
      </ul>
    </div>
  </div>
  <?php if(!empty($thumbs)): ?>
  <div class="gallery-thumbs" style="width: <?php print $dimensions['slides']['width']; ?>px;">
    <div class="wrapper">
      <ul>
        <?php foreach ($thumbs as $id => $data): ?>
          <li class="slide-<?php print $id; ?>" style="width: <?php print $dimensions['thumbs']['width']; ?>px;"><a href="#<?php print $data['hash_id']; ?>"><?php print $data['image']; ?></a></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
  <?php endif; ?>
</div>

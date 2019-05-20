<div class="panel-pane pane-entity-field pane-node-title-field">
    <div class="pane-content">
        <div class="field field-name-title-field field-type-text field-label-hidden">
            <div class="field-items">
                <div class="field-item even"><h1><?php print $title; ?></h1>
                    <div class="back_link"><?php print $back_link; ?></div>
                </div>
            </div>
        </div>
    </div>
</div>
<div class="gpep-links-block">
  <div class="col-xs-12 col-sm-12">
    <div class="hwc-gpep-intro-text">
      <span><?php print $intro_text; ?></span>
    </div>
    <div class="hwc-gpep-links">
      <?php print implode('', $links); ?>
    </div>
  </div>
</div>

<?php
/**
 * @file
 * Returns the HTML for an article node.
 */
?>
<?php
/** @var array $content */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <div class="container">
    <div class="group-left col-sm-4">
      <?php print render($content['field_thumbnail']); ?>
    </div>
    <div class="group-right col-sm-8">
        <h2>
          <?php print render($content['title_field']['#object']->title); ?>
          
        </h2>
  
        <div class="field field-name-field-image field-type-image field-label-hidden field-external-infographic-content">
          <div class="field-items">
            <div class="field-item even">
              <span class="label_multilang_file label-external-infographic-open"><?php print t("Open in"); ?>:</span>
              <?php
                foreach ($node->field_infographic_url as $key => $value) {
                  if ($key != 'nol' && $key != 'tr' ){
              ?>
                    <span class="link-infographic-custom">
                      <a href='/<?php print  $key ?><?php print $content['field_infographic_url']['#items'][0]['url'] ?>?lan=<?php echo $key ?>'>
                        <?php echo $key ?> <span class="separator-infographic">|</span> 
                      </a>
                    </span> 
              <?php   
                  }
                }
              ?>
            </div>
          </div>
        </div>
    
    </div>

    

    <?php
    
    

    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    //  print render($content['links']['#links']['addtoany']['title']);
    //  unset($content['links']['#links']['addtoany']);


    print render($content['comments']);
    ?>
  </div>
</article>

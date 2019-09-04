<div class="how-to-apply">
  <h3><?php print t('How to apply');?></h3>
  <div class="timeline">
    <div>1</div>
    <div><?php echo t(gmdate('F', $download_deadline)) . gmdate(' Y', $download_deadline);?></div>
    <div>2</div>
    <div><?php echo t(gmdate('F', $registration_deadline)) . gmdate(' Y', $registration_deadline);?></div>
    <div>3</div>
  </div>
  <div class="boxes">
    <div class="box <?php echo $download_class; ?>">
      <h4><?php echo $download_title; ?></h4>
      <p><?php echo $download_body; ?></p>
      <div><?php
        if ($download_class == 'active') {
          echo $download_link;
        } ?></div>
    </div>
    <div class="box <?php echo $application_form_class; ?>">
      <h4><?php echo $application_form_title; ?></h4>
      <p><?php echo $application_form_body; ?></p>
      <div><?php
        if ($application_form_class == 'active') {
          echo $application_form_link;
        } ?></div>
    </div>
    <div class="box <?php echo $see_results_class; ?>">
      <h4><?php echo $see_results_title; ?></h4>
      <p><?php echo $see_results_body; ?></p>
    </div>
  </div>
</div>






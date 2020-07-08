<?php
/** @var timestamp $download_deadline */
/** @var timestamp $registration_deadline */
/** @var timestamp $first_date */
/** @var timestamp $last_date */
?>
<div class="how-to-apply">
  <h3><?php print t('How to apply');?></h3>
  <div class="timeline">
    <div><span><?php
        if (variable_get('hwc_partner_registration_first_date_month', TRUE)) {
          echo t(gmdate('F', $first_date));
        }
        echo gmdate(' Y', $first_date);
        ?></span></div>
    <div><span><?php
        echo t(gmdate('F', $download_deadline)) . gmdate(' Y', $download_deadline);
        echo ' - ';
        echo t(gmdate('F', $registration_deadline)) . gmdate(' Y', $registration_deadline);
        ?></span></div>
    <div><span><?php
        if (variable_get('hwc_partner_registration_last_date_month', FALSE)) {
          echo t(gmdate('F', $last_date));
        }
        echo gmdate(' Y', $last_date);
        ?></span></div>
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
      <div><?php echo $application_form_link; ?></div>
    </div>
    <div class="box <?php echo $see_results_class; ?>">
      <h4><?php echo $see_results_title; ?></h4>
      <p><?php echo $see_results_body; ?></p>
    </div>
  </div>
</div>

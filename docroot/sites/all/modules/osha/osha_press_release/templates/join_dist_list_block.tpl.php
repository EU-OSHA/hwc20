<div id="join-list">
  <div id="join-list-intro">
    <?php print $join_dist_list_block_intro_text;?>
  </div>
  <div id="join-list-link">
    <?php
      print l($join_dist_list_link_label, "mailto:$join_dist_list_link_url", array(
        'html' => TRUE,
        'external' => TRUE,
        'query' => array(
          'subject' => "News Distribution List Registration",
          'body' => $join_dist_list_email_text,
        ),
      ));
    ?>
  </div>
</div>

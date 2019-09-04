<span class="add-to-my-calendar" id="add-to-calendar-<?php print $nid; ?>" href="#"></span>
<script>
  var myCalendar<?php print $nid; ?> = createCalendar({
    options: {
    },
    data: {
      title: '<?php print strip_tags($title); ?>',
      start: new Date('<?php print $start_date; ?>'),
      end: new Date('<?php print $end_date; ?>'),
      description: '<?php print $description; ?>'
    }
  });
  document.querySelector('#add-to-calendar-<?php print $nid; ?>').appendChild(myCalendar<?php print $nid; ?>);
</script>


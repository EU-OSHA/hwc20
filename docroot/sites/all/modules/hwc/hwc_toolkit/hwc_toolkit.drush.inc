<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function hwc_toolkit_drush_command()
{
  $items = array();
  $items['tools-to-queue'] = array(
    'description' => 'Refresh strings',
    'examples' => array(),
    'options' => array(),
  );
  return $items;
}

function drush_hwc_toolkit_tools_to_queue() {
  $added = hwc_toolkit_add_tool_to_queue();
  drush_log('Added = ' . $added, 'ok');
}

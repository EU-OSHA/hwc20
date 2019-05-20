<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Practical tool details - single column'),
  'category' => t('Columns: 1'),
  'icon' => 'practical_tool_details.png',
  'theme' => 'panels_practical_tool_details',
  'css' => 'practical_tool_details.css',
  'regions' => array('middle' => t('Middle column')),
);

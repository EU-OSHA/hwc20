<?php

$aliases['staging'] = array(
  'uri' => 'D',
  'db-allows-remote' => TRUE,
  'remote-host' => 'D',
  'remote-user' => 'D',
  'root' => 'D',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
  'command-specific' => array(
    'sql-sync' => array(
      'simulate' => '1',
      'source-dump' => '/tmp/hwc-source-dump.sql',
    ),
  ),
);


// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}

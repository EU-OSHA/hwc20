<?php

/**
 * Implements COMMANDFILE_drush_command().
 */
function hwc_toolkit_migration_drush_command()
{
  $items = array();
  $items['tools-and-examples'] = array(
    'description' => 'Import Tools and Examples',
    'examples' => array(),
    'options' => array(),
  );
  return $items;
}

function drush_hwc_toolkit_migration_tools_and_examples() {
  $file = sprintf('%s/data/tae.json', dirname(__FILE__));
  if (!is_readable($file)) {
    drupal_set_message("Cannot read taxonomy file! ($file).", 'warning');
  }
  else {
    $json = json_decode(file_get_contents($file), TRUE);
    $taxonomy = 'tools_and_examples';
    $voc = taxonomy_vocabulary_machine_name_load($taxonomy);
    if (empty($voc)) {
      drupal_set_message("$taxonomy doesn't exits!", 'warning');
    }
    else {
      if (empty($json)) {
        drupal_set_message("Empty taxonomy $taxonomy found in file!", 'warning');
      }
      else {
        $map = [];
        foreach ($json as $item) {
          // Creating the term.
          $term = new stdClass();
          $term->name = $term->name_field['en'][0]['value'] = $item['name'];
          $term->vid = $voc->vid;
          $term->language = 'en';
          if ($item['parent'] && $map[$item['parent']]) {
            $term->parent = $map[$item['parent']];
          }
          taxonomy_term_save($term);
          if (!empty($term->tid)) {
            $map[$item['alias']] = $term->tid;
          }
          else {
            drupal_set_message("$term->name could not be saved!", 'warning');
          }
        }
      }
    }
  }
}

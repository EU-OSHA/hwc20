<?php
/**
 * @file
 * hwc_glossary.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hwc_glossary_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_allow_no_description';
  $strongarm->value = 0;
  $export['lexicon_allow_no_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_alphabar_instruction';
  $strongarm->value = '';
  $export['lexicon_alphabar_instruction'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_alphabar_separator';
  $strongarm->value = '|';
  $export['lexicon_alphabar_separator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_alphabet';
  $strongarm->value = array(
    0 => 'a',
    1 => 'b',
    2 => 'c',
    3 => 'd',
    4 => 'e',
    5 => 'f',
    6 => 'g',
    7 => 'h',
    8 => 'i',
    9 => 'j',
    10 => 'k',
    11 => 'l',
    12 => 'm',
    13 => 'n',
    14 => 'o',
    15 => 'p',
    16 => 'q',
    17 => 'r',
    18 => 's',
    19 => 't',
    20 => 'u',
    21 => 'v',
    22 => 'w',
    23 => 'x',
    24 => 'y',
    25 => 'z',
  );
  $export['lexicon_alphabet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_blocking_tags';
  $strongarm->value = 'abbr acronym';
  $export['lexicon_blocking_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_case';
  $strongarm->value = '0';
  $export['lexicon_case'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_click_option';
  $strongarm->value = '0';
  $export['lexicon_click_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_digits';
  $strongarm->value = array();
  $export['lexicon_digits'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_disable_indicator';
  $strongarm->value = 0;
  $export['lexicon_disable_indicator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_go_to_top_link';
  $strongarm->value = 0;
  $export['lexicon_go_to_top_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_go_to_top_link_fragment';
  $strongarm->value = 'top';
  $export['lexicon_go_to_top_link_fragment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_icon';
  $strongarm->value = 'sites/all/modules/contrib/lexicon/imgs/lexicon.gif';
  $export['lexicon_icon'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_introduction_48';
  $strongarm->value = array(
    'value' => '',
    'format' => 'full_html',
  );
  $export['lexicon_introduction_48'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_link';
  $strongarm->value = 'absolute';
  $export['lexicon_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_link_related';
  $strongarm->value = 0;
  $export['lexicon_link_related'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_link_to_term_page';
  $strongarm->value = 0;
  $export['lexicon_link_to_term_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_local_links_scroll';
  $strongarm->value = 0;
  $export['lexicon_local_links_scroll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_mark_terms';
  $strongarm->value = 0;
  $export['lexicon_mark_terms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_match';
  $strongarm->value = 'b';
  $export['lexicon_match'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_page_per_letter';
  $strongarm->value = 1;
  $export['lexicon_page_per_letter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_path_48';
  $strongarm->value = 'glossary';
  $export['lexicon_path_48'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_replace';
  $strongarm->value = 'template';
  $export['lexicon_replace'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_replace_all';
  $strongarm->value = '1';
  $export['lexicon_replace_all'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_separate_letters';
  $strongarm->value = 0;
  $export['lexicon_separate_letters'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_show_description';
  $strongarm->value = 1;
  $export['lexicon_show_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_show_edit';
  $strongarm->value = 0;
  $export['lexicon_show_edit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_show_search';
  $strongarm->value = 0;
  $export['lexicon_show_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_superscript';
  $strongarm->value = 'i';
  $export['lexicon_superscript'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_suppress_unused';
  $strongarm->value = 1;
  $export['lexicon_suppress_unused'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_term_class';
  $strongarm->value = 'lexicon-term';
  $export['lexicon_term_class'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_title_48';
  $strongarm->value = 'Glossary';
  $export['lexicon_title_48'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lexicon_vids';
  $strongarm->value = array(
    48 => '48',
    22 => 0,
    3 => 0,
    30 => 0,
    29 => 0,
    23 => 0,
    34 => 0,
    33 => 0,
    4 => 0,
    13 => 0,
    5 => 0,
    14 => 0,
    15 => 0,
    47 => 0,
    6 => 0,
    32 => 0,
    1 => 0,
    44 => 0,
    35 => 0,
    39 => 0,
    38 => 0,
    19 => 0,
    28 => 0,
    12 => 0,
    8 => 0,
    20 => 0,
    21 => 0,
    40 => 0,
    42 => 0,
    11 => 0,
    31 => 0,
    27 => 0,
    9 => 0,
    46 => 0,
    37 => 0,
    41 => 0,
    36 => 0,
    43 => 0,
    45 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
  );
  $export['lexicon_vids'] = $strongarm;

  return $export;
}

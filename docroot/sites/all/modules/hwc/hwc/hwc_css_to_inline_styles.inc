<?php
use \TijsVerkoyen\CssToInlineStyles\CssToInlineStyles;

function hwc_css_to_inline_styles($content, $stylesheet_path) {
  //  $stylesheet_path = drupal_get_path('module', 'osha_newsletter') . '/includes/css/htmlmail.css';
  if (($library = libraries_load('CssToInlineStyles')) && !empty($library['loaded'])) {
    if (!$stylesheet_path) {
      $stylesheet_path = drupal_get_path('module', 'osha_newsletter') . '/includes/css/newsletter.css';
    }
    $styles = file_get_contents($stylesheet_path);
    $cssToInlineStyles = new CssToInlineStyles();
    foreach ($content as $idx => $document) {
      $content[$idx] = $cssToInlineStyles->convert($document, $styles);
    }
  }
  return $content;
}

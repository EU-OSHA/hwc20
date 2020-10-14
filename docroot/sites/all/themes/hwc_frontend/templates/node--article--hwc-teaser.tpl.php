<?php
/**
 * @file
 * Returns the HTML for an article node.
 */

if (!empty($content['field_recommended_resources'])) {
  print '<span class="recommended-resources-title">' . t('Recommended resources') . '</span>';
  print render($content['field_recommended_resources']);
}

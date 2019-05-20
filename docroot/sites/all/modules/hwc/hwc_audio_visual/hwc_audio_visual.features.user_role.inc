<?php
/**
 * @file
 * hwc_audio_visual.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hwc_audio_visual_user_default_roles() {
  $roles = array();

  // Exported role: Audio Visual.
  $roles['Audio Visual'] = array(
    'name' => 'Audio Visual',
    'weight' => 13,
  );

  return $roles;
}

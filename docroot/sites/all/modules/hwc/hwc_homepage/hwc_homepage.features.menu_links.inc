<?php
/**
 * @file
 * hwc_homepage.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hwc_homepage_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_text-resize:admin/config/user-interface/text_resize
  $menu_links['management_text-resize:admin/config/user-interface/text_resize'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/text_resize',
    'router_path' => 'admin/config/user-interface/text_resize',
    'link_title' => 'Text Resize',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for your Text Resize block.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_text-resize:admin/config/user-interface/text_resize',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'management_user-interface:admin/config/user-interface',
  );
  // Exported menu link: menu-social-links_facebook:http://www.facebook.com
  $menu_links['menu-social-links_facebook:http://www.facebook.com'] = array(
    'menu_name' => 'menu-social-links',
    'link_path' => 'http://www.facebook.com',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'alter' => TRUE,
      'content' => array(
        'image' => 'public://menuimage/fb-square-col-small.png',
      ),
      'attributes' => array(
        'title' => 'Visit us on Facebook',
        'id' => 'fb_osha_campaigns',
        'name' => 'Facebook',
        'class' => array(
          0 => 'fb_osha_campaigns',
        ),
        'style' => 'flush:right',
        'target' => '_blank',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-social-links_facebook:http://www.facebook.com',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Facebook');
  t('Text Resize');


  return $menu_links;
}

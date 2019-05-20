<?php
/**
 * @file
 * hwc_toolkit.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hwc_toolkit_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_article|title_body';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_article';
  $ds_fieldsetting->view_mode = 'title_body';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|tk_article|title_body'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_example|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_example';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|tk_example|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_example|hwc_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_example';
  $ds_fieldsetting->view_mode = 'hwc_teaser';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'See more',
        'link class' => '',
        'wrapper' => '',
        'class' => '',
        'field_formatter_class' => '',
      ),
    ),
  );
  $export['node|tk_example|hwc_teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_example|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_example';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'See more',
        'link class' => '',
        'wrapper' => '',
        'class' => '',
        'field_formatter_class' => '',
      ),
    ),
  );
  $export['node|tk_example|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_tool|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_tool';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'exclude node title settings' => '1',
        'field_formatter_class' => '',
      ),
    ),
  );
  $export['node|tk_tool|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_topic|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_topic';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
    ),
  );
  $export['node|tk_topic|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_topic|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_topic';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'exclude node title settings' => '1',
        'field_formatter_class' => '',
      ),
    ),
  );
  $export['node|tk_topic|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tk_topic|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tk_topic';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'See more',
        'link class' => '',
        'wrapper' => '',
        'class' => '',
        'field_formatter_class' => '',
      ),
    ),
  );
  $export['node|tk_topic|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hwc_toolkit_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title_field',
        1 => 'body',
        2 => 'field_tk_topics',
        3 => 'field_tk_article',
      ),
      'right' => array(
        4 => 'field_image',
      ),
    ),
    'fields' => array(
      'title_field' => 'left',
      'body' => 'left',
      'field_tk_topics' => 'left',
      'field_tk_article' => 'left',
      'field_image' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|tk_article|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_article|title_body';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_article';
  $ds_layout->view_mode = 'title_body';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_tk_article',
        3 => 'field_tk_topics',
        4 => 'field_tools_examples',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_tk_article' => 'ds_content',
      'field_tk_topics' => 'ds_content',
      'field_tools_examples' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|tk_article|title_body'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_example|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_example';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_organisation',
        2 => 'field_country',
        3 => 'body',
        4 => 'field_download_pdf',
        5 => 'field_external_link',
      ),
      'right' => array(
        6 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_organisation' => 'left',
      'field_country' => 'left',
      'body' => 'left',
      'field_download_pdf' => 'left',
      'field_external_link' => 'left',
      'field_image' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|tk_example|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_example|hwc_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_example';
  $ds_layout->view_mode = 'hwc_teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title_field',
        2 => 'body',
        3 => 'node_link',
        4 => 'field_organisation',
        5 => 'field_country',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title_field' => 'right',
      'body' => 'right',
      'node_link' => 'right',
      'field_organisation' => 'right',
      'field_country' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|tk_example|hwc_teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_example|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_example';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title_field',
        2 => 'field_organisation',
        3 => 'field_country',
        4 => 'body',
        5 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title_field' => 'right',
      'field_organisation' => 'right',
      'field_country' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|tk_example|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_section|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|tk_section|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_tool|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_tool';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_introduction',
        2 => 'field_benefits',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_introduction' => 'ds_content',
      'field_benefits' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|tk_tool|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_topic|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_topic';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title_field',
        1 => 'title',
        2 => 'body',
      ),
      'right' => array(
        3 => 'field_image',
      ),
    ),
    'fields' => array(
      'title_field' => 'left',
      'title' => 'left',
      'body' => 'left',
      'field_image' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|tk_topic|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_topic|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_topic';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right' => array(
        2 => 'field_image',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'field_image' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|tk_topic|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tk_topic|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tk_topic';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title_field',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title_field' => 'right',
      'body' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|tk_topic|teaser'] = $ds_layout;

  return $export;
}

<?php

/**
 * Field handler to show the target languages
 *
 * @ingroup views_field_handlers
 */
class tmgmt_handler_field_tmgmt_job_item_language extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  function render($values) {
    $object = $this->get_value($values);
    return tmgmt_language_label($object);
  }

}

/**
 * Field handler to show the label
 *
 * @ingroup views_field_handlers
 */
class osha_tmgmt_handler_field_tmgmt_entity_label extends tmgmt_handler_field_tmgmt_entity_label {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    if ($entity = $this->get_value($values)) {
      $label = $entity->label();
      switch ($entity->item_type) {
        case 'node':
          // Set it to empty to let the views handle the label (from revision).
          $label = '';
          break;

        case 'taxonomy_term':
          $uri = $entity->getSourceUri();
          $label = l($entity->label(), $uri['path'], $uri['options']);
          break;

        case 'menu':
          $menu_id_parts = explode(':', $entity->item_id);
          $menu_id = end($menu_id_parts);
          $path = 'admin/structure/menu/manage/' . $menu_id;
          $label = l($entity->label(), $path);
          break;

        case 'menu_link':
          $menu_id_parts = explode(':', $entity->item_id);
          $menu_id = end($menu_id_parts);
          $path = "admin/structure/menu/item/$menu_id/edit";
          $label = l($entity->label(), $path);

      }
      return $label;
    }
  }
}

/**
 * Class osha_tmgmt_handler_field_tmgmt_job_item_operations handles Operations
 */
class osha_tmgmt_handler_field_tmgmt_job_item_operations extends tmgmt_handler_field_tmgmt_job_item_operations {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $item = $this->get_value($values);
    $element = array();
    $element['#theme'] = 'links';
    $element['#attributes'] = array('class' => array('inline'));
    $uri = $item->uri();
    if ($item->getCountTranslated() > 0 && entity_access('accept', 'tmgmt_job_item', $item)) {
      $element['#links']['review'] = array(
        'href' => $uri['path'],
        'query' => array('destination' => current_path()),
        'title' => t('review'),
      );
    }
    // Do not display view on unprocessed jobs.
    elseif ($item->getJob() && !$item->getJob()->isUnprocessed() && user_access('view translation job item')) {
      $element['#links']['view'] = array(
        'href' => $uri['path'],
        'query' => array('destination' => current_path()),
        'title' => t('view'),
      );
    }
    if (user_access('administer tmgmt') && !$item->isAccepted()) {
      $element['#links']['delete'] = array(
        'href' => 'admin/tmgmt/items/' . $item->tjiid . '/delete',
        'query' => array('destination' => current_path()),
        'title' => t('delete'),
      );
    }
    if ($item->getCountTranslated() > 0 && user_access('preview layout validation') && $item->item_type == 'node') {
      $element['#links']['preview'] = array(
        'href' => sprintf('node/%s/layout-validation/%s', $item->item_id, $item->tjiid),
        'title' => t('preview layout'),
         'attributes' => array('target' => '_blank'),
      );
    }
    if ($item->state == TMGMT_JOB_ITEM_STATE_ACCEPTED
        && $item->item_type == 'menu_link'
        && user_access('preview layout validation')) {
      $item_id = str_replace('menu:item:', '', $item->item_id);
      $url = url(
        sprintf('admin/structure/menu/item/%s/translate/%s', $item_id, $item->target_language),
        array('absolute' => TRUE)
      );
      $url = $url . '?destination=admin/tmgmt/jobs/' . $item->tjid;
      $element['#links']['edit'] = array(
        'href' => $url,
        'title' => t('edit'),
      );
    }
    if ($item->state == TMGMT_JOB_ITEM_STATE_ACCEPTED
        && $item->item_type == 'default'
        && user_access('preview layout validation')) {

      $url = url(
        sprintf('admin/config/regional/translate/edit/%s/%s', $item->item_id, $item->target_language),
        array('absolute' => TRUE)
      );
      $url = $url . '?destination=admin/tmgmt/jobs/' . $item->tjid;
      $element['#links']['edit'] = array(
        'href' => $url,
        'title' => t('edit'),
      );
    }
    if ($item->state == TMGMT_JOB_ITEM_STATE_ACCEPTED
        && $item->item_type == 'taxonomy_term'
        && user_access('preview layout validation')) {

      $url = url(
        sprintf('taxonomy/term/%s/edit/%s', $item->item_id, $item->target_language),
        array('absolute' => TRUE)
      );
      $url = $url . '?destination=admin/tmgmt/jobs/' . $item->tjid;
      $element['#links']['edit'] = array(
        'href' => $url,
        'title' => t('edit'),
      );
    }
    return drupal_render($element);
  }
}

/**
 * Class osha_tmgmt_handler_field_tmgmt_job_item_operations handles Operations
 */
class osha_tmgmt_handler_field_tmgmt_job_item_state extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($job_item) {
    if (isset($job_item->tmgmt_job_item_state)) {
      return osha_tmgmt_get_job_item_state_label($job_item->tmgmt_job_item_state);
    }
    return '';
  }
}

/**
 * Class osha_tmgmt_handler_field_tmgmt_job_item_activity handles node activity
 */
class osha_tmgmt_handler_field_tmgmt_job_item_activity extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($row) {
    if ($row->tmgmt_job_item_plugin == 'entity' && $row->tmgmt_job_item_item_type == 'node') {
      $nid = $row->tmgmt_job_item_item_id;
      $node = node_load($nid);
      $node = workbench_moderation_node_current_load($node);
      module_load_include('module', 'osha');
      return osha_node_activity_name($node);
    }
    return '';
  }
}

/**
 * Class osha_tmgmt_handler_field_tmgmt_job_item_activity handles node activity
 */
class osha_tmgmt_handler_field_tmgmt_job_item_section extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($row) {
    if ($row->tmgmt_job_item_plugin == 'entity' && $row->tmgmt_job_item_item_type == 'node') {
      $nid = $row->tmgmt_job_item_item_id;
      $node = node_load($nid);
      if (!empty($node->workbench_access)) {
        module_load_include('inc', 'workbench_access', 'workbench_access.tokens');
        $sections = _workbench_access_get_node_section_names($node);
        return current($sections);
      }
    }
    return '';
  }
}

/**
 * Class osha_tmgmt_handler_field_tmgmt_job_item_activity handles node activity
 */
class osha_tmgmt_handler_field_tmgmt_job_item_type extends tmgmt_handler_field_tmgmt_job_item_type {

  /**
   * {@inheritdoc}
   */
  public function render($row) {
    $job = tmgmt_job_item_load($row->tjiid);
    switch ($job->item_type) {
      case 'node':
        return parent::render($row);

      case 'default':
        return 'String literal';
    }
    return ucfirst(str_replace('_', ' ', $job->item_type));
  }
}

/**
 * Class osha_tmgmt_handler_field_tmgmt_job_item_activity handles node activity
 */
class osha_tmgmt_handler_field_tmgmt_job_item_creator extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($row) {
    if ($row->tmgmt_job_item_plugin == 'entity' && $row->tmgmt_job_item_item_type == 'node') {
      $nid = $row->tmgmt_job_item_item_id;
      if ($node = node_load($nid)) {
        if ($creator = user_load($node->uid)) {
          return $creator->name;
        }
      }
    }
    return '';
  }
}

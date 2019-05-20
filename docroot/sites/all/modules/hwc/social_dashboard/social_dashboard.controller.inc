<?php
/**
 * @file
 * Defines the inline entity form controller for SocialDashboardStep entities.
 */

/**
 * Class DashboardItemEntityController
 *
 * Ensure Bootstrap Tours are imported and exported with tour steps.
 */
class DashboardItemEntityController extends EntityAPIControllerExportable {

  public function export($entity, $prefix = '') {
    $wrapper = entity_metadata_wrapper('dashboard_item', $entity);
    return parent::export($entity, $prefix);
  }

  public function import($data) {
    return parent::import($data);
  }

  /**
   * Add in a presave before any else to handle imported steps.
   */
  public function invoke($hook, $entity) {
    parent::invoke($hook, $entity);
  }
}

/**
 * Class SocialDashboardUIController
 *
 * Adjust the table headers when viewing the overview page.
 */
class DashboardItemUIController extends EntityDefaultUIController {
  /**
   * Overrides EntityDefaultUIController::overviewTableHeaders().
   */
  protected function overviewTableHeaders($conditions, $rows, $additional_header = array()) {
    $headers = parent::overviewTableHeaders($conditions, $rows, $additional_header);
    return $headers;
  }

  /**
   * Overrides EntityDefaultUIController::overviewTableRow().
   */
  protected function overviewTableRow($conditions, $id, $entity, $additional_cols = array()) {
    return parent::overviewTableRow($conditions, $id, $entity, $additional_cols);
  }

}

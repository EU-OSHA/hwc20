<?php

/**
 * @file
 * Contains the MigrateLanguagefieldFieldHandler class.
 */

/**
 * Migrate field handler for language fields.
 */
class MigrateLanguagefieldFieldHandler extends MigrateSimpleFieldHandler {

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    parent::__construct();
    $this->registerTypes(array('language_field'));
  }
}

<?php
/**
 * IController.php
 * Interface for controllers
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
interface IController {
    /**
     * Execute the controller
     */
    public static function getName();

    /**
     * Execute the controller
     */
    public function execute();
}
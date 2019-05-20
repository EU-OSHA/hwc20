<?php
/**
 * IForm.php
 * Interface for forms
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
interface IForm {
    /**
     * Load action
     */
    public function load();

    /**
     * Save action
     */
    public function save();

    /**
     * Send action
     */
    public function send();
}
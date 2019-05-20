<?php
/**
 * IModel.php
 * Interface for Models
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
interface IModel {
    /**
     * Filter specific attributes
     * @param $attribute
     */
    public function filter($attribute);
}
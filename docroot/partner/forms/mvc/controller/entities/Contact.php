<?php
/**
 * Contact.php
 * Controller for the Contact form
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Contact extends Controller implements IController, IForm {
    /**
     * Class constructor
     * @param bool $directOutput
     */
    public function __construct($directOutput = true) {
        $this->directOutput = $directOutput;
        $this->model = new Model($this->getEntityName());
        $params = Parameters::getInstance();
        $params->set('actionType', 'submit');
    }

    /**
     * Retrieve the class name
     * @return string
     */
    public static function getName() {
        return strtolower(__CLASS__);
    }

    /**
     * Retrieve the entity name
     * @return string
     */
    public function getEntityName() {
        $params = Parameters::getInstance();
        $entity = strtolower($params->getUrlParamValue('entity') . '_' . __CLASS__);
        return $entity;
    }
}

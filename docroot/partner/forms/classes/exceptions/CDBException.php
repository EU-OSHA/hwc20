<?php
/**
 * Class CDBException
 * @author Juan Jose Arol Rosa <Juan.Jose.Arol.Rosa@everis.com>
 * @version 1.0
 */
class CDBException extends Exception {
    public function __construct($errorMessage, $errorCode) {
        $code = empty($errorCode) ? -1 : $errorCode;
        $lang = Lang::getInstance();
        if (empty($errorMessage)) {
            $message = $lang->get('error_contacting_cdb') ?
                $lang->get('error_contacting_cdb') : 'Error contacting the CDB';
        } else {
            $message = $lang->get($errorMessage) ?
                $lang->get($errorMessage) : $errorMessage;
        }
        parent::__construct($message, $code);
    }
}
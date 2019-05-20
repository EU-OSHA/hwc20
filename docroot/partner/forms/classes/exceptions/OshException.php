<?php
/**
 * Class OshException
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class OshException extends Exception {
    public function __construct($errorMessage, $errorCode) {
        $code = empty($errorCode) ? -1 : $errorCode;
        $lang = Lang::getInstance();
        if (empty($errorMessage)) {
            $message = $lang->get('undefined_error') ? $lang->get('undefined_error') : 'Undefined error';
        } else {
            $message = $lang->get($errorMessage) ? $lang->get($errorMessage) : $errorMessage;
        }
        parent::__construct($message, $code);
    }
}
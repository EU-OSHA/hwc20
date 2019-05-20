<?php
/**
 * Lang.php
 * Language class
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
final class Lang {
    /**
     * @var Array of messages
     */
    private $messages;

    /**
     * Private class constructor so nobody else can instance it
     */
    private function __construct() {}

    /**
     * Private class clone so nobody else can clone it
     */
    private function __clone() {}

    /**
     * Retrieve the persistent instance
     * @return \Lang
     */
    public static function getInstance() {
        static $inst = null;
        if ($inst === null) {
            $class = __CLASS__;
            $inst = new $class();
            // Load the configuration
            $params = Parameters::getInstance();
            $langPath = $params->get('langPath');
            $lang = $params->get('lang');
            if ($langFile = file_get_contents(APP_ROOT . $langPath . $lang)) {
                $parsedContent = json_decode($langFile, true);
                if (isset($parsedContent['messages'])) {
                    $inst->messages = $parsedContent['messages'];
                }
            }
        }
        return $inst;
    }

    /**
     * Retrieve a message
     * @param $name
     * @return string
     */
    public function get($name) {
        $ret = isset($this->messages[$name]) ? $this->messages[$name] : '';
        return $ret;
    }
}
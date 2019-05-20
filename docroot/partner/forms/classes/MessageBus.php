<?php
/**
 * MessageBus.php
 * Message bus to store all the messages of an execution
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class MessageBus {
    /**
     * Messages array
     * @var array
     */
    private $messages;

    /**
     * Private class constructor so nobody else can instance it
     *
     */
    private function __construct() {}

    /**
     * Private class clone so nobody else can clone it
     *
     */
    private function __clone() {}

    /**
     * Retrieve the persistent instance
     * @return \MessageBus
     */
    public static function getInstance() {
        static $inst = null;
        if ($inst === null) {
            $class = __CLASS__;
            $inst = new $class();
        }
        return $inst;
    }

    /**
     * Add a message to the bus
     * @param $id
     * @param $message
     */
    public function put($id, $message) {
        $this->messages[$id] = $message;
    }

    /**
     * Retrieve a single message
     * @param $id
     * @return mixed
     */
    public function getMessage($id) {
        return $this->messages[$id];
    }

    /**
     * Retrieve the bus content
     * @return array
     */
    public function getMessages() {
        return $this->messages;
    }
}
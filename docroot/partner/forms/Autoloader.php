<?php
/**
 * Simple Recursive Autoloader
 *
 * A simple autoloader that loads class files recursively starting in the directory
 * where this class resides.  Additional options can be provided to control the naming
 * convention of the class files.
 *
 * @package Autoloader
 * @license http://opensource.org/licenses/MIT  MIT License
 * @author  Rob Dunham <contact@robunham.info>
 */
class Autoloader {
    /**
     * File extension as a string. Defaults to ".php".
     */
    protected static $fileExt = '.php';

    /**
     * The top level directory where recursion will begin. Defaults to the current
     * directory.
     */
    protected static $pathTop = __DIR__;

    /**
     * A placeholder to hold the file iterator so that directory traversal is only
     * performed once.
     */
    protected static $fileIterator = null;

    /**
     * Autoload function for registration with spl_autoload_register
     *
     * Looks recursively through project directory and loads class files based on
     * filename match.
     *
     * @param string $className
     */
    public static function loader($className) {
        // Look for the class in the registered paths
        $className .= '.php';
        if (is_readable(APP_ROOT . 'classes/' . $className)) {
            require_once(APP_ROOT . 'classes/' . $className);
        } else if (is_readable(APP_ROOT . 'classes/exceptions/' . $className)) {
            require_once(APP_ROOT . 'classes/exceptions/' . $className);
        } else if (is_readable(APP_ROOT . 'mvc/controller/' . $className)) {
            require_once(APP_ROOT . 'mvc/controller/' . $className);
        } else if (is_readable(APP_ROOT . 'mvc/controller/entities/' . $className)) {
            require_once(APP_ROOT . 'mvc/controller/entities/' . $className);
        } else if (is_readable(APP_ROOT . 'mvc/model/' . $className)) {
            require_once(APP_ROOT . 'mvc/model/' . $className);
        } else if (is_readable(APP_ROOT . 'mvc/view/' . $className)) {
            require_once(APP_ROOT . 'mvc/view/' . $className);
        }
        /*
        $directory = new RecursiveDirectoryIterator(static::$pathTop, RecursiveDirectoryIterator::SKIP_DOTS);
        static::$fileIterator = new RecursiveIteratorIterator($directory);
        static::$fileIterator = new RegexIterator(static::$fileIterator, '/^.+\.php$/i', RecursiveRegexIterator::GET_MATCH);
        $filename = $className . static::$fileExt;
        foreach (static::$fileIterator as $file) {
            $file = implode($file);
            if (strtolower(pathinfo($file, PATHINFO_BASENAME)) === strtolower($filename) && strpos($file, '/lib/') === false) {
                if (is_readable($file)) {
                    require_once($file);
                }
                break;
            }
        }
        */
    }

    /**
     * Sets the $fileExt property
     *
     * @param string $fileExt The file extension used for class files.  Default is "php".
     */
    public static function setFileExt($fileExt) {
        static::$fileExt = $fileExt;
    }

    /**
     * Sets the $path property
     *
     * @param string $path The path representing the top level where recursion should
     *                     begin. Defaults to the current directory.
     */
    public static function setPath($path) {
        static::$pathTop = $path;
    }
}
Autoloader::setFileExt('.php');
spl_autoload_register('Autoloader::loader');
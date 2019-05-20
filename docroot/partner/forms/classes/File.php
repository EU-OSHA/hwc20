<?php
/**
 * File.php
 * File helper
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class File {
    /**
     * Check if a file exists
     *
     * @param $filename
     * @return bool
     */
    public static function exists($filename) {
        return file_exists($filename);
    }

    /**
     * Read a file
     *
     * @param $filename
     * @return bool|string
     */
    public static function read($filename) {
        $ret = false;
        if (file_exists($filename)) {
            if (($fp = fopen($filename, 'r')) !== false) {
                $ret = fread($fp, filesize($filename));
            }
        }
        return $ret;
    }

    /**
     * Write a file
     *
     * @param $filename
     * @param $content
     * @return bool|int
     */
    public static function write($filename, $content) {
        $ret = false;
        if (!file_exists($filename)) {
            touch($filename);
        }
        if (chmod($filename, 0760)) {
            if (($fp = fopen($filename, 'w')) !== false) {
                $ret = fwrite($fp, $content);
            }
        }
        return $ret;
    }

    /**
     * Append content to a file
     *
     * @param $filename
     * @param $content
     * @return bool|int
     */
    public static function append($filename, $content) {
        $ret = false;
        if (!file_exists($filename)) {
            touch($filename);
        }
        if (chmod($filename, 0770)) {
            if (($fp = fopen($filename, 'a')) !== false) {
                $ret = fwrite($fp, $content);
            }
        }
        return $ret;
    }

    /**
     * Delete a file
     *
     * @param $filename
     * @return bool
     */
    public static function delete($filename) {
        return unlink($filename);
    }

    /**
     * Clear a folder
     * @param $path
     */
    public static function clearFolder($path) {
        array_map('unlink', glob($path));
    }

    /**
     * Browse a directory and return the content
     *
     * @param string $path
     * @param string $ext
     * @param string $prefix
     * @return array
     */
    public static function browseDirectory($path, $ext = '', $prefix = '') {
        $directory = new RecursiveDirectoryIterator($path);
        $iterator = new RecursiveIteratorIterator($directory);
        $resourceFiles = new RegexIterator($iterator, '/^.+' . $ext . '$/i');
        $resources = array();
        foreach($resourceFiles as $file) {
            $file = $file->getFilename();
            if ($file != '.' && $file != '..') {
                $resources[] = $prefix . $file;
            }
        }
        return $resources;
    }

    /**
     * Download a file
     * @param $filename
     * @param $path
     * @param $mime
     */
    public static function download($filename, $path, $mime) {
        header("Content-disposition: attachment; filename=" . $filename . ".pdf");
        header("Content-type: " . $mime);
        readfile($path);
    }
}
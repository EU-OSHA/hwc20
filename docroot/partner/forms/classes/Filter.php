<?php
/**
 * Filter.php
 * Filter helper
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Filter {
    /**
     * Sanitize HTML content
     * @param $content
     * @return string
     */
    public static function sanitizeHtml($content) {
        $config = HTMLPurifier_Config::createDefault();
        $config->set('Core.Encoding', 'UTF-8');
        $config->set('HTML.Doctype', 'HTML 4.01 Transitional');
        $config->set('CSS.AllowTricky', true);
       // $config->set('HTML.Allowed', 'div,p,a[href],strong,em,label,img[src|alt|title],fieldset,form[action|method],input');
        $config->set('HTML.Trusted', true);
        $sanitiser = new HTMLPurifier($config);
        return $sanitiser->purify($content);
    }
}
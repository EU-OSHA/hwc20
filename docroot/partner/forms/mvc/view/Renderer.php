<?php
/**
 * Render a view
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Renderer {
    private $basePath;
    private $baseUrl;
    private $cssPath;
    private $cssUrl;
    private $htmlHeaderTpl;
    private $htmlFooterTpl;
    private $cachePath;
    private $headerTpl;
    private $footerTpl;
    private $bodyTpl;
    private $includeHeaderFooter;
    private $htmlPath;
    private $tempPath;

    /**
     * Class constructor
     * @param $view
     * @param bool|true $includeHeaderFooter
     */
    public function __construct($view, $includeHeaderFooter = true) {
        $params = Parameters::getInstance();
        $this->basePath = APP_ROOT . $params->get('viewPath');
        $this->baseUrl = APP_URL . $params->get('viewPath');
        $this->cssPath = APP_ROOT . $params->get('cssPath');
        $this->cssUrl = APP_URL . $params->get('cssPath');
        $this->jsPath = APP_ROOT . $params->get('jsPath');
        $this->jsUrl = APP_URL . $params->get('jsPath');
        $this->htmlHeaderTpl = $params->get('htmlHeaderTpl');
        $this->htmlFooterTpl = $params->get('htmlFooterTpl');
        $this->cachePath = $params->get('cachePath');
        $this->headerTpl = $params->get('headerTpl');
        $this->footerTpl = $params->get('footerTpl');
        $this->bodyTpl = strtolower($view . '.html');
        $this->htmlPath = $params->get('htmlPath');
        $this->tempPath = $params->get('tempPath');
        $this->includeHeaderFooter = $includeHeaderFooter;
    }

    /**
     * Set the view path
     * @param $viewPath
     */
    public function setViewPath($viewPath) {
        $this->basePath = APP_ROOT . $viewPath;
        $this->baseUrl = APP_URL . $viewPath;
    }

    /**
     * Set the current view
     * @param $view
     */
    public function setView($view) {
        $this->bodyTpl = strtolower($view . '.html');
    }

    /**
     * Set the include header/footer mode
     * @param $includeHeaderFooter
     */
    public function setIncludeHeaderFooter($includeHeaderFooter) {
        $this->includeHeaderFooter = $includeHeaderFooter;
    }

    /**
     * Generate the header/footer
     * @param $dwoo
     * @param $tpl
     * @param $contentArray
     * @return mixed
     */
    private function renderPart($dwoo, $tpl, $contentArray) {
        return $dwoo->get($this->basePath . $tpl, $contentArray);
    }

    /**
     * Insert the default header
     * @param $dwoo
     * @param $printable
     * @return mixed
     */
    private function renderHtmlHeader($dwoo, $printable = false) {
        $params = Parameters::getInstance();
        $content = array(
            'js' => File::browseDirectory($this->jsPath, '.js', $this->jsUrl),
            'css' => File::browseDirectory($this->cssPath, '.css', $this->cssUrl),
            'nonce' => $params->get('nonce'),
            'printable' => $printable,
        );
//        if (!$printable) {
            $value = $this->cssUrl . 'print.css';
            if(($key = array_search($value, $content['css'])) !== false) {
                unset($content['css'][$key]);
            }
//        }
        return $dwoo->get($this->basePath . $this->htmlHeaderTpl, $content);
    }

    /**
     * Insert the default footer
     * @param $dwoo
     * @return mixed
     */
    private function renderHtmlFooter($dwoo) {
        return $dwoo->get($this->basePath . $this->htmlFooterTpl);
    }

    /**
     * String encoding
     * @param $string
     * @return array|string
     */
    private function utf8Encode($string)
    {
        if (is_array($string)) {
            foreach ($string as $key => &$value) {
                $value = $this->utf8Encode($value);
            }
            $ret = $string;
        } elseif (is_a($string, 'stdClass')) {
            $ret = $this->utf8Encode(get_object_vars($string));
        } else {
            $ret = utf8_encode($string);
        }

        return $ret;
    }

    /**
     * Render the content
     * @param null $contentArray
     * @return string
     */
    public function render($contentArray = null) {
        // Clear the output folder
        File::clearFolder($this->tempPath . '*.pdf');
        File::clearFolder($this->tempPath . '*.html');
        // Register Dwoo namespace and register autoloader
        $dwoo = new Dwoo();
        if (isset($contentArray)) {
            if (is_array($contentArray)) {
                foreach ($contentArray as $key => &$value) {
                    if (!is_array($value) && !mb_detect_encoding($value, 'UTF-8')) {
                        $value = $this->utf8Encode($value);
                    }
                }
            } else {
                if (!mb_detect_encoding($contentArray, 'UTF-8')) {
                    $contentArray = $this->utf8Encode($contentArray);
               }
            }

            $content = $dwoo->get($this->basePath . $this->bodyTpl, $contentArray);
            $content = str_ireplace('&nbsp;on', ' YES', $content);

            $content = preg_replace("/Telephone prefix:<\/strong><\/div>\s+<div><strong><\/strong>/", "Telephone prefix:</strong>", $content);

        }
        if ($this->includeHeaderFooter) {
            $this->setViewPath($this->htmlPath);
            $printable = (isset($contentArray['printable']) && $contentArray['printable']) || (isset($contentArray['pdf']) && $contentArray['pdf']) ? true : false;

            if ($printable) {
                $content = str_ireplace("</strong>&nbsp;1</div>", "</strong> YES</div>", $content);
                $content = str_ireplace("</strong>&nbsp;true</div>", "</strong> YES</div>", $content);
            }
            $htmlHeader = $this->renderHtmlHeader($dwoo, $printable);
            $htmlFooter = $this->renderHtmlFooter($dwoo);
            $header = $this->renderPart($dwoo, $this->headerTpl, $contentArray);
            $footer = $this->renderPart($dwoo, $this->footerTpl, $contentArray);
        } else {
            $htmlHeader = $htmlFooter = $header = $footer = '';
        }
        $content = $htmlHeader . $header. $content . $footer . $htmlFooter;
        return $content;
    }
}
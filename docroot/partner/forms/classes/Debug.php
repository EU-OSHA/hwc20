<?php

/**
 * Class Debug
 *
 * @author     Joaquin Rua Conde     <joaquin.rua.conde@everis.com>
 * @copyright  2015 Everis
 * @version    1.0
 */
class Debug
{
    /** @var bool $error */
    public static $error = false;
    /** @var string $fontSizeContent */
    public static $fontSizeContent;
    /** @var string $fontSizeHead */
    public static $fontSizeHead;
    /** @var string $border */
    public static $border;
    /** @var string $background */
    public static $background;
    /** @var string $color */
    public static $color;

    public function __construct()
    {
    }

    /**
     * Function dump
     *
     * @param            $data
     * @param bool|false $die
     */
    public static function dump($variable, $caption = 'Debug', $die = false, $dump_type = 'var_dump', $error = false)
    {
        static::$error = $error;
        if (static::$error === false) {
            static::$fontSizeContent = '12px';
            static::$fontSizeHead    = '18px';
            static::$border          = '1px solid #A9B7C6';
            static::$background      = '#EFEFAF';
            static::$color           = '#2B2B2B';
        } elseif (in_array(static::$error, array(E_NOTICE, E_USER_NOTICE, E_DEPRECATED, E_USER_DEPRECATED))) {
            static::$fontSizeContent = '14px';
            static::$fontSizeHead    = '20px';
            static::$border          = '1px solid #53DCCD';
            static::$background      = '#FFAA00';
            static::$color           = '#2B2B2B';
        } elseif (in_array(static::$error, array(E_WARNING, E_USER_WARNING))) {
            static::$fontSizeContent = '16px';
            static::$fontSizeHead    = '22px';
            static::$border          = '1px solid #53DCCD';
            static::$background      = '#B27700';
            static::$color           = '#2B2B2B';
        } else {
            static::$fontSizeContent = '18px';
            static::$fontSizeHead    = '26px';
            static::$border          = '1px solid #53DCCD';
            static::$background      = '#FF5500';
            static::$color           = '#2B2B2B';
        }
        // start the output buffering
        ob_start();
        // generate the output
        $dump_type($variable);
        // get the output
        $output = ob_get_clean();
        // format the label
        $label_text = $caption;
        $caption    = ($caption === null) ? '' : '<h2 style="margin: 0">' . trim($caption) . '</h2>';
        // neaten the newlines and indents
        $output = preg_replace("/\]\=\>\n(\s+)/m", "] => ", $output);

        $header = '';
        if (! empty($caption)) {
            $header = '<h2 style="' . self::_getHeaderCss() . '">' . $label_text . '</h2>';
        }
        print '<pre style="' . self::_getContainerCss() . '">' . $header . $output . '</pre>';
        //print $output;
        ($die === true) ? die() : null;
    }

    private static function _getHeaderCss()
    {
        return self::_arrayToCss(
            array(
                'border-bottom' => static::$border,
                'font-size'     => static::$fontSizeHead,
                'font-family'   => 'Consolas, Courier, monospace',
                'font-weight'   => 'bold',
                'margin'        => '0 0 10px 0',
                'padding'       => '3px 0 10px 0',
                'color'         => static::$color
            )
        );
    }

    /**
     * Convert a key/value pair array into a CSS string
     *
     * @param array $rules List of rules to process
     *
     * @return string
     */
    private static function _arrayToCss(array $rules)
    {
        $strings = array();
        foreach ($rules as $key => $value) {
            $strings[] = $key . ': ' . $value;
        }

        return join('; ', $strings);
    }

    /**
     * Get the CSS string for the output container
     *
     * @return string
     */
    private static function _getContainerCss()
    {
        return self::_arrayToCss(
            array(
                'background-color'      => static::$background,
                'border'                => static::$border,
                'border-radius'         => '10px',
                '-moz-border-radius'    => '10px',
                '-webkit-border-radius' => '10px',
                'font-size'             => static::$fontSizeContent,
                'font-family'           => 'Consolas, Courier, monospace',
                'line-height'           => '1.4em',
                'margin'                => '30px',
                'padding'               => '7px',
                'color'                 => static::$color,
                'opacity'               => 0.85
            )
        );
    }

}
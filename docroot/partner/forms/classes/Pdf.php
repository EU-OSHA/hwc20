<?php
/**
 * Pdf.php
 * Convert HTML content into PDF
 * @author Eduardo Martos (eduardo.martos.gomez@everis.com)
 */
class Pdf {
    /**
     * Save the content into PDF
     *
     * @param $content
     * @return bool|mixed
     */
    public static function render($content) {
        $ret = false;
        $params = Parameters::getInstance();
        $outputFileName = date('d-m-Y_H-i');
        $tempFile = APP_ROOT . $params->get('tempPath') . $outputFileName . '.html';
        if (File::write($tempFile, $content)) {
            $outputFile = APP_ROOT . $params->get('tempPath') . $outputFileName . '.pdf';
            $pdfcommand = $params->get('pdfcommand');
            $exec = $pdfcommand . ' "' . $tempFile . '" "' . $outputFile . '"';
            exec($exec, $output, $ret);
            File::delete($tempFile);
            $ret = File::exists($outputFile) ? $outputFile : false;
        }
        return $ret;
    }
}
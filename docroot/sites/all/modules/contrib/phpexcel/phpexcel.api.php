<?php

/**
 * @file
 * Module API documentation.
 */

/**
 * @defgroup phpexcel_api PHPExcel API
 * @{
 * PHPExcel (the library) is a powerful PHP library to export and import data
 * to and from Excel file. It is very flexible, and well built. The PHPExcel
 * Drupal module, on the other hand, provides a "wrapper", a simpler API that
 * behaves in a "Drupal" way. This module simplifies the export or import of
 * data, abstracting much of the complexity, at the cost of flexibility.
 *
 * The idea is to provide an API very similar to Drupal's theme_table()
 * function.
 *
 * Using the module's functions requires the phpexcel.inc file to be loaded:
 * @code
 * module_load_include('inc', 'phpexcel');
 * @endcode
 *
 * Exporting data is done via phpexcel_export().
 * @code
 * phpexcel_export(array('Header 1', 'Header 2'), array(
 *   array('A1', 'B1'),
 *   array('A2', 'B2'),
 * ), 'path/to/file.xls');
 * @endcode
 *
 * It is also possible to pass an array of options to the export function:
 * @code
 * phpexcel_export(array('Header 1', 'Header 2'), array(
 *   array('A1', 'B1'),
 *   array('A2', 'B2'),
 * ), 'path/to/file.xls', array('description' => "Some description"));
 * @endcode
 *
 * Look at phpexcel_export() for more information on the parameters and their
 * possible values.
 *
 * @todo Document return values
 * @todo Document import
 * @}
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Implements hook_phpexcel_export().
 *
 * @see phpexcel_export()
 *
 * @param string $op
 *    The current operation. Can either be "headers", "new sheet", "data",
 *    "pre cell" or "post cell".
 * @param array|string &$data
 *    The data. Depends on the value of $op:
 *    - "headers": The $data parameter will contain the headers in array form.
 *      The headers have not been added to the document yet and can be altered
 *      at this point.
 *    - "new sheet": The $data parameter will contain the sheet ID. This is a
 *      new sheet and can be altered, if required, using the $phpexcel
 *      parameter.
 *    - "data": The $data parameter contains all the data to be exported as a
 *      3-dimensional array. The data has not been exported yet and can be
 *      altered at this point.
 *    - "pre cell": The $data parameter contains the call value to be rendered.
 *      The value has not been added yet and can still be altered.
 *    - "post cell": The $data parameter contains the call value that was
 *      rendered. This value cannot be altered anymore.
 * @param PHPExcel|PHPExcel_Worksheet $phpexcel
 *    The current object used. Can either be a PHPExcel object when working
 *    with the excel file in general or a PHPExcel_Worksheet object when
 *    iterating through the worksheets. Depends on the value of $op:
 *    - "headers" or "data": The $phpexcel parameter will contain the PHPExcel
 *      object.
 *    - "new sheet", "pre cell" or "post cell": The $phpexcel parameter will
 *      contain the PHPExcel_Worksheet object.
 * @param array $options
 *    The $options array passed to the phpexcel_export() function.
 * @param int $column
 *    The column number. Only available when $op is "pre cell" or "post cell".
 * @param int $row
 *    The row number. Only available when $op is "pre cell" or "post cell".
 *
 * @ingroup phpexcel_api
 */
function hook_phpexcel_export($op, &$data, $phpexcel, $options, $column = NULL, $row = NULL) {
  switch ($op) {
    case 'headers':

      break;

    case 'new sheet':

      break;

    case 'data':

      break;

    case 'pre cell':

      break;

    case 'post cell':

      break;
  }
}

/**
 * Implements hook_phpexcel_import().
 *
 * @see phpexcel_import()
 *
 * @param string $op
 *    The current operation. Either "full", "sheet", "row", "pre cell" or
 *    "post cell".
 * @param mixed &$data
 *    The data. Depends on the value of $op:
 *    - "full": The $data parameter will contain the fully loaded Excel file,
 *      returned by the PHPExcel_Reader object.
 *    - "sheet": The $data parameter will contain the current
 *      PHPExcel_Worksheet.
 *    - "row": The $data parameter will contain the current PHPExcel_Row.
 *    - "pre cell": The $data parameter will contain the current cell value. The
 *      value has not been added to the data array and can still be altered.
 *    - "post cell": The $data parameter will contain the current cell value.
 *      The value cannot be altered anymore.
 * @param PHPExcel_Reader|PHPExcel_Worksheet|PHPExcel_Cell $phpexcel
 *    The current object used. Can either be a PHPExcel_Reader object when
 *    loading the Excel file, a PHPExcel_Worksheet object when iterating
 *    through the worksheets or a PHPExcel_Cell object when reading data
 *    from a cell. Depends on the value of $op:
 *    - "full", "sheet" or "row": The $phpexcel parameter will contain the
 *      PHPExcel_Reader object.
 *    - "pre cell" or "post cell": The $phpexcel parameter will contain the
 *      PHPExcel_Cell object.
 * @param array $options
 *    The arguments passed to phpexcel_import(), keyed by their name.
 * @param int $column
 *    The column number. Only available when $op is "pre cell" or "post cell".
 * @param int $row
 *    The row number. Only available when $op is "pre cell" or "post cell".
 *
 * @ingroup phpexcel_api
 */
function hook_phpexcel_import($op, &$data, $phpexcel, $options, $column = NULL, $row = NULL) {
  switch ($op) {
    case 'full':

      break;

    case 'sheet':

      break;

    case 'row':

      break;

    case 'pre cell':

      break;

    case 'post cell':

      break;
  }
}

/**
 * @} End of "addtogroup hooks".
 */

<?php

/**
 * Class CDB
 * @author  Juan Jose Arol Rosa <Juan.Jose.Arol.Rosa@everis.com>
 * @author  Eduardo Martos (eduardo.martos.gomez@everis.com)
 * @version 2.0
 */
final class CDB
{
    /** @var CDB Host */
    private $host;
    /** @var CDB port */
    private $port;
    /** @var string CDB resource string */
    private $resource;
    /** @var boolean Debug mode */
    private $debug;
    /** @var array Mapped fields */
    private $fields;
    /** @var array Mapped dropDowns */
    private $dropdowns;
    /** @var string Session ID */
    private $sessionID;
    /** @var array CDB map */
    private $cdbMap;
   
    /** Private class constructor so nobody else can instance it */
    private function __construct()
    {
    }

    /** Private class clone so nobody else can clone it */
    private function __clone()
    {
    }

    /**
     * Retrieve the persistent instance
     *
     * @param  array $cdbMap
     * @param string $sessionId
     *
     * @return $thi
     */
    public static function getInstance($cdbMap, $sessionId = '', $loadFromCDB = false)
    {   
        
////file_put_contents("/tmp/curl.log", "1".PHP_EOL, FILE_APPEND | LOCK_EX);
        static $inst = null;
        if ($inst === null) {
            $class = __CLASS__;
            $inst  = new $class();
        }
        $inst->cdbMap = $cdbMap;
        $inst->initialize();

        if ($sessionId) {

            $inst->initializeSession($sessionId);
        }
        // Load the data of the dropDowns
        if ($inst->cdbMap) {
            if(($loadFromCDB)||((!isset($inst->dropdowns['company_osh_orgtype']) || !$inst->dropdowns['company_osh_orgtype']['values']) && (!isset($inst->dropdowns['company_osh_bussinessector']) || !$inst->dropdowns['company_osh_bussinessector']['values'])
                    && (!isset($inst->dropdowns['company_osh_osh_appform_osh_country']) || !$inst->dropdowns['company_osh_osh_appform_osh_country']['values']) && (!isset($inst->dropdowns['company_osh_country']) || !$inst->dropdowns['company_osh_country']['values'])
                    && (!isset($inst->dropdowns['comrep_osh_prefixmediaprphone']) || !$inst->dropdowns['comrep_osh_prefixmediaprphone']['values']))){
                $inst->loadDropdownsData();
            }
        }

        return $inst;
    }

    /** Initialize the instance */
    private function initialize()
    {
//file_put_contents("/tmp/curl.log", "2".PHP_EOL, FILE_APPEND | LOCK_EX);
        $params = Parameters::getInstance();
        $cdb    = $params->get('cdb');
        if ($cdb['debug'] == 'true') {
            $this->host     = APP_ROOT;
            $this->resource = $cdb['debug_folder'];
            $this->debug    = true;
        } else {
            $this->host     = $cdb['host'];
            $this->port     = $cdb['port'];
            $this->resource = $cdb['resource'];
        }
    }

    private function initializeSession($sessionId)
    {
//file_put_contents("/tmp/curl.log", "3".PHP_EOL, FILE_APPEND | LOCK_EX);
        $this->sessionID = $sessionId;
        // Set the context
        $this->setContext();

        if ($this->cdbMap) {
             // Load the fields
            $this->getSessionData();
        }

    }

    /**
     * Retrieve the value of a regular field
     *
     * @param $key
     *
     * @return string|null
     */
    public function get($key)
    {
//file_put_contents("/tmp/curl.log", "4".PHP_EOL, FILE_APPEND | LOCK_EX);
        $value = (! empty($key) && isset($this->fields[$key])) ? $this->fields[$key] : null;

        return $value;
    }

    /**
     * Retrieve the value of a dropDown field
     *
     * @param $key
     *
     * @return null
     */
    public function getDropdown($key)
    {
//file_put_contents("/tmp/curl.log", "5".PHP_EOL, FILE_APPEND | LOCK_EX);
        $value = (! empty($key) && isset($this->dropdowns[$key])) ? $this->dropdowns[$key] : null;

        return $value;
    }

    /**
     * Retrieve the value of a image field
     *
     * @param $key
     *
     * @return array|bool
     */
    public function getImage($key)
    {
   
//file_put_contents("/tmp/curl.log", "6".PHP_EOL, FILE_APPEND | LOCK_EX);
        $ret  = false;
        $data = (! empty($key) && isset($this->fields[$key])) ? $this->fields[$key] : null;
        if ($data) {
            $imgData = base64_decode($data);
            if (function_exists('finfo_open')) {
                $f        = finfo_open();
                $mimeType = finfo_buffer($f, $imgData, FILEINFO_MIME_TYPE);
            } else {
                $mimeType = 'application/octet-stream';
            }
            $ret = array(
                'mime'    => $mimeType,
                'content' => $data,
            );
        }

        return $ret;
    }

    /**
     * Set the value of a field
     *
     * @param $key
     * @param $value
     */
    public function set($key, $value)
    {
//file_put_contents("/tmp/curl.log", "7".PHP_EOL, FILE_APPEND | LOCK_EX);
        if (isset($this->fields[$key])) {
            $this->fields[$key] = $value;
        }
    }

    /**
     * Retrieve data of a session
     *
     * @throws \CDBException
     */
    private function getSessionData()
    {
//file_put_contents("/tmp/curl.log", "8".PHP_EOL, FILE_APPEND | LOCK_EX);

        $readMethod   = $this->getMethod('read', 'read_mf');
        $url          = $this->buildUrl($readMethod);
        $responseData = $this->getData($url);
        $response     = $responseData[$readMethod['response']];
        $countries    = $responseData['returnPaises'];
        
        $params = Parameters::getInstance();



//file_put_contents("/tmp/curl.log", "8.0 ".implode(",",$responseData).PHP_EOL, FILE_APPEND | LOCK_EX);
        if(isset($responseData['returnContacts'])){
            $response2    = $responseData['returnContacts'];
        
        }
        if(isset($response)){
		if (!is_array($response))
		{
                	$response = json_decode($response, true);
//file_put_contents("/tmp/curl.log", "8.0.0: ".$params->getUrlParamValue('maintenance_mode').PHP_EOL, FILE_APPEND | LOCK_EX);
			if ($params->getUrlParamValue('maintenance_mode'))
			{
				$arrayToMerge = array();
				foreach($response as $keyPar=> $valuePar)
				{
					$arrayToMerge = array_merge($arrayToMerge, $valuePar);
//file_put_contents("/tmp/curl.log", "8.0.1: ".$keyPar.", ".$valuePar.PHP_EOL, FILE_APPEND | LOCK_EX);
				}
				$response = array();
				$response[0] = $arrayToMerge;
			}
		}
        }
        if(isset($response2)){
             if(! is_array($response2)) {
                $response2 = json_decode($response2, true);
            }
        }
        if(isset($countries)){
            if (! is_array($countries)) {
                $countries = json_decode($countries, true);
            }
        }
        //Reseteamos la variable del main contact change check
        unset($_SESSION['mainContactChangeCheck']);
        unset($_SESSION['basicRequirements']);

        // Filter the response to clean the prefixes
        foreach ($response as $key => $value) {
////file_put_contents("/tmp/curl.log", "8.1: ".$key.", ".$value.PHP_EOL, FILE_APPEND | LOCK_EX);
//foreach($value as $keyPar=> $valuePar)
//{
//	//file_put_contents("/tmp/curl.log", "8.1.1: ".$keyPar.", ".$valuePar.PHP_EOL, FILE_APPEND | LOCK_EX);
//}
            if (strpos($key, '.') !== false) {
                $key = explode('.', $key)[1];
                if($key == "osh_campaignpledge" && $value['Value'] != ""){
                    $this->savePledgeData($value['Value']);
                }else if($key == "osh_quoteonhwc" && $value['Value'] != ""){
                    $this->saveQuoteData($value['Value']);
                }
            }
            $responseFixed[$key] = $value;
//file_put_contents("/tmp/curl.log", "8.2: ".$responseFixed[$key].PHP_EOL, FILE_APPEND | LOCK_EX);
foreach($responseFixed as $keyPar=> $valuePar)
{
	//file_put_contents("/tmp/curl.log", "8.2.1: ".$keyPar.", ".$valuePar.PHP_EOL, FILE_APPEND | LOCK_EX);
}
foreach($responseFixed[$key] as $keyPar => $valuePar)
{
	//file_put_contents("/tmp/curl.log", "8.2.2: ".$keyPar.", ".$valuePar.PHP_EOL, FILE_APPEND | LOCK_EX);
	if(isset($responseFixed[$key]['Fields']))
	{
		foreach($responseFixed[$key]['Fields'] as $keyPar2=> $valuePar2)
		{
			//file_put_contents("/tmp/curl.log", "8.2.2.1: ".$keyPar2.", ".$valuePar2.PHP_EOL, FILE_APPEND | LOCK_EX);
		}
	}
}
        }

//        $params = Parameters::getInstance();
//file_put_contents("/tmp/curl.log", "8.5".$params.PHP_EOL, FILE_APPEND | LOCK_EX);
        if ($params->getUrlParamValue('maintenance_mode')) {
            $_SESSION['partner_nid'] = $params->get("partner_nid");
            $_SESSION['language'] = $params->get("language");
            $this->getSessionDataMF($response, $countries, $response2);
        } else {
            $this->getSessionDataAppForm($response, $countries);
        }
    }

    /**
     * Function getSessionDataAppForm
     *
     * @param $response
     * @param $countries
     */
    private function getSessionDataAppForm($response, $countries)
    {
//file_put_contents("/tmp/curl.log", "9".PHP_EOL, FILE_APPEND | LOCK_EX);
        $params      = Parameters::getInstance();
        $partnerType = $params->get('osh_category');
        $formType    = $params->get('osh_leads');
        $statusCode  = $params->get('statuscode');
        $sent        = intval($params->get('cdb')['sent']);

        $response['returnPaises'] = $countries;

        //(CRG - #154 - Antes si era un category MP, new y invitation sent, se mostraba el resultado de los campos, sino no... ahora se pide que �stos filtros tambien se hagan para los OCP y FOP)
//        if (! (($partnerType === 'mp' || $partnerType === 'ocp' || $partnerType === 'pcp') && $formType === 'new' && $statusCode === $sent))
//        {
        if (!
                (//Si es MP u OCP, el osh_leads est� informado como new y est� sent
                    ($partnerType === 'mp' || $partnerType === 'ocp')
                    && $formType === 'new' && $statusCode === $sent
                )
                ||
                ($partnerType === 'pcp' && $statusCode === $sent)//Si es PCP y est� sent
            )
        {
        //Informamos los campos,sino no
        //        if (!$partnerType === 'mp' && $formType === 'new' && $statusCode === $sent)) {
        //(/CRG - #154)

            if(isset($response['osh_mainemail']) && $response['osh_mainemail'] != ""){
                $response['contact_osh_mainemailAux'] = $response['osh_mainemail'];
            }
            if(isset($response['osh_orgname']) && $response['osh_orgname'] != ""){
                $response['company_osh_orgnameAux'] = $response['osh_orgname'];
            }
            if(isset($response['osh_firstname']) && $response['osh_firstname'] != ""){
                $response['contact_osh_maincontactpersonfirstnameAux'] = $response['osh_firstname'];
            }
            if(isset($response['osh_lastname']) && $response['osh_lastname'] != ""){
                $response['contact_osh_maincontactpersonlastnameAux'] = $response['osh_lastname'];
            }
            if(isset($response['osh_basicrequirements']) && $response['osh_basicrequirements'] == "true"){
                $response['osh_basicrequirements'] = 'on';
            }

            foreach ($response as $attrName => $attrValue) {
                if (strpos($attrName, 'prefix') !== false  && is_array($attrValue)){
                    $response[$attrName] = $attrValue['Id'];
                }
            }

            error_log("EVE_CSM_SESSION_" . var_export($response, true));
            foreach ($this->cdbMap as $htmlName => $cdbName) {
                if (isset ($response[$cdbName])) {
                    if (is_array($response[$cdbName]) && isset($response[$cdbName]['Name'])) {
                        $this->fields[$htmlName] = $response[$cdbName]['Name'];
                        /*} elseif (strpos($cdbName, 'profile') !== false) {
                            $this->fields['profiles'][$htmlName] = $response[$cdbName];*/
                    } elseif ($cdbName === "returnPaises") {
                        $this->fields[$htmlName] = $countries;
                    } else {
                        $this->fields[$htmlName] = $response[$cdbName];
                    }
                }
            }
        }
//        if ($statusCode != $sent){
//            //Insertamos una variable para mostrar el check del main contact change.
//            $_SESSION['mainContactChangeCheck'] = true;
//        }
        // Debug::dump($this->fields, 'FIELDS', true);
    }

    /**
     * Get session data of Maintenance Forms
     *
     * @param $response
     *
     * @throws \CDBException
     */
    private function getSessionDataMF($response, $countries, $response2)
    {
//file_put_contents("/tmp/curl.log", "10".PHP_EOL, FILE_APPEND | LOCK_EX);
        //Workaround para resolver la response en caso de que un mismo user tenga varios roles. 
        //En este caso, envío información duplicada errónea, por lo que comprobamos que es esta casuística
        // (envío una response con 3 arrauys en vez de 2), y en ese caso nos quedamos con la que se debe.
        if (isset($response[2]) && isset($response[1]['Fields'])) {
            $response = $response[1]['Fields'];
        }elseif (isset($response[0]['Fields'])) {
            $response = $response[0]['Fields'];
        } else {
            throw new CDBException('configuration_error', 500);
        }
        $responseFixed[] = array();
        
        // Filter the response to clean the prefixes
        foreach ($response as $key => $value) {
//file_put_contents("/tmp/curl.log", "10.1".PHP_EOL, FILE_APPEND | LOCK_EX);
            if (strpos($key, '.') !== false) {
//file_put_contents("/tmp/curl.log", "10.2".PHP_EOL, FILE_APPEND | LOCK_EX);
                $key = explode('.', $key)[1];
                if($key == "osh_campaignpledge" && $value['Value'] != ""){
//file_put_contents("/tmp/curl.log", "10.3".PHP_EOL, FILE_APPEND | LOCK_EX);
                    $this->savePledgeData($value['Value']);
                }else if($key == "osh_quoteonhwc" && $value['Value'] != ""){
//file_put_contents("/tmp/curl.log", "10.4".PHP_EOL, FILE_APPEND | LOCK_EX);
                    $this->saveQuoteData($value['Value']);
                }
//                
            }
            $responseFixed[$key] = $value;
        }
		
		//The phone prefix for the main contact seems to come out of the normal structure in the JSON so, in order to obtain and show it, the following "if" is needed.
		if(isset($response['osh_prefixphone1']['Name']))
		{
			$this->fields['contact_osh_prefixmaincontactphone'] = $response['osh_prefixphone1']['Name'];
		}
		
        foreach($response2 as $key => $value){
            foreach($value['Fields'] as $key2 => $value2){
//file_put_contents("/tmp/curl.log", "10.4.1: ".$key2.", ".$value2.PHP_EOL, FILE_APPEND | LOCK_EX);
                if(isset($value['Fields']['osh_campaigncontacttype']) && $value['Fields']['osh_campaigncontacttype'] == 2){
                    $keyValue = $this->setUserRepresentativeFields($value, $key2, $value2);
                } else if(isset($value['Fields']['osh_campaigncontacttype']) && ($value['Fields']['osh_campaigncontacttype'] == 3 )){
 
                    $keyValue = $this->setCeoFields($value, $key2, $value2);
                } else if(isset($value['Fields']['osh_campaigncontacttype']) && $value['Fields']['osh_campaigncontacttype'] == 4){

                    $keyValue = $this->setUserCOMRepresentativeFields($value, $key2, $value2);
                } else{
                    $keyValue = $this->setOtherUsersField($key, $value, $key2, $value2);
                }
                $responseFixed[$this->before(';',$keyValue)] = $this->after(';',$keyValue);
//                $key2 = $key . $key2;
//                $responseFixed[$key2] = $value2;
            }
        }
        $response                 = $responseFixed;
        $response['returnPaises'] = $countries;
        foreach ($this->cdbMap as $htmlName => $cdbName) {
//file_put_contents("/tmp/curl.log", "10.5".PHP_EOL, FILE_APPEND | LOCK_EX);
            if (isset ($response[$cdbName])) {
//file_put_contents("/tmp/curl.log", "10.6: ".$cdbName. ", ".$response[$cdbName].PHP_EOL, FILE_APPEND | LOCK_EX);
                if  (is_array($response[$cdbName]) && isset($response[$cdbName]['Value'])&& isset($response[$cdbName]['Value']['Value'])) {
                    $this->fields[$htmlName] = $response[$cdbName]['Value']['Value'];
                } else if (is_array($response[$cdbName]) && isset($response[$cdbName]['Value'])&& isset($response[$cdbName]['Value']['Name'])) {
                    $this->fields[$htmlName] = $response[$cdbName]['Value']['Name'];
                } elseif ($cdbName === "returnPaises") {
                    $this->fields[$htmlName] = $countries;
                } else {
                    $this->fields[$htmlName] = isset($response[$cdbName]['Value']) ? $response[$cdbName]['Value'] : $response[$cdbName];
                }
            }
        }
    }
    
    public function setOtherUsersField($key, $value, $key2, $value2){
//file_put_contents("/tmp/curl.log", "11".PHP_EOL, FILE_APPEND | LOCK_EX);
        $otherUserId = substr($key, -1)+1;
        if($key2 == "firstname"){
            $value2 = $value2 . " " . $value['Fields']['lastname'];
            $key = "fullname".$otherUserId;
            $value = $value2;
            return $key .";" . $value;
        }else if ($key2 == "lastname"){
            return null;
        }else if($key2 == "telephone1"){
            $key = "osh_otheruserphone".$otherUserId;
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "emailaddress1"){
            $key = "osh_otheruseremail".$otherUserId;
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "osh_prefixphone1") {
            $key = "osh_otheruserprefix".$otherUserId;
            error_log('--- osh_prefixphone1: ');
            if ($value2['Id'] != null && $value2['Id'] != "") {
                $value = $value2['Id'];
            } else {
                $value = "";
            }
            return $key .";" . $value;
        }
        
    }
    public function setCeoFields($value, $key2, $value2){
           
//file_put_contents("/tmp/curl.log", "12".PHP_EOL, FILE_APPEND | LOCK_EX);
        if($key2 == "firstname"){
            $key = "osh_ceofirstname";
            $value = $value2;
            return $key .";" . $value;
        }else if ($key2 == "lastname"){
            $key = "osh_ceolastname";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "osh_ceoimage"){
            $key = "osh_ceoimage";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "osh_position"){
            $key = "osh_positionid";
            $value = $value2;
            return $key .";" . $value;
        }
    }
      public function setUserRepresentativeFields($value, $key2, $value2){
//file_put_contents("/tmp/curl.log", "13".PHP_EOL, FILE_APPEND | LOCK_EX);
        if($key2 == "firstname"){
            $key = "osh_representativefirstname";
            $value = $value2;
            return $key .";" . $value;
        }else if ($key2 == "lastname"){
            $key = "osh_representativelastname";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "telephone1"){
            $key = "osh_representativetelephone1";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "emailaddress1"){
            $key = "osh_representativeemailaddress1";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "osh_prefixphone1") {
            $key = "osh_prefixrepresentativephone";
            $value = $value2['Id'];
            return $key .";" . $value;
        }
        
    }
    public function setUserCOMRepresentativeFields($value, $key2, $value2){
//file_put_contents("/tmp/curl.log", "14".PHP_EOL, FILE_APPEND | LOCK_EX);
        if($key2 == "firstname"){
            $key = "osh_mediaproshfirstname";
            $value = $value2;
            return $key .";" . $value;
        }else if ($key2 == "lastname"){
            $key = "osh_mediaproshlastname";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "telephone1"){
            $key = "osh_phonemediapr";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "emailaddress1"){
            $key = "osh_emailmediapr";
            $value = $value2;
            return $key .";" . $value;
        }else if($key2 == "osh_prefixphone1") {
            $key = "osh_prefixmediaprphone";
            $value = $value2['Id'];
            return $key .";" . $value;
        }
    }
    function after ($a, $inthat)
    {
//file_put_contents("/tmp/curl.log", "15".PHP_EOL, FILE_APPEND | LOCK_EX);
        if (!is_bool(strpos($inthat, $a)))
        return substr($inthat, strpos($inthat,$a)+strlen($a));
    }

    function before ($a, $inthat)
    {
//file_put_contents("/tmp/curl.log", "16".PHP_EOL, FILE_APPEND | LOCK_EX);
        return substr($inthat, 0, strpos($inthat, $a));
    }

    public function savePledgeData($value){
        $_SESSION['pledgeOld'] = $value;
    }
    public function saveQuoteData($value){
        $_SESSION['quoteOld'] = $value;
    }
    /**
     * Set the context of the application via CDB
     *
     * @throws \CDBException
     * @throws \OshException
     */
    private function setContext()
    {
//file_put_contents("/tmp/curl.log", "17".PHP_EOL, FILE_APPEND | LOCK_EX);
        $params = Parameters::getInstance();
        if ($this->debug) {
            $params->setUrlParamValue('entity', $params->get('entity') ? $params->get('entity') : $params->get('defaultEntity'));
            $params->setUrlParamValue('partner_type', $params->get('partner_type') ? $params->get('partner_type') : $params->get('defaultPartnerType'));
            $params->setUrlParamValue('status_code', $params->get('status_code'));
            $params->setUrlParamValue('maintenance_mode', $params->get('maintenance_mode'));
            $params->setUrlParamValue('locked', $params->get('locked'));

            return;
        }
        $readMethod = $this->getMethod('read', 'read_mf');
        $url        = $this->buildUrl($readMethod);
        $response   = $this->getData($url);
        $response   = $response[$readMethod['response']];
        if (! is_array($response)) {
            $response = json_decode($response, true);
            $_SESSION['categoryReal'] = ($response[0]['Fields']['memberof.osh_categoryid']['Value']['Name']);
          //  $_SESSION['mainContactPrefix'] = json_encode($response[0]['Fields']['osh_prefixphone1']);
        }
        if (! $params->getUrlParam('entity') || ! $params->getUrlParam('partner_type') || ! $params->getUrlParam('maintenance_mode') || ! $params->getUrlParam('locked')) {
            throw new OshException('bad_config', 500);
        } else {
            if ($params->getUrlParamValue('maintenance_mode')) {
//                error_log("Entity: " .print_r($response,1));
                $this->setContextForMaintenanceForm($response);
            } else {
//                error_log("Entity: " .print_r($response,1));
                $this->setContextForAppForm($response);
            }
        }
    }

    /**
     * Set the context for AppForms
     * @throws \CDBException
     */
    private function setContextForAppForm($response)
    {

//file_put_contents("/tmp/curl.log", "18".PHP_EOL, FILE_APPEND | LOCK_EX);
        $params      = Parameters::getInstance();
        $categoryKey = $params->getUrlParam('entity');
        
        $params->set('NewFromURL', true);
        if (! isset($response[$categoryKey]['Name']) || ! isset($params->get('cdb')['category'])) {
            throw new CDBException("no_partner_type", 500);
        } else {
            
            $category    = $response[$categoryKey]['Name'];
            $categoryMap = $params->get('cdb')['category'];
            $locked      = $params->get('cdb')['locked'];
            $statusCode  = $params->getUrlParam('status_code');
            $statusCode  = intval($response[$statusCode]);
            $gracePeriod = $params->get('cdb')['graceperiod'];
            if (array_search($statusCode, $gracePeriod) !== false) {
                $params->setUrlParamValue('graceperiod', true);
            }
            $params->set('statuscode', $statusCode);
            foreach ($categoryMap as $categoryPattern => $categoryName) {
                if (strpos(strtolower($category), $categoryPattern) !== false) {
                    $categoryTranslated = $categoryMap[$categoryPattern];
                    if ($categoryTranslated != 'pcp') {
                        $params->setUrlParamValue('entity', $categoryTranslated);
                    } else {
                        $params->setUrlParamValue('entity', 'ocp');
                    }

                    if ($categoryTranslated === 'fop') {
                        $params->setUrlParamValue('partner_type', 'current');
                        //$params->setUrlParamValue('maintenance_mode', 'mf');
                    } elseif ($categoryTranslated === 'pcp') {
                        $params->setUrlParamValue('partner_type', 'new');

                        $params->setUrlParamValue('locked', false);
                        $params->setUrlParamValue('potential', true);
                        $params->setUrlParamValue('maintenance_mode', false);
                    } else {
                        $partnerType      = $params->getUrlParam('partner_type');
                        $partnerTypeValue = isset($response[$partnerType]) ? 'new' : 'current';
                        $params->setUrlParamValue('partner_type', $partnerTypeValue);
                        if (array_search($statusCode, $locked) !== false) {
                            $params->setUrlParamValue('locked', true);
                        }
                    }
                }
            }
        }
    }

    /**
     * Set the context for maintenance forms
     * @throws \CDBException
     */
    private function setContextForMaintenanceForm($response)
    {
//file_put_contents("/tmp/curl.log", "19".PHP_EOL, FILE_APPEND | LOCK_EX);
        $params      = Parameters::getInstance();
        $categoryKey = $params->getUrlParam('entity_mf');
        if (isset($response[0]['Fields'])) {
            $response = $response[0]['Fields'];
        } else {
            throw new CDBException('configuration_error', 500);
        }
        if (! isset($response[$categoryKey]['Value']['Name']) || ! isset($params->get('cdb')['category'])) {
            throw new CDBException("no_partner_type", 500);
        } else {
            $category    = $response[$categoryKey]['Value']['Name'];
            $categoryMap = $params->get('cdb')['category'];
            $statusCode  = $params->getUrlParam('status_code');
            if(isset($response[$statusCode])){
                $statusCode  = intval($response[$statusCode]);
            }
            $gracePeriod = $params->get('cdb')['graceperiod'];
            if (array_search($statusCode, $gracePeriod) !== false) {
                $params->setUrlParamValue('graceperiod', true);
            }
            foreach ($categoryMap as $categoryPattern => $categoryName) {
                if (strpos(strtolower($category), $categoryPattern) !== false) {
                    $categoryTranslated = $categoryMap[$categoryPattern];
                    $params->setUrlParamValue('entity', $categoryTranslated);
                    if ($categoryTranslated === 'fop') {
                        $params->setUrlParamValue('partner_type', 'current');
                    } else {
                        $partnerType      = $params->getUrlParam('partner_type');
                        $partnerTypeValue = isset($response[$partnerType]) ? 'new' : 'current';
                        $params->setUrlParamValue('partner_type', $partnerTypeValue);
                    }
                }
            }
            //Lock fields if the changes are pending validation.
            if(isset($_SESSION['fieldsValidatingDialog']) && $_SESSION['fieldsValidatingDialog'] == true){
                $params->setUrlParamValue('locked', true);
            }
        }
//file_put_contents("/tmp/curl.log", "19.10".PHP_EOL, FILE_APPEND | LOCK_EX);
    }

    /**
     * Retrieve the correct method regarding on the context
     *
     * @return string
     * @throws \CDBException
     */
    private function getMethod($key, $keyMf)
    {
//file_put_contents("/tmp/curl.log", "20".PHP_EOL, FILE_APPEND | LOCK_EX);
        $params = Parameters::getInstance();
        $readMethod = null;
        if ($key == 'update' || $keyMf == 'update_mf' ||$key == 'satisfaction' || $keyMf == 'satisfaction_mf' ||$key == 'question' || $keyMf == 'question_mf'
            || $keyMf == 'requirements'  || $keyMf == 'requirements_mf') {
            if (isset($params->get('cdb')['regular_methods'])) {
                if ($params->getUrlParamValue('maintenance_mode')) {
                    if (isset($params->get('cdb')['regular_methods'][$keyMf])) {
                        $readMethod = $params->get('cdb')['regular_methods'][$keyMf];
                    }
                } else {
                    if (isset($params->get('cdb')['regular_methods'][$key])) {
                        $readMethod = $params->get('cdb')['regular_methods'][$key];
                    }
                }
            }
        }else {
            if (isset($params->get('cdb')['regular_methods'])) {
                if ($params->getUrlParamValue('maintenance_mode')) {
                    if (isset($params->get('cdb')['regular_methods'][$keyMf])) {
                        $readMode = 'read_mf';
                    }
                } else {
                    if (isset($params->get('cdb')['regular_methods'][$key])) {
                        $readMode = 'read';
                    }
                }
            }
            if (! isset($params->get('cdb')['regular_methods'][$readMode]) || ! isset($params->get('cdb')['regular_methods'][$readMode]['name']) || ! isset($params->get('cdb')['regular_methods'][$readMode]['idParam']) || ! isset($params->get('cdb')['regular_methods'][$readMode]['response'])) {
                throw new CDBException('configuration_error', 500);
            } else {
                $readMethod = $params->get('cdb')['regular_methods'][$readMode];
            }
        }

        return $readMethod;
    }

    /**
     * Build the URL
     */
    private function buildUrl($method)
    {
//file_put_contents("/tmp/curl.log", "21".PHP_EOL, FILE_APPEND | LOCK_EX);

        if ($this->debug) {
            $url = $method['name'];
        } else {
            $url = (! empty($this->sessionID)) ? $method['name'] . '?' . $method['idParam'] . '=' . $this->sessionID : '';
        }
//file_put_contents("/tmp/curl.log", $url.PHP_EOL, FILE_APPEND | LOCK_EX);
        return $url;
    }

    /**
     * Load the data of the dropDown fields
     */
    private function loadDropdownsData()
    {
//file_put_contents("/tmp/curl.log", "22".PHP_EOL, FILE_APPEND | LOCK_EX);
        $params          = Parameters::getInstance();
        $dropDownMethods = $params->get('cdb')['dropdown_methods'];
        foreach ($dropDownMethods as $method) {
            $this->getDropdownData($method);
        }
    }

    /**
     * Load the data of a single dropDown field
     *
     * @param $method
     *
     * @throws \CDBException
     */
    private function getDropdownData($method)
    {
//file_put_contents("/tmp/curl.log", "23".PHP_EOL, FILE_APPEND | LOCK_EX);
        if ($response = $this->getData($method['method'])) {
            $response = $response[$method['data']];
            if (! is_array($response)) {
                $response = json_decode($response, true);
            }
            // Combined response (more than one dropdown)
            if (is_array($response) && count($response) && isset($response[0]['Name'])) {
                $this->getCombinedDropdown($response);
                // Single dropDown
            } else {
                $this->getSingleDropdown($method, $response);
            }
        }
    }

    /**
     * Retrieve a combined dropDown
     *
     * @param $response
     */
    private function getCombinedDropdown($response)
    {
//file_put_contents("/tmp/curl.log", "24".PHP_EOL, FILE_APPEND | LOCK_EX);
        foreach ($response as $field) {
            if (($key = array_search($field['Name'], $this->cdbMap)) !== false) {
                $values = $field['Values'];
                if (isset($this->fields[$key])) {
                    $this->dropdowns[$key]['selected'] = $this->fields[$key];
                }
                $this->dropdowns[$key]['values'] = $values;
            }
        }
    }

    /**
     * Retrieve a single dropDown (i.e. countries)
     *
     * @param $method
     * @param $response
     */
    private function getSingleDropdown($method, $response)
    {
//file_put_contents("/tmp/curl.log", "25".PHP_EOL, FILE_APPEND | LOCK_EX);
        $fieldNameArray = $method['fields'];
        $values         = $response;
file_put_contents("/tmp/curl.log", "fields INIT".PHP_EOL, FILE_APPEND | LOCK_EX);
//foreach($this->fields as $incomingField)
//{
//file_put_contents("/tmp/curl.log", "Field: ".$incomingField.PHP_EOL, FILE_APPEND | LOCK_EX);
//file_put_contents("/tmp/curl.log", key($incomingField).PHP_EOL, FILE_APPEND | LOCK_EX);
//}
//file_put_contents("/tmp/curl.log", "fields END".PHP_EOL, FILE_APPEND | LOCK_EX);
        foreach ($fieldNameArray as $fieldName) {
//file_put_contents("/tmp/curl.log", "25"." ".$fieldName.PHP_EOL, FILE_APPEND | LOCK_EX);
            if (isset($this->fields[$fieldName])) {
//file_put_contents("/tmp/curl.log", "25"." ".$fieldName.PHP_EOL, FILE_APPEND | LOCK_EX);
                $this->dropdowns[$fieldName]['selected'] = $this->fields[$fieldName];
            }
            $this->dropdowns[$fieldName]['values'] = $values;
        }
    }

    /**
     * Execute a service and retrieve the data
     *
     * @param $url
     *
     * @return array|null
     *
     * @throws \CDBException
     */
    private function getData($url)
    {
//file_put_contents("/tmp/curl.log", "26".PHP_EOL, FILE_APPEND | LOCK_EX);
        $resource = $this->host . $this->port . $this->resource . $url;

//file_put_contents("/tmp/curl.log", "26 resource: ".$resource.PHP_EOL, FILE_APPEND | LOCK_EX);
        error_log("Eve_CSM_GetData_" . var_export($resource, true));
        $response = null;
//        $time_pre = microtime(true);
        if ($content = @file_get_contents($resource)) {
//            $time_post = microtime(true);
//            error_log("Fase1: " .($time_post - $time_pre) . " seconds");
            $response = json_decode($content, true);
            error_log("Eve_CSM_GetData_response_" . var_export($response, true));
            if (! $this->debug && intval($response['returnCode']) !== 1) {
                if(intval($response['returnCode']) === -69){
                    $_SESSION['fieldsValidatingDialog'] = true;
//file_put_contents("/tmp/curl.log", "26.1".PHP_EOL, FILE_APPEND | LOCK_EX);
                }else{
//file_put_contents("/tmp/curl.log", "26.2".PHP_EOL, FILE_APPEND | LOCK_EX);
//file_put_contents("/tmp/curl.log", $response['returnMessage'].PHP_EOL, FILE_APPEND | LOCK_EX);
                    throw new CDBException($response['returnMessage'], $response['returnCode']);
                }
            }
        } else {
            throw new CDBException('resource_not_found', 404);
        }
foreach ($response as $value)
{ 
	//file_put_contents("/tmp/curl.log", $value.PHP_EOL, FILE_APPEND | LOCK_EX);
} 

        return $response;
    }

    /**
     * Update CDB User
     *
     * @param array $data
     */
    public function updateData($data)
    {
//file_put_contents("/tmp/curl.log", "27".PHP_EOL, FILE_APPEND | LOCK_EX);
        $this->setDataPost($data);
    }


    public function submitSatisfaction($id, $satisfaction)
    {
//file_put_contents("/tmp/curl.log", "28".PHP_EOL, FILE_APPEND | LOCK_EX);
        $this->updateSatisfaction($id, $satisfaction);
    }

    public function updateRequirements($id, $requirements)
    {
//file_put_contents("/tmp/curl.log", "29".PHP_EOL, FILE_APPEND | LOCK_EX);
        $this->submitRequirements($id, $requirements);
    }

    public function submitQuestion($id, $title, $message, $email)
    {
//file_put_contents("/tmp/curl.log", "30".PHP_EOL, FILE_APPEND | LOCK_EX);
        $this->updateQuestion($id, $title, $message, $email);
    }

    /**
     * @param string $parameters
     *
     * @throws \CDBException
     */
//    private function setData($parameters)
//    {
//        $updateMethod = $this->getMethod('update', 'update_mf');
//        $url          = $this->host . $this->port . $this->resource . $updateMethod . '?' . http_build_query($parameters);
//        error_log("URL: " .$url);
//        $ch           = curl_init($url);
//        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
//        $server_output = curl_exec($ch);
//         error_log("Respuesta: " .  print_r($server_output,1));
//        $this->processResponse($server_output);
//        curl_close($ch);
//        
//    }
    
        /**
     * @param string $parameters
     *
     * @throws \CDBException
     */
    private function setDataPost($parameters)
    {
//file_put_contents("/tmp/curl.log", "31".PHP_EOL, FILE_APPEND | LOCK_EX);
        error_log(var_export($parameters, true));

       if(isset($parameters['id'])){
            $id="id=" .$parameters['id'];
            unset($parameters['id']);
        }
        if(isset($parameters['paises'])){
            $paises="paises=" .$parameters['paises'];
            unset($parameters['paises']);
        }else{
            $paises="paises=";
        }
        $otherusers="otherusers=";
        if(isset($parameters['otherusers1']) && $parameters['otherusers1'] != "(||)"){
            $otherusers.= str_replace(" ", "", $parameters['otherusers1']);
            unset($parameters['otherusers1']);
        }
        if($otherusers != "otherusers=" && isset($parameters['otherusers2'])&& $parameters['otherusers2'] != "(||)"){
           $otherusers.= ","; 
        }
        if(isset($parameters['otherusers2'])&& $parameters['otherusers2'] != "(||)"){
            $otherusers.= str_replace(" ", "", $parameters['otherusers2']);
            unset($parameters['otherusers2']);
        }
        if($otherusers != "otherusers=" && isset($parameters['otherusers3'])&& $parameters['otherusers3'] != "(||)"){
           $otherusers.= ","; 
        }
        if(isset($parameters['otherusers3'])&& $parameters['otherusers3'] != "(||)"){
            $otherusers.= str_replace(" ", "", $parameters['otherusers3']);
            unset($parameters['otherusers3']);
        }
        if($otherusers != "otherusers=" && isset($parameters['otherusers4'])&& $parameters['otherusers4'] != "(||)"){
           $otherusers.= ","; 
        }
        if(isset($parameters['otherusers4'])&& $parameters['otherusers4'] != "(||)"){
            $otherusers.= str_replace(" ", "", $parameters['otherusers4']);
            unset($parameters['otherusers4']);
        }
        if($otherusers != "otherusers=" && isset($parameters['otherusers5'])&& $parameters['otherusers5'] != "(||)"){
           $otherusers.= ","; 
        }
        if(isset($parameters['otherusers5'])&& $parameters['otherusers5'] != "(||)"){
            $otherusers.= str_replace(" ", "", $parameters['otherusers5']);
            unset($parameters['otherusers5']);
        }
		
        /* "osh_ceo_changed" param can only be send on mantenaince*/
        $params = Parameters::getInstance();
        if(empty($params->get('mf')) && isset($parameters['fields']['osh_ceo_changed'])){
                unset($parameters['fields']['osh_ceo_changed']);
        }
        /* */
        
        $updateMethod = $this->getMethod('update', 'update_mf');
        
        $urlBase          = $this->host . $this->port . $this->resource . $updateMethod;

        //obtain gecos
        if (isset($_SESSION['auth'])) {
            $auth = $_SESSION['auth'];
            error_log("EVE_CSM_SESSION: " . var_export( $_SESSION['auth'], true));
        } else {
            $auth = '';
            error_log("EVE_CSM_SESSION_ID: " . var_export( $auth, true));
        }


        if(isset($id)){
            $url = $urlBase . "?" . $id ."&" .$otherusers . "&" . $paises . "&auth=" . $auth;
        }else{
            $url = $urlBase . "?" . $otherusers . "&" . $paises . "&auth=" . $auth;
        }
        $url = $url. "&option=" .$parameters['option'];

        $ch = curl_init();
        error_log("URL: " .$url);
        curl_setopt($ch, CURLOPT_URL,$url);
        curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYPEER, 0); 

        $fieldsJson = json_encode($parameters['fields'],JSON_UNESCAPED_SLASHES | JSON_UNESCAPED_UNICODE);
        curl_setopt($ch, CURLOPT_POSTFIELDS, base64_encode($fieldsJson));
        error_log("Fields:   " .print_r(base64_encode($fieldsJson),1));
        
        error_log("Fields2:   " .print_r($parameters['fields'],1));
        
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        $server_output = curl_exec ($ch);
//file_put_contents("/tmp/curl.log", $ch.PHP_EOL, FILE_APPEND | LOCK_EX);
        if($server_output === false)
        {
            error_log('Curl error: ' . curl_error($ch));
//file_put_contents("/tmp/curl.log", $ch.PHP_EOL, FILE_APPEND | LOCK_EX);
//file_put_contents("/tmp/curl.log", curl_error($ch).PHP_EOL, FILE_APPEND | LOCK_EX);
        }
        else
        {
//file_put_contents("/tmp/curl.log", $ch.PHP_EOL, FILE_APPEND | LOCK_EX);
            echo 'Operación completada sin errores';
        }

        curl_close($ch);
        
        error_log("Respuesta: " .  print_r($server_output,1));
        //After doing submit you can display the pending validation dialog
        if (isset($_SESSION['ValidatingDialogHidden'])) {
            unset($_SESSION['ValidatingDialogHidden']);
        }
        $this->processResponse($server_output);

        
    }

    /**
     * Process the response of the CDB
     *
     * @param $response
     */
    private function processResponse($response) {
//file_put_contents("/tmp/curl.log", "32".PHP_EOL, FILE_APPEND | LOCK_EX);
        if ($processedResponse = json_decode($response, true)) {
            $params = Parameters::getInstance();
            if($processedResponse['returnCode'] != 1){
                $_SESSION['returnCode'] = 'error';
            }else{
                $_SESSION['returnCode'] = 'ok';
            }
            if (isset($processedResponse['newId']) && $processedResponse['newId']) {
                
                $session = Session::getInstance();
                $params->setUrlParamValue('session_id', $processedResponse['newId']);
                if($processedResponse['newId'] != ""){
                    $session->setAttribute(Constants::SESSIONID_NAME, $processedResponse['newId']);
                }
                $params->setUrlParamValue('no_session_id', false);
            }
        }
    }

    private function updateSatisfaction($id, $satisfaction){
//file_put_contents("/tmp/curl.log", "33".PHP_EOL, FILE_APPEND | LOCK_EX);
        $satisfactionMethod = $this->getMethod('satisfaction', 'satisfaction_mf');
        $urlBase          = $this->host . $this->port . $this->resource . $satisfactionMethod;
        $url = $urlBase . "?id=" . $id ."&satisfaction=" .$satisfaction;
        $ch = curl_init();
        error_log("URL: " .$url);
        curl_setopt($ch, CURLOPT_URL,$url);
        //curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        $server_output = curl_exec ($ch);
        if($server_output === false)
        {
            error_log('Curl error: ' . curl_error($ch));
        }
        else
        {
            echo 'Operación completada sin errores';
        }


        curl_close($ch);

        error_log("Respuesta: " .  print_r($server_output,1));
    }

    private function submitRequirements($id, $requirements){
//file_put_contents("/tmp/curl.log", "34".PHP_EOL, FILE_APPEND | LOCK_EX);
        $requirementsMethod = $this->getMethod('requirements', 'requirements_mf');
        $urlBase          = $this->host . $this->port . $this->resource . $requirementsMethod;
        $url = $urlBase . "?id=" . $id ."&requirements=" .$requirements;
        $ch = curl_init();
        error_log("URL: " .$url);
        curl_setopt($ch, CURLOPT_URL,$url);
        //curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        $server_output = curl_exec ($ch);
		
        if($server_output === false)
        {
            error_log('Curl error: ' . curl_error($ch));
        }
        else
        {
            echo 'Operación completada sin errores';
        }

        curl_close($ch);

        error_log("Respuesta: " .  print_r($server_output,1));
    }
    private function updateQuestion($id, $title, $message, $email){
//file_put_contents("/tmp/curl.log", "35".PHP_EOL, FILE_APPEND | LOCK_EX);
        $questionMethod = $this->getMethod('question', 'question_mf');
        $urlBase          = $this->host . $this->port . $this->resource . $questionMethod;
        $url = $urlBase . "?id=" . $id ."&title=" .urlencode($title)."&message=" .urlencode($message) . "&email=". urlencode($email);
        $ch = curl_init();
        error_log("URL: " .$url);
        curl_setopt($ch, CURLOPT_URL,$url);
        //curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt ($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        $server_output = curl_exec ($ch);

        if($server_output === false)
        {
            error_log('Curl error: ' . curl_error($ch));
        }
        else
        {
            echo 'Operación completada sin errores';
        }


        curl_close($ch);

        error_log("Respuesta: " .  print_r($server_output,1));
    }

}

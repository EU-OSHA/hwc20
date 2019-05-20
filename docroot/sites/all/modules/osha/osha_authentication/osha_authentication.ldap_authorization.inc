<?php
/**
 * @file
 * osha_authentication.ldap_authorization.inc
 */

/**
 * Implements hook_default_ldap_authorization().
 */
function osha_authentication_default_ldap_authorization() {
  $export = array();

  $consumer_type = new stdClass();
  $consumer_type->disabled = FALSE; /* Edit this to true to make a default consumer_type disabled initially */
  $consumer_type->api_version = 1;
  $consumer_type->sid = 'osha';
  $consumer_type->consumer_type = 'drupal_role';
  $consumer_type->consumer_module = 'ldap_authorization_drupal_role';
  $consumer_type->status = TRUE;
  $consumer_type->only_ldap_authenticated = TRUE;
  $consumer_type->use_first_attr_as_groupid = FALSE;
  $consumer_type->mappings = 'a:8:{i:0;a:6:{s:12:"user_entered";s:13:"administrator";s:4:"from";s:53:"cn=ADMIN,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:13:"administrator";s:10:"simplified";s:13:"administrator";s:5:"valid";b:0;s:13:"error_message";s:101:"Role <em class="placeholder">administrator</em>_name does not exist and role creation is not enabled.";}i:1;a:6:{s:12:"user_entered";s:8:"Approver";s:4:"from";s:56:"cn=APPROVER,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:8:"Approver";s:10:"simplified";s:8:"Approver";s:5:"valid";b:0;s:13:"error_message";s:96:"Role <em class="placeholder">Approver</em>_name does not exist and role creation is not enabled.";}i:2;a:6:{s:12:"user_entered";s:18:"Events Coordinator";s:4:"from";s:57:"cn=EVENTCOOR,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:18:"Events Coordinator";s:10:"simplified";s:18:"Events Coordinator";s:5:"valid";b:0;s:13:"error_message";s:106:"Role <em class="placeholder">Events Coordinator</em>_name does not exist and role creation is not enabled.";}i:3;a:6:{s:12:"user_entered";s:13:"Events Editor";s:4:"from";s:56:"cn=EVENTEDT,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:13:"Events Editor";s:10:"simplified";s:13:"Events Editor";s:5:"valid";b:0;s:13:"error_message";s:101:"Role <em class="placeholder">Events Editor</em>_name does not exist and role creation is not enabled.";}i:4;a:6:{s:12:"user_entered";s:16:"Layout Validator";s:4:"from";s:54:"cn=LAYVAL,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:16:"Layout Validator";s:10:"simplified";s:16:"Layout Validator";s:5:"valid";b:0;s:13:"error_message";s:104:"Role <em class="placeholder">Layout Validator</em>_name does not exist and role creation is not enabled.";}i:5;a:6:{s:12:"user_entered";s:19:"Translation Liaison";s:4:"from";s:54:"cn=TRLIAS,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:19:"Translation Liaison";s:10:"simplified";s:19:"Translation Liaison";s:5:"valid";b:0;s:13:"error_message";s:107:"Role <em class="placeholder">Translation Liaison</em>_name does not exist and role creation is not enabled.";}i:6;a:6:{s:12:"user_entered";s:19:"Translation Manager";s:4:"from";s:53:"cn=TRLMN,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:19:"Translation Manager";s:10:"simplified";s:19:"Translation Manager";s:5:"valid";b:0;s:13:"error_message";s:107:"Role <em class="placeholder">Translation Manager</em>_name does not exist and role creation is not enabled.";}i:7;a:6:{s:12:"user_entered";s:18:"authenticated user";s:4:"from";s:52:"cn=READ,ou=MainSite,ou=Sites,dc=osha,dc=europa,dc=eu";s:10:"normalized";s:18:"authenticated user";s:10:"simplified";s:18:"authenticated user";s:5:"valid";b:0;s:13:"error_message";s:106:"Role <em class="placeholder">authenticated user</em>_name does not exist and role creation is not enabled.";}}';
  $consumer_type->use_filter = TRUE;
  $consumer_type->synch_to_ldap = FALSE;
  $consumer_type->synch_on_logon = TRUE;
  $consumer_type->revoke_ldap_provisioned = TRUE;
  $consumer_type->create_consumers = TRUE;
  $consumer_type->regrant_ldap_provisioned = TRUE;
  $export['drupal_role'] = $consumer_type;

  return $export;
}

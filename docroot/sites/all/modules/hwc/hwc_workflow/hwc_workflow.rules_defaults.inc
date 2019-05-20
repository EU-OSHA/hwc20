<?php
/**
 * @file
 * hwc_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function hwc_workflow_default_rules_configuration() {
  $items = array();
  $items['hwc_workflow_notifi_partner_when_his_content_rejected'] = entity_import('rules_config', '{ "hwc_workflow_notifi_partner_when_his_content_rejected" : {
      "LABEL" : "Partner notification when his content Rejected",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "new-state" ],
            "op" : "IN",
            "value" : { "value" : [ "draft", "final_draft" ] }
          }
        },
        { "data_is" : {
            "data" : [ "previous-state" ],
            "op" : "IN",
            "value" : { "value" : [ "to_be_approved", "needs_review" ] }
          }
        },
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "node_has_partner_section" : { "entity" : [ "node" ] } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } }
      ],
      "DO" : [
        { "hwc_custom_mail_to_users_of_partner" : {
            "node" : [ "node" ],
            "settings_type" : { "value" : { "rejection" : "rejection" } }
          }
        }
      ]
    }
  }');
  $items['hwc_workflow_notification_partner_document_created'] = entity_import('rules_config', '{ "hwc_workflow_notification_partner_document_created" : {
      "LABEL" : "Partner notification Document created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "document" : "document" } }
          }
        },
        { "disable_masquerading_notifications" : [] }
      ],
      "DO" : [
        { "hwc_mail_to_users_of_partner" : {
            "node" : [ "node" ],
            "subject" : "HWC Workflow: New document added for your company",
            "message" : "\\u003Cp\\u003EDear partner,\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EYour [node:type] is currently in the \\u201cpublish\\u201d status\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EThank you for your participation in the Healthy Workplaces Campaign 2018-2019 Manage Dangerous Substances campaign.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E"
          }
        }
      ]
    }
  }');
  $items['hwc_workflow_rules_hwc_workflow_een_from_reviewed'] = entity_import('rules_config', '{ "hwc_workflow_rules_hwc_workflow_een_from_reviewed" : {
      "LABEL" : "EU-OSHA EEN Reviewer Notification from Reviewed to Approved ",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } },
        { "disable_masquerading_notifications" : [] },
        { "data_is" : { "data" : [ "new-state" ], "value" : "to_be_approved" } },
        { "node_een_partner" : { "entity" : [ "node" ] } },
        { "data_is" : { "data" : [ "previous-state" ], "value" : "needs_review" } }
      ],
      "DO" : [
        { "hwc_mail_to_users_of_role" : {
            "node" : [ "node" ],
            "roles" : { "value" : { "17" : "17" } },
            "settings_type" : { "value" : { "supervisor" : "supervisor" } }
          }
        }
      ]
    }
  }');
  $items['hwc_workflow_rules_hwc_workflow_een_notification_to_be_approved'] = entity_import('rules_config', '{ "hwc_workflow_rules_hwc_workflow_een_notification_to_be_approved" : {
      "LABEL" : "EU-OSHA EEN Reviewer Notification to be Approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } },
        { "disable_masquerading_notifications" : [] },
        { "data_is" : { "data" : [ "new-state" ], "value" : "to_be_approved" } },
        { "node_een_partner" : { "entity" : [ "node" ] } },
        { "NOT data_is" : { "data" : [ "previous-state" ], "value" : "to_be_approved" } },
        { "NOT data_is" : { "data" : [ "previous-state" ], "value" : "needs_review" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "17" : "17" } },
            "subject" : "New news\\/events item uploaded by HWC partner",
            "message" : "\\u003Cp\\u003EPlease go to the back-office of the HWC website at \\u003Ca href=\\u0022https:\\/\\/healthy-workplaces.eu\\/en\\/admin\\/content\\u0022\\u003Ehttps:\\/\\/healthy-workplaces.eu\\/en\\/admin\\/content\\u003C\\/a\\u003E and check the news\\/events item created by a HWC partner.\\u003C\\/p\\u003E\\r\\n"
          }
        }
      ]
    }
  }');
  $items['hwc_workflow_rules_hwc_workflow_staff_from_reviewed'] = entity_import('rules_config', '{ "hwc_workflow_rules_hwc_workflow_staff_from_reviewed" : {
      "LABEL" : "HWC Staff Reviewer Notification from Reviewed to Approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } },
        { "disable_masquerading_notifications" : [] },
        { "data_is" : { "data" : [ "new-state" ], "value" : "to_be_approved" } },
        { "NOT node_een_partner" : { "entity" : [ "node" ] } },
        { "data_is" : { "data" : [ "previous-state" ], "value" : "needs_review" } }
      ],
      "DO" : [
        { "hwc_mail_to_users_of_role" : {
            "node" : [ "node" ],
            "roles" : { "value" : { "15" : "15" } },
            "settings_type" : { "value" : { "supervisor" : "supervisor" } }
          }
        }
      ]
    }
  }');
  $items['hwc_workflow_rules_hwc_workflow_staff_notif_to_be_approved'] = entity_import('rules_config', '{ "hwc_workflow_rules_hwc_workflow_staff_notif_to_be_approved" : {
      "LABEL" : "HWC Staff Reviewer Notification to be Approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } },
        { "disable_masquerading_notifications" : [] },
        { "data_is" : { "data" : [ "new-state" ], "value" : "to_be_approved" } },
        { "NOT node_een_partner" : { "entity" : [ "node" ] } },
        { "NOT data_is" : { "data" : [ "previous-state" ], "value" : "to_be_approved" } },
        { "NOT data_is" : { "data" : [ "previous-state" ], "value" : "needs_review" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "15" : "15" } },
            "subject" : "New news\\/events item uploaded by HWC partner",
            "message" : "\\u003Cp\\u003EPlease go to the back-office of the HWC website at \\u003Ca href=\\u0022https:\\/\\/healthy-workplaces.eu\\/en\\/admin\\/content\\u0022\\u003Ehttps:\\/\\/healthy-workplaces.eu\\/en\\/admin\\/content\\u003C\\/a\\u003E and check the news\\/events item created by a HWC partner.\\u003C\\/p\\u003E\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_hwc_workflow_notif_his_content_published'] = entity_import('rules_config', '{ "rules_hwc_workflow_notif_his_content_published" : {
      "LABEL" : "Partner notification when his content published",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "new-state" ], "value" : "published" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "node_has_partner_section" : { "entity" : [ "node" ] } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } }
      ],
      "DO" : [
        { "hwc_custom_mail_to_users_of_partner" : {
            "node" : [ "node" ],
            "settings_type" : { "value" : { "approved" : "approved" } }
          }
        }
      ]
    }
  }');
  $items['rules_hwc_workflow_notif_partner_to_be_reviewed'] = entity_import('rules_config', '{ "rules_hwc_workflow_notif_partner_to_be_reviewed" : {
      "LABEL" : "Notification partner when to be reviewed",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "new-state" ], "value" : "needs_review" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } }
      ],
      "DO" : [
        { "hwc_mail_to_users_of_partner" : {
            "node" : [ "node" ],
            "subject" : "HWC Workflow: New content has been sent for validation",
            "message" : "\\u003Cp\\u003EDear Partner,\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EThank you for submitting a [node:type] item for publication on your organisation\\u2019s profile on the campaign website. Once validated by EU-OSHA, this update will be visible on your public profile. You will be informed when the update has been published.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EThank you for your participation in the Healthy Workplaces Campaign 2018-2019 Manage Dangerous Substances campaign.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_hwc_workflow_notification_after_approval'] = entity_import('rules_config', '{ "rules_hwc_workflow_notification_after_approval" : {
      "LABEL" : "Notification after approval",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow" ],
      "ON" : { "node_cpm_approve" : [] },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "[HWC Website] CMW: ([node:nid]) [node:title-field]",
                  "message" : "\\u003Cp\\u003EDear [list_item:name],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E[user:name] should approve this content: \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "mail" : {
            "to" : [ "user:mail" ],
            "subject" : "[HWC Website] CMW: ([node:nid]) [node:title-field]",
            "message" : "\\u003Cp\\u003EDear [user:name],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EA content item should be approved by you: \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_hwc_workflow_notification_partner_content_created'] = entity_import('rules_config', '{ "rules_hwc_workflow_notification_partner_content_created" : {
      "LABEL" : "Notification partner content created (CMW_ED_US_02)",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } },
        { "disable_masquerading_notifications" : [] }
      ],
      "DO" : [
        { "hwc_mail_to_users_of_partner" : {
            "node" : [ "node" ],
            "subject" : "HWC Workflow: New content added for your company",
            "message" : "\\u003Cp\\u003EDear partner,\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EYour [node:type] is currently in the \\u201csave-as-draft\\u201d status which means that you can still edit it before you decide to \\u201csubmit\\u201d it for validation\\u201d\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EThank you for your participation in the Healthy Workplaces Campaign 2018-2019 Manage Dangerous Substances campaign.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_hwc_workflow_notification_partner_content_published'] = entity_import('rules_config', '{ "rules_hwc_workflow_notification_partner_content_published" : {
      "LABEL" : "Partner notification when content Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "new-state" ], "value" : "published" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "node_has_partner_section" : { "entity" : [ "node" ] } }
      ],
      "DO" : [
        { "hwc_custom_mail_to_users_of_partner" : {
            "node" : [ "node" ],
            "settings_type" : { "value" : { "approved" : "approved" } }
          }
        }
      ]
    }
  }');
  $items['rules_hwc_workflow_notification_to_be_approved'] = entity_import('rules_config', '{ "rules_hwc_workflow_notification_to_be_approved" : {
      "LABEL" : "Notification when to be approved",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow" ],
      "ON" : { "node_to_be_approved" : [] },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "[HWC Website] CMW: ([node:nid]) [node:title-field]",
                  "message" : "\\u003Cp\\u003EDear [list_item:name],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E[user:name] should approve this content \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "mail" : {
            "to" : [ "user:mail" ],
            "subject" : "[HWC Website] CMW: ([node:nid]) [node:title-field]",
            "message" : "\\u003Cp\\u003EDear [user:name],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EA content item should be approved by you: \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_hwc_workflow_notification_to_be_reviewed'] = entity_import('rules_config', '{ "rules_hwc_workflow_notification_to_be_reviewed" : {
      "LABEL" : "External Provider notification  when to be Reviewed",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "new-state" ], "value" : "needs_review" } },
        { "NOT data_is" : { "data" : [ "previous-state" ], "value" : "needs_review" } }
      ],
      "DO" : [
        { "hwc_mail_to_users_of_role" : {
            "node" : [ "node" ],
            "roles" : { "value" : { "13" : "13" } },
            "settings_type" : { "value" : { "reviewer" : "reviewer" } }
          }
        }
      ]
    }
  }');
  $items['rules_notification_partner_to_be_reviewed_by_partner'] = entity_import('rules_config', '{ "rules_notification_partner_to_be_reviewed_by_partner" : {
      "LABEL" : "Notification to be reviewed by the partner",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hwc_workflow", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "events" : "events", "news" : "news" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_wf_notification" } },
        { "data_is_empty" : { "data" : [ "node:field-wf-notification" ] } },
        { "disable_masquerading_notifications" : [] },
        { "data_is" : { "data" : [ "new-state" ], "value" : "draft" } },
        { "data_is" : { "data" : [ "previous-state" ], "value" : "to_be_approved" } }
      ],
      "DO" : [
        { "hwc_mail_to_users_of_partner" : {
            "node" : [ "node" ],
            "subject" : "HWC Workflow: item is requested \\u2018to be reviewed by the partner\\u2019 TODO",
            "message" : "\\u003Cp\\u003EDear partner,\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003ETODO\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EThank you for your participation in the Healthy Workplaces for TODO campaign.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notification_related_partners_document_created'] = entity_import('rules_config', '{ "rules_notification_related_partners_document_created" : {
      "LABEL" : "Related Partners notification Document created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "hwc_workflow", "rules" ],
      "ON" : { "node_insert--document" : { "bundle" : "document" } },
      "IF" : [
        { "document_related_partner_notifications" : { "entity" : [ "node" ] } }
      ],
      "DO" : [
        { "hwc_mail_to_related_partners" : {
            "node" : [ "node" ],
            "subject" : "HWC Workflow: New document added for your company",
            "message" : "\\u003Cp\\u003EDear partner,\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EYour [node:type] is currently in the \\u201cpublish\\u201d status\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EThank you for your participation in the Healthy Workplaces Campaign 2018-2019 Manage Dangerous Substances campaign.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E__SIGNATURE__\\u003C\\/p\\u003E"
          }
        }
      ]
    }
  }');
  return $items;
}

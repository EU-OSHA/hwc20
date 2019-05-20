<?php
/**
 * @file
 * hwc_workflow.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function hwc_workflow_workbench_moderation_export_transitions() {
  $items = array(
    'draft:final_draft' => array(
      'from_name' => 'draft',
      'to_name' => 'final_draft',
      'name' => 'Creating Final Draft',
    ),
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => 'Publishing',
    ),
    'final_draft:draft' => array(
      'from_name' => 'final_draft',
      'to_name' => 'draft',
      'name' => 'Rejecting Draft as Final',
    ),
    'final_draft:needs_review' => array(
      'from_name' => 'final_draft',
      'to_name' => 'needs_review',
      'name' => 'Reviewing Final Draft',
    ),
    'final_draft:to_be_approved' => array(
      'from_name' => 'final_draft',
      'to_name' => 'to_be_approved',
      'name' => 'Skip Review process',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:published' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'name' => 'Publish',
    ),
    'needs_review:to_be_approved' => array(
      'from_name' => 'needs_review',
      'to_name' => 'to_be_approved',
      'name' => 'Requesting Approval',
    ),
    'published:draft' => array(
      'from_name' => 'published',
      'to_name' => 'draft',
      'name' => 'Unpublish',
    ),
    'to_be_approved:draft' => array(
      'from_name' => 'to_be_approved',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'to_be_approved:final_draft' => array(
      'from_name' => 'to_be_approved',
      'to_name' => 'final_draft',
      'name' => 'Reject',
    ),
    'to_be_approved:needs_review' => array(
      'from_name' => 'to_be_approved',
      'to_name' => 'needs_review',
      'name' => 'Reject',
    ),
    'to_be_approved:published' => array(
      'from_name' => 'to_be_approved',
      'to_name' => 'published',
      'name' => 'Publishing',
    ),
  );
  return $items;
}

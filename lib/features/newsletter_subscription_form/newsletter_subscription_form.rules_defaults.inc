<?php
/**
 * @file
 * newsletter_subscription_form.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function newsletter_subscription_form_default_rules_configuration() {
  $items = array();
  $items['rules_webform_to_newsletter'] = entity_import('rules_config', '{ "rules_webform_to_newsletter" : {
      "LABEL" : "Webform to newsletter",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "webform_rules", "rules", "simplenews_rules" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "webform_has_id" : {
            "form_id" : "webform_client_form_1927",
            "selected_webform" : { "value" : { "webform-client-form-1927" : "webform-client-form-1927" } }
          }
        }
      ],
      "DO" : [
        { "simplenews_rules_action_subscribe" : { "mail" : "[user:mail]", "tid" : "43", "confirmation" : "0" } }
      ]
    }
  }');
  return $items;
}

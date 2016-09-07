<?php
/**
 * @param $form
 * @param $form_state
 * @return mixed
 */
function commerce_moodle_services_admin_form($form, &$form_state) {
    $form['moodle_services_token'] = [
        '#type' => 'textfield',
        '#title' => t('Token'),
        '#required' => TRUE,
        '#default_value' => variable_get('moodle_services_token')
    ];

    $form['moodle_services_domain_name'] = [
        '#type' => 'textfield',
        '#title' => t('Domain name'),
        '#required' => TRUE,
        '#default_value' =>  variable_get('moodle_services_domain_name'),
    ];
    return system_settings_form($form);
}
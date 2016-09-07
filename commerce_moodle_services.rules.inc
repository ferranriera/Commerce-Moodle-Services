<?php
function commerce_moodle_services_rules_action_info() {
    return array(
        'commerce_moodle_services_subscription' => array(
            'label' => t('Enroll User to moodle course'),
            'parameter' => array(
                'commerce_order' => array(
                    'type' => 'commerce_order',
                    'label' => t('Order to empty'),
                ),
            ),
            'configurable' => FALSE,
            'group' => t('Commerce Moodle'),
            'callbacks' => array(
                'execute' => 'commerce_moodle_services_subscription',
            ),
        ),
    );

}

function commerce_moodle_services_subscription($order){

    $moodle = new MoodleServicesUser($order->uid);

    $response = $moodle->existsUser();

    if (!isset($response['users'][0])) {
        $response = $moodle->createUser();
        $moodle_user_id = $response[0]['id'];
    } else {
        $moodle_user_id = $response['users'][0]['id'];
    }

    $moodle = new MoodleServicesCohort();

    foreach ($order->commerce_line_items['und'] as $line) {
        $response = $moodle->enrollCourse($moodle_user_id, $line);

        //This is weird, but if the response is NULL it meens that the user has been enrolled to the course properly.
        if ($response == null) {
            drupal_set_message(t('You have been sucessfully enrolled to the course'), 'status');
        }
    }
}
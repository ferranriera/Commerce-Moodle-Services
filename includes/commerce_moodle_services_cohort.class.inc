<?php

/**
 * Class MoodleServicesCohort
 */
class MoodleServicesCohort extends MoodleServices {

    /**
     * @param $moodle_user_id
     * @param $line
     * @return mixed|null|string
     */
    function enrollCourse($moodle_user_id, $productId) {

            $data = array(
                'enrolments[0][userid]' => $moodle_user_id,
                'enrolments[0][roleid]' => '5',
                'enrolments[0][courseid]' => $productId
            );

            $function_name = 'enrol_manual_enrol_users';

            return $this->request(HttpClientRequest::METHOD_POST, $function_name, $params = array(), $data);
    }

}
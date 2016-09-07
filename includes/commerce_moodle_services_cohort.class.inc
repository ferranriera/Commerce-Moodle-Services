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
    function enrollCourse($moodle_user_id, $line) {

            $line_item = commerce_line_item_load($line['line_item_id']);
            $product_id = $line_item->commerce_product['und'][0]['product_id'];
            $product = commerce_product_load($product_id);

            $data = array(
                'enrolments[0][userid]' => $moodle_user_id,
                'enrolments[0][roleid]' => '5',
                'enrolments[0][courseid]' => $product->field_moodle_id['und'][0]['value']
            );

            $functionname = 'enrol_manual_enrol_users';
            $params = array();

            return $this->request(HttpClientRequest::METHOD_POST, $functionname, $params, $data);
    }

}
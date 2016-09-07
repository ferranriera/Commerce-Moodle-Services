<?php

/**
 * Class MoodleServices
 */
abstract class MoodleServices {

    /**
     * @var null
     */
    private $url;
    /**
     * @var null
     */
    private $token;

    /**
     * MoodleServices constructor.
     */
    function __construct() {
        $this->url = variable_get('moodle_services_domain_name');
        $this->token = variable_get('moodle_services_token');
    }

    /**
     * @param $method
     * @param $functionname
     * @param $params
     * @param $data
     * @return mixed|null|string
     */
    function request($method, $functionname, $params, $data) {

        $url="{$this->url}/webservice/rest/server.php?moodlewsrestformat=json&wstoken={$this->token}&wsfunction={$functionname}";

        $response = '';
        $formatter = new HttpClientCompositeFormatter(HttpClientBaseFormatter::FORMAT_FORM, HttpClientBaseFormatter::FORMAT_JSON);
        $client = new HttpClient(null, $formatter);

        $client->options['curlopts'] = array(
            CURLOPT_SSL_VERIFYHOST => 0,            // don't verify ssl
            CURLOPT_SSL_VERIFYPEER => false,        //
            CURLOPT_VERBOSE        => 1                //
        );

        $request = new HttpClientRequest($url, array(
            'method' => $method,
            'parameters' => $params,
            'data' => $data,
        ));

        try {
            $response = $client->execute($request);
            if (is_array($response)) {
                if (array_key_exists('exception', $response)) {
                    watchdog('Commerce Moodle Services', 'Exception detected. Exception: %e, Message: %m, Error code: %ec', array('%e' => $response['exception'], '%m' => $response['message'], '%ec' => $response['errorcode']), WATCHDOG_ERROR);
                    drupal_set_message(t('An error occurred and Moodle enrollment did not complete. Please contact with the administrator'), 'error');
                }
            }
        }
        catch (HttpClientException $e) {
            debug($e);
            watchdog('Commerce Moodle Services', '%e', array('%e' => $e), WATCHDOG_ERROR);
            drupal_set_message(t('An error occurred and Moodle enrollment did not complete. Please contact with the administrator'), 'error');
        }

        return $response;
    }

}
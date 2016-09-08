<?php

/**
 * Class MoodleServicesUser
 */
class MoodleServicesUser extends MoodleServices{

    /**
     * @var
     */
    private $username;
    /**
     * @var
     */
    private $mail;

    /**
     * MoodleServicesUser constructor.
     * @param $uid
     */
    function __construct($uid) {
        parent::__construct();
        $user=user_load($uid);
        $this->username=$user->name;
        $this->mail=$user->mail;
    }

    /**
     * @return mixed|null|string
     */
    function createUser(){
        //TODO: Solve error with special chars username.
        $data = array(
            'users[0][username]' => urlencode($this->username),
            'users[0][firstname]' => '',
            'users[0][lastname]' => '',
            'users[0][password]' => '',
            'users[0][email]' => $this->mail,
        );

        $function_name = 'core_user_create_users';

        return $this->request(HttpClientRequest::METHOD_POST, $function_name, $params= array(), $data);
    }

    /**
     * @return mixed|null|string
     */
    function existsUser(){

        $data = array(
            'criteria[0][key]' => 'username',
            'criteria[0][value]' => $this->username
        );

        $function_name = 'core_user_get_users';

        return $this->request(HttpClientRequest::METHOD_POST, $function_name, $params= array(), $data);
    }

}
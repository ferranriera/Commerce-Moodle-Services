Commerce Moodle Services
========================

## Intro

Yet another module to provide integration between Drupal Commerce and Moodle.
It provides a Rule that try to create a Moodle user if it doesn't exist and then enroll this user to the courses.

## Requisites:

* Drupal 7
* Commerce
* Rules
* Http_Client

## Instalation instructions

1. Install this module as usual.
2. Create a integer called field_course_id in the product entity
3. Got to admin/config/services/moodle-services and configure the url of the endpoint and the token.

## Advise

This module is in beta only for development purpose. This module is based in some code of Droodle-Drupal module from cannod. Thanks to that!


<?php

/**
 * Class MoodleServicesCohort
 */
class Parser {

    static public function get(array $lines) {

        $products = [];
        foreach ($lines as $line) {
            $line_item = commerce_line_item_load($line['line_item_id']);
            $product_id = $line_item->commerce_product['und'][0]['product_id'];
            $product = commerce_product_load($product_id);
            foreach ($product->field_moodle_id['und'] as $moodleId) {
                $products[] = $moodleId['value'];
            }
        }

        return $products;
    }

}



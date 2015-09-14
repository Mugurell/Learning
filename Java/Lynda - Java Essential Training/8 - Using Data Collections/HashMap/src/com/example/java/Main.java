/**
 * Created by petru on 09-Sep-15.
 *
 *  A HashMap is an implementation of the interface Map.
 *  Is used to manage an represent an unordered data collection.
 */


package com.example.java;


import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) {

        Map<String, String> map = new HashMap<>();

        map.put("California", "Sacramento");
        map.put("Oregon", "Salem");
        map.put("Washington", "Olympia");

        System.out.println(map);

        map.put("Alaska", "Juneau");
        // now it is very possible the order is different
        System.out.println(map);

        // search for values, based on it's key
        String cap = map.get("Oregon");
        System.out.println(cap);

        // remove an item from the map
        map.remove("California");
        System.out.println(map);

    }

}

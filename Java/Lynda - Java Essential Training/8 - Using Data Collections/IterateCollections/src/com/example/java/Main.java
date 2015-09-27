/**
 * Created by petru on 09-Sep-15.
 */



package com.example.java;


import java.util.*;

public class Main {

    public static void main(String[] args) {

    // Loop through ordered data

        System.out.println("*****Ordered data******");
        List<String> list = new ArrayList<>();
        list.add("California");
        list.add("Oregon");
        list.add("Washington");

        System.out.println("toString() output");
        // will implicitly call the toString method of the object
        System.out.println(list);
        System.out.println("");

        // how to iterate thought every element of a collection
        System.out.println("ArrayList iterator");
        Iterator<String> iterator = list.iterator();
        // to iterate using an iterator must use two methods
        // hasNext() -> bool indicating whether there's available data
        // next() - moves to the next element and returns a reference to it
        while (iterator.hasNext()) {
            String value = iterator.next();
            System.out.println(value);
        }
        System.out.println("");

        System.out.println("ArrayList ForEach");
        for (String value : list) {
            System.out.println(value);
        }
        System.out.println("");

        System.out.println("Java 8 method reference");
        list.forEach(System.out::println);
        System.out.println("");


    // Loop through unordered data
        System.out.println("\n******Unordered data******");
        Map<String, String> map = new HashMap<>();
        map.put("California", "Sacremento");
        map.put("Oregon", "Salem");
        map.put("Washington", "Olympia");
        // will implicitly call the toString method
        System.out.println(map);
        System.out.println("");

        System.out.println("HashMap Iterator");
        // keySet() returns a set of the keys in our Map
        Set<String> keys = map.keySet();
        Iterator<String> iterator1 = keys.iterator();
        while (iterator1.hasNext()) {
            String key = iterator1.next();
            System.out.println("The capital of " + key + " is " + map.get(key));
        }
        System.out.println("");

        System.out.println("HashMap ForEach");
        for (String key : keys) {
            System.out.println("The capital of " + key + " is " + map.get(key));
        }

    }

}

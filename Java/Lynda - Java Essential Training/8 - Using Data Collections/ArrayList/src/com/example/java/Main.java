/**
 * Created by petru on 09-Sep-15.
 *
 *  An array list contains an ordered collection of data.
 */


package com.example.java;


import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        // It's good practice!? to declare what type of items
        // will be contained
        // This is done with generic notation - the diamond operator <>
        List<String> list = new ArrayList<>();

        list.add("California");
        list.add("Oregon");
        list.add("Washington");

        System.out.println(list);

        list.add("Alaska");
        System.out.println(list);

        list.remove(0);
        System.out.println(list);

        // to access an individual element from the list
        // can't use subscripts. Must use the get() method of List
        String state = list.get(1);
        System.out.println(state);

        // find an item in the List
        int pos = list.indexOf("Alaska");
        System.out.println(list.get(pos) + " is at position " + pos);

    }

}

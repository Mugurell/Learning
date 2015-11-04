/**
 * Created by petru on 12-Oct-15.
 */


package com.example.java;


public class Animal {
    private String name;

    public Animal() {}
    public Animal(String n) { name = n; }



    @Override
    public String toString() {
        return String.format("%s] Name: %s\n"
                                , getClass().getName()
                                , name);
    }
}

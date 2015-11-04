/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class Runner {
    private int RaceID;

    // default constructor
    public Runner() {  /*do nothing*/ }

    public String performSport() {
        return "Running";
    }

    public String toString() {
        return String.format("%d is %s\n", RaceID, performSport());
    }

}

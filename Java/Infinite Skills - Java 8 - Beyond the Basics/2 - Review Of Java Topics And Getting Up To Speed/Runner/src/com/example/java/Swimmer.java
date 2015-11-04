/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class Swimmer {
    private int raceID;

    // default constructor
    public Swimmer() {  /* do nothing*/ }

    // explicit constructor
    public Swimmer(int racerID) {
        raceID = racerID;
    }

    public String performSport() {
        return "Swimming";
    }

    public String toString() {
        return String.format("%d is %s.\n", raceID, performSport());
    }
}
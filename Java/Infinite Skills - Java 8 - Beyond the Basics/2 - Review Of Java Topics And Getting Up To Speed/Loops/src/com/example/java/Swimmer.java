/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class Swimmer {
    private int raceID;
    private String name;

    // default constructor
    public Swimmer() {  /* do nothing*/ }

    // explicit constructors
    public Swimmer(int racerID) {
        raceID = racerID;
    }
    public Swimmer(int id, String name) { raceID = id; this.name = name; }

    // add mutators/accessors for swimmer
    public int    getRaceID()          { return raceID; }
    public String getName()            { return name; }
    public void   setRaceID(int value) { raceID = value; }
    public void   setName(String n)    { name = n; }

    public String performSport() {
        return "Swimming";
    }

    public String toString() {
        return String.format("%s - %d is %s\n"
                , getName()
                , getRaceID()
                , performSport());
    }
}

/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class Runner {
    private int raceID;
    private String name;


    // default constructor
    public Runner() {  /*do nothing*/ }


    // add mutators/accessors for runner
    public int    getRaceID()          { return raceID; }
    public String getName()            { return name; }
    public void   setRaceID(int value) { raceID = value; }
    public void setName(String n)    { name = n; }

    public String performSport() {
        return "Running";
    }

    public String toString() {
        return String.format("%s - %d is %s\n"
                , getName()
                , getRaceID()
                , performSport());
    }
}

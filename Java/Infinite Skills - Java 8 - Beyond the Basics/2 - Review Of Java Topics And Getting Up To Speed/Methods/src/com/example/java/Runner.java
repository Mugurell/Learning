/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class Runner {
    private int raceID;

    // default constructor
    public Runner() {  /*do nothing*/ }


    // add mutators/accessors for runner
    public int  getraceID()          { return raceID; }
    public void setraceID(int value) { raceID = value; }

    public String performSport() {
        return "Running";
    }

    public String toString() {
        return String.format("%d is %s\n", raceID, performSport());
    }
}

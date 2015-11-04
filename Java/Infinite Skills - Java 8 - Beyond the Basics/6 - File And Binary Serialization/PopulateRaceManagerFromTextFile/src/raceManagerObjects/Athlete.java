package raceManagerObjects;

import raceManagerValidation.Validate;

/**
 * Created by petru on 15-Oct-15.
 */


public abstract class Athlete implements RaceParticipant, Person
{
    private int     _racerID;
    private String  _name;
    private int     _age;
    private boolean _isInjured;


    /**
     * Create a new simple raceManagerObjects.Athlete.
     */
    public Athlete()
    {  /*do nothing*/ }

    /**
     * Create a new, complex raceManagerObjects.Athlete
     * @param racerID it's ID for the race.
     * @param name    it's name.
     * @param age     it's age.
     */
    public Athlete(int racerID, String name, int age)
    {
        _racerID = racerID;
        _name = name;
        _age = age;
    }


    // add mutators/accessors for athlete
    public int getRacerID() {
        return _racerID;
    }

    public void setRacerID(int value) {
        Validate.NumberRangeValidation(0, 999999, value);
        _racerID = value;
    }

    public String getName() {
        return _name;
    }

    public void setName(String n) {
        // Throw exception if value is null or empty
        Validate.StringHasContent(n);
        _name = n;
    }

    public int getAge() {
        return _age;
    }

    public void setAge(int age) {
        Validate.NumberRangeValidation(18, 66, age);
        _age = age;
    }

    public boolean getIsInjured() {
        return _isInjured;
    }

    public void setIsInjured(boolean v) {
        _isInjured = v;
    }


    /**
     * Get the current activity of the raceManagerObjects.Athlete as a String.
     * @return String describing current activity.
     */
    public abstract String performRaceActivity();

    /**
     * get the state of this raceManagerObjects.Athlete as a String.
     * @return String  raceManagerObjects.Athlete info + activity
     */
    public String toString()
    {
        return String.format("[%s] %s, %d years - #%d"
                , getClass()
                , getName()
                , getAge()
                , getRacerID());
    }

    /**
     * Get the data String for a generic Athlete
     * @return String to match: name=someString;age=someInt;id=someInt;injured=someBoolean
     */
    public String toDataString() {
        return String.format("name=%s;age=%d;id=%d;injured=%b",
                             getName(), getAge(), getRacerID(), getIsInjured());
    }
}

package raceManagerObjects;

import raceManagerValidation.AthleteInjuredException;

/**
 * Created by petru on 09-Oct-15.
 */


public class Swimmer extends Athlete {

    // default constructor
    public Swimmer() {  /* do nothing*/ }

    // explicit constructors
    public Swimmer(int id, String name, int age) { super(id, name, age); }


    public String performRaceActivity() {
        if (getIsInjured()) {
            throw new AthleteInjuredException("Cramps. Bad ones.");
        }
        return "Swimming";
    }

    public String toString() {
        return String.format("%s is %s.\n"
                , super.toString()
                , performRaceActivity());
    }

    /**
     * Get the data String for a Swimmer
     * @return String to match: SWIMMER|name=someString;age=someInt;id=someInt;injured=someBoolean
     */
    public String toDataString() {
        return String.format("SWIMMER|%s", super.toDataString());
    }
}

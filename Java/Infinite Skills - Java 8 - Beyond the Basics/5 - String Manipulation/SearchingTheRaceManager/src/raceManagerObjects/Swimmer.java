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
}

package raceManagerObjects;

import raceManagerValidation.AthleteInjuredException;

/**
 * Created by petru on 09-Oct-15.
 */


public class Runner extends Athlete {
    private String _shoeBrand;

    /**
     * Create a new simple raceManagerObjects.Runner.
     */
    public Runner() {  /*do nothing*/ }

    /**
     * Create a new, complex raceManagerObjects.Runner
     * @param racerID  it's ID for the race.
     * @param name  it's name.
     * @param age  it's age.
     * @param brand brand of shoes wear
     */
    public Runner(int racerID, String name, int age, String brand) {
        super(racerID, name, age);
        _shoeBrand = brand;
    }


    /**
     * Get the endorsed/preferred shoe brand of this raceManagerObjects.Runner.
     * @return String  preferred/endorsed shoe brand of this raceManagerObjects.Runner.
     */
    public String getShoeBrand() { return _shoeBrand; }

    /**
     * Set the show brand that this raceManagerObjects.Runner must wear.
     * @param brand  String - the new shoe brand.
     */
    public void setShoeBrand(String brand) { _shoeBrand = brand; }


    /**
     * Get the current activity of the Runner.
     * If he's injured throws a runtime exception, else returns the current activity
     * @return  String describing current activity.
     * @throws  AthleteInjuredException if this Runner is injured
     */
    public String performRaceActivity() {
        if (getIsInjured()) {
            throw new AthleteInjuredException("Runner broke their foot!");
        }
        return "Running";
    }

    /**
     * Get the state of this raceManagerObjects.Runner as a String.
     * @return String  raceManagerObjects.Runner info + activity.
     */
    public String toString() {
        return String.format("%s is %s with %s shoes.\n"
                , super.toString()
                , performRaceActivity()
                , getShoeBrand());
    }
}

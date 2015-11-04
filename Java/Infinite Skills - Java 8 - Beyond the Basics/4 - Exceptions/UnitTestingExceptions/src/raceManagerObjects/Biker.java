package raceManagerObjects;

import raceManagerValidation.AthleteInjuredException;

/**
 * Created by petru on 15-Oct-15.
 */
public class Biker extends Athlete {
    boolean _usesClips;

    /**
     * Create a new simple raceManagerObjects.Biker.
     */
    public Biker() {  /*do nothing*/ }

    /**
     * Create a new, complex raceManagerObjects.Biker
     * @param racerID  it's ID for the race.
     * @param name  it's name.
     * @param age  it's age.
     * @param usesClips  if it uses clips or not
     */
    public Biker(int racerID, String name, int age, boolean usesClips) {
        super(racerID, name, age);
        _usesClips = usesClips;
    }


    /**
     * Get if this raceManagerObjects.Biker uses clipless pedals or not.
     * @return boolean  if uses clips or not.
     */
    public boolean getUsesClips() { return _usesClips; }

    /**
     * Set if this will use clips or not.
     * @param value boolean - if uses clips or not.
     */
    public void setUsesClips(boolean value) { _usesClips = value;}


    /**
     * Get the current activity of this biker.
     * If he's injured throws a runtime exception, else returns the current activity
     * @return  String describing current activity.
     * @throws  AthleteInjuredException if this Runner is injured
     */
    public String performRaceActivity() {
        if (getIsInjured()) {
            throw new AthleteInjuredException();
        }
        return "Biking";
    }

    /**
     * get the state of this raceManagerObjects.Biker as a String.
     * @return String  raceManagerObjects.Biker info + activity
     */
    public String toString() {
        if (_usesClips)
            return String.format("%s is %s with clips.\n", super.toString(), performRaceActivity());
        else
            return String.format("%s is %s without clips.\n", super.toString(), performRaceActivity());
    }
}

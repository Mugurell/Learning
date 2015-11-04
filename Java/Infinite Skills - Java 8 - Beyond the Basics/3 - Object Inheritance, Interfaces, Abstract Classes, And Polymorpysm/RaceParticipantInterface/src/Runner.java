/**
 * Created by petru on 09-Oct-15.
 */


public class Runner implements RaceParticipant {
    private int _racerID;


    /**
     * Create a new simple Runner.
     */
    public Runner() {  /*do nothing*/ }

    /**
     * Create a new, complex Runenr
     * @param racerID  it's ID for the race.
     */
    public Runner(int racerID) {
        _racerID = racerID;
    }


    // add mutators/accessors for runner
    public int    getRacerID()          { return _racerID; }
    public void   setRacerID(int value) { _racerID = value; }


    /**
     * Get the current activity of the Runner as a String.
     * @return String describing current activity.
     */
    public String performRaceActivity() {
        return "Running";
    }

    /**
     * get the state of this Runner as a String.
     * @return String  Runner info + activity
     */
    public String toString() {
        return String.format("[%s] %d is %s\n"
                , getClass()
                , getRacerID()
                , performRaceActivity());
    }
}

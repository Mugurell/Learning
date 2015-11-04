/**
 * Created by petru on 09-Oct-15.
 */


public class Runner implements Person, RaceParticipant {
    private int _racerID;
    private String _name;
    private int _age;


    /**
     * Create a new simple Runner.
     */
    public Runner() {  /*do nothing*/ }

    /**
     * Create a new, complex Runner
     * @param racerID  it's ID for the race.
     * @param name  it's name.
     * @param age  it's age.
     */
    public Runner(int racerID, String name, int age) {
        _racerID = racerID;
        _name = name;
        _age = age;
    }


    // add mutators/accessors for runner
    public int    getRacerID()          { return _racerID; }
    public String getName()             { return _name; }
    public int    getAge()              { return _age; }
    public void   setRacerID(int value) { _racerID = value; }
    public void   setName(String n)     { _name = n; }
    public void   setAge(int age)       { _age = age; }


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
        return String.format("[%s] %s, %d years - #%d is %s\n"
                , getClass()
                , getName()
                , getAge()
                , getRacerID()
                , performRaceActivity());
    }
}

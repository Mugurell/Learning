/**
 * Created by petru on 15-Oct-15.
 */


public abstract class Athlete implements RaceParticipant, Person {
    private int _racerID;
    private String _name;
    private int _age;


    /**
     * Create a new simple Athlete.
     */
    public Athlete() {  /*do nothing*/ }

    /**
     * Create a new, complex Athlete
     * @param racerID  it's ID for the race.
     * @param name  it's name.
     * @param age  it's age.
     */
    public Athlete(int racerID, String name, int age) {
        _racerID = racerID;
        _name = name;
        _age = age;
    }


    // add mutators/accessors for athlete
    public int    getRacerID()          { return _racerID; }
    public String getName()             { return _name; }
    public int    getAge()              { return _age; }
    public void   setRacerID(int value) { _racerID = value; }
    public void   setName(String n)     { _name = n; }
    public void   setAge(int age)       { _age = age; }


    /**
     * Get the current activity of the Athlete as a String.
     * @return String describing current activity.
     */
    public abstract String performRaceActivity();

    /**
     * get the state of this Athlete as a String.
     * @return String  Athlete info + activity
     */
    public String toString() {
        return String.format("[%s] %s, %d years - #%d"
                , getClass()
                , getName()
                , getAge()
                , getRacerID());
    }
}

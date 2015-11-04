/**
 * Created by petru on 09-Oct-15.
 */


public class Swimmer implements Person, RaceParticipant {
    private int _racerID;
    private String _name;
    private int _age;

    // default constructor
    public Swimmer() {  /* do nothing*/ }

    // explicit constructors
    public Swimmer(int id) { _racerID = id; }
    public Swimmer(int id, String name, int age) { _racerID = id; _name = name; _age = age; }

    // add mutators/accessors for swimmer
    public int    getRacerID()          { return _racerID; }
    public String getName()             { return _name; }
    public int    getAge()              { return _age; }
    public void   setRacerID(int value) { _racerID = value; }
    public void   setName(String n)     { _name = n; }
    public void   setAge(int value)     { _age = value; }

    public String performRaceActivity() {
        return "Swimming";
    }

    public String toString() {
        return String.format("[%s] %s, %d years - #%d is %s\n"
                , getClass()
                , getName()
                , getAge()
                , getRacerID()
                , performRaceActivity());
    }
}

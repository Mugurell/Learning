import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


// Don't want the Athletetest to be instantiated directly
public abstract class AthleteTest {

    protected String _name = "Test";
    protected int _racerID = 452;
    protected int _age = 32;
    private Athlete a1;
    private Athlete a2;

    public abstract Athlete getAthlete();
    public abstract Athlete getComplexAthlete();


    public AthleteTest() {
        a1 = getAthlete();
        a2 = getComplexAthlete();
    }

    @Before
    public abstract void setUp() throws Exception;

    @After
    public abstract void tearDown() throws Exception;


    @Test
    public void testConstructors() throws Exception {
        assertNotNull("Default Athlete could not be created", a1);
        assertNotNull("Complex Athlete could not be created", a2);
        assertEquals("Name not set correctly on a2.", _name, a2.getName());
        assertEquals("RacerID not set correctly on a2.", _racerID, a2.getRacerID());
        assertEquals("Age not set correctly on a2.", _age, a2.getAge());
    }


    @Test
    public void testGetSetRacerID() throws Exception {
        a1.setRacerID(_racerID);
        assertEquals("The racerID is not as expected", _racerID, a1.getRacerID());
    }

    @Test
    public void testGetSetName() throws Exception {
        a1.setName(_name);
        assertEquals("The _name is not as expected", _name, a1.getName());
    }

    @Test
    public void testGetSetAge() throws Exception {
        a1.setAge(_age);
        assertEquals("The _age is not as expected", _age, a1.getAge());
    }


    // By making this abstract, the subclasses will be forced to implement it.
    public abstract void testPerformRaceActivity() throws Exception;


    @Test
    public void testToString() throws Exception {
        a1.setName(_name);
        a1.setAge(_age);
        a1.setRacerID(_racerID);
        String rts = a1.toString();
        assertTrue("toString does not contain racerID", rts.contains(String.format("%d", _racerID)));
        assertTrue("toString does not contain name", rts.contains(_name));
        assertTrue("toString does not contain age", rts.contains(Integer.toString(_age)));
        assertTrue("toString does not contain class", rts.contains(a1.getClass().toString()));
    }
}
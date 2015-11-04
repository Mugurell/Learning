package raceManagerObjects;

import raceManagerValidation.AthleteInjuredException;
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
    public abstract void setUp();

    @After
    public abstract void tearDown();


    @Test
    public void testConstructors() {
        assertNotNull("Default raceManagerObjects.Athlete could not be created", a1);
        assertNotNull("Complex raceManagerObjects.Athlete could not be created", a2);
        assertEquals("Name not set correctly on a2.", _name, a2.getName());
        assertEquals("RacerID not set correctly on a2.", _racerID, a2.getRacerID());
        assertEquals("Age not set correctly on a2.", _age, a2.getAge());
    }


    @Test
    public void testGetSetRacerID() {
        a1.setRacerID(_racerID);
        assertEquals("The racerID is not as expected", _racerID, a1.getRacerID());
    }

    @Test(expected=IllegalArgumentException.class)
    public void testSetRacerIDExceptionMin() {
        a1.setRacerID(-1);
    }

    @Test(expected=IllegalArgumentException.class)
    public void testSetRacerIDExceptionMax() {
        a1.setRacerID(10000001);
    }


    @Test
    public void testGetSetName() {
        a1.setName(_name);
        assertEquals("The _name is not as expected", _name, a1.getName());
    }

    @Test(expected=IllegalArgumentException.class)
    public void testSetNameExceptionNullString() {
        a1.setName(null);
    }

    @Test(expected=IllegalArgumentException.class)
    public void testSetNameExceptionEmptyString() {
        a1.setName("");
    }



    @Test
    public void testGetSetAge() {
        a1.setAge(_age);
        assertEquals("The _age is not as expected", _age, a1.getAge());
    }

    @Test(expected=IllegalArgumentException.class)
    public void testSetAgeException() {
        a1.setAge(-1);
    }


    // By making this abstract, the subclasses will be forced to implement it.
    public abstract void testPerformRaceActivity();

    /**
     * Test here for injuries to save repeated code in subclasses.
     */
    @Test(expected = AthleteInjuredException.class)
    public void testPerformRaceActivityInjuryException() {
        a2.setIsInjured(true);
        a2.performRaceActivity();
    }


    @Test
    public void testToString() {
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
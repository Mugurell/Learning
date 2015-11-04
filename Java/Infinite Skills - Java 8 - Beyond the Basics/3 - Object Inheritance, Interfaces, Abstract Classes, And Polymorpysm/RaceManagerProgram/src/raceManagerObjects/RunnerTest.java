package raceManagerObjects;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class RunnerTest extends AthleteTest
{
    private Runner r;
    private String raceActivity = new String("Running");
    private String shoes = "ordinary";


    @Override
    public Athlete getAthlete() { return new Runner(); }

    @Override
    public Athlete getComplexAthlete() {
        return new Runner(_racerID, _name, _age, shoes);
    }

    // Run a setup before any execution of each test.
    @Before
    public void setUp() throws Exception {
        r = new Runner();
    }

    // Run a teardown after the execution of each test.
    @After
    public void tearDown() throws Exception {
        r = null;
    }

    @Test
    public void testConstructors() throws Exception {
        super.testConstructors();
        Runner r2 = new Runner(_racerID, _name, _age, shoes);
        assertNotNull("Complex raceManagerObjects.Runner could not be created", r2);
        assertEquals("Not wearing the correct shoes", shoes, r2.getShoeBrand());
    }



    @Test
    public void testGetSetShoes() throws Exception {
        r.setShoeBrand(shoes);
        assertEquals("The shoe brand is not as expected", shoes, r.getShoeBrand());
    }


    @Test
    public void testPerformRaceActivity() throws Exception {
        String pra = r.performRaceActivity();
        assertTrue("Bad race activity", pra.contains(raceActivity));
    }


    @Override
    public void testToString() throws Exception {
        super.testToString();
        r.setShoeBrand(shoes);
        String rts = r.toString();
        assertTrue("toString does not contain shoes", rts.contains(shoes));
        assertTrue("toString does not contain performRaceActivity", rts.contains(raceActivity));
    }
}

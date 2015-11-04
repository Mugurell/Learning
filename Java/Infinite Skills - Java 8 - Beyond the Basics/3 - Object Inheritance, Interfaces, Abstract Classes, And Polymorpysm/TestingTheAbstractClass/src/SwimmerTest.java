/**
 * Created by petru on 12-Oct-15.
 */


import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class SwimmerTest extends AthleteTest{

    private Swimmer s;
    private String raceActivity = "Swimming";


    // Run a setup before any execution of each test
    @Before
    public void setUp() throws Exception {
        s = new Swimmer();
    }

    // Run a teardown after the execution of each test.
    // Unit testing strategies and practices:  test conditions should not cross tests!
    @After
    public void tearDown() throws Exception {
        s = null;
    }


    @Override
    public Athlete getAthlete() { return new Swimmer(); }

    @Override
    public Athlete getComplexAthlete() { return new Swimmer(_racerID, _name, _age); }


    // This will be tested in AthleteTest regarding..
//    @Test
//    public void testConstructors() throws Exception {
//        // A Swimmer does not have unique fields beside an Athlete
//        super.testConstructors();
//    }


    @Test
    public void testPerformRaceActivity() throws Exception {
        String sport = "Swimming";
        assertEquals("Not performing the correct sport", sport, s.performRaceActivity());
    }

    @Test
    public void testToString() throws Exception {
        // A Swimmer has the same fields as an Athlete
        super.toString();
        assertTrue("toString does not contain performRaceActivity", s.toString().contains(raceActivity));

    }
}
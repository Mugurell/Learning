/**
 * Created by petru on 12-Oct-15.
 */


import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class SwimmerTest {

    private Swimmer s;
    private String name = "Jill";
    private int age = 44;
    private int racerID = 319515;
    private String raceActivity = "Swimming";


    // Run a setup before any execution of each test
    @Before
    public void setUP() throws Exception {
        s = new Swimmer();
    }

    // Run a teardown after the execution of each test.
    // Unit testing strategies and practices:  test conditions should not cross tests!
    @After
    public void tearDown() throws Exception {
        s = null;
    }

    @Test
    public void testConstructors() throws Exception {
        assertNotNull("Could  not create basic Swimmer", s);
        Swimmer s2 = new Swimmer(age);
        assertNotNull("Could not create Swimmer s2", s2);
        assertEquals("RacerID could not be set for s2", age, s2.getRacerID());
        Swimmer s3 = new Swimmer(racerID, name, age);
        assertNotNull("Could not create complex Swimmer", s3);
        assertEquals("Id is not set as expected on complex constructor", racerID, s3.getRacerID());
        assertEquals("Name not set as expected on complex constructor", name, s3.getName());
        assertEquals("Age not set as expected on complex constructor", age, s3.getAge());
    }


    @Test
    public void testGetSetID() throws Exception {
        s.setRacerID(racerID);
        assertEquals("ID not set as expected", racerID, s.getRacerID());
    }

    @Test
    public void testGetSetName() throws Exception {
        s.setName(name);
        assertEquals("Name not set as expected", name, s.getName());
    }

    @Test
    public void testGetSetAge() throws Exception {
        s.setAge(age);
        assertEquals("Age not set as expected", age, s.getAge());
    }


    @Test
    public void testPerformRaceActivity() throws Exception {
        String sport = "Swimming";
        assertEquals("Not performing the correct sport", sport, s.performRaceActivity());
    }

    @Test
    public void testToString() throws Exception {
        s.setName(name);
        s.setRacerID(racerID);
        s.setAge(age);
        String outputString = s.toString();
        assertTrue("toString does not contain name", outputString.contains(name));
        assertTrue("toString does not contain id", outputString.contains(String.format("%d", racerID)));
        assertTrue("toString does not contain age", outputString.contains(Integer.toString(age)));
        assertTrue("toString does not contain performRaceActivity", outputString.contains(raceActivity));
        assertTrue("toString does not contain class", outputString.contains(s.getClass().toString()));
    }
}
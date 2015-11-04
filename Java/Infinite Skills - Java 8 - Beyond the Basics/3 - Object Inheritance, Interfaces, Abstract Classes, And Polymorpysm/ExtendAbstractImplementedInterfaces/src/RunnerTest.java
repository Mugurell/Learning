import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class RunnerTest {
    private Runner r;
    private int racerId = 1234;
    private String name = "TestName";
    private int age = 33;
    private String raceActivity = new String("Running");
    private String shoes = "ordinary";

    // Run a setup before any execution of each test.
    @Before
    public void setUp() throws Exception {
        r = new Runner(racerId, name, age, shoes);
    }

    // Run a teardown after the execution of each test.
    @After
    public void tearDown() throws Exception {
        r = null;
    }

    @Test
    public void testConstructors() throws Exception {
        Runner r2 = new Runner();
        assertNotNull("Default Runner could not be created", r2);

        Runner r3 = new Runner(racerId, name, age, shoes);
        assertNotNull("Complex Runner could not be created", r3);
        assertEquals("RacerID not set correctly on r3.", racerId, r3.getRacerID());
        assertEquals("Name not set correctly on r3.", name, r3.getName());
        assertEquals("Age not set correctly on r3.", age, r3.getAge());
        assertEquals("Not wearing the correct shoes", shoes, r3.getShoeBrand());
    }


    @Test
    public void testGetSetRacerID() throws Exception {
        r.setRacerID(racerId);
        assertEquals("The racerID is not as expected", racerId, r.getRacerID());
    }

    @Test
    public void testGetSetName() throws Exception {
        r.setName(name);
        assertEquals("The name is not as expected", name, r.getName());
    }

    @Test
    public void testGetSetAge() throws Exception {
        r.setAge(age);
        assertEquals("The age is not as expected", age, r.getAge());
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

    @Test
    public void testToString() throws Exception {
        String rts = r.toString();
        assertTrue("toString does not contain racerID", rts.contains(String.format("%d", racerId)));
        assertTrue("toString does not contain name", rts.contains(name));
        assertTrue("toString does not contain age", rts.contains(Integer.toString(age)));
        assertTrue("toString does not contain performRaceActivity", rts.contains(raceActivity));
        assertTrue("toString does not contain the shoe brand", rts.contains(shoes));
        assertTrue("toString does not contain class", rts.contains(r.getClass().toString()));
    }
}

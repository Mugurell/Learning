import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class RunnerTest {
    private Runner r;
    private int racerId = 1234;
    private String raceActivity = new String("Running");

    // Run a setup before any execution of each test.
    @Before
    public void setUp() throws Exception {
        r = new Runner(racerId);
    }

    // Run a teardown after the execution of each test.
    @After
    public void tearDown() throws Exception {
        r = null;
    }

    @Test
    public void testConstructors() {
        Runner r2 = new Runner();
        assertNotNull("Default Runner could not be created", r2);

        Runner r3 = new Runner(racerId);
        assertNotNull("Complex Runner could not be created", r3);
        assertEquals("RacerID not set correctly on r3.", racerId, r3.getRacerID());
    }


    @Test
    public void testGetSetRacerID() throws Exception {
        r.setRacerID(racerId);
        assertEquals("The racerID is not as expected", racerId, r.getRacerID());
    }


    @Test
    public void testPerformRaceActivity() throws Exception {
        String pra = r.performRaceActivity();
        assertTrue("Bad race activity", pra.contains(raceActivity));
    }

    @Test
    public void testToString() throws Exception {
        r.setRacerID(racerId);
        String rts = r.toString();
        assertTrue("toString does not contain racerID"
                , rts.contains(String.format("%d", racerId)));
        assertTrue("toString oes not contain performRaceActivity"
                , rts.contains(raceActivity));
        String rc = r.getClass().toString();
        assertTrue("toString does not contain class", rts.contains(rc));
    }
}

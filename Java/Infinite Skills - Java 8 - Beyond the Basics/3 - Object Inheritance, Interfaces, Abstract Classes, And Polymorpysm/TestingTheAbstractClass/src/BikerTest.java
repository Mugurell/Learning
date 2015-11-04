import junit.framework.TestCase;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;


public class BikerTest extends AthleteTest {
    private Biker b;
    private String raceActivity = new String("Biking");
    private boolean usesClips = true;

    // Run a setup before any execution of each test.
    @Before
    public void setUp() throws Exception {
        b = new Biker(_racerID, _name, _age, usesClips);
    }

    // Run a teardown after the execution of each test.
    @After
    public void tearDown() throws Exception { b = null; }


    @Override
    public Athlete getAthlete() { return new Biker(); }

    @Override
    public Athlete getComplexAthlete() {
        return new Biker(_racerID, _name, _age, usesClips);
    }


    @Test
    public void testConstructors() throws Exception {
        super.testConstructors();
        Biker b2 = new Biker(_racerID, _name, _age, usesClips);
        assertNotNull("Complex biker could not be created", b2);
        assertEquals("Clips not set correctly on b2", usesClips, b2.getUsesClips());
    }


    @Test
    public void testGetSetUsesClips() throws Exception {
        b.setusesClips(usesClips);
        assertEquals("UsesClips is not as expected", usesClips, b.getUsesClips());
    }


    @Test
    public void testPerformRaceActivity() throws Exception {
        String pra = b.performRaceActivity();
        assertTrue("Bad race activity", pra.contains(raceActivity));
    }

    @Test
    public void testToString() throws Exception {
        super.testToString();
        b.setusesClips(true);
        String rts = b.toString();
        assertTrue("toString does not contain performRaceActivity", rts.contains(raceActivity));
        if (b.getUsesClips())
            assertTrue("toString does not contain usesClips", rts.contains("with clips"));
        else
            assertTrue("toString does not contain usesClips", rts.contains("without clips"));
    }
}
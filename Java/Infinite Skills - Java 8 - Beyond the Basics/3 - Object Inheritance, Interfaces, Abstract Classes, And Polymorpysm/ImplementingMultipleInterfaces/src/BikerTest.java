import junit.framework.TestCase;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;
import static org.junit.Assert.assertTrue;


public class BikerTest extends TestCase {
    private Biker b;
    private int racerId = 222;
    private String name = "TestName";
    private int age = 25;
    private String raceActivity = new String("Biking");

    // Run a setup before any execution of each test.
    @Before
    public void setUp() throws Exception {
        b = new Biker(racerId, name, age);
    }

    // Run a teardown after the execution of each test.
    @After
    public void tearDown() throws Exception {
        b = null;
    }

    @Test
    public void testConstructors() throws Exception {
        Biker r2 = new Biker();
        assertNotNull("Default Biker could not be created", r2);

        Biker r3 = new Biker(racerId, name, age);
        assertNotNull("Complex Biker could not be created", r3);
        assertEquals("RacerID not set correctly on r3.", racerId, r3.getRacerID());
        assertEquals("Name not set correctly on r3.", name, r3.getName());
        assertEquals("Age not set correctly on r3.", age, r3.getAge());
    }


    @Test
    public void testGetSetRacerID() throws Exception {
        b.setRacerID(racerId);
        assertEquals("The racerID is not as expected", racerId, b.getRacerID());
    }

    @Test
    public void testGetSetName() throws Exception {
        b.setName(name);
        assertEquals("The name is not as expected", name, b.getName());
    }

    @Test
    public void testGetSetAge() throws Exception {
        b.setAge(age);
        assertEquals("The age is not as expected", age, b.getAge());
    }


    @Test
    public void testPerformRaceActivity() throws Exception {
        String pra = b.performRaceActivity();
        assertTrue("Bad race activity", pra.contains(raceActivity));
    }

    @Test
    public void testToString() throws Exception {
        b.setRacerID(racerId);
        String rts = b.toString();
        assertTrue("toString does not contain racerID"
                , rts.contains(String.format("%d", racerId)));
        assertTrue("toString does not contain name", rts.contains(name));
        assertTrue("toString does not contain age"
                , rts.contains(Integer.toString(age)));
        assertTrue("toString does not contain performRaceActivity"
                , rts.contains(raceActivity));
        String rc = b.getClass().toString();
        assertTrue("toString does not contain class", rts.contains(rc));
    }
}
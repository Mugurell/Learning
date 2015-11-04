/**
 * Created by petru on 12-Oct-15.
 */


package com.example.java;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;


public class SwimmerTest {

    Swimmer s;
    String name = "Jill";
    int racerID = 319515;


    // Run a setup before any execution of each test
    @Before
    public void setUP() throws Exception {
        s = new Swimmer();
    }

    // Run a teardown after the execution of each test.
    // Unit testing strategies and practices:  test conditions should
    // not cross tests!
    @After
    public void tearDown() throws Exception {
        s = null;
    }

    @Test
    public void testConstructors() {
        assertNotNull("Could  not create basic Swimmer", s);
        Swimmer s2 = new Swimmer(racerID, name);
        assertNotNull("Could not create complex Swimmer", s2);
        assertEquals("Name not set as expected on complex constructor"
                        , name
                        , s2.getName());
        assertEquals("Id is not set as expected on complex constructor"
                        , racerID
                        , s2.getRaceID());
    }

    @Test
    public void testGetSetName() {
        s.setName(name);
        assertEquals("Name not set as expected", name, s.getName());
    }

    @Test
    public void testGetSetID() {
        s.setRaceID(racerID);
        assertEquals("ID not set as expected", racerID, s.getRaceID());
    }

    @Test
    public void testPerformSport() {
        String sport = "Swimming";
        assertEquals("Not performing the correct sport"
            , sport
            ,s.performSport());
    }

    @Test
    public void testToString() {
        s.setName(name);
        s.setRaceID(racerID);
        String outputString = s.toString();
        assertTrue("toString does not contain name"
                , outputString.contains(name));
        assertTrue("toString does not contain id"
                , outputString.contains(String.format("%d", racerID)));
    }
}
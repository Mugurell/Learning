/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class Methods
{
    public static void main(String[] args)
    {
        //create a new runner
        Runner r = new Runner();
        r.setraceID(4321);

        // create a new swimmer (default)
        Swimmer s = new Swimmer();
        s.setRaceID(6553);

        // create a new swimmer (explicit)
        Swimmer s2 = new Swimmer(6853);

        System.out.println(r);
        System.out.println(s);
        System.out.println(s2);

        // NSE
        System.out.println("X equals Y? " + Utilities.nullSafeEquals("X", "Y"));

    }
}

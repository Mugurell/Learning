/**
 * Created by petru on 09-Oct-15.
 */

package com.example.java;

public class ConditionalOperators
{
    public static void main(String[] args)
    {
        // create a new runner
        Runner r = new Runner();
        r.setRaceID(2434);
        r.setName("Tom");

        // create a new swimmer(default)
        Swimmer s = new Swimmer();
        s.setRaceID(4325);

        // create a new swimmer(explciit)
        Swimmer s2 = new Swimmer(4562, "Jason");

        System.out.println(r);
        System.out.println(s);
        System.out.println(s2);

        // NULL Safe Equals Checks
        System.out.println("X equals Y? " + Utilities.nullSafeEquals("X", "Y"));

        System.out.println("rName = sName? "
                + Utilities.nullSafeEquals(r.getName(), s.getName()));
        System.out.println("rName = s2Name? "
                + Utilities.nullSafeEquals(r.getName(), s2.getName()));
        System.out.println("rName = Tom? "
                + Utilities.nullSafeEquals(r.getName(), "Tom"));

        System.out.println("sName = s2Name? "
                + Utilities.nullSafeEquals(r.getName(), s2.getName()));
        System.out.println("sName = rName? "
                + Utilities.nullSafeEquals(s.getName(), r.getName()));
        System.out.println("sName = null? "
                + Utilities.nullSafeEquals(s.getName(), null));

        System.out.println("s2Name = rName? "
                + Utilities.nullSafeEquals(s2.getName(), r.getName()));
        System.out.println("s2Name = sName? "
                + Utilities.nullSafeEquals(s2.getName(), s.getName()));
        System.out.println("s2Name = Jason? "
                + Utilities.nullSafeEquals(s2.getName(), "Jason"));
    }
}

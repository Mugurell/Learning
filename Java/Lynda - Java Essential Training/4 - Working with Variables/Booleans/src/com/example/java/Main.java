/**
 * Created by petru on 08-Sep-15.
 */


package com.example.java;


public class Main {

    // a static member of the class
    static boolean bDef;

    public static void main(String[] args) {

        // lower case infers a primitive variable, not an object
        // all primitive variables have default values.
        // an uninitialized boolean will always start as false
        // local variables must always be initialized, will use a var from outside
        boolean b1 = true;
        boolean b2 = false;

        System.out.println("The value of b1 is " + b1);
        System.out.println("The value of b2 is " + b2);

        // bDef is uninitialized. the default is false
        System.out.println("The value of bDef is " + bDef);

        boolean b3 = !b1;
        System.out.println("The value of b3 is " + b3);

        int i1 = 0;
        boolean before = (i1 != 0);
        System.out.println("The value of before is " + before);

        String sBoolean = "true";
        boolean parsed = Boolean.parseBoolean(sBoolean);
        System.out.println("Parsed: " + parsed);

    }

}

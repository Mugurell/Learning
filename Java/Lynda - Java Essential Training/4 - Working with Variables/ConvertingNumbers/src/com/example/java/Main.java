/**
 * Created by petru on 08-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        int intValue1 = 56;

        // when working with primitives, we're always making a copy of the value
        // and not creating a reference to the original value
        int intvalue2 = intValue1;
        System.out.println("The second value is " + intvalue2);

        // widening the type. no risk of loosing data. no special syntax needed
        long longValue1 = intValue1;
        System.out.println("The long value is " + longValue1);

        // narrowing the value to the new type
        short shortValue1 = (short) intValue1;
        System.out.println("The short value is " + shortValue1);

        // the conversion will fail
        int intValue3 = 1024;
        byte byteValue = (byte) intValue3;
        System.out.println("The byte value is " + byteValue);

        // narrowing conversion will lead to truncating the initial value
        double doubleValue = 3.99999d;
        int intValue4 = (int) doubleValue;
        System.out.println("The double value is " + intValue4);

    }

}
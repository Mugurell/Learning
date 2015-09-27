/**
 * Created by petru on 08-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        int intValue1 = 56;
        int intValue2 = 42;

        int result1 = intValue1 + intValue2;
        System.out.println("Addition: " + result1);

        int result2 = intValue1 - intValue2;
        System.out.println("Substraction: " + result2);

        int result3 = intValue1 * intValue2;
        System.out.println("Multiplication: " + result3);

        // the returned result will be a datatype that matches the widest
        // datatype of any of the parts, in this case an int
        double result4 = (double) intValue1 / intValue2;
        System.out.println("Division: " + result4);

        double result5 = (double) intValue1 % intValue2;
        System.out.println("Remainder: " + result5);

        // will round it to the nearest integer variable
        double doubleValue = -3.99999;
        long rounded = Math.round(doubleValue);
        System.out.println("Rounded: " + rounded);

        double absValue = Math.abs(doubleValue);
        System.out.println("Absolute: " + absValue);

    }

}

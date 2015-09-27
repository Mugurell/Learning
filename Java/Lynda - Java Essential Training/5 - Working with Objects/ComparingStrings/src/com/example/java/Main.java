/**
 * Created by petru on 08-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        String str1 = "Hello";
        // instead of creating another object, the compiler will point
        // the second reference variable to the original object
        // process named interning; the compiler interns the second value
        String str2 = "Hello";
        if (str1 == str2) {
            System.out.println("They match!");
        } else {
            System.out.println("They don't match!");
        }

        String str3 = "hello";
        if (str1 == str3) {
            System.out.println("They match!");
        } else {
            System.out.println("They don't match!");
        }

        String part1 = "Hello ";
        String part2 = "WORLD";
        String str4 = part1 + part2;
        String str5 = "Hello World";
        if (str4 == str5) {
            System.out.println("They match!");
        } else {
            System.out.println("They don't match!");
        }

        /*************************************************************
         *  In order to accurately compare strings in Java must use
         *  the String class's equals() or equalsIgnoreCase methods
         *************************************************************/
        // in order to accurately compare strings in Java
        // the String class's equals() or equalsIgnoreCase methods
        if (str4.equals(str5)) {
            System.out.println("They match!");
        } else {
            System.out.println("They don't match!");
        }

        if (str4.equalsIgnoreCase(str5)) {
            System.out.println("They match!");
        } else {
            System.out.println("They don't match!");
        }

    }

}

/**
 * Created by petru on 09-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        int monthNumber = 13;

        if (monthNumber >= 1 && monthNumber <= 3) {
            System.out.println("You're in quarter one!");
        } else if (monthNumber >= 4 && monthNumber <= 6) {
            System.out.println("You're in quarter two!");
        } else if (monthNumber >= 7 && monthNumber <= 9) {
            System.out.println("You're in quarter three!");
        } else if (monthNumber >= 10 && monthNumber <= 12) {
            System.out.println("You're in quarter four!");
        } else {
            System.out.println("That's an unknown month!");
        }

    }

}

/**
 * Created by petru on 08-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        String s1 = "Welcome to California!";
        System.out.println("Lenght of string: " + s1.length());

        int position = s1.indexOf("California");
        System.out.println("Position of substring: " + position);

        String sub = s1.substring(11);
        System.out.println(sub);

        String s2 = "Welcome!                ";
        int len1 = s2.length();
        System.out.println(len1);

        // trim() removes ws from both beginning / end of a string
        String s3 = s2.trim();
        System.out.println(s3.len);

    }

}

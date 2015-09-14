/**
 * Created by petru on 09-Sep-15.
 */


// Even if an error occurs the application
// should try to run to completion


package com.example.java;


public class Main {

    public static void main(String[] args) {

        String welcome = "Welcome!";
        char[] chars = welcome.toCharArray();

        try {
            char lastChar = chars[chars.length];
            System.out.println(lastChar);
        } catch (ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        }

    }

}

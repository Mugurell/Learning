package com.example.java;

/**
 * Created by petru on 08-Sep-15.
 */


public class MaxValues {

    public static void main(String[] args) {

        byte b = 127;

        System.out.println("Byte: " + b);

        if (b < Byte.MAX_VALUE) {
            b++;
        }

        System.out.println("Byte: " + b);

    }
}

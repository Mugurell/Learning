/**
 * Created by petru on 09-Sep-15.
 */


package com.example.java;


import java.util.Arrays;

public class Main {

    public static void main(String[] args) {

        System.out.println("Array of primitives");
        int ints[] = {9, 6, 3};
        Arrays.sort(ints);
        for (int i = 0; i < ints.length; i++) {
            System.out.println(ints[i]);
        }

        System.out.println("\nArray of Strings");
        String strings[] = {"Red", "Green", "Blue"};
        Arrays.sort(strings);
        for (String color : strings) {
            System.out.println(color);
        }

        System.out.println("\nSetting an initial size");
        int sized[] = new int[10];     // 10 elements default initialized
        for (int i = 0; i < sized.length; i++) {
            sized[i] = i * 100;
        }
        for (int value : sized) {
            System.out.println(value);
        }

        System.out.println("\nCopying an array");
        int copied[] = new int[5];
        // copy from sized, starting at position 5
        // to copied, starting at position 0, until position 5
        System.arraycopy(sized, 5, copied, 0, 5);
        for (int value : copied)
            System.out.println(value);

    }

}

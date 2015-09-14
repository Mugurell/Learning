/**
 * Created by petru on 09-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        String[] months = {"January", "February", "March", "April",
                           "May", "June", "July", "August", "September",
                           "October", "November", "December"};

//        for (int i = 0; i < months.length; i++) {
//            System.out.println(months[i]);
//        }

//        for (int i = months.length - 1; i >= 0; i-- ) {
//            System.out.println(months[i]);
//        }

//        for (String month : months) {
//            System.out.println(month);
//        }

//        int counter = 0;
//        while (counter < months.length) {
//            System.out.println(months[counter++]);
//        }

        int counter = 0;
        do {
            System.out.println(months[counter++]);
        } while (counter < months.length);

    }

}

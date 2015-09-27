/**
 * Created by petru on 09-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        // two dimensional array: states and their capitals
        String[][] states = new String[3][2];
        states[0][0] = "California";
        states[0][1] = "Sacramento";
        states[1][0] = "Oregon";
        states[1][1] = "Salem";
        states[2][0] = "Washington";
        states[2][1] = "Olympia";

        // length refers to the outer array
        // so this loop will be iterated 3 times
        for (int i = 0; i < states.length; i++) {
            StringBuilder sb = new StringBuilder();
            sb.append("The capitol of ")
              .append(states[i][0])
              .append(" is ")
              .append(states[i][1])
              .append(".");
            System.out.println(sb);
        }

    }

}

/**
 * Created by petru on 09-Sep-15.
 *
 * Requirements:
 *  - read value from the terminal as stirngs
 *  - convert them to the appropriate numeric types
 *  - do simple math operations with them
 *  - print the result back to the terminal
 */


package com.challenge.java;


import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // get some input
        System.out.print("Let's do some math"
                        + "\n\tPlease enter an integer: ");
        Scanner sb = new Scanner(System.in);
        String string1 = sb.nextLine();
        System.out.println("\tNow please enter a fractional number: ");
        String string2 = sb.nextLine();

        // convert the strings to appropriate primitives
        int     nr1 = Integer.parseInt(string1);

        // the fractional number will be converted from String to BigDecimal
        // double  nr2 = Double.parseDouble(string2);


        // ask for the requested mathematical operation
        System.out.println("\nNow type the symbol of the mathematical operation"
                + "\nyou want to perform with them: ");
        char operation = sb.next().charAt(0);

        // get the result with no precission loss
        BigDecimal bigNr1 = new BigDecimal(nr1);
        BigDecimal bigNr2= new BigDecimal(string2);
        BigDecimal total = new BigDecimal(0);

        switch(operation) {
            case '+':
                total = bigNr1.add(bigNr2);
                break;
            case '-':
                total = bigNr1.subtract(bigNr2);
                break;
            case '*':
                total = bigNr1.multiply(bigNr2);
                break;
            case '/':
                total = bigNr1.divide(bigNr2, 2, RoundingMode.HALF_UP);
                break;
            default:
                System.out.println("\n**Invalid requested operation**");
                break;
        }

        System.out.println("\nSo " + nr1 + operation + bigNr2 + " = " + total);
        System.out.println("\nPretty cool, huh?");

    }

}

/**
 * Created by petru on 09-Sep-15.
 */


package com.example.java;


import java.util.Scanner;

public class Main {

    static double Add(double nr1, double nr2) { return nr1 + nr2; }
    static double Subs(double nr1, double nr2) { return nr1 - nr2; }
    static double Mult(double nr1, double nr2) { return nr1 * nr2; }
    static double Div(double nr1, double nr2) { return nr1 / nr2; }

    static String getInput(String message) {
        System.out.print(message);

        Scanner sc = new Scanner(System.in);

        return sc.nextLine();
    }

    public static void main(String[] args) {
        String nr1 = getInput("Enter a numeric value: ");
        String nr2 = getInput("Enter a numeric value: ");
        String op = getInput("Choose an operation (+ - * /): ");
        double no1, no2;
        no1 = no2 = 0;
        char operation = '+';

        // test if the requested operation is valid
        try {
            char[] inputOp = op.toCharArray();
            if (inputOp.length > 1  || (inputOp[0] != '+' && inputOp[0] != '-'
                    && inputOp[0] != '*' && inputOp[0] != '/')) {

                throw new Exception("Unrecognized operation!");
            }
            operation = inputOp[0];

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        // test if both operands are valid numbers
        try {
            no1 = Double.parseDouble(nr1);
            no2 = Double.parseDouble(nr2);
        } catch (NumberFormatException e) {
            System.out.println("Invalid operand!");
        }

        // If all checks are good (valid numbers and valid operations)
        // call a simple helper function to get us the result
        double result = doMath(no1, no2, operation);

        // a little bit of formatting..
        System.out.println("\nResult:");
        for (int i = 0; i < "result:".length() ; i++) {
            System.out.print('*');
        }
        System.out.println("");
        System.out.println(no1 + " " + operation + " " + no2 + " = " + result);

    }

    static double doMath(double nr1, double nr2, char op) {
        double result = 0;
        switch (op) {
            case '+': result = Add(nr1, nr2); break;
            case '-': result = Subs(nr1, nr2); break;
            case '*': result = Mult(nr1, nr2); break;
            case '/': result = Div(nr1, nr2); break;
            default:
                System.out.println("Shouldn't be here!");
                break;
        }

        return result;
    }

}

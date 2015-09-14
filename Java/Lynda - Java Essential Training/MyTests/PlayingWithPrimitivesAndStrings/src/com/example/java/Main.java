/**
 * Created by petru on 08-Sep-15.
 */


package com.example.java;


import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws InterruptedException {

        String name;
        System.out.print("Please enter your name: ");
        Scanner scanner = new Scanner(System.in);
        name = scanner.next();

        System.out.println("Nice to meet you" + name);
        System.out.print("\nAnd how old are you?: ");

        int age = scanner.nextInt();
        System.out.println("So you're " + Integer.toString(age) + ", cool!");

    }

}

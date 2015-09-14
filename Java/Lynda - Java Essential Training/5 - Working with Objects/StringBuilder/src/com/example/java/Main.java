/**
 * Created by petru on 08-Sep-15.
 */


package com.example.java;


import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        String str1 = "Hello";
        String str2 = "World";

        // this will create 3 distinct objects
        // a lot of string concatenation can cause problems in memory management
        String str3 = str1 + ", " + str2 + "!";
        System.out.println(str3);

        // to avoid that, it is recommended to use the StringBuilder()
        // we'll create just one object instead of three
//        StringBuilder sb = new StringBuilder("Hello");
//        sb.append(", ");
//        sb.append("World");
//        sb.append("!");

        // the StringBuilder returns a reference ;-)
        StringBuilder sb = new StringBuilder("Hello")
                .append(", ").append("World").append('!');
        System.out.println(sb);

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a value: ");
        String input = scanner.nextLine();
        System.out.println(input);

        sb.delete(0, sb.length());
        for (int i = 0; i < 3; i++) {
            input = scanner.nextLine();
            sb.append(input + "\n");
        }

        System.out.println(sb);

    }

}

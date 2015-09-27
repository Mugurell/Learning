/**
 * Created by petru on 09-Sep-15.
 *
 *  When writing error-handling code, the important thing is to
 * identify all of the different exceptions that the code might generate
 * and write catch blocks for each one of those.
 *  This makes the code more robust, more likely to survive when the
 * application is running.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        String welcome = "Welcome!";
        char[] chars = welcome.toCharArray();

        try {
            char lastChar = chars[chars.length - 1];
            System.out.println(lastChar);

            // this will surely generate an exception
            String sub = welcome.substring(10);

        } catch (ArrayIndexOutOfBoundsException e) {
//            e.printStackTrace();
            System.out.println("Array index problem!");

            // because different scopes I can use the same exceptio name
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println("String index problem!");
        }

    }

}

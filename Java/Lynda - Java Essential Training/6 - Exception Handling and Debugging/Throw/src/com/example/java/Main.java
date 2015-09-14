/**
 * Created by petru on 09-Sep-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {

        String welcome = "Welcome!";
        char[] chars = welcome.toCharArray();

        try {

            if (chars.length < 10) {
                // when explicitly throw an error
                // you have to handle it one way or another
                throw (new Exception("My custom message"));
            }

            char lastChar = chars[chars.length - 1];
            System.out.println(lastChar);

            String sub = welcome.substring(10);
            System.out.println(sub);
        } catch (ArrayIndexOutOfBoundsException e) {
//            e.printStackTrace();
            System.out.println("Array index problem!");
        } catch (StringIndexOutOfBoundsException e) {
//            e.printStackTrace();
            System.out.println("String index problem!");
        } catch (Exception e) {
//            e.printStackTrace();
            System.out.println(e.getMessage());
        }

    }

}

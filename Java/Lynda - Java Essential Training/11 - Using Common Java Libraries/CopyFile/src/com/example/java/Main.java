/**
 * Created by petru on 10-Sep-15.
 *
 *   Because of the new try with resources syntax, there's no need to
 * explicitly close the created objects.
 *   If this syntax is not supported (pre Java 7), they must be instantiated
 * within the try block and then closed explicitly by calling they're close()
 * before finishing executing the code.
 */


package com.example.java;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class Main {

    public static void main(String[] args) {

        String sourceFile = "files/random.txt";
        String targetFile = "files/target.txt";

        // syntax named try with resources - introduced in Java 7
        // whenever you declare objects within the parentheses after the
        // try keyword, that means that this objects implement a method named
        // close(), or to be more accurate, an interface named AutoCloseable()
        try (
                FileReader fReader = new FileReader(sourceFile);
                // this has readLine() - very easy to read one line at a time
                BufferedReader bReader = new BufferedReader(fReader);
                FileWriter fWriter = new FileWriter(targetFile);
        ) {

            while (true) {
                // if bReader finds text it will return a string, otherwise NULL
                String line = bReader.readLine();
                if (line == null) {
                    break;
                } else {
                    // bReader.readLine ignores '\n'
                    fWriter.write(line + "\n");
                }
            }
            System.out.println("File Copied!");

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}

/**
 * Created by petru on 11-Sep-15.
 *
 *   Knowing what's in the Apache commons library can be enormously helpful.
 * A lot of the common tasks has already been solved by other Java developers,
 * who shared their solutions through Apache commons.
 */


package com.example.java;


import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {

        File sourceFile = new File("files/random.txt");
        File targetFile = new File("files/target.txt");

        // FileUtils is coming from the Apache jar
        try {
            FileUtils.copyFile(sourceFile, targetFile);
            System.out.println("File copied!");
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}

/**
 * Created by petru on 10-Sep-15.
 *
 *   In Java 7 a new IO library has been introduced, which greatly simplify
 * a lot of common operations. To be implemented in Android.
 */


package com.example.java;


import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;

public class Main {

    public static void main(String[] args) {

        // a Path object can point to either a directory or a file
        // Paths.get() takes a series of strings which allows to give it the
        // complete location without bothering with slashes etc
        Path sourceFile = Paths.get("files", "random.txt");
        Path targetFile = Paths.get("files", "target.txt");

        try {
            Files.copy(sourceFile, targetFile,
                    StandardCopyOption.REPLACE_EXISTING);
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("File Copied!");

    }

}

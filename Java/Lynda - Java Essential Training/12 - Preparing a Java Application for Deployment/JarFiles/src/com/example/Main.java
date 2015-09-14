/**
 *   A jar file is a Java archive.
 * A file in zip format that contains one or more Java classes precompiled
 * so that jar file can be run as a complete application.
 *   This is all done with a tool included in JDK called JAR
 */



package com.example;

import java.io.*;
import java.net.URL;

public class Main {

    private static final String FLOWERS_FEED =
            "http://services.hanselandpetal.com/feeds/flowers.xml";

    public static void main(String[] args) throws IOException {

        InputStream stream = null;
        BufferedInputStream buff = null;


        try {
            // there are more URL classes. Must choose the one from java.net
            URL url = new URL(FLOWERS_FEED);
            stream = url.openStream();
            buff = new BufferedInputStream(stream);

            StringBuilder sb = new StringBuilder();

            while (true) {
                // read() go and gets a character from the stream
                // if it gets it successfully - it returns a numeric value
                // if it's unsuccessful it returns -1
                int data = buff.read();

                if (data == -1)
                    break;
                else
                    sb.append((char)data);
            }

            System.out.println((sb));

            /**
             * This can be used to save the content of that xml to a local file
             */
//            File outputFile = new File("files/outputFile.txt");
//            FileWriter fWriter = new FileWriter(outputFile);
//            fWriter.write(sb.toString());

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            // because I haven't used try with resources
            // need to model the code so to close the streams explicitly
            stream.close();
            buff.close();
        }

    }

}

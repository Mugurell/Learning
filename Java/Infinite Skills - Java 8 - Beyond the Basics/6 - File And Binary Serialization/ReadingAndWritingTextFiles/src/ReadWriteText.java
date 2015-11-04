import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by petru on 26-Oct-15.
 */


public class ReadWriteText
{
    private static final String inputPath  = "src\\Racers.txt";
    private static final String outputPath = "src\\RacersModified.txt";

    public static void main(String[] args) {
        File              inputFile = new File(inputPath);
        ArrayList<String> racers    = new ArrayList<>();

        // try with resources - Java 7+
        try (Scanner input = new Scanner(inputFile);
             FileWriter fw = new FileWriter(outputPath)) {
            // Read every Racer's name from the inputPath.
            while (input.hasNextLine()) {
                String nextRacer = input.nextLine();
                racers.add(nextRacer);
                System.out.println(nextRacer + " added!");
            }

            // Write to a file using the Scanner object
            Random r = new Random();
            int max = 85, min = 20;
            for (String s : racers) {
                // Append a random age to every Racer, and write the data into the file
                int age = r.nextInt(max - min) + min + 1;   // 0 based
                fw.write(String.format("%7s - %2d\n", s, age));
            }
        } catch (IOException ioex) {
            ioex.printStackTrace();
            System.out.println("Bbye!");
        } catch (Exception ex) {
            ex.printStackTrace();
            System.out.println("This should'nt happen :-(");
        }
    }
}

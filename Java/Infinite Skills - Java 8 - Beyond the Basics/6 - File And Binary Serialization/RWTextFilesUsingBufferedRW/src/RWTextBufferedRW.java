import java.io.*;
import java.util.ArrayList;
import java.util.Random;

/**
 * Created by petru on 27-Oct-15.
 */


public class RWTextBufferedRW
{
    private static final String inputPath  = "src\\Racers.txt";
    private static final String outputPath = "src\\RacersModified.txt";
    private static final int maxAge = 60;
    private static final int minAge = 16;

    public static void main(String[] args) {
        // In order to use BufferedRW we need FileRW
        try (FileReader fr = new FileReader(inputPath);
             FileWriter fw = new FileWriter(outputPath);
             BufferedReader br = new BufferedReader(fr);
             BufferedWriter bw = new BufferedWriter(fw)) {
            String nextLine = null;
            ArrayList<String> racers = new ArrayList<>();
            Random r = new Random();

            nextLine = br.readLine();
            while ((nextLine = br.readLine()) != null) {
                System.out.println("Fresh blood: " + nextLine);
                racers.add(nextLine);
            }

            for (String each : racers) {
                int age = r.nextInt(maxAge - minAge) + minAge;   // [16 - 60)
                bw.write(String.format("%8s - %2d", each, age));
                bw.newLine();   // cool way to write a line separator
            }
            // Just printing the stackTrace to console is not good practice in production code.
            // In production code would be better to use logging, or log4j library.
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

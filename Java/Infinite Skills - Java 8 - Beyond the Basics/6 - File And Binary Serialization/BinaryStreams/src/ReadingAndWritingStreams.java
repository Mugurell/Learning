import java.io.*;
import java.util.ArrayList;

/**
 * Created by petru on 28-Oct-15.
 */


public class ReadingAndWritingStreams
{
    // Reading and writing text files using streams is possible, but not the best use of resources.
    // Basically, all files can be read at the binary level.

    public static String inFilePath  = "src\\MyData.dat";
    public static String outFilePath = "src\\MyNewData.dat";

    public static void main(String[] args) {
        try (// Used to read/write streams of raw bytes (like from images).
             FileInputStream fis = new FileInputStream(new File(inFilePath));
             FileOutputStream fos = new FileOutputStream(new File(outFilePath));
             // It reads bytes and decodes them into characters using a specified/system default charset.
             InputStreamReader ir = new InputStreamReader(fis);
             // All characters printed by a PrintStream are converted into bytes using the platform's default charset.
             // The PrintWriter class should be used in situations that require writing characters rather than bytes.
             PrintStream ps = new PrintStream(fos);
             // Reads text from a character input stream.
             BufferedReader br = new BufferedReader(ir);) {

            ArrayList<String> lines = new ArrayList<>();
            String nextLine = null;

            while ((nextLine = br.readLine()) != null) {
                lines.add(nextLine);
            }
            for (String s : lines) {
                StringBuilder sb = new StringBuilder(s);
                ps.println(sb.reverse().toString());    // print in reverse just for fun.
            }
        // Again, just printing the stackTrace is not good practice in production code!
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

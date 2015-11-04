import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by petru on 28-Oct-15.
 */


// To make this even more interesting we'll work with an image which we'll make unreadable, appearing like scrambled
// data, until we "decrypt it". This is possible because we're working on binary level.


public class ReadingAndWritingStreamsNonText
{
    private static String origImage  = "src\\img\\codeImage.png";   // original image source
    private static String encrypted = "src\\img\\data.bin";  // encrypted image
    private static String decryptImage = "src\\img\\codeImage-decrypted.png";   // decrypted image

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter a shift to encrypt/decrypt the file: ");
        int shift = Integer.parseInt(input.next());

        try {
            FileInputStream fis = null;
            FileOutputStream fos = null;
            PrintStream ps = null;

            // If shift > 0 we'll do encrypting, else we'll do decrypting.
            fis = (shift > 0 ? new FileInputStream(origImage) : new FileInputStream(encrypted));
            fos = (shift > 0 ? new FileOutputStream(encrypted) : new FileOutputStream(decryptImage));
            ps = new PrintStream(fos);

            boolean done = false;
            while (!done) {
                // read in the file
                int next = fis.read();
                if (next == -1) {   // fis.read() will return -1 if the end of the file is reached.
                    done = true;
                }
                else {
                    // encrypt or decrypt based on shift
                    ps.write(((byte) next) + shift);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("\n\tOperation Completed!");
    }
}

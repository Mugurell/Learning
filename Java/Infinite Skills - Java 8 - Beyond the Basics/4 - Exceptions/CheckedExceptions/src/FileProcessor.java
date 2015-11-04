/**
 * Created by petru on 17-Oct-15.
 */


import java.io.*;
import java.util.Scanner;


public class FileProcessor
{
    public static void main(String[] args)
    {
//        String invalid = null;
//        Validate.StringHasContent(invalid);
//
//        try {
//            Validate.StringHasContentChecked(invalid);
//        } catch (IOException e) {
//            e.printStackTrace();
//        }



        String     path = "files/data.txt";
        File       f    = new File(path);
        FileWriter fw   = null;
        try {
            Scanner input = new Scanner(f);
            int count = 0;
            while (input.hasNextLine()) {
                System.out.println(input.nextLine());
                count++;
            }
            input.close();
            fw = new FileWriter(path, true);
            fw.write("I have modified the data " + (count - 1) + " times!\n");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException ioex) {
            ioex.printStackTrace();
        } finally {
            try {
                fw.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

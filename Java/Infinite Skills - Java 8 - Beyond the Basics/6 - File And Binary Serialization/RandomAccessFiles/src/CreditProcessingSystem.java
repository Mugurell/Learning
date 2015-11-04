import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

/**
 * Created by petru on 28-Oct-15.
 */

/* At the base of all this is a RandomAccessFile object.
 * It behaves like a large array of bytes. To r/w into it, you use a file pointer which points to the beginning of
 * the block of bytes you want to work on. You access different places in this array of bytes using the seek function.
 * seek() sets the offset position, measured in bytes from the beginning of the file, at which to set the file pointer.
 */


public class CreditProcessingSystem
{
    private static final int    RECORD_LENGTH = 16;     // because using a long and a double - 8 + 8 = 16 bytes
    private static       String dataFilePath  = "src\\data\\CreditProcessingData.dat";

    public static void main(String[] args) {
        // First, if a file exists, let's load it up. Otherwise, we'll just start with a new one.
        try (RandomAccessFile cData = new RandomAccessFile(dataFilePath, "rw")) {   // open the file for r/w
            boolean done = false;
            Scanner input = new Scanner(System.in);

            // user interaction
            while (!done) {
                int choice = printMenu();
                long ccNum;
                int position;

                switch (choice) {
                    case 1:
                        // Add a new card to the end of the file.
                        CreditCard cc = getNewCardDetails();
                        cData.seek(cData.length());                 // move to the end of the file
                        cData.writeLong(cc.getCreditCardNumber());  // write a Long
                        cData.writeDouble(cc.getBalance());         // write a Double
                        System.out.println(cc.toString() + " added to the system.");
                        break;
                    case 2:
                        // Find and view.
                        System.out.println("Please enter the 16-digit number of the card to view:");
                        ccNum = Long.parseLong(input.nextLine());
                        position = findCardPosition(ccNum, cData);
                        if (position >= 0) {    // if ccNum isn't found, findCardPosition returns -1
                            System.out.println("");
                            displayCardDetails(position, cData);
                            System.out.println("");
                        }
                        else {
                            System.out.println("No card with that number found.");
                        }
                        break;
                    case 3:
                        // Update card details.
                        System.out.println("Please enter the 16-digit number of the card to view:");
                        ccNum = Long.parseLong(input.nextLine());
                        position = findCardPosition(ccNum, cData);

                        if (position >= 0) {
                            double newBalance = getBalance();
                            if (newBalance >= 0.0) {
                                cData.seek(position * RECORD_LENGTH);   // move pointer and overwrite at position
                                cData.writeLong(ccNum);
                                cData.writeDouble(newBalance);
                                System.out.println("Updated: " + ccNum + " to balance $" + newBalance);
                            }
                        }
                        else {
                            System.out.println("No card with that number found.");
                        }
                        break;
                    case 4:
                        // List all data
                        System.out.println("");
                        long totalRecords = cData.length() / RECORD_LENGTH;
                        if (totalRecords == 0) {
                            System.out.println("No current cards on file.");
                        }
                        else {
                            for (int i = 0; i < totalRecords; i++) {
                                displayCardDetails(i, cData);
                            }
                        }
                        System.out.println("");
                        break;
                    case 5:
                    default:
                        done = true;
                        break;
                }
            }

            System.out.println("Thank you for using the credit card manager");
        } catch (IOException ioex) {
            ioex.printStackTrace();
        }
    }

    private static int printMenu() {
        Scanner menuInput = new Scanner(System.in);
        System.out.println("Please select from the following choices:");
        System.out.println("Enter 1 for adding a new credit card");
        System.out.println("Enter 2 for viewing details of a credit card");
        System.out.println("Enter 3 to update card details");
        System.out.println("Enter 4 to list all cards and balances");
        System.out.println("Enter 5 to quit");
        return Integer.parseInt(menuInput.nextLine());
    }

    private static CreditCard getNewCardDetails() {
        CreditCard cc = new CreditCard();
        cc.setCreditCardNumber(getCardNumber());
        cc.setBalance(getBalance());
        return cc;
    }

    private static long getCardNumber() {
        Scanner getNumber    = new Scanner(System.in);
        String  matchPattern = "[0-9]{16}";
        boolean valid        = false;

        while (!valid) {
            System.out.println("Please enter a valid 16-digit credit card number:");
            String userNum = getNumber.nextLine();
            valid = userNum.matches(matchPattern);
            //really we should make sure not used too, but not going to worry about it.
            if (valid) {
                return Long.parseLong(userNum);
            }
        }
        return -1;
    }

    private static double getBalance() {
        Scanner getBalance = new Scanner(System.in);
        System.out.println("Please enter the current card balance:");
        return Double.parseDouble(getBalance.nextLine());
    }

    private static int findCardPosition(long cardNumber, RandomAccessFile f) throws IOException {
        // RECORD_LENGTH = long[8 bytes] + double[8 bytes] == 16 bytes
        // All records are stored in blocks of 16 bytes
        long totalRecords = f.length() / RECORD_LENGTH;

        for (int i = 0; i < totalRecords; i++) {
            f.seek(i * RECORD_LENGTH);  //move to the start of the next record (next block of 16 bytes)
            long ccNum = f.readLong();  //get the next card number
            if (ccNum == cardNumber) {  //if is a match, return i
                return i;
            }
        }
        return -1;  //if no match, return -1
    }

    private static void displayCardDetails(int position, RandomAccessFile f) throws IOException {
        f.seek(position * RECORD_LENGTH);   // move to the indicated record (block of 16 bytes)
        CreditCard cc = new CreditCard(f.readLong(), f.readDouble());   // from where read a long and then a double
        System.out.println("Card Details: " + cc.toString());
    }

}

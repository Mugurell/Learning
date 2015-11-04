import javax.smartcardio.Card;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by petru on 28-Oct-15.
 */

/* The whole deal here is reading/writing an object from/to a file in binary. Bytes.
 * So the most important methods here are: saveCardDataToFile and readCardDataFromFile.
 */


public class CreditProcessingSystem
{
    private static String dataFilePath = "src\\data\\CreditProcessingData.bin";

    public static void main(String[] args) {
        boolean done  = false;
        Scanner input = new Scanner(System.in);
        // Because all the elements of this ArrayList are serializable we'll gonna be able to save and restore this
        // entire array to/from a state file easily.
        ArrayList<CreditCard> cards = null;
        CreditCard            cc    = null;

        // user interaction
        while (!done) {
            int choice = printMenu();
            switch (choice) {
                case 1:
                    if (cards == null) {
                        cards = new ArrayList<>();
                    }
                    // add a new card to the array
                    cc = getNewCardDetails();
                    // for simplicity we'll ignore other needed checks on the received data
                    if (cc != null) {
                        cards.add(cc);
                        System.out.println(cc.toString() + " added to the system");
                    }

                    break;
                case 2:
                    if (cards == null || cards.size() == 0) {
                        System.out.println("There are currently no cards in the system.");
                    }
                    else {
                        // Find and view.
                        System.out.println("Please enter the 16-digit number of the card to view:");
                        cc = findCard(Long.parseLong(input.nextLine()), cards);
                        if (cc != null) {
                            displayCardDetails(cc);
                        }
                        else {
                            System.out.println("No card with that number found.");
                        }
                    }
                    break;
                case 3:
                    if (cards == null || cards.size() == 0) {
                        System.out.println("There are currently no cards in the system");
                    }
                    else {
                        System.out.println("Please enter the 16-digit number of the card to view:");
                        cc = findCard(Long.parseLong(input.nextLine()), cards);
                        if (cc != null) {
                            cc.setBalance(getBalance());
                        }
                        else {
                            System.out.println("No card with that number found.");
                        }
                    }
                    break;
                case 4:
                    // List all data.
                    if (cards == null || cards.size() == 0) {
                        System.out.println("There are currently no cards in the system.");
                    }
                    else {
                        System.out.println("");
                        for (CreditCard c : cards) {
                            displayCardDetails(c);
                        }
                    }
                    System.out.println("");
                    break;
                case 5:
                    // Load existing data from file.
                    cards = loadCardDataFromFile();
                    System.out.println("Loaded " + cards.size() + " cards from file into the system");
                    break;
                case 6:
                    // Save data to file.
                    saveCardDataToFile(cards);
                    System.out.println("Saved " + cards.size() + " cards to file.");
                    break;
                case 7:
                default:
                    done = true;
                    break;
            }
        }

        System.out.println("Thank you for using the credit card manager");
    }

    private static int printMenu() {
        Scanner menuInput = new Scanner(System.in);
        System.out.println("Please select from the following choices:");
        System.out.println("Enter 1 for adding a new credit card");
        System.out.println("Enter 2 for viewing details of a credit card");
        System.out.println("Enter 3 to update card details");
        System.out.println("Enter 4 to list all cards and balances");
        System.out.println("Enter 5 to load all cards from system file");
        System.out.println("Enter 6 to save all cards to system file");
        System.out.println("Enter 7 to quit");
        return Integer.parseInt(menuInput.nextLine());
    }

    private static CreditCard getNewCardDetails() {
        CreditCard cc = new CreditCard();
        cc.setCreditCardNumber(getCardNumber());
        cc.setBalance(getBalance());
        return cc;
    }

    private static CreditCard findCard(long cardNum, ArrayList<CreditCard> cards) {
        for (CreditCard cc : cards) {
            if (cc.getCreditCardNumber() == cardNum) {
                return cc;
            }
        }
        return null;
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

    private static void displayCardDetails(CreditCard cc) {
        System.out.println("Card Details: " + cc.toString());
    }

    private static ArrayList<CreditCard> loadCardDataFromFile() {
        ArrayList<CreditCard> cards = null;
        try (FileInputStream fis = new FileInputStream(dataFilePath);
            ObjectInputStream ois = new ObjectInputStream(fis)) {
            cards = ((ArrayList<CreditCard>) ois.readObject());
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return cards;
    }

    private static void saveCardDataToFile(ArrayList<CreditCard> cards) {
        try (FileOutputStream fos = new FileOutputStream(dataFilePath);
            ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeObject(cards);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}

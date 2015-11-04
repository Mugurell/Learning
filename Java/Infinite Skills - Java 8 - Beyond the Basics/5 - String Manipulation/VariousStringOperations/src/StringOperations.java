import java.util.Scanner;

/**
 * Created by petru on 25-Oct-15.
 */


public class StringOperations
{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter any verb: ");
        String aString       = input.next();
        String anotherString = " to the store!";

        // charAt (also shows length)
        for (int i = 0; i < aString.length(); i++) {
            System.out.println("[ " + i + "] " + aString.charAt(i));
        }

        // compareTo (There is also compareToIgnoreCase)
        // Will look at them in both directions
        System.out.print(aString + " compared to ZZZZ: ");
        System.out.println(aString.compareTo("ZZZZ"));
        System.out.print("ZZZZ comnpared to " + aString + ": ");
        System.out.println("ZZZZ".compareTo(aString));
        System.out.print(aString + " compare to AAAA: ");
        System.out.println(aString.compareTo("AAAA"));
        System.out.print("AAAA compare to " + aString + ": ");
        System.out.println("AAAA".compareTo(aString));
        System.out.print(aString + " compared to " + aString + ": ");
        System.out.println(aString.compareTo(aString));

        // concat
        System.out.print(aString + " concatenated to " + "\"" + anotherString + "\": " );
        System.out.println(aString.concat(anotherString));

        // contains (to tackle case sensitiveness could do toUpperCase / toLowerCase
        System.out.print("Does " + aString + " contains any letter 'r'? : ");
        System.out.println((aString.contains("r") ? "Yes!" : "No!"));
        System.out.print("Does " + aString + " contains 'wal' ? : ");
        System.out.println((aString.contains("wal") ? "Yes!" : "No!"));

        // equals and equalsIgnoreCase
        System.out.println("Does " + aString + " equals " + "anotherString?");
        System.out.println(aString.equals(anotherString));
        System.out.println(aString.equalsIgnoreCase(anotherString));
        System.out.println(anotherString.equals(aString));
        System.out.println(anotherString.equals(aString));

        // formatting
        String name = "Ted";
        int age = 32;
        double price = 3.99;
        boolean isFalse = false;
        char question = '?';
        String formattedString = String.format("%s, age %d, paid $%.2f for bread%c\t%b\n",
                                               name, age, price, question, isFalse);
        System.out.println(formattedString);

        // find indexes of any characters
        System.out.println("The first index of any r in " + aString + " is: " + aString.indexOf('r'));
        System.out.println("The first index of any g in " + aString + " is: " + aString.indexOf('g'));
        System.out.println("The last index of any r in " + aString + " is: " + aString.lastIndexOf('r'));
        System.out.println("The last index of any g in " + aString + " is: " + aString.lastIndexOf('g'));

        // replace
        System.out.println("Replace all 'r' chars in " + aString + " with '@' chars");
        System.out.println(aString.replace('r', '@').replace('R', '@'));
//        System.out.println(aString.replace('R', '@'));

        // startsWith
        System.out.println("Does " + aString + " starts with rev? " + aString.startsWith("rev"));
        System.out.println("Does " + aString + " starts with rev? " + aString.toLowerCase().startsWith("rev"));

        // substring
        System.out.println("Remove the first char of a string using substring: " + aString.substring(1));
        System.out.println("Remove the last two chars of a string using substring: "
                           + aString.substring(0, (aString.length() - 2)));
        System.out.println("Get something from the middle: " + aString.substring(2, 6));

        // toLowerCase & toUpperCase
        System.out.println(aString + " toLowerCase: " +aString.toLowerCase());
        System.out.println(aString + " toUpperCase: " +aString.toUpperCase());
    }
}

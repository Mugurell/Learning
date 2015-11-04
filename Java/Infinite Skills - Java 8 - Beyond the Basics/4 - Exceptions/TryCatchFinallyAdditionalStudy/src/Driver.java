import java.util.Scanner;

/**
 * Created by petru on 18-Oct-15.
 */


public class Driver
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        try {
            System.out.print("[Dividing by zero is illegal]"
                             + "\nEnter any number but zero: ");
            int x = Integer.parseInt(input.next());
            try {
                int y = 32 / x;
                System.out.println("32 divided by " + x + " = " + y);
            } finally {
                System.out.println("We are done with division!");
            }

            throw new RuntimeException("Custom message. To be replaced.");
        } catch (NumberFormatException nfe) {
            try {
                System.out.println("NumberFormatException happened."
                                   + "\n\tPlease enter a valid number.");
                // implementation exceeds the scope of this exercise.
            } catch (Exception ex) {
                System.out.println("Nested NFE completed");
            }
        } catch (ArithmeticException aex) {
            try {
                System.out.println("Outer arithmetic exception.");
                throw new IllegalArgumentException("IAEX thrown for fun.");
            } catch (NumberFormatException nfe) {
                System.out.println("Pretty much unreachable code here...");
            } catch (Exception ex) {
                // since we are already in a catch, we can't hit the catch at the next level
                // Would have to wrap the whole thing in a try..
              //  ex.printStackTrace();
                System.out.println(ex.getMessage());
              //  throw new RuntimeException("You can't catch this! :-P");
            } finally {
                System.out.println("Nested AEX completed");
            }
        } catch (RuntimeException rex) {
            // Won't get hit because we are already in a catch when this was thrown
            System.out.println("Runtime Exception");
//            rex.printStackTrace();
            System.out.println(rex.getMessage());
        } finally {
            System.out.println("The end of the line here.");
        }
    }
}

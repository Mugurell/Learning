import java.util.Scanner;

/**
 * Created by petru on 18-Oct-15.
 */


public class ShowCustomUncheckedExceptions
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter any number: ");
        try {
            int nr = Integer.parseInt(input.next());
            if (nr < 100) {
                throw new CustomUncheckedException("Number is too small!");
            }
        } catch (NumberFormatException nfe) {
            System.out.println("Please enter a number next time ;-)");
/*        } catch (CustomUncheckedException cuex) {
            System.out.println("My custom defined unchecked exception catched.");*/
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }
    }
}

import java.util.Scanner;

/**
 * Created by petru on 18-Oct-15.
 */


public class ShowCustomCheckedExceptions
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter a number: ");
       /* int nr = Integer.parseInt(input.next());
        if (nr < 10) {
            throw new CustomUncheckedException("Number is too small!");
          //  throw new CustomCheckedException("Number is too small!");
        }*/

        try {
            int nr = Integer.parseInt(input.nextLine());
            if (nr < 100) {
                throw new CustomCheckedException("Number is too small, please don't do this!");
            }
        } catch (NumberFormatException nfe) {
            System.out.println("Please enter a number next time! ;-)");
        } catch (CustomCheckedException ccex) {
            System.out.println(ccex.getMessage());
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }
    }
}

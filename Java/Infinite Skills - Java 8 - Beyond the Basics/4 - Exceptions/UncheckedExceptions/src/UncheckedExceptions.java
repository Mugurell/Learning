import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Created by petru on 16-Oct-15.
 */
public class UncheckedExceptions
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String name;
        int age;
        try {
            System.out.print("Please enter your name: ");
            name = input.next();
            System.out.print("Please enter your age: ");
            age = input.nextInt();
            System.out.println("Hello, " + name + ", " + age);
//        } catch (Exception ex) {
//            System.out.println(ex.toString());
        } catch (InputMismatchException mism) {
            System.out.println(mism.toString());
        }
        System.out.println("Still running...");

        try {
            int x = 10;
            System.out.print("Please enter an integer: ");
            int z = Integer.parseInt(input.nextLine());
            System.out.println(x / z);
            try {
                System.out.print("Please enter another integer: ");
                z = Integer.parseInt(input.nextLine());
                System.out.println(x / z);
            } finally {
                System.out.println("This is the nested finally");
            }
        } catch (NumberFormatException nfe) {
            System.out.println("Number format exception");
            System.out.println(nfe.toString());
        } catch (ArithmeticException ae) {
            System.out.println("Arithmetic exception");
            System.out.println(ae.toString());
        } catch (Exception ex) {
            System.out.println("Some other exception");
            System.out.println(ex.toString());
        } finally {
            System.out.println("This is the last finally");
        }
    }
}

import java.util.Scanner;


public class InputHelper
{
    public String getInput(String message) {
        Scanner sc = new Scanner(System.in);
        System.out.println(message);
        return sc.nextLine();
    }
}
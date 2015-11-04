import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by petru on 25-Oct-15.
 */


public class BasicRegexRules
{
/*
     *        '.'  ==> match any character [A-Za-z0-9!@# EXCEPT '/n'
	 *        '^{...}'  ==> match at start [^ - starts with]   //{...} denotes ANY REGEX in this key
	 *        '{...}$' ==> match at end [$ - ends with]
	 *        '[A-Za-z0-9]' ==> match any cap, any small, and 0-9 //can be separated out to each.
	 *        '[^somevalue] ==> doesn't match somevalue [^ - ANYTHING EXCEPT immediately right]
	 *        '*' ==> Match ANY number of times [0 or more]
	 *        '+' ==> Match One or more times   [1 or more]
	 *        '?' ==> 0 or 1 times only[yes or no]
	 *        '{n}' ==> match 'n' number of times [EXACTLY n times]
	 *        '\w' ==> Matches a normal char and underscore [A-Za-z0-9_  [alphanumeric or underscore]]
	 *        '\W' ==> Negates '\w' ==> Anything but alphanumeric & underscore.
	 *        '\s' ==> matches whitespace
	 *        '\S' ==> Negates 'S' =>> Anything but whitespace characters
	 *        '\d' ==> matches digit [0-9]
	 *        '+\d' ==> matches positive number
	 *        '-\d' ==> matches negative number
	 *        '-?\d' ==> matches any numbers (positive or negative)
	 */

    //lets see some of this in action
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        /**** Determine if a user entered phone number has a valid format or  not ***/
        // following regex: - an optional country prefix, the + sign and one or two positive numbers
        //                  - followed by pairs [3, 3, 4] of numbers separated or not by slashes
        String regexPhoneNumber = "(\\++?\\d{1,2})?\\d{3}-?\\d{3}-?\\d{4}";
        System.out.println("Please enter a phone number: ");
        String inPhone = input.nextLine();
        if (inPhone.matches(regexPhoneNumber)) {
            System.out.println("Thank you for entering a valid phone number!");
        }
        else {
            System.out.println("This number: " + inPhone + " does not have a valid format.");
        }


        /*** Let's determine if a string has any "invalid" characters: ***/
        // The part in square brackets is a character class - it matches exactly one of the enclosed characters.
        // So, the following regex mean: - pick one alphanumeric character, case independent, 0 or more times.
        String validCharactersRegex = "[0-9A-Za-z]*";
        System.out.println("Please enter a new password, using only letters and numbers: ");
        String inPassword = input.nextLine();
        if (inPassword.matches(validCharactersRegex)) {
            System.out.println("Your new password has been recorded!");
        }
        else {
            System.out.println("We're sorry, this password is invalid!");
        }


        /*** Now let's not allow a blank one, and make it have to be 8 characters long! ***/
        String validCharactersRegex2 = "[0-9A-Za-]{8}";
        System.out.println("Please enter a new password, using exactly any 8 letters and numbers: ");
        inPassword = input.nextLine();
        if (inPassword.matches(validCharactersRegex2)) {
            System.out.println("Your new password has been recorded!");
        }
        else {
            System.out.println("We're sorry, this password is invalid!");
        }


        /*** Now let's make it 8 chars long with at least one special character ***/
        // following regex: - exactly 7 alphanumeric characters, followed by
        //                  - exactly 1 non-alphanumeric character (because of the '^')
        String validCharactersRegex3 = "[0-9A-Za-z]{7}[^0-9A-Za-z]{1}";
        System.out.println("Please enter a new password, using exactly any 7 letters and numbers,"
                           + " and exactly one special character in it at the end: ");
        inPassword = input.nextLine();
        if (inPassword.matches(validCharactersRegex3)) {
            System.out.println("Your new password has been recorded!");
        }
        else {
            System.out.println("We're sorry, this password is invalid!");
        }


        /*** Now let's search for a partial name ***/
        String            nameStrSWB = "^B\\w*";    // string must start with 'B' and have other >=0 alphanumeric chars
        String            nameStrEWn = "\\w*n$";    // string containing >=0 alphanumeric chars ending with 'n'
        String            nameStrA   = ".*a.*";     // string that must contain 'a'; can have other alphanumeric chars
        ArrayList<String> names      = new ArrayList<String>();
        names.add("Adam");
        names.add("Jason");
        names.add("Brian");
        names.add("Suzanne");
        names.add("Melissa");
        names.add("Angie");
        names.add("Belinda");
        names.add("Becky");

        StringBuilder strSWB = new StringBuilder();
        StringBuilder strEWn = new StringBuilder();
        StringBuilder strA   = new StringBuilder();
        for (String n : names) {
            if (n.matches(nameStrSWB)) strSWB.append(n + ", ");
            if (n.matches(nameStrEWn)) strEWn.append(n + ", ");
            if (n.matches(nameStrA))   strA.append  (n + ", ");
        }
        if (strSWB.length() >= 0)
            System.out.println("Begin with 'B': "+strSWB.replace(strSWB.length()-2, strSWB.length()-1, ".").toString());
        if (strEWn.length() >= 0)
            System.out.println("Ends with 'n': "+strEWn.replace(strEWn.length()-2, strEWn.length()-1, ".").toString());
        if (strA.length() >= 0)
            System.out.println("Contains an 'a': " + strA.replace(strA.length()-2, strA.length()-1, ".").toString());
    }
}

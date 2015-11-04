/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


import java.util.Scanner;

public class Loops {

    public static void main(String[] args) {

        Runner raceRunner;
        Swimmer raceSwimmer;

        // A while loop can run 0 to n number of times based on user input
        // and start condition.
        // If we set runRaceManager = false, no loops will execute.
        boolean runRaceManager = true;
        while (runRaceManager)
        {
            int menuChoice = printMenu();
            switch (menuChoice)
            {
                case 1:
                    System.out.println("You chose to create a new Runner.");
                    raceRunner = getNewRunner();
                    System.out.println("Your Runner, " + raceRunner.toString());
                    break;
                case 2:
                    System.out.println("You chose to create a new Swimmer.");
                    raceSwimmer = getNewSwimmer();
                    System.out.println("Your Swimmer, "
                            + raceSwimmer.toString());
                    break;
                case 3:
                    System.out.println("Thank you for using this interface!");
                    break;
                default:
                    break;
            }
            runRaceManager = false;
        }

        System.out.println("\n*************LOOP 1 COMPLETED**************\n");

        // do..while loops will run at least once, then continue n times
        do
        {
            // Remember, from exit of the last loop, RRM is false, but this will
            // still execute once.
            // Set to true if you want more than one execution
            // runRaceManager = true;
            int menuChoice = printMenu();
            switch (menuChoice)
            {
                case 1:
                    System.out.println("You chose to create a new Runner.");
                    raceRunner = getNewRunner();
                    System.out.println("Your Runner, " + raceRunner.toString());
                    break;
                case 2:
                    System.out.println("You chose to create a new Swimmer.");
                    raceSwimmer = getNewSwimmer();
                    System.out.println("Your Swimmer, "
                            + raceSwimmer.toString());
                    break;
                case 3:
                    System.out.println("Thank you for using this interface!");
                    break;
                default:
                    break;
            }
        } while (runRaceManager);

        System.out.println("\n*************LOOP 3 COMPLETED**************\n");

        // for loops run a specific set of times no matter what
        for (int i = 0; i < 4; i++)
        {
            int menuChoice = printMenu();
            switch (menuChoice)
            {
                case 1:
                    System.out.println("You chose to create a new Runner.");
                    raceRunner = getNewRunner();
                    System.out.println("Your Runner, " + raceRunner.toString());
                    break;
                case 2:
                    System.out.println("You chose to create a new Swimmer.");
                    raceSwimmer = getNewSwimmer();
                    System.out.println("Your Swimmer, "
                            + raceSwimmer.toString());
                    break;
                case 3:
                    System.out.println("Thank you for using this interface!");
                    break;
                default:
                    break;
            }
        }

        System.out.println("\n*************LOOP 2 COMPLETED**************\n");


    }


    /**
     * Print the options menu
     * @return the int selected by the user for menu options
     */
    public static int printMenu()
    {
        Scanner input = new Scanner(System.in);
        System.out.println("\n\n*************************************");
        System.out.println("* Welcome to the great Race Manager *");
        System.out.println("*************************************");
        System.out.println("What would you like to do today?");
        System.out.println("-------------------------------------");
        System.out.println("Enter '1' to add a new Runner");
        System.out.println("Enter '2' to add a new Swimmer");
        System.out.println("Enter '3' to quit");
        System.out.println("-------------------------------------");
        System.out.println("*************************************");

        int result = Integer.parseInt(input.nextLine());
        return result;
    }


    /**
     * Get a new Runner from the user
     * @return Runner with details as enetered by the user
     */
    public static Runner getNewRunner()
    {
        Scanner input = new Scanner(System.in);
        Runner r = new Runner();
        System.out.print("Please enter the name of the Runner: ");
        r.setName(input.next());
        System.out.print("Please enter the raceID of the Runner: ");
        r.setRaceID(Integer.parseInt(input.next()));

        return r;
    }


    /**
     * Get a new Swimmer from the user
     * @return Swimmer with details as enetered by the user
     */
    public static Swimmer getNewSwimmer()
    {
        Scanner input = new Scanner(System.in);
        Swimmer s = new Swimmer();
        System.out.print("Please enter the name of the Swimmer: ");
        s.setName(input.next());
        System.out.print("Please enter the raceID of the Swimmer: ");
        s.setRaceID(Integer.parseInt(input.next()));

        return s;
    }

}

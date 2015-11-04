/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


import java.util.ArrayList;
import java.util.Scanner;


public class BasicDataStructures {

    public static void main(String[] args) {

        // final has the same meaning as const in C++
        final int MAX_RACE_RUNNERS = 5;
        Runner[] raceRunners = new Runner[MAX_RACE_RUNNERS];
        int raceRunnersCount = 0;
        // the advantage of an ArrayList is that it is automatically resizing
        // itself as we go
        ArrayList<Swimmer> raceSwimmers = new ArrayList<>();

        boolean runRaceManager = true;
        while (runRaceManager) {
            int menuChoice = printMenu();
            switch (menuChoice) {
                case 1:
                    System.out.println("You chose to create a new Runner.");
                    if (raceRunnersCount < MAX_RACE_RUNNERS) {
                        raceRunners[raceRunnersCount++] = getNewRunner();
                    }
                    else {
                        System.out.println("\n!!! The race is full. "
                            + "No runners can be added!!!");
                    }
                    break;
                case 2:
                    System.out.println("You chose to create a new Swimmer.");
                    raceSwimmers.add(getNewSwimmer());
                    break;
                case 3:
                    System.out.println("Thank you for using this interface!");
                    runRaceManager = false;
                    break;
                default:
                    System.out.println("Shouldn't be here! :-|");
                    break;
            }
        }

        System.out.println("\n*****************Results*****************");
        System.out.println("Runners:");
        for (int i = 0; i < raceRunnersCount; i++) {
            System.out.print("\t" + raceRunners[i]);
        }
        System.out.println("Swimmers:");
        for (int i = 0; i < raceSwimmers.size(); i++) {
            System.out.print("\t" + raceSwimmers.get(i));
        }

    }   // main


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

package raceManagerSystem;

import java.util.ArrayList;
import java.util.Scanner;

import raceManagerObjects.*;
import raceManagerSearching.AthleteFindByPartialName;
import raceManagerSearching.AthleteFindByRacerID;
import raceManagerSearching.AthleteFindByType;
import raceManagerSearching.AthleteFinder;

public class Program
{
    public static final int _menuStars = 70;
    private static Race    _race;
    private static Scanner _input;

    public static void main(String[] args) {
        _input = new Scanner(System.in);
        printWelcome();
        boolean completedEntries = false;
        while (!completedEntries) {
            int choice = printMenu();
            switch (choice) {
                case 1:
                    //create a new race
                    _race = new Race();
                    System.out.println("Created a new Race");
                    break;
                case 2:
                    if (checkRaceCreated()) {
                        //add a racer
                        System.out.println("What is the racer name?");
                        String n = _input.nextLine();
                        System.out.println("What is the racer's age?");
                        int a = Integer.parseInt(_input.nextLine());
                        System.out.println("What type of racer is this [B, R, S]?");
                        String t = _input.nextLine();
                        Athlete aRacer = null;
                        if (t.equalsIgnoreCase("b")) {
                            System.out.println("Does this biker use clips [y/n]?");
                            String uci = _input.nextLine();
                            boolean uc = false;
                            if (uci.charAt(0) == 'y' || uci.charAt(0) == 'Y') {
                                uc = true;
                            }
                            aRacer = new Biker(0, n, a, uc);
                        }
                        else if (t.equalsIgnoreCase("s")) {
                            aRacer = new Swimmer(0, n, a);
                        }
                        else {
                            //default to runner
                            System.out.println("What brand of shoes does this runner use?");
                            String shoes = _input.nextLine();
                            aRacer = new Runner(0, n, a, shoes);
                        }

                        if (aRacer != null) {
                            boolean addRacer = _race.addRacer(aRacer);
                            if (addRacer) {
                                printRacer("Successfully added racer: ", aRacer);
                            }
                            else {
                                System.out.println("Could not add the racer!");
                            }
                        }
                    }
                    else {
                        System.out.println("You must create the race first.");
                    }
                    break;
                case 3:
                    //remove a racer
                    if (checkRaceCreated()) {
                        System.out.println("What is the name of the racer to remove?");
                        String n = _input.nextLine();
                        boolean removed = _race.removeRacer(n);
                        if (removed) {
                            System.out.println("Successfully Removed Athlete " + n);
                        }
                        else {
                            System.out.println("Could not remove athlete with name: " + n);
                        }
                    }
                    else {
                        System.out.println("You must create the race first.");
                    }
                    break;
                case 4:
                    if (checkRaceCreated()) {
                        //find a racer by name, ID, or type
                        int findByChoice = printFindMenu();
                        String matchVariable = null;
                        AthleteFinder af = null;
                        switch (findByChoice) {
                            case 1:
                                //find by name
                                System.out.println("Please enter the name or partial name to match: ");
                                matchVariable = _input.nextLine();
                                af = new AthleteFindByPartialName(matchVariable);
                                break;
                            case 2:
                                //find by id
                                System.out.println("Please enter the racer id to match: ");
                                matchVariable = _input.nextLine();
                                af = new AthleteFindByRacerID(Integer.parseInt(matchVariable));
                                break;
                            case 3:
                                //find by type
                                int typeChoice = printTypeChoiceMenu();
                                switch (typeChoice) {
                                    case 1:
                                        matchVariable = "runner";
                                        break;
                                    case 2:
                                        matchVariable = "biker";
                                        break;
                                    case 3:
                                        matchVariable = "swimmer";
                                        break;
                                    default:
                                        break;
                                }
                                af = new AthleteFindByType(matchVariable);
                                break;
                            default:
                                break;
                        }
                        //find all matching racers
                        ArrayList<Athlete> athletes = _race.findMatchingAthletes(af);
                        for (Athlete a : athletes) {
                            printRacer("Athlete Match Found: ", a);
                        }
                    }
                    else {
                        System.out.println("You must create the race first.");
                    }
                    break;
                case 5:
                    if (checkRaceCreated()) {
                        //get winner
                        Athlete a = _race.getWinner();
                        if (a != null) {
                            printRacer("The winner is: ", a);
                        }
                    }
                    else {
                        System.out.println("You must create the race first.");
                    }
                    break;
                case 6:
                    if (checkRaceCreated()) {
                        Athlete[] racers = (Athlete[]) _race.getRacers();
                        if (racers != null && racers.length > 0) {
                            for (Athlete a : racers) {
                                printRacer("Next racer: ", a);
                            }
                        }
                        else {
                            System.out.println("Please add some racers first.");
                        }
                    }
                    else {
                        System.out.println("You must create the race first.");
                    }
                    break;
                case 7:
                default:
                    //quit
                    completedEntries = true;
            }
        }
        printCompleted();
    }

    private static int printMenu() {
        stars(_menuStars);
        System.out.println("Enter 1 to create a new race");
        System.out.println("Enter 2 to add a new racer");
        System.out.println("Enter 3 to remove a racer");
        System.out.println("Enter 4 to find a racer");
        System.out.println("Enter 5 to get the winner");
        System.out.println("Enter 6 to list the racers");
        System.out.println("Enter 7 to quit");
        stars(_menuStars);
        return Integer.parseInt(_input.nextLine());
    }

    private static int printFindMenu()
    {
        stars(_menuStars);
        System.out.println("Enter 1 to find by name");
        System.out.println("Enter 2 to find by Id");
        System.out.println("Enter 3 to find by type");
        stars(_menuStars);
        return Integer.parseInt(_input.nextLine());
    }

    private static int printTypeChoiceMenu()
    {
        stars(_menuStars);
        System.out.println("Enter 1 to find Runners");
        System.out.println("Enter 2 to find Bikers");
        System.out.println("Enter 3 to find Swimmers");
        stars(_menuStars);
        return Integer.parseInt(_input.nextLine());
    }

    private static void printRacer(String message, Athlete a) {
        dashes(_menuStars);
        String outputDetails = "[%s] Name: %s Age: %d RacerId: %d Activity: %s %s";
        String t             = null;
        String extra         = null;
        if (a instanceof Runner) {
            t = "Runner";
            Runner r = (Runner) a;
            extra = "Shoes: " + r.getShoeBrand();
        }
        else if (a instanceof Biker) {
            t = "Biker";
            Biker b = (Biker) a;
            extra = "Using clips: " + b.getUsesClips();
        }
        else if (a instanceof Swimmer) {
            t = "Swimmer";
            extra = "";
        }
        System.out.println(String.format(outputDetails
                , t
                , a.getName()
                , a.getAge()
                , a.getRacerID()
                , a.performRaceActivity()
                , extra));
        dashes(_menuStars);
    }

    private static boolean checkRaceCreated() {
        return _race != null;
    }

    private static void printWelcome() {
        stars(_menuStars);
        System.out.println("Welcome to this Race Manager.");
        System.out.println("What would you like to do today?");
        stars(_menuStars);
    }

    private static void printCompleted() {
        stars(_menuStars);
        System.out.println("Thank you for using this Race Manager");

        stars(_menuStars);
    }

    private static void stars(int num) {
        for (int i = 0; i < num; i++) {
            System.out.print("*");
        }
        System.out.print("\n");
    }

    private static void dashes(int num) {
        for (int i = 0; i < num; i++) {
            System.out.print("-");
        }
        System.out.print("\n");
    }
}

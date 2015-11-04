import com.sun.org.apache.bcel.internal.generic.SWAP;

import java.util.Random;

/**
 * Created by petru on 01-Nov-15.
 */


public class Driver
{
    private static int[]    myInts;
    private static String[] myStrings;
    private static Animal[] myAnimals;
    private static final int SIZE = 10;

    public static void main(String[] args) {
        resetInts();
        resetStrings();
        resetAnimals();

        /*** Turn this on to see defaults: ***/
//        printInts();
//        printsStrings();
//        printAnimals();

        Random r = new Random();
        int p1 = r.nextInt(9);
        int p2 = r.nextInt(9);
        while (p1 == p2) {
            p2 = r.nextInt(9);
        }
        System.out.println("P1: " + p1);
        System.out.println("P2: " + p2);

        System.out.println("**************** NON-GENERIC SWAPS ***************");
        // Non-generic methods. No animals here!
        swapInts(p1, p2, myInts);
        printInts();

        System.out.println("******************* GENERIC SWAPS ******************");
        // Can't use primitives in Generics
        resetInts();
//        swapItems(p1, p2, myInts);
        Integer[] myIntegers = new Integer[SIZE];
        for (int i = 0; i < SIZE; i++) {
            myIntegers[i] = ((Integer) myInts[i]);
        }
        swapItems(p1, p2, myIntegers);
        for (Integer i : myIntegers) {
            System.out.println("Next Integer: " + i);
        }

        resetStrings();
        swapItems(p1, p2, myStrings);
        printStrings();

        resetAnimals();
        swapItems(p1, p2, myAnimals);
        printAnimals();

        // Can you define a generic print method and use that instead?
        // Of course, but you would need to use getClass() to tell what type
        printItems(myStrings);
        printItems(myAnimals);
    }


    private static void resetInts() {
        myInts = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            myInts[i] = i + 1;
        }
    }

    private static void printInts() {
        for (int i : myInts) {
            System.out.println("Next int: " + i);
        }
    }

    private static void resetStrings() {
        myStrings = new String[]{"The", "Quick", "Brown", "Fox", "Jumps", "Over", "The", "Lazy", "Dogs"};
    }

    private static void printStrings() {
        for (String s : myStrings) {
            System.out.println("Next String: " + s);
        }
    }

    private static void resetAnimals() {
        myAnimals = new Animal[SIZE];
        myAnimals[0] = new Animal("Antilope");
        myAnimals[1] = new Animal("Bear");
        myAnimals[2] = new Animal("Chipmunk");
        myAnimals[3] = new Animal("Dog");
        myAnimals[4] = new Animal("Eagle");
        myAnimals[5] = new Animal("Frog");
        myAnimals[6] = new Animal("Giraffe");
        myAnimals[7] = new Animal("Hedgehog");
        myAnimals[8] = new Animal("Ibex");
        myAnimals[9] = new Animal("Jaguar");
    }

    private static void printAnimals() {
        for (Animal a : myAnimals) {
            System.out.println("Next Animal: " + a);
        }
    }

    public static void swapStrings(int p1, int p2, String[] strings) {
        String temp = strings[p1];
        strings[p1] = strings[p2];
        strings[p2] = temp;
    }

    public static void swapInts(int p1, int p2, int[] ints) {
        int temp = ints[p1];
        ints[p1] = ints[p2];
        ints[p2] = temp;
    }


    // Generic swap method
    public static <T> void swapItems(int p1, int p2, T[] items) {
        T temp    = items[p1];
        items[p1] = items[p2];
        items[p2] = temp;
    }


    // Generic item printer
    public static <T> void printItems(T[] items) {
        for (T item : items) {
            System.out.println("Next " + item.getClass().getName() + ": " + item);
        }
    }


}

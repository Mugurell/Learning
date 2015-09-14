/**
 * Created by petru on 10-Sep-15.
 *
 *   An interface is a contract, it defines a set of methods with particular
 * signatures, and any class that implements that interface MUST implement those
 *   It is somewhat common to see interfaces used directly, but for this
 * all of the interface methods must be implemented in that compilation unit.
 *
 *   An abstract class is abstract because it contains the abstract keyword.
 * After that, it can have a mix of fully implemented methods and abstract ones.
 *   An abstract class cannot be instantiated directly,
 * only their subclasses can be instantiated.
 *
 *   Whether to use anstract classes or interfaces is frequently
 * just a matter of personal preferences.
 *
 *   Javadoc's job is to extract documentation about the Java application,
 * including information directly drawn from the code, but also from comments.
 */


package com.example.java;


import com.example.java.model.*;

import java.util.ArrayList;
import java.util.List;

/**
 * This is an <b>olive press</b> application,
 * and it's job is to <i>press olives</i>!
 */
public class Main {

    /**
     * The main method
     * @param args - an array of string values
     */
    public static void main(String[] args) {

        List<Olive> olives = new ArrayList<>();

        olives.add(new Kalamata());
        olives.add(new Kalamata());
        olives.add(new Ligurian());
        olives.add(new Ligurian());
        olives.add(new Ligurian());
        olives.add(new Ligurian());

        /**
         * Press is an interface!
         */
        Press press = new OlivePress();
        press.setOil(5);
        int totalOil = press.getOil(olives);
        System.out.println("\nYou got " + totalOil + " units of oil");

        // An interface can be instantiated directly.
        // But for this, all the code must be implemented.
//        Press p2 = new Press() {
//            @Override
//            public int getOil(List<Olive> olives) {
//                return 0;
//            }
//
//            @Override
//            public void setOil(int oil) {
//
//            }
//        }

    }

}

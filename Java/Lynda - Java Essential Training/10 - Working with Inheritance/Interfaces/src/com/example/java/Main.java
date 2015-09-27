/**
 * Created by petru on 10-Sep-15.
 *
 *   An interface is a contract, it defines a set of methods with particular
 * signatures, and any class that implements that interface MUST implement those
 *   An abstract class is one that has defined what a method looks like,
 * but doesn't have the method body in which to say how it's supposed to work.
 */


package com.example.java;


import com.example.java.model.*;

import java.util.ArrayList;
import java.util.List;


public class Main {

    public static void main(String[] args) {

        List<Olive> olives = new ArrayList<>();

        olives.add(new Kalamata());
        olives.add(new Kalamata());
        olives.add(new Ligurian());
        olives.add(new Ligurian());
        olives.add(new Ligurian());
        olives.add(new Ligurian());

        // Press is an interface
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

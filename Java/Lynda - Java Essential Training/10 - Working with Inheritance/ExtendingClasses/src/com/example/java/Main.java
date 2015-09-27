/**
 * Created by petru on 10-Sep-15.
 *
 *   An enum class is used as a list of possible values that can be used
 * for any particular variable.
 *   The enum class can be created either in it's own separate code file,
 * or as a nested enum if it's only going to be used in only one Java class.
 *   Just as with constants (the final keyword) the naming convention
 * is to use all upper case.
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

        OlivePress press = new OlivePress();
        int totalOil = press.getOil(olives);
        System.out.println("\nYou got " + totalOil + " units of oil");

    }

}

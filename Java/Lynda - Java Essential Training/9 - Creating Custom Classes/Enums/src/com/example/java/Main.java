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


import com.example.java.model.OLiveName;
import com.example.java.model.Olive;

import java.util.ArrayList;
import java.util.List;


public class Main {

    public static void main(String[] args) {

        List<Olive> olives = new ArrayList<>();

        olives.add(new Olive(OLiveName.KALAMATA, 0x2E0854, 3));
        olives.add(new Olive(OLiveName.KALAMATA, 0x2E0854, 3));
        olives.add(new Olive(OLiveName.LIGURIAN, 0x000000, 2));
        olives.add(new Olive(OLiveName.LIGURIAN, 0x000000, 2));
        olives.add(new Olive(OLiveName.LIGURIAN, 0x000000, 2));
        olives.add(new Olive(OLiveName.LIGURIAN, 0x000000, 2));

        OlivePress press = new OlivePress();
        int totalOil = press.getOil(olives);
        System.out.println("\nTotal oil: " + totalOil);

    }

}

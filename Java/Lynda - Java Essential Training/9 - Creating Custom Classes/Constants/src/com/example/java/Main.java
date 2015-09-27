/**
 * Created by petru on 10-Sep-15.
 * <p>
 * In Java, the const keyword exists, but it is not implemented.
 * Java developers use the final keyword to signal that a variable's value
 * can only be set once !
 */


package com.example.java;


import com.example.java.model.Olive;

import java.util.ArrayList;
import java.util.List;


public class Main {

    public static void main(String[] args) {

        List<Olive> olives = new ArrayList<>();

        olives.add(new Olive(Olive.KALAMATA, 0x2E0854, 3));
        olives.add(new Olive(Olive.KALAMATA, 0x2E0854, 3));
        olives.add(new Olive(Olive.LIGURIAN, 0x000000, 2));
        olives.add(new Olive(Olive.LIGURIAN, 0x000000, 2));
        olives.add(new Olive(Olive.LIGURIAN, 0x000000, 2));
        olives.add(new Olive(Olive.LIGURIAN, 0x000000, 2));

        OlivePress press = new OlivePress();
        int totalOil = press.getOil(olives);
        System.out.println("\nTotal oil: " + totalOil);

    }

}

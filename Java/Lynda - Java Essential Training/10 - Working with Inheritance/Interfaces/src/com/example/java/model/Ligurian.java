package com.example.java.model;

/**
 * Created by petru on 10-Sep-15.
 */


// by default, the sublass expects there's a no argument constructor
// int it's superclass.
public class Ligurian extends Olive {

    public Ligurian() {
        // the keyword super is actually a method call
        super(OLiveName.LIGURIAN, OliveColor.BLACK, 5);
    }
}

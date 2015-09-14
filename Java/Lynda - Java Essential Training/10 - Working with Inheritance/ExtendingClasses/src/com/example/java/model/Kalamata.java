package com.example.java.model;

/**
 * Created by petru on 10-Sep-15.
 */


// by default, the sublass expects there's a no argument constructor
// int it's superclass.
public class Kalamata extends Olive {

    public Kalamata() {
        // the keyword super is actually a method call
        super(OLiveName.KALAMATA, OliveColor.PURPLE, 2);
    }
}

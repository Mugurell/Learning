package com.example.java.model;

/**
 * Created by petru on 10-Sep-15.
 *
 * In Java, the const keyword exists, but it is not implemented.
 * Java developers use the final keyword to signal that a variable's value
 * can only be set once !
 */


// each instance will represent a single olive. yeah.
public class Olive {

    // the enum becomes a type of it's own
    private OLiveName name = OLiveName.KALAMATA;
    private OliveColor color = OliveColor.PURPLE;
    private int oil = 3;

    // will not do anything; just to satisfy the compiler's rules
//    public Olive() {}

    public Olive(OLiveName name, OliveColor color, int oil) {
        this.name = name;
        this.color = color;
        this.oil = oil;
    }

    public OLiveName getName() {
        return name;
    }

    public void setName(OLiveName name) {
        this.name = name;
    }

    public OliveColor getColor() {
        return color;
    }

    public void setColor(OliveColor color) {
        this.color = color;
    }

    public int crush() {
        System.out.println("Ouch!");
        return oil;
    }

    public void setOil(int oil) {
        this.oil = oil;
    }
}

package com.example.java.model;

/**
 * Created by petru on 10-Sep-15.
 *
 * In Java, the const keyword exists, but it is not implemented.
 * Java developers use the final keyword to signal that a variable's value
 * can only be set once !
 */


// each instance will represent a single olive. yeah.
public abstract class Olive {

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
        // this is calling getOrigin() although it doesn't know what the result
        // is gonna be, because the subclasses have that specific information
        String msg = name + ", from " + getOrigin() + ": " + oil + " units";
        System.out.println(msg);
        return oil;
    }

    public void setOil(int oil) {
        this.oil = oil;
    }


    // an abstract method.
    // the olive class itself doesn't have an origin
    // every subclass of this class must declare it's "origin"
    public abstract String getOrigin();


    @Override
    public String toString() {
        return name.toString();
    }
}

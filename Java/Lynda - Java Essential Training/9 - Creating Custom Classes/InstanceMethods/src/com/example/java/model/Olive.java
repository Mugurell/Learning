package com.example.java.model;

/**
 * Created by petru on 10-Sep-15.
 *
 * "model" is a common bit of Java vocabulary
 * A model class defines your data model.
 */


// each instance will represent a single olive. yeah.
public class Olive {

    private String name = "Kalimata";
    private long color = 0x2E0854;  // dark purple
    private int oil = 3;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getColor() {
        return color;
    }

    public void setColor(long color) {
        this.color = color;
    }

    public int crush() {
        System.out.println("Ouch");    // what an olive says when you crush it
        return oil;
    }

    public void setOil(int oil) {
        this.oil = oil;
    }

}

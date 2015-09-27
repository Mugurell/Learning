package com.example.java.model;

/**
 * Created by petru on 10-Sep-15.
 */


public enum OliveColor {
    PURPLE("Purple", 0x2E0854),
    BLACK("Black", 0x000000),
    GREEN("Green", 0x00FF00);

    String name;
    long color;

    OliveColor(String name, long color) {
        this.name = name;
        this.color = color;
    }

    @Override
    public String toString() {
        return name;
    }
}

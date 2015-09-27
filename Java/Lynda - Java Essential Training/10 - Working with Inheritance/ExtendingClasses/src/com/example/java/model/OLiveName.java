package com.example.java.model;

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


public enum OLiveName {
    KALAMATA("Kalimata"), LIGURIAN("Ligurian");

    private String name;

    OLiveName(String name) {
        this.name = name;
    }

    // every Java class and enum has a toString method !
    // the default toString method of an enum simply translates the identifier
    @Override
    public String toString() {
        return name;
    }
}
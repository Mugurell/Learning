/**
 * Created by petru on 13-Oct-15.
 */

package com.example.java;


public class Cat extends Animal {
    private boolean _isDeclawed;

    public Cat() {
        // Call directly the default constructor of the superclass
        // By default, this is already in place
        super();
    }

    public Cat(String name, String breed, boolean isDeclawed) {
        super(name, breed);
        _isDeclawed = isDeclawed;
    }

    public String toString() {
        return String.format("%s\tIs declawed: %b"
                                , super.toString()
                                , _isDeclawed);
    }
}

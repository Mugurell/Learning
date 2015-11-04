/**
 * Created by petru on 13-Oct-15.
 */


package com.example.java;


public class Dog extends Animal {
    private boolean _isServiceAnimal;
    public Dog() { /* do nothing*/ }

    public Dog(String name) { super(name); }

    public Dog(String name, String breed, boolean isServiceAnimal) {
        super(name, breed);
        _isServiceAnimal = isServiceAnimal;
    }

    public String toString() {
        return String.format("%s\tIs a service animal: %b\n"
                , super.toString()
                , _isServiceAnimal);
    }
}

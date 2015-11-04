/**
 * Created by petru on 13-Oct-15.
 */


package com.example.java;


public class Dog extends Animal {
    private boolean _isServiceAnimal;

    /**
     * Default Dog.
     */
    public Dog() { /* do nothing*/ }

    /**
     * Simple constructor for Dog.
     * @param name String name of this Dog
     */
    public Dog(String name) { super(name); }

    /**
     * Complex Dog.
     * @param name  String name of this Dog.
     * @param breed  String breed of this Dog
     * @param isServiceAnimal  boolean is a service animal.
     */
    public Dog(String name, String breed, boolean isServiceAnimal) {
        super(name, breed);
        _isServiceAnimal = isServiceAnimal;
    }

    /**
     * Set if this Dog is a service animal or not.
     * @param value  boolean is a service animal or not.
     */
    public void setIsServiceAnimal(boolean value) {
        _isServiceAnimal = value;
    }

    /**
     * Get if this Dog a service animal.
     * @return boolean  indicate if this is a service animal or not
     */
    public boolean getIsServiceAnimal() {
        return _isServiceAnimal;
    }

    /**
     * Return this Dog as a String.
     * @return String representing all Dog's properties
     */
    public String toString() {
        return String.format("%s\tIs a service animal: %b\n"
                , super.toString()
                , _isServiceAnimal);
    }
}

/**
 * Created by petru on 13-Oct-15.
 */

package com.example.java;


public class Cat extends Animal {
    private boolean _isDeclawed;

    /**
     * Default Cat.
     */
    public Cat() {
        // Call directly the default constructor of the superclass
        // By default, this is already in place
        super();
    }

    /**
     * Explicit Cat constructor.
     * @param name String name of the Cat.
     * @param breed String breed of the Cat.
     * @param isDeclawed boolean is the Cat declawed.
     */
    public Cat(String name, String breed, boolean isDeclawed) {
        super(name, breed);
        _isDeclawed = isDeclawed;
    }

    /**
     * Get if the cat is declawed or not.
     * @return boolean value for isDeclawed.
     */
    public boolean getIsDeclawed() { return _isDeclawed; }

    /**
     * Set if this Cat is declawed or not
     * @param value boolean to indicate if the cat is declawed or not.
     */
    public void setIsDeclawed(boolean value) { _isDeclawed = value; }

    /**
     * Return the Cat as a String.
     * @return String representing all this Cat's properties
     */
    public String toString() {
        return String.format("%s\tIs declawed: %b\n"
                                , super.toString()
                                , _isDeclawed);
    }
}

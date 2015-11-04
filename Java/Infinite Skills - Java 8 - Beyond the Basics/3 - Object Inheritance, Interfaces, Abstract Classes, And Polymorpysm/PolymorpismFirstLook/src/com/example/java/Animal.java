/**
 * Created by petru on 13-Oct-15.
 */


package com.example.java;


public class Animal {

    private String _name;
    private String _breed;

    /**
     * Default Animal.
     */
    Animal() { }

    /**
     * Simple Animal.
     * @param name String representing the Animal's name
     */
    Animal(String name) { _name = name; }

    /**
     * Complex Animal.
     * @param name String representing the Animal's name.
     * @param breed String representing the Animal's breed.
     */
    Animal(String name, String breed) { _name = name; _breed = breed; }

    /**
     * Set the name of the Animal.
     * @param newName String representing the name.
     */
    public void setName(String newName) { _name = newName; }

    /**
     * Set the breed of the Animal.
     * @param newBreed String representing the breed.
     */
    public void setBreed(String newBreed) { _breed = newBreed; }

    /**
     * Get the name of the Animal.
     * @return String representing the name.
     */
    public String getName() { return _name; }

    /**
     * Get the breed of the Animal.
     * @return String representing the breed.
     */
    public String getbreed() { return _breed; }


    /**
     * Return the Animal as a String
     * @return String containing the Animal's class, the breed and it's name.
     */
    @Override
    public String toString() {
        return String.format("[%s]\n\tBreed: %s\n\tName: %s\n"
                                , getClass().getName()
                                , _breed
                                , _name);
    }
}

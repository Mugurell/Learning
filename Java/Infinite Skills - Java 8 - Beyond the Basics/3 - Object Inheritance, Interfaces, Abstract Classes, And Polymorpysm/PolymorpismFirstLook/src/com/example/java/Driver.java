/**
 * Created by petru on 13-Oct-15.
 */


package com.example.java;


public class Driver {

    public static void main(String[] args) {

        // Can store any super/subclass objects as the superclass type
        // with implicit upcasting.
        Animal[] pets = new Animal[5];
        Dog d = new Dog("Fido", "Cocker", false);
        Cat c = new Cat("Bubulina", "Persian", true);
        pets[0] = d;
        pets[1] = new Dog("Woofy", "German Shepard", true);
        pets[2] = c;
        pets[3] = new Cat("Tom", "Siamese", false);
        pets[4] = new Animal("Tank", "Fish");

        for (Animal a : pets) {
            System.out.println(a);
        }

        // java.lang.ClassCastException: com.example.java.Dog
        // cannot be cast to com.example.java.Cat
        // ((Cat)pets[0]).setIsDeclawed(false);

        for (Animal a : pets) {
            if (a instanceof Dog) {
                Dog myPetDog = (Dog)a;
                myPetDog.setIsServiceAnimal(false);
                System.out.println("Set " + a.getName() + " 's value for"
                        + " \"is a service animal\" to false.");
            }
            else if (a instanceof Cat) {
                ((Cat) a).setIsDeclawed(true);
                System.out.println("Set " + a.getName() + "'s value for"
                        + " \"is declawed\" to true.");
            }

            System.out.println(a);
        }
    }
}

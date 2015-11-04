/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class ClassesAndConstructors {
    public static void main(String[] args){
        // create a new runner(default)
        Runner r = new Runner();

        // create a new swimmer (default)
        Swimmer s = new Swimmer();

        // create a new swimmer (explicit)
        Swimmer s2 = new Swimmer(123);

        System.out.println(r);
        System.out.println(s);
        System.out.println(s2);
    }
}

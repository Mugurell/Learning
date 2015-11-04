package com.example.java;

/**
 * Created by petru on 09-Oct-15.
 */
public class Utilities {
    /**
     * Get equality without worrying about null pointer exception
     * @param one the first object to compare to
     * @param two the first object to compare to
     * @return true is equal, else false.
     */
    public static boolean nullSafeEquals(Object one, Object two) {
        // Note: This code is not correct yet
        return one.equals(two);
    }
}

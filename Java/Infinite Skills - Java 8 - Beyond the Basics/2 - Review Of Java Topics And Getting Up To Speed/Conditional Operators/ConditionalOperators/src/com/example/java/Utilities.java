package com.example.java;

/**
 * Created by petru on 09-Oct-15.
 */
public class Utilities {
    /**
     * Get equality without worrying about null pointer exception
     * @param left the first object to compare to
     * @param right the first object to compare to
     * @return true is equal, else false.
     */
    public static boolean nullSafeEquals(Object left, Object right) {
        // To prevent a NULL Pointer Exception, the left object - implicit
        // object - can't be null.
        // It Won't matter if the right object - explicit object - is null.
        if (null == left) {
            return null == right;
        }
        else {
            return left.equals(right);
        }
    }
}

package raceManagerValidation;

/**
 * Created by petru on 17-Oct-15.
 */


public class Validate
{
    /**
     * Validate that a String is not null or empty.
     * @param test (String) to test.
     * @throws IllegalArgumentException if null or empty String
     */
    public static void StringHasContent(String test) {
        if (test == null || test.length() == 0) {
            throw new IllegalArgumentException("Null or Empty String encountered.");
        }
    }


    /**
     * Validate that a number is at least a certain value
     * @param min  the minimum value for the range
     * @param value  the number received for validation
     * @throws IllegalArgumentException if validation fails
     */
    public static void NumberRangeValidation(int min, int value) {
        if (value < min) {
            throw new IllegalArgumentException("Number is not valid");
        }
    }


    /**
     * Test to make sure a number is in range (both inclusive)
     * @param min  the minimum value for the range
     * @param max  the maximum value for the range
     * @param value  the number received for validation
     */
    public static void NumberRangeValidation(int min, int max, int value) {
        if (value < min || value > max) {
            throw new IllegalArgumentException("Number is not valid");
        }
    }
}

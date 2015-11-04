/**
 * Created by petru on 09-Oct-15.
 */


package com.example.java;


public class Main {

    public static void main(String[] args) {
        /*
            Types
            String  - Any text, wrapped in ""s
            Character (char)    - 2 bytes   - may contain any Unicode characters
            Byte      (byte)    - 1 signed byte (-128 - +127)
            Short     (short)   - 2 bytes       (-32768 - +32767)
            Integer   (int)     - 4 bytes       (-2^31  - +2^31 - 1)
            Long      (long)    - 8 bytes       (-2^63  - +2^63 - 1)
            Float     (float)   - 4 bytes
            Double    (double)  - 8 bytes
            Boolean   (boolean) - 4 bytes
         */

        // Variables == store the values we work with
        String fName = "John";
        char middleInit = 'V';
        char middleInitSymbool = '.';
        String lName = "Kirk";

        byte age = 43;  // a byte can gold (-128 - +127)
        short numberOfKlingonShipsEncountered = 432;
        int numberOfPlanetsDiscovered = 1_274_321;
        long wholeKilometersTraveled = 42_353_416_532_235L;
        float numberOfHourOfService = 345_234_324.432F;
        double costOfMission = 6_432_761_432.34;
        boolean missionSuccess = true;

        String output = String.format
                ("Captain %s %s%s %s, age %d, spent 62 years in space.\n"
                + "During this time, the Enterprise encountered %d Klingon "
                + "ships of various type and classification.\n"
                + "%s and the Enterprise crew discovered %d planets, while "
                + "travelling approximately %d kilometers.\n"
                + "The Enterprise crew served efficiently for %.1f hours.\n"
                + "The cost of the missiopn translated to 21st century American"
                + " dollars would be %.2f.\n"
                + "Therefore, the mission success is: %b.\n"
                        , fName
                        , middleInit
                        , middleInitSymbool
                        , lName
                        , age
                        , numberOfKlingonShipsEncountered
                        , lName
                        , numberOfPlanetsDiscovered
                        , wholeKilometersTraveled
                        , numberOfHourOfService
                        , costOfMission
                        , missionSuccess
                );
        System.out.println(output);

    }

}

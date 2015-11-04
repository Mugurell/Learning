package raceManagerDatabase;

/**
 * Created by petru on 31-Oct-15.
 */


public class RaceManagerOperations
{
    public static final String ATHLETE_TABLE_NAME      = "Athlete";
    public static final String ATHLETE_TYPE_TABLE_NAME = "AthleteType";

    public static String CreateAthleteTableDetails() {
        return "'RacerID' INT NOR NULL AUTO_INCREMENT, "
               + "'Name' VARCHAR(100) NOT NULL, "
               + "'Age' INT NOT NULL, "
               + "'IsInjured' BIT NOT NULL, "
               + "'TypeID' INT NOT NULL, "
               + "'Shoes' VARCHAR(45) NULL, "
               + "'UsesClips' Bit NULL, "
               + "PRIMARY KEY ('RacerID')";
    }

    public static String CreateAthleteTypeTableDetails() {
        return "'ID' INT NOT NULL AUTO_INCREMENT, " +
               "'AthleteType' VARCHAR(45) NOT NULL, " +
               "PRIMARY KEY ('ID')";
    }

}

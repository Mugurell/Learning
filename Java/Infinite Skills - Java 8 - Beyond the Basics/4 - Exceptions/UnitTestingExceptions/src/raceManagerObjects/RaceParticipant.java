package raceManagerObjects;

/**
 * Created by petru on 14-Oct-15.
 */


public interface RaceParticipant {

    // !!!  The keywords "public" & "abstract" are implicit   !!!


    /**
     * Set the Racer contest ID.
     * @param racerId  the ID of the racer.
     */
    void setRacerID(int racerId);

    /**
     * Get this Racer's contest ID.
     * @return int - the id of the Racer.
     */
    int getRacerID();

    /**
     * See the Racer performing the race activity.
     * @return String - the race activity being performed
     */
    String performRaceActivity();
}

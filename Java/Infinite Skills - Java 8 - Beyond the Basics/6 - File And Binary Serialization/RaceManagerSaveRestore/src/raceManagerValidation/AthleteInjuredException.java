package raceManagerValidation;

/**
 * Created by petru on 18-Oct-15.
 */


public class AthleteInjuredException extends RuntimeException
{
    public AthleteInjuredException() {
        super("the Athlete was unable to complete the race due to injury.");
    }

    public AthleteInjuredException(String msg) {
        super(msg);
    }
}

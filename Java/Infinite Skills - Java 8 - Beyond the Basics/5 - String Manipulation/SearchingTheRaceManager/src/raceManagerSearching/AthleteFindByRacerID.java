package raceManagerSearching;

import raceManagerObjects.Athlete;

/**
 * Created by petru on 26-Oct-15.
 */


public class AthleteFindByRacerID implements AthleteFinder
{
    int _racerID;

    public AthleteFindByRacerID(int racerID) {
        _racerID = racerID;
    }

    @Override
    public boolean searchForAthlete(Athlete searcher) {
        return searcher.getRacerID() == _racerID;
    }
}

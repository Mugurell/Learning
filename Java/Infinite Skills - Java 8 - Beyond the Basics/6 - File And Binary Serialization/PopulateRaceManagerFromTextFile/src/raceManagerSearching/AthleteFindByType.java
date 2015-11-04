package raceManagerSearching;

import raceManagerObjects.Athlete;
import raceManagerObjects.Biker;
import raceManagerObjects.Runner;
import raceManagerObjects.Swimmer;

/**
 * Created by petru on 26-Oct-15.
 */


public class AthleteFindByType implements AthleteFinder
{
    private String _type;

    public AthleteFindByType(String type) {
        _type = type;
    }

    @Override
    public boolean searchForAthlete(Athlete searcher) {
        if (_type.equalsIgnoreCase("runner")) {
            return searcher instanceof Runner;
        }
        if (_type.equalsIgnoreCase("biker")) {
            return searcher instanceof Biker;
        }
        if (_type.equalsIgnoreCase("swimmer")) {
            return searcher instanceof Swimmer;
        }
        return false;
    }
}

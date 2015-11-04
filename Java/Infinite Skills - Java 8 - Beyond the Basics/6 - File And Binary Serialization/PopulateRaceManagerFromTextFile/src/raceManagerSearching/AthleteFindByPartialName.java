package raceManagerSearching;

import raceManagerObjects.Athlete;

/**
 * Created by petru on 26-Oct-15.
 */


public class AthleteFindByPartialName implements AthleteFinder
{
    private String _searchedPhrase;

    public AthleteFindByPartialName(String searchedFor) {
        _searchedPhrase = searchedFor;
    }

    @Override
    public boolean searchForAthlete(Athlete searcher) {
        String regexMatcher = String.format(".*%s.*", _searchedPhrase);
        return searcher.getName().matches(regexMatcher);
    }
}

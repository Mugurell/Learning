/**
 * Created by petru on 01-Nov-15.
 */


public class Animal
{
    private String _name;

    public Animal() {
        // do nothing
    }

    public Animal(String species) {
        _name = species;
    }

    public String toString() {
        return String.format("[%s] Name: %s",
                             getClass().getName(),
                             _name);
    }
}

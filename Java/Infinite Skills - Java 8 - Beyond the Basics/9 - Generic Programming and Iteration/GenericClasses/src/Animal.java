/**
 * Created by petru on 01-Nov-15.
 */


public class Animal
{
    private String _name;

    public Animal() {
        _name = "Generic Animal";
    }

    public Animal(String name) {
        _name = name;
    }

    public void setName(String name) {
        _name = name;
    }

    public String getName() {
        return _name;
    }

    public String toString() {
        return String.format("[%s] Name: %s",
                             getClass().getName(),
                             _name);
    }

    public boolean equals(Object o1) {
        if (o1 == null) return false;
        if (!(o1 instanceof Animal)) return false;
        return (_name.equals(((Animal) o1).getName()));
    }
}

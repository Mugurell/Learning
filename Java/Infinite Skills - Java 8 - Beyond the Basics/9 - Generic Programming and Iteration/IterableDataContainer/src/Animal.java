/**
 * Created by petru on 02-Nov-15.
 */


public class Animal
{
    protected String name;

    public Animal() {
        /*do nothing*/
    }

    public Animal(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return String.format("[%s] Name: %s", getClass().getName(), name);
    }

    public boolean equals(Object o) {
        // If the received Object is exactly the same as this, return true.
        if (this == o) return true;

        // If the received Object is null or it doesn't have the same type as this class return false.
        if (o == null || getClass() != o.getClass()) return false;

        Animal animal = (Animal) o;
        // Test the value of the name field.
        return !(name != null ? !name.equals(animal.name) : animal.name != null);
    }
}
/**
 * Created by petru on 02-Nov-15.
 */


public class Animal implements Comparable<Animal>
{
    private String name;

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

    @Override
    public boolean equals(Object o) {
        // If the received Object is exactly the same as this, return true.
        if (this == o) return true;

        // If the received Object is null or it doesn't have the same type as this class return false.
        if (o == null || getClass() != o.getClass()) return false;

        Animal animal = (Animal) o;
        // Test the value of the name field.
        return !(name != null ? !name.equals(animal.name) : animal.name != null);
    }

    @Override
    public int compareTo(Animal o) {
        if (o == null) return 1;    // this is bigger

        // Strings are comparable
        int val = ((Animal) o).name.compareTo(this.name);
        if (val < 0) return -1;     // this is smaller
        if (val > 0) return 1;      // this is bigger
        return val; // the names are equal, so return 0
    }
}
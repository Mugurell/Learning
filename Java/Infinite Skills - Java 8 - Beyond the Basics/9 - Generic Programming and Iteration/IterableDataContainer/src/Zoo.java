import java.util.Iterator;

/**
 * Created by petru on 02-Nov-15.
 */


// Because IterableDataContainer implemented the Iterable interface,
// it can now  be the target of the "for-each loop" statement.

public class Zoo
{
    public static void main(String[] args) {
        IterableDataContainer<Animal> animals = new IterableDataContainer<>();
        animals.add(new Animal("Chipmunk"));
        animals.add(new Animal("Aardvark"));
        animals.add(new Animal("Hedgehog"));
        animals.add(new Animal("Dog"));
        animals.add(new Animal("Ibex"));
        animals.add(new Animal("Frog"));
        animals.add(new Animal("Giraffe"));
        animals.add(new Animal("Eagle"));
        animals.add(new Animal("Jaguar"));
        animals.add(new Animal("Bear"));

        System.out.println("*********************************");
        // This for-each loop will internally manage an iterator and use the hasNext() and next() methods.
        for (Animal a : animals) {
            System.out.println(a);
        }
        System.out.println("*********************************\n");

        // Can also explicitly use an iterator to loop through the elements.
        for (Iterator<Animal> it = animals.iterator(); it.hasNext(); ) {
            Animal a = it.next();
            System.out.println(a);

            if (a.getName().equals("Dog")) {
                it.remove();
                // it.remove();
            }
        }
    }
}

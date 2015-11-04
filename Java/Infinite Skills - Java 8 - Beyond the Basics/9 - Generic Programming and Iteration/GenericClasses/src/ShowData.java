/**
 * Created by petru on 01-Nov-15.
 */


public class ShowData
{
    public static void main(String[] args) {
        DataContainer<String> sData = new DataContainer<>("Something");
        DataContainer<Integer> iData = new DataContainer<>(0);
        System.out.println(sData);
        System.out.println(iData);


        BetterDataContainer<Integer, String> bdc1 = new BetterDataContainer<>(0, "Aardvark");
        BetterDataContainer<Integer, String> bdc2 = new BetterDataContainer<>(1, "Dog");
        BetterDataContainer<Integer, Animal> bdc3 = new BetterDataContainer<>(2, new Animal("Zebra"));
        BetterDataContainer<Integer, Animal> bdc4 = new BetterDataContainer<>(3, new Animal("Koala"));
        System.out.println(bdc1);
        System.out.println(bdc2);
        System.out.println(bdc3);
        System.out.println(bdc4);


        BestDataContainer<Animal> bdc0 = new BestDataContainer<Animal>();
        bdc0.add(new Animal("Antilope"));
        bdc0.add(new Animal("Bear"));
        bdc0.add(new Animal("Chipmunk"));
        bdc0.add(new Animal("Dog"));
        bdc0.add(new Animal("Eagle"));
        bdc0.add(new Animal("Frog"));
        bdc0.add(new Animal("Giraffe"));
        bdc0.add(new Animal("hedgehog"));
        bdc0.add(new Animal("Ibex"));
        bdc0.add(new Animal("Jaguar"));
        System.out.println(bdc0);

        bdc0.removeAt(0);
        bdc0.removeItem(new Animal("Frog"));
        System.out.println(bdc0);

        System.out.println(bdc0.get(5));
    }
}

package raceManagerObjects;

/**
 * Created by petru on 14-Oct-15.
 */


public interface Person {
    /**
     * Get the name of this raceManagerObjects.Person.
     * @return String  representing the name.
     */
    String getName();

    /**
     * Set the name of this raceManagerObjects.Person.
     * @param name  the new name.
     */
    void setName(String name);

    /**
     * Get the age of the raceManagerObjects.Person.
     * @return int  representing the age.
     */
    int getAge();

    /**
     * Set the age of this raceManagerObjects.Person.
     * @param age  the new age value.
     */
    void setAge(int age);
}

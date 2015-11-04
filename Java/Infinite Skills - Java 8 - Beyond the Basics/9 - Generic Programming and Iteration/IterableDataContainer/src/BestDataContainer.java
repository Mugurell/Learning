import java.util.NoSuchElementException;

/**
 * Created by petru on 02-Nov-15.
 */


public abstract class BestDataContainer<T>
{
    Object[] data;          // data structure
    int      countItems;    // number of valid items stored

    /**
     * Default ctor.
     * Will delegate the explicit ctor to create an array of 10 Objects.
     */
    public BestDataContainer() {
        this(10);
    }

    /**
     * Explicit ctor.
     * Creates an array of Objects with the capacity set to the received int parameter.
     * @param capacity number of Objects the 'data' array will hold'
     */
    public BestDataContainer(int capacity) {
        data = new Object[capacity];
    }

    /**
     * Get the current size of our array. Not the capacity!
     * @return the value of the 'countItems' field.
     */
    public int size() {
        return countItems;
    }


    /**
     * Add an Object to the container.
     * Can't add if the received Object is null, already contained or the container is already at max capacity.
     * @param item Object to add.
     * @return true if added, false otherwise.
     */
    public boolean add(T item) {
        // can't add if item is null or already at max capacity
        if (item == null || countItems == data.length) {
            return false;
        }

        // don't add duplicates
        int itemIndex = findItem(item);
        if (itemIndex > 0) {
            return false;
        }

        // else, add the item
        data[countItems++] = item;
        return true;
    }

    /**
     * Remove the item at the indicated index, if it exists.
     * @param index the index of the Object the user want to be removed.
     * @return true if the item was removed, false otherwise.
     * @throws NoSuchElementException if the index received is not valid.
     */
    public boolean removeAt(int index) throws NoSuchElementException {
        validateIndex(index);
        int i = index;
        int j = i + 1;
        // Move all the next Objects to a previous position.
        while (j < countItems) {
            data[j - 1] = data[j];
            j++;
        }
        countItems--;   // Decrement the valid Objects counter because 1 Object was removed.
        return true;
    }

    /**
     * Remove an item that is equal to the one received as argument.
     * Can't remove if the received item is null or not contained in the array.
     * @param item  the item to remove.
     * @return  true if the item was removed, false otherwise.
     */
    public boolean removeItem(T item) {
        if (item == null) return false;
        int index = findItem(item);
        if (index < 0) return false;
        return removeAt(index);
    }

    /**
     * Find the index of a certain Object in our array.
     * @param item  an exact match of the element to be found in the array.
     * @return  the index position of the Object in our array, or -1 if it isn't found.
     */
    public int findItem(T item) {
        for (int i = 0; i < countItems; i++) {
            if (data[i].equals(item)) {
                return i;
            }
        }
        return -1;  // if the item wasn't found
    }

    /**
     * Get an item by it's index
     * @param index  the index of the requested Object from our array.
     * @return  the requested Object.
     * @throws NoSuchElementException if the index isn't valid.
     */
    public T get(int index) throws NoSuchElementException {
        validateIndex(index);
        return ((T) data[index]);   // unsafe cast
    }

    /**
     * Validate the index.
     * @param index  index in our array to validate.
     * @throws NoSuchElementException if the index isn't valid.
     */
    protected void validateIndex(int index) throws NoSuchElementException {
        if (index < 0 || index > countItems) {
            throw new NoSuchElementException("Invalid index");
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < countItems; i++) {
            sb.append("Next item: " + data[i] + "\n");
        }

        return sb.toString();
    }
}

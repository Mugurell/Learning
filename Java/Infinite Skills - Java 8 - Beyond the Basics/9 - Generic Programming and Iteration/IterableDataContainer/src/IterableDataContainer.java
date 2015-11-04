import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Created by petru on 02-Nov-15.
 */


// When we're implementing an iterator, our collection MUST implement it's own iterator!

public class IterableDataContainer<T> extends BestDataContainer implements Iterable<T>
{
    public Iterator<T> iterator() {
        return new BestDataContainerIterator<T>();
    }

    public Iterator<T> iterator(int index) {
        return new BestDataContainerIterator<T>(index);
    }


    // By implementing this we now have the ability to return an iterator and implement methods of the iterator itself.
    private class BestDataContainerIterator<T> implements Iterator<T>
    {
        private int currentIndex;
        private int priorIndex;
        private final int BAD_INDEX = -1;

        // Create an iterator at the front of the container.
        public BestDataContainerIterator() {
            this(0);
        }

        /**
         * Create an iterator from the index.
         * @param index  starting position of the iterator.
         */
        public BestDataContainerIterator(int index) {
            validateIndex(index);
            currentIndex = index;
            priorIndex = BAD_INDEX;
        }

        @Override
        public boolean hasNext() {
            return currentIndex < size();
        }

        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            priorIndex = currentIndex;  // wherever we're at will become the prior
            // Return the element of type T from the current location in the data[] field of IterableContainer.
            return (T) IterableDataContainer.this.data[currentIndex++];
        }

        @Override
        public void remove() {
            CheckValidRemoveState();

            // Remove it.
            IterableDataContainer.this.removeAt(priorIndex);

            // Make another remove impossible. To not be able to call two remove() in a row.
            priorIndex = BAD_INDEX;
        }

        private void CheckValidRemoveState() {
            if (priorIndex == BAD_INDEX) {
                throw new IllegalStateException("Must move next before removing items!");
            }
        }
    }
}

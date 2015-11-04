/**
 * Created by petru on 01-Nov-15.
 */


public class DataContainer<T>
{
    T _data;

    public DataContainer(T data) {
        _data = data;
    }

    public T getData() {
        return _data;
    }

    public void setData(T data) {
        _data = data;
    }


    /**
     * Get the data printout. Relies on T having it's own toString() defined.
     * @return String representing the state of the container data.
     */
    public String toString() {
        return _data == null ? null : String.format("%s", _data.toString());
    }
}

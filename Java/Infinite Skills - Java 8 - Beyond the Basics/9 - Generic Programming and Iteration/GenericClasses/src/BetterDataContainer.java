import javafx.util.converter.BigDecimalStringConverter;

/**
 * Created by petru on 01-Nov-15.
 */


public class BetterDataContainer<T, S>
{
    T obj1;
    S obj2;

    public BetterDataContainer(T obj1, S obj2) {
        this.obj1 = obj1;
        this.obj2 = obj2;
    }


    public T getObj1() {
        return obj1;
    }

    public void setObj1(T obj1) {
        this.obj1 = obj1;
    }

    public S getObj2() {
        return obj2;
    }

    public void setObj2(S obj2) {
        this.obj2 = obj2;
    }


    @Override
    public String toString() {
        return "BetterDataContainer{" +
               "obj1=" + obj1 +
               ", obj2=" + obj2 + '}';
    }
}

/**
 * Created by petru on 18-Oct-15.
 */


public class CustomCheckedException extends Exception
{
    public CustomCheckedException() { super("A custom checked exception has been encountered."); }

    public CustomCheckedException(String msg) { super(msg); }
}

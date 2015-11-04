/**
 * Created by petru on 18-Oct-15.
 */


public class CustomUncheckedException extends RuntimeException
{
    public CustomUncheckedException() { super("A custom unchecked exception has been encountered"); }

    public CustomUncheckedException(String msg) { super(msg); }
}

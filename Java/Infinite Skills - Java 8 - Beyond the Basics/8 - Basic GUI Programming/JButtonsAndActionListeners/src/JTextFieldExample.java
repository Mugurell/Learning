import javax.swing.*;

/**
 * Created by petru on 03-Nov-15.
 */


public class JTextFieldExample extends JTextField
{
    private String text;

    public JTextFieldExample() {
        super.setColumns(10);
    }

    public JTextFieldExample(String text) {
        super(text);
    }

    public JTextFieldExample(String text, int columns) {
        super(text, columns);
    }

//    public void setText(String text) {
//        this.text = text;
//    }
}

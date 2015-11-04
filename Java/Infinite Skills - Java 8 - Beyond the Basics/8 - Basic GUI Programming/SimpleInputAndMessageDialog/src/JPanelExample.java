import javax.swing.*;
import java.awt.*;

/**
 * Created by petru on 03-Nov-15.
 */


public class JPanelExample extends JPanel
{
    public JTextFieldExample TextField1 = new JTextFieldExample();

    public JPanelExample() {
        setBorder(BorderFactory.createLineBorder(Color.BLUE, 3, true));

        JLabel label1 = new JLabel("Please enter some text!");

        add(label1);
        add(TextField1);
    }

    public void setTextFieldName(String name) {
        if (TextField1 == null) throw new IllegalStateException();
        if (name == null) throw new IllegalArgumentException();
        TextField1.setText(name);
    }
}

import javax.swing.*;
import java.awt.*;

/**
 * Created by petru on 03-Nov-15.
 */


public class JPanelExample extends JPanel
{
    public JPanelExample() {
        setBorder(BorderFactory.createLineBorder(Color.BLUE, 3, true));

        JLabel label1 = new JLabel("Please enter some text!");
        JTextFieldExample TextField1 = new JTextFieldExample("Lullaby", 10);

        add(label1);
        add(TextField1);
    }
}

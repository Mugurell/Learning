import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by petru on 04-Nov-15.
 */


public class ButtonPressAction implements ActionListener
{
    @Override
    public void actionPerformed(ActionEvent e) {
        JButton jb = (JButton) e.getSource();   // get the Object which called this method

        JOptionPane.showMessageDialog(null, "Button: " + jb.getName() + " pressed");
    }
}

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by petru on 03-Nov-15.
 */


public class JPanelExample extends JPanel
{
    public JTextFieldExample TextField1;

    public JPanelExample() {
        setBorder(BorderFactory.createLineBorder(Color.BLUE, 3, true));

        JLabel label1 = new JLabel("Please enter your name:");
        TextField1 = new JTextFieldExample("Pamela", 30);

        add(label1);
        add(TextField1);

        JButton jb = new JButton("Press Me");
        jb.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = JOptionPane.showInputDialog("Please enter your name: ");
                TextField1.setText(name);
            }
        });
        add(jb);

        JButton jb2 = new JButton("Press me too!");
        jb2.setName("Button two");
        jb2.addActionListener(new ButtonPressAction());
        add(jb2);
    }

    public void setTextFieldName(String name) {
        if (TextField1 == null) throw new IllegalStateException();
        if (name == null) throw new IllegalArgumentException();
        TextField1.setText(name);
    }
}

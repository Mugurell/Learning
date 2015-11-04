import javax.swing.*;
import java.awt.*;

/**
 * Created by petru on 03-Nov-15.
 */


public class JFrameExample extends JFrame
{
    public JFrameExample() {
        setLocation(250, 250);
        setSize(GUIProgram.WIDTH + 20, GUIProgram.HEIGHT + 60);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("My JFrame Example");
        setBounds(0, 0, GUIProgram.WIDTH + 20, GUIProgram.HEIGHT + 60);
        setVisible(true);
    }
}

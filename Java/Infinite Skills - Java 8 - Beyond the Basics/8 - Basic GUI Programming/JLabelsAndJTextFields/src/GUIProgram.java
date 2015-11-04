import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

/**
 * Created by petru on 03-Nov-15.
 */


public class GUIProgram
{
    public static final int WIDTH  = 640;
    public static final int HEIGHT = 480;

    // All of our programs will gonna be inside main()
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    JFrameExample jfe = new JFrameExample();
                    JPanelExample jpe = new JPanelExample();

                    // add the panel directly to the jfe Jframe.
                    jfe.getContentPane().add(jpe);

//                    JLabel label1 = new JLabel("Please enter some text!");
//                    JTextField textField1 = new JTextField("Lullaby");
//                    textField1.setColumns(12);  // make the text field larger than the width of the string



                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }
}

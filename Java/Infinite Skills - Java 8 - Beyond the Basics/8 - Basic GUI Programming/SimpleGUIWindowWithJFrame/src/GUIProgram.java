import javax.swing.*;
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
/*                    JFrame jf = new JFrame();
                    jf.setLocation(250, 250);
                    jf.setSize(WIDTH + 20, HEIGHT + 60);
                    jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    jf.setTitle("My JFrame");
                    jf.setBounds(0, 0, WIDTH + 20, HEIGHT + 60);
                    jf.setVisible(true);
*/
                    JFrameExample jfe = new JFrameExample();

                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }
}

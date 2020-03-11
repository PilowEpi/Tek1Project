import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DebugMode extends JPanel{
    public DebugMode(){
        super();
        this.setPreferredSize(new Dimension(500,400));
        this.setBackground(Color.BLACK);
        
        JButton test = new JButton("test");
        this.add(test);
    }
}

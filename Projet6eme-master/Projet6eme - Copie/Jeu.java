    
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Jeu extends JPanel{
    private HUD hud;
    private JeuPanel OnScreen;
    private App app;
    
    public Jeu(App app){
        super();
        
        this.app = app;
        
        setPreferredSize(new Dimension(1290,795));
        
        setLayout(new BorderLayout());
        
        hud = new HUD(app);
        OnScreen = new JeuPanel();
        this.add(OnScreen, BorderLayout.CENTER);
        this.add(hud, BorderLayout.SOUTH);
    }
}
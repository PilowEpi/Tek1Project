import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JPanel;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


public class HUD extends JPanel implements ActionListener{
	public static HUD instance;
    private App app;
    public int energiep1 = 1000;
    public int energiep2 = 1000;
    private BufferedImage j1;
    private BufferedImage j2;
    public static boolean getRepaint=false;
    public boolean victoryp1=false,victoryp2=false;
    
    public HUD(App app){
    	super();


    	instance = this;
    	
    	
            this.app = app;
            setPreferredSize(new Dimension(1280,75));
            setBackground(Color.BLACK);
            try {
                j1 = ImageIO.read(new File("Ressources/logoj1.png"));
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                j2 = ImageIO.read(new File("Ressources/logoj2.png"));
            } catch (IOException e) {
                e.printStackTrace();
            }
        
    }
    
    public void SetEnergy(int value, boolean isPlayer1){
    	if(isPlayer1){
    		energiep1 = value;
    		if(energiep1 <= 0)
    			energiep1 = 0;
    	}
    	else{
    		energiep2 = value;
    		if(energiep2 <= 0)
    			energiep2 = 0;
    	}
    		
    	if(energiep1 == 0 || energiep2 == 0){
    		GameOver(isPlayer1);
    		Player2.actif = false;
    		Player1.actif=false;
    		tir.actif=false;
    	}
    }
    
    public void GameOver(boolean isPlayer1) {
    	System.out.println("GAME OVER du joueur :");
    	if(isPlayer1==true) {
    		System.out.println("Joueur 1");
    		victoryp2=true;
    		
    	}
    	if(isPlayer1==false){
    		System.out.println("Joueur 2");
    		victoryp1=true;
    		
    	}
    	repaint();
    }
    
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.setColor(Color.WHITE);
 
	        //joueur 1
	        g.drawString("Joueur 1", 10, 20);
	        g.drawImage(j1,530,10, null);
	        g.drawString("Energie:"+ energiep1, 10, 70);
	        
	        //Bouton home
	        JButton home = new JButton("X");
	        this.add(home);
	        home.addActionListener(this);
	        home.setBounds(600,0,50,75);
	        
	        //Joueur 2
	        g.drawString("Joueur 2", 660, 20);
	        g.drawString("Energie:"+ energiep2, 660, 70);
	        g.drawImage(j2,1210,10, null);
        
	       if(victoryp1==true) {
	    	   g.drawString("Victoire du joueur 1", 10, 40);
	       }
	       if (victoryp2==true) {
	    	   g.drawString("Victoire du joueur 2", 660, 40);
	       }
            
        
    }   

    public void actionPerformed(ActionEvent ae) {
        System.out.println("Retour vers le menu");
        app.setMenu(0);
    }
}
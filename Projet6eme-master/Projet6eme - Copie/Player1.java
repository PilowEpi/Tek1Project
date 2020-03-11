import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Player1 extends JComponent implements Runnable{
    
	protected int c1,c2; //taille du personnage
	public static volatile int x=10,y=10; //Coordonnée de départ
    private static volatile boolean gauche = false;
    private static volatile boolean droite = false;
    private static volatile boolean haut = false;
    private static volatile boolean bas = false;
    private static volatile String dir;
    public static boolean actif = true;
    private int vitesse = 5; //Longueur du déplacement
    private int energie = 1000;
    private JeuPanel jp;
    
    
    public Player1(JeuPanel jp){
        this(10,30);
        this.jp = jp;
    }
    public Player1() {
    	
    }
    public void Reset() {
    	x= 20;
    	y= 10;
    	vitesse=5;
    	energie =1000;
    	actif = true;
    	
    }
    
    public Player1(int c1 , int c2){
        this.c1=c1;
        this.c2=c2;
    }
    
    public void paint(Graphics g){
        super.paint(g);
        g.setColor(Color.RED);
        g.fillRect(x,y,c1,c2);
    }
    
    public void Gauche(boolean bl) {
		gauche = bl;
		dir = "gauche";
    }
    public void Droite(boolean bl) {
    	droite = bl;
    	dir = "droite";
    }
    public void Haut(boolean bl) {
    	haut = bl;
    	dir = "haut";
    }
    public void Bas(boolean bl) {
    	bas = bl;
    	dir = "bas";
    }
    
    public int getX() {
    	return x;
    }
    
    public int getY() {
    	return y;
    }
    
    public String getDir() {
    	return dir;
    }
    
    public void degat() {
    	energie--;
    	HUD.instance.SetEnergy(energie,true);
		HUD.instance.repaint();
		System.out.println(energie);
    }

    public void run(){
    	System.out.println("initilisé...");
    	while(actif) {
    		if(gauche) {
    			if(x > 0) {
    				x = x - vitesse;
    				jp.actualise();
    				//System.out.println(x);
    			}
    		}
    		if(droite) {
				if( x < 1270) {
    				x = x + vitesse;
    				jp.actualise();
    				//System.out.println(x);
				}
    		}
    		if(haut) {
    			if( y > 0) {
    				y = y - vitesse;
    				jp.actualise();
    				//System.out.println(y);
    			}
    		}
    		if(bas) {
				if( y < 690) {
    				y = y + vitesse;
    				jp.actualise();
    				//System.out.println(y);
				}
    		}
    		try {
    			Thread.sleep(5);
    		}catch(InterruptedException ie) {
    			System.out.println("Player 1 Crash");
    		}
    	}
    }
}
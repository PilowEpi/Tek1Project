import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.*;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Menu extends JPanel implements MouseListener{
	private App app;
	private JPanel jbutton;
	private JLabel b1;//Jouer
    private JLabel b2;//Option
    private JLabel b3;//Crédit
    private JLabel b4;//Quitter
	
	
	 public Menu(App app) {
		 super();
		 
		 this.app = app;
		
		 this.setPreferredSize(new Dimension(1280,795));
		 this.setLayout(new BorderLayout());
					 
		 jbutton = new JPanel();
		 jbutton.setLayout(new GridLayout(0,4));
		 		 
	     ImageIcon icon = new ImageIcon("Ressources/Test.png");
	     JLabel thumb = new JLabel();
	     thumb.setIcon(icon);
	     this.add(thumb, BorderLayout.CENTER);
	     
	     JPanel jpbutton = new JPanel();
	     jpbutton.setLayout(new GridLayout());
	     ImageIcon button1 = new ImageIcon("Ressources/Bouton1.png");
	     b1 = new JLabel();
	     b1.setIcon(button1);
	     b1.addMouseListener(this);
	     jbutton.add(b1);
	     
	     ImageIcon button2 = new ImageIcon("Ressources/Bouton2.png");
	     b2 = new JLabel();
	     b2.setIcon(button2);
	     b2.addMouseListener(this);
	     jbutton.add(b2);
	     
	     ImageIcon button3 = new ImageIcon("Ressources/Bouton3.png");
	     b3 = new JLabel();
	     b3.setIcon(button3);
	     b3.addMouseListener(this);
	     jbutton.add(b3);
	     
	     ImageIcon button4 = new ImageIcon("Ressources/Bouton4.png");
	     b4 = new JLabel();  
	     b4.setIcon(button4);
	     b4.addMouseListener(this);
	     jbutton.add(b4);
	     
	     this.add(jbutton, BorderLayout.SOUTH);
	    
	}
		public void mouseExited(MouseEvent me){
			Object obj = (Object)me.getSource();
	        if(obj==b1){
	            ImageIcon be = new ImageIcon("Ressources/Bouton1.png");
	            b1.setIcon(be);
	            repaint();
	        }
	        if(obj==b2){
	        	ImageIcon be = new ImageIcon("Ressources/Bouton2.png");
	            b2.setIcon(be);
	            repaint();
	        }
	        if(obj==b3){
	        	ImageIcon be = new ImageIcon("Ressources/Bouton3.png");
	            b3.setIcon(be);
	            repaint();
	        }
	        if(obj==b4){
	        	ImageIcon be = new ImageIcon("Ressources/Bouton4.png");
	            b4.setIcon(be);
	            repaint();
	        }
	    }
	    public void mouseEntered(MouseEvent me){
	    	Object obj = (Object)me.getSource();
	        if(obj==b1){
	            ImageIcon be = new ImageIcon("Ressources/Bouton1e.png");
	            b1.setIcon(be);
	            repaint();
	        }
	        if(obj==b2){
	        	ImageIcon be = new ImageIcon("Ressources/Bouton2e.png");
	            b2.setIcon(be);
	            repaint();
	        }
	        if(obj==b3){
	        	ImageIcon be = new ImageIcon("Ressources/Bouton3e.png");
	            b3.setIcon(be);
	            repaint();
	        }
	        if(obj==b4){
	        	ImageIcon be = new ImageIcon("Ressources/Bouton4e.png");
	            b4.setIcon(be);
	            repaint();
	        }
	    }
	    public void mouseReleased(MouseEvent me){}
	    public void mousePressed(MouseEvent me){}
	    public void mouseClicked(MouseEvent me){
	        Object obj = (Object)me.getSource();
	        if(obj==b1){
	            System.out.println("Bouton 1 actionné");
	            InputData.commandArray = Option.ReadFile("change.txt");
	            app.setMenu(1);
	        }
	        if(obj==b2){
	            System.out.println("Bouton 2 actionné");
	            app.setMenu(2);
	        }
	        if(obj==b3){
	            System.out.println("Bouton 3 actionné");
	            new Credit();
	        }
	        if(obj==b4){
	            System.out.println("Bouton 4 actionné");
	            System.exit(0);
	        }

	    }
}
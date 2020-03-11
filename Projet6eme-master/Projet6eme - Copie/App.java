import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.awt.Image.*;
import java.applet.Applet;
import java.net.URL;
import java.applet.AudioClip;
        
public class App extends JFrame{
    private Credit cr;
    public JPanel jpfond;
    public int[] newcommand;
	public int[] command;
    
    public static void main(String[] args){
        new App();
    }
       
    public App(){
          super("Kawaii loli battlefield");
          this.setContentPane(new Menu(this));
          
          this.pack();
          this.setVisible(true);
          this.setResizable(false);
          this.setLocationRelativeTo(null);  
          this.setDefaultCloseOperation(App.EXIT_ON_CLOSE);
    }
	public void setMenu(int i) {
    	if(i==0){
    		System.out.println("Go menu");
    		this.setContentPane(new Menu(this));
    		
        }
        else if(i==1){
        	System.out.println("Go Jeu");
            this.setContentPane(new Jeu(this));
        }
        else if(i==2) {
        	System.out.println("Go Option");
        	this.setContentPane(new Option(this));
        
        }
        this.pack();
		
	}
	
}

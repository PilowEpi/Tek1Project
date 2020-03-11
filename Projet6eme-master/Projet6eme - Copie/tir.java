import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class tir extends JComponent implements Runnable{
	
	protected int c1, c2;
	private static volatile int x= 20, y=20;
	public static volatile boolean actif = true;
	public static volatile boolean tir1 = false;
	public static volatile boolean tir2 = false;
	private static volatile String dir1 = "droite" ;
	private static volatile String dir2 = "gauche";
	Player1 p1 = new Player1();
	Player2 p2 = new Player2();
	private JeuPanel jp;
	
	public tir(JeuPanel jp) {
		this.jp = jp;
		System.out.println("tir ok");
	}
	
	public tir(int c1, int c2) {
		this.c1=c1;
        this.c2=c2;
	}
	
	public void paint(Graphics g) {
		super.paint(g);
		if(tir1) {
			g.setColor(Color.BLACK);
			if(dir1=="gauche") {
				g.fillRect(0,p1.getY()+13,p1.getX(),5);
			}
			if(dir1=="droite") {
				g.fillRect(p1.getX()+10,p1.getY()+13,1280-p1.getX()+10,5);
			}
			if(dir1=="haut") {
				g.fillRect(p1.getX()+3,0,5,p1.getY());
			}
			if(dir1=="bas") {
				g.fillRect(p1.getX()+3,p1.getY()+30,5,720-p1.getY()+30);
			}
		}
		if(tir2) {
			g.setColor(Color.BLACK);
			if(dir2=="gauche") {
				g.fillRect(0,p2.getY()+13,p2.getX(),5);
			}
			if(dir2=="droite") {
				g.fillRect(p2.getX()+10,p2.getY()+13,1280-p2.getX()+10,5);
			}
			if(dir2=="haut") {
				g.fillRect(p2.getX()+3,0,5,p2.getY());
			}
			if(dir2=="bas") {
				g.fillRect(p2.getX()+3,p2.getY()+30,5,720-p2.getY()+30);
			}
		}
	}
	
	public void feuj1(boolean bl) {
		tir1 = bl;
		dir1 = p1.getDir();
	}
	
	public void feuj2(boolean bl) {
		tir2 = bl;
		dir2 = p2.getDir();
	}
	
	public void run() {
		System.out.println("tir lancé");
		while(actif) {
			if(tir1) {
				p1.degat();
				if(dir1=="gauche") {
					if(p1.getY()+13>=p2.getY() && p1.getY()+13<=p2.getY()+30 && p1.getX()>=p2.getX()) {
						p2.degat();
					}
				}
				if(dir1=="droite") {
					if(p1.getY()+13>=p2.getY() && p1.getY()+13<=p2.getY()+30 && p1.getX()<=p2.getX()) {
						p2.degat();
					}
				}
				if(dir1=="haut") {
					if(p1.getX()+3>=p2.getX() && p1.getX()+3<=p2.getX()+10 && p1.getY()>=p2.getY()) {
						p2.degat();
					}
				}
				if(dir1=="bas") {
					if(p1.getX()+3>=p2.getX() && p1.getX()+3<=p2.getX()+10 && p1.getY()<=p2.getY()) {
						p2.degat();
					}
				}
				jp.actualise();
			}
			if(tir2) {
				p2.degat();
				if(dir2=="gauche") {
					if(p2.getY()+13>=p1.getY() && p2.getY()+13<=p1.getY()+30 && p2.getX()>=p1.getX()) {
						p1.degat();
					}
				}
				if(dir2=="droite") {
					if(p2.getY()+13>=p1.getY() && p2.getY()+13<=p1.getY()+30 && p2.getX()<=p1.getX()) {
						p1.degat();
					}
				}
				if(dir2=="haut") {
					if(p2.getX()+3>=p1.getX() && p2.getX()+3<=p1.getX()+10 && p2.getY()>=p1.getY()) {
						p1.degat();
					}
				}
				if(dir2=="bas") {
					if(p2.getX()+3>=p1.getX() && p2.getX()+3<=p1.getX()+10 && p2.getY()<=p1.getY()) {
						p1.degat();
					}
				}
				jp.actualise();
			}
			try{
				Thread.sleep(5);
			}catch(InterruptedException ie) {}
		}
	}
}
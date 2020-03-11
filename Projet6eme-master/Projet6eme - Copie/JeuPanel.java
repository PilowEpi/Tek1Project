import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JeuPanel extends JPanel{
    
	Player1 p1 = new Player1(this);
	Thread p1t = new Thread(new Player1(this));
	Player2 p2 = new Player2(this);
	Thread p2t = new Thread(new Player2(this));
	tir tr =  new tir(this);
	Thread trt = new Thread(new tir(this));

	
	public JeuPanel(){
        super();
        setLayout(null);    
        setPreferredSize(new Dimension(1280,720));
        setBackground(Color.GREEN);
        Reset();
             
         
        InputMap im = p1.getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW);
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_GAUCHE), 0, false),"GaucheE");
        ActionMap ap = p1.getActionMap();
        ap.put("GaucheE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Gauche(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_GAUCHE), 0, true),"GaucheR");
        ap.put("GaucheR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Gauche(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_DROIT),0,false),"DroiteE");
        ap.put("DroiteE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Droite(true);
        	}
    	});
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_DROIT), 0, true),"DroiteR");
        ap.put("DroiteR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Droite(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_HAUT), 0, false),"HautE");
        ap.put("HautE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Haut(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_HAUT), 0, true),"HautR");
        ap.put("HautR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Haut(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_BAS), 0, false),"BasE");
        ap.put("BasE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Bas(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_BAS), 0, true),"BasR");
        ap.put("BasR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p1.Bas(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_TIR), 0, false),"TirE");
        ap.put("TirE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		tr.feuj1(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J1_TIR), 0, true),"TirR");
        ap.put("TirR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		tr.feuj1(false);
        		actualise();
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_GAUCHE), 0, false),"p2GaucheE");
        ap.put("p2GaucheE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Gauche(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_GAUCHE), 0, true),"p2GaucheR");
        ap.put("p2GaucheR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Gauche(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_DROIT), 0, false),"p2DroiteE");
        ap.put("p2DroiteE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Droite(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_DROIT), 0, true),"p2DroiteR");
        ap.put("p2DroiteR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Droite(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_HAUT), 0, false),"p2HautE");
        ap.put("p2HautE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Haut(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_HAUT), 0, true),"p2HautR");
        ap.put("p2HautR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Haut(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_BAS), 0, false),"p2BasE");
        ap.put("p2BasE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Bas(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_BAS), 0, true),"p2BasR");
        ap.put("p2BasR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		p2.Bas(false);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_TIR), 0, false),"p2TirE");
        ap.put("p2TirE", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		tr.feuj2(true);
        	}
        });
        
        im.put(KeyStroke.getKeyStroke(InputData.GetKey(TypeButton.J2_TIR), 0, true),"p2TirR");
        ap.put("p2TirR", new AbstractAction() {
        	public void actionPerformed(ActionEvent ae) {
        		tr.feuj2(false);
        		actualise();

        	}
        });
    }
	public void Reset() {
		add(p1);
        add(p2);
        add(tr);
        p1t.start();
        p2t.start();
        trt.start();
        Player2.actif = true;
		Player1.actif=true;
		tir.actif=true;
	}
    
    public void paint(Graphics g){
        super.paint(g);
        Component[] comp = this.getComponents();
        for(int i = 0 ; i < comp.length ; i++){
            comp[i].paint(g);
        }
    }
    public void actualise() {
    	repaint();
    }
}
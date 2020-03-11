import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.util.List;
import java.nio.file.Path;
import java.nio.file.Paths;


public class Option extends JPanel implements ActionListener{
   private App app;
   public String j1_gauche,j1_droit,j1_haut,j1_bas,j1_tir;
   public String j2_gauche,j2_droit,j2_haut,j2_bas,j2_tir;
   public JLabel jlchange;
   public String donnee;
   public int inttouche;
   public int[] command,newcommand;
   private JButton jbquit,jbRetab,jbok;
   private JButton jb_j1_gauche,jb_j1_droit,jb_j1_haut,jb_j1_bas,jb_j1_tir;
   private JButton jb_j2_gauche,jb_j2_droit,jb_j2_haut,jb_j2_bas,jb_j2_tir;
   private boolean verif=true,bug=true;

public Option(App app){
		
       	super();
       	this.app = app;
       	this.setPreferredSize(new Dimension(1280,795));
       	this.setLayout(null);       
       	this.setBackground(Color.BLACK);
       	command = ReadFile("base.txt");
       	newcommand = ReadFile("change.txt");
       	
		if(verif==true) {
			   jbquit = CreateButton("Fermer", TypeButton.J_QUIT);
		       jbquit.setBounds(600, 750, 80, 30);
		       this.add(jbquit);
		}
       jbRetab = CreateButton("Rétablir",TypeButton.J_RETAB);
       jbRetab.setBounds(685, 750, 80, 30);
       this.add(jbRetab);
       
       jbok =CreateButton("Ok",TypeButton.J_OK);
       jbok.setBounds(515, 750, 80, 30);
       this.add(jbok);
       
       //Joueur 1
       
       jb_j1_gauche = CreateButton("Changer",TypeButton.J1_GAUCHE);
       jb_j1_gauche.setBounds(500, 150, 90, 30);
       this.add(jb_j1_gauche);
       
       jb_j1_droit = CreateButton("Changer",TypeButton.J1_DROIT);
       jb_j1_droit.setBounds(500, 250, 90, 30);
       this.add(jb_j1_droit);
       
       jb_j1_haut = CreateButton("Changer",TypeButton.J1_HAUT);
       jb_j1_haut.setBounds(500, 350, 90, 30);
       this.add(jb_j1_haut);
       
       jb_j1_bas = CreateButton("Changer",TypeButton.J1_BAS);
       jb_j1_bas.setBounds(500, 450, 90, 30);
       this.add(jb_j1_bas);
       
       jb_j1_tir = CreateButton("Changer", TypeButton.J1_TIR);
       jb_j1_tir.setBounds(500, 550, 90, 30);
       this.add(jb_j1_tir);
       
       //Joueur 2
       
       jb_j2_gauche = CreateButton("Changer",TypeButton.J2_GAUCHE);
       jb_j2_gauche.setBounds(1150, 150, 90, 30);
       this.add(jb_j2_gauche);
       
       jb_j2_droit = CreateButton("Changer",TypeButton.J2_DROIT);
       jb_j2_droit.setBounds(1150, 250, 90, 30);
       this.add(jb_j2_droit);
       
       jb_j2_haut = CreateButton("Changer",TypeButton.J2_HAUT);
       jb_j2_haut.setBounds(1150, 350, 90, 30);
       this.add(jb_j2_haut);
       
       jb_j2_bas = CreateButton("Changer",TypeButton.J2_BAS);
       jb_j2_bas.setBounds(1150, 450, 90, 30);      
       this.add(jb_j2_bas);
       
       jb_j2_tir = CreateButton("Changer",TypeButton.J2_TIR);
       jb_j2_tir.setBounds(1150, 550, 90, 30);
       this.add(jb_j2_tir);
       
       SetInputString(true);
       
       this.setVisible(true);
       
   }
	public JButton CreateButton(String name,TypeButton tpBut) {
		JButton jb = new GetButton(name,tpBut);
		jb.setFocusable(false);
		jb.addActionListener(this);
		return jb;
	}
	public void actionPerformed (ActionEvent e) {
		GetButton jb = (GetButton)e.getSource();
       	newcommand = ReadFile("change.txt");
		
		if(jb.TpBut == TypeButton.J_QUIT) {
			System.out.println("go menu");
			verif = VerifInput(verif,newcommand);
			if(verif==false) {
				System.out.println(verif);
				bug=false;
				repaint();
			}
			else{
				app.setMenu(0);		
			}
		}
		else if(jb.TpBut == TypeButton.J_RETAB) {
			ResetInput();
			repaint();
		}
		else if(jb.TpBut == TypeButton.J_OK) {
			repaint();
		}
		else
		{
			SetupInput(jb.TpBut);
			SetInputString(true);
			repaint();
			InputData.commandArray = newcommand;
			
			// InputData.GetKey(TypeButton.J1_GAUCHE) à faire pour les commandes 
			
		}
			
	}
	public boolean VerifInput(boolean verif,int[] command) {
		
		for(int i=0;i<10;i++) {
			for(int y=0;y<10;y++) {
				if(i != y) {
					if(command[i]==command[y]) {
						verif=false;
						return verif;
					}
					else {
						verif=true;
						
					}
				}
				
			}
		}
		return verif;	
	}
	public void SetInputString(boolean isNewCommand)
	{
		int[] commandArray = isNewCommand ? newcommand : command;
		
	       j1_gauche=Character.toString((char)commandArray[0]);
	       j1_droit=Character.toString((char)commandArray[1]);
	       j1_haut=Character.toString((char)commandArray[2]);
	       j1_bas=Character.toString((char)commandArray[3]);
	       j1_tir=Character.toString((char)commandArray[4]);
	       
	       j2_gauche=Character.toString((char)commandArray[5]);
	       j2_droit=Character.toString((char)commandArray[6]);
	       j2_haut=Character.toString((char)commandArray[7]);
	       j2_bas=Character.toString((char)commandArray[8]);
	       j2_tir=Character.toString((char)commandArray[9]);
	}
	
	public void ResetInput()
	{
		for(int i = 0; i < command.length; i++)
		{
			try {
				Write(Integer.toString(command[i]), i);
			} catch (IOException e) {
				System.out.println("RESET fail ");
			}
		}
		SetInputString(false);
		bug=true;
		repaint();
	}
	
	public void SetupInput(TypeButton tpBut) {
		InputJB();
		newcommand[tpBut.GetValue()]=inttouche;
		donnee=Integer.toString(newcommand[tpBut.GetValue()]);
		try {
			Write(donnee,tpBut.GetValue());
		} catch (IOException e1) {
			System.out.println(tpBut+" ne peut pas être changer");
		}
	}
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(Color.WHITE);
				
		//Ligne Centrale
		g.fillRect(650, 50, 2, 650);
				
		//Joueur 1 
		g.setFont(new Font(null, Font.BOLD, 35));
		g.drawString("Joueur 1", 300, 50);
		g.setFont(new Font(null, Font.BOLD, 25));
		g.drawString("Gauche", 50, 175);
		g.drawString("Droite", 50, 275);
		g.drawString("Haut", 50, 375);
		g.drawString("Bas", 50, 475);
		g.drawString("Tir", 50, 575);
		
		g.drawString(j1_gauche, 350, 175);
        g.drawString(j1_droit, 350, 275);
        g.drawString(j1_haut, 350, 375);
        g.drawString(j1_bas, 350, 475);
        g.drawString(j1_tir, 350, 575);
		
		
		//Joueur 2
		g.setFont(new Font(null, Font.BOLD, 35));
		g.drawString("Joueur 2", 925,50);
		g.setFont(new Font(null, Font.BOLD, 25));
		g.drawString("Gauche", 700, 175);
		g.drawString("Droite", 700, 275);
		g.drawString("Haut", 700, 375);
		g.drawString("Bas", 700, 475);
		g.drawString("Tir", 700, 575);
		
		g.drawString(j2_gauche, 1000, 175);
        g.drawString(j2_droit, 1000, 275);
        g.drawString(j2_haut, 1000, 375);
        g.drawString(j2_bas, 1000, 475);
        g.drawString(j2_tir, 1000, 575);
			
        //BUG 
        if(bug==false) {
          g.drawString("Touches en double",515 , 725);
        }
      
	}
		public static int[] ReadFile(String name) {
			int[] command = new int[10];
			int rd = 0;
			try{
				// Sert a aller dans un fichier et le lire dans un boucle par ligne
				InputStream flux=new FileInputStream(name); 
				InputStreamReader lecture=new InputStreamReader(flux);
				BufferedReader buff=new BufferedReader(lecture);
				String ligne;
				
				while ((ligne=buff.readLine())!=null){
						// System.out.println(ligne);
						switch(rd) {
						case 0 :  	command[rd]=Integer.parseInt(ligne);				
						case 1 :	command[rd]=Integer.parseInt(ligne);
						case 2 :	command[rd]=Integer.parseInt(ligne);
						case 3 :	command[rd]=Integer.parseInt(ligne);
						case 4 :	command[rd]=Integer.parseInt(ligne);
						case 5 :	command[rd]=Integer.parseInt(ligne);
						case 6 :	command[rd]=Integer.parseInt(ligne);
						case 7 :	command[rd]=Integer.parseInt(ligne);
						case 8 :	command[rd]=Integer.parseInt(ligne);
						case 9 :	command[rd]=Integer.parseInt(ligne);
						
					}
					rd++;
				}
				rd=0;
				buff.close(); 
				}		
				catch (Exception e){
				System.out.println("Impossible de lire : "+name);
				}
				return command;					
			}
		public void Write(String donnee,int num_ligne) throws IOException {
			Path path =Paths.get("change.txt");
			List<String> lines = Files.readAllLines(path);			
			lines.remove(num_ligne);
				lines.add(num_ligne,donnee);			
			
			Files.write(path,lines);	
		}
		public int InputJB() {
			String rep="";
			System.out.println("Entrer votre touche");
			rep = JOptionPane.showInputDialog("Quel est votre touche ? ");
			inttouche=0;
			inttouche= rep.charAt((char)inttouche);
			System.out.println("Voici votre touche : ");
			System.out.println(inttouche);
			return inttouche;
		}
		
}
		
			
			
			
			
			
				
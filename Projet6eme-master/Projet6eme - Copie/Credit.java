import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Credit extends JFrame implements ActionListener{
   private JButton close;
   private boolean debug = false;
    
   public Credit(){
       super("Crédit");
       JPanel jpcredit = new JPanel();
       jpcredit.setBackground(Color.BLACK);
       jpcredit.setLayout(new GridLayout(3,1));
       
       JLabel titre = new JLabel("Kawaii loli battlefield", SwingConstants.CENTER);
       titre.setFont(new Font(null, Font.BOLD, 25));
       titre.setForeground(Color.WHITE);
       jpcredit.add(titre);
       JLabel nom = new JLabel("Un jeu de Justin Dejonckheere et Mathieu Roger", SwingConstants.CENTER);
       nom.setForeground(Color.WHITE);
       jpcredit.add(nom);
       
       JButton jbquit = new JButton("Fermer");
       jbquit.setFocusable(false);
       jbquit.addActionListener(this);
       jpcredit.add(jbquit);
       
       this.setContentPane(jpcredit);
       this.pack();
       this.setResizable(false);
       this.setLocationRelativeTo(null);
       this.setVisible(true);
   }
   
   public void paintComponent(Graphics g) {
	   g.setColor(Color.BLUE);
	   g.drawString("test", 10, 10);
	   
   }
   
   public void actionPerformed(ActionEvent ae){
       this.dispose();
   }

}

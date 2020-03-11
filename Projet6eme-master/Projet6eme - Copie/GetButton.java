import javax.swing.*;
import java.awt.*;

public class GetButton extends JButton{
	public TypeButton TpBut;
	
	public GetButton(String name,TypeButton tpBut) {
		super(name);
		this.TpBut=tpBut;		
	}
	
}

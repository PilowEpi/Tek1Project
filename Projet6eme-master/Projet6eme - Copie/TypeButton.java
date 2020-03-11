
public enum TypeButton {
	J1_GAUCHE(0),
	J1_DROIT(1),
	J1_HAUT(2),
	J1_BAS(3),
	J1_TIR(4),
	J2_GAUCHE(5),
	J2_DROIT(6),
	J2_HAUT(7),
	J2_BAS(8),
	J2_TIR(9),
	J_QUIT(10),
	J_RETAB(11),
	J_OK(12);
	
	private final int value;
	
	TypeButton(int value)
	{
		this.value = value;
	}
	
	public int GetValue() 
	{
		return value;
	}
			
}


public class InputData {
	public static int[] commandArray;
	
	public static int GetKey(TypeButton action){
		if(commandArray.length == 0)
			return -1;
		System.out.println(commandArray[action.GetValue()]);
		return commandArray[action.GetValue()];
	}	
}

package ctci;

import java.util.Arrays;

public class Problem1_1 {

	public static boolean isWhollyUnique(String string){
		char[] cstr = string.toCharArray();
		Arrays.sort(cstr);
		for(int i = 0; i < cstr.length; i++){
			if(i > 0 && cstr[i] == cstr[i - 1]){
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args){
		String greeting = "He World!";
		System.out.print(isWhollyUnique(greeting));
	}
}

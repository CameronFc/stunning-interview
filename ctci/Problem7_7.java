package ctci;

import java.util.Scanner;

public class Problem7_7 {

	public static boolean is357(int value){
		while(value % 3 == 0){
			value = value / 3;
		}
		while(value % 5 == 0){
			value = value / 5;
		}
		while(value % 7 == 0){
			value = value / 7;
		}
		if(value == 1 ){
			return true;
		}else{
			return false;
		}
	}
	
	public static int root357(int n){
		int oldValue = 1;
		
		int last3 = 3;
		int last5 = 5;
		int last7 = 7;
		
		int counter = 0;
		
		while(counter < n){
			
			int min3 = Math.min(Math.min(last3 * 3, last5 * 5), last7 * 7);
			int min5 = Math.min(Math.min(last3 * 3, last5 * 5), last7 * 7);
			int min7 = Math.min(Math.min(last3 * 3, last5 * 5), last7 * 7);
			
			if(min3 <= min5 && min3 <= min7 && min3 > oldValue){
				last3 = min3;
				oldValue = min3;
			}else if(min5 <= min3 && min5 <= min7 && min5 > oldValue){
				last5 = min5;
				oldValue = min5;				
			}else if(min7 > oldValue){
				last7 = min7;
				oldValue = min7;								
			}else{
				System.out.println("None of the 9 values were larger than the previous 357!");
			}
			System.out.println(Integer.toString(oldValue));
			
			counter++;
		}
		
		return oldValue;
	}
	
	// Simplest method, proceed until we find a nth value
	public static int simple357(int n){
		int value = -1;
		int counter = 0;
		int i = 0;;
		while(counter < n){
			i++;
			if(is357(i)){
				counter++;
				value = i;
				System.out.println(Integer.toString(i));
			}
		}
		return value;
	}
	
	public static void main(String[] args) {
		System.out.println("Enter nth term:");
		Scanner scanner = new Scanner(System.in);		
		int n = scanner.nextInt();
		scanner.close();		
		System.out.println(Integer.toString(root357(n)));
	}

}
